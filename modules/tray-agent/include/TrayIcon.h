#include "pch.h"

class TrayIcon
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	TrayIcon(CWindow const& win, unsigned int const id = 99);
	//! Destructor.
	~TrayIcon();

	//
	// Public types
	//
public:
	//! Icon constants.
	enum IconConstants
	{
		WM_TRAY_ICON = WM_USER + 1024
	};
	//! Wrapper around NOTIFYICONDATA
	struct IconData : public NOTIFYICONDATA
	{
		IconData(HWND handle, unsigned int const id)
		{
			::ZeroMemory(this, sizeof(NOTIFYICONDATA));
			cbSize = sizeof(NOTIFYICONDATA);
			hWnd = handle;
			uID = id;
			uCallbackMessage = TrayIcon::WM_TRAY_ICON;
			uFlags = NIF_MESSAGE;
		}
	};
	//! Icon data pointer type.
	typedef std::shared_ptr<IconData> IconDataPtr;

	//
	// Public interface.
	//
public:
	//! Returns icon id.
	unsigned int GetId() const;
	//! Removes icon.
	bool RemoveIcon();
	//! Sets icon.
	bool SetIcon(unsigned short const& rId, std::wstring const& tooltip = _T(""));

	//
	// Private data members.
	//
private:
	//! Icon data pointer.
	IconDataPtr iconData_;
	//! Is icon added.
	bool isAdded_;
	//! Icon id.
	unsigned int id_;
};