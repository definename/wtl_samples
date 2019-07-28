#include "pch.h"
#include "TrayIcon.h"
#include "Resource.h"

TrayIcon::TrayIcon(CWindow const& win, unsigned int const id /*= 99*/)
	: iconData_(new IconData(win, id))
	, isAdded_(false)
	, id_(id)
{ }

TrayIcon::~TrayIcon()
{
	try
	{
		RemoveIcon();
	}
	catch (std::exception const& e)
	{
		std::cerr << "Tray icon destruction error: " << e.what();
	}
}

unsigned int TrayIcon::GetId() const
{
	return id_;
}

bool TrayIcon::RemoveIcon()
{
	if (!isAdded_)
		return false;

	bool ok = ::Shell_NotifyIcon(NIM_DELETE, iconData_.get()) == TRUE;
	if (ok)
		isAdded_ = false;

	return ok;
}

bool TrayIcon::SetIcon(unsigned short const& rId, std::wstring const& tooltip /*= _T("")*/)
{
	CIcon icon;
	icon.LoadIcon(rId, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), LR_DEFAULTSIZE);

	iconData_->hIcon = icon.m_hIcon;
	iconData_->uFlags |= NIF_ICON;

	iconData_->uFlags |= NIF_TIP;
	if (!tooltip.empty() && tooltip.size() < _countof(iconData_->szTip))
		wcscpy_s(iconData_->szTip, tooltip.c_str());

	bool ok = ::Shell_NotifyIcon(isAdded_ ? NIM_MODIFY : NIM_ADD, iconData_.get()) == TRUE;
	if (ok)
		isAdded_ = true;

	return ok;
}