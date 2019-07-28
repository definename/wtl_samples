#include "pch.h"
#include "App.h"
#include "Resource.h"

App::~App()
{
	trayIcon_->RemoveIcon();
}

LRESULT App::OnClose(UINT, WPARAM, LPARAM, BOOL&)
{
	DestroyWindow();
	return 0;
}

LRESULT App::OnCommand(UINT, WPARAM wParam, LPARAM, BOOL&)
{
	switch (static_cast<unsigned int>(wParam))
	{
	case ID_PREFERENCES:
	{
		MessageBox(_T("Preferences"));
		break;
	}
	case ID_EXIT:
	{
		PostMessage(WM_CLOSE);
		break;
	}
	default:
		break;
	}

	return 0;
}

LRESULT App::OnCreate(UINT, WPARAM, LPARAM, BOOL&)
{
	trayIcon_.reset(new TrayIcon(*this));
	if (!trayIcon_->SetIcon(IDI_CONNECTED, _T("Agent Disconnected")))
		MessageBox(_T("Unable to set tray icon"));

	return 0;
}

LRESULT App::OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
{
	::PostQuitMessage(0);
	return 0;
}

LRESULT App::OnTray(UINT, WPARAM wParam, LPARAM lParam)
{
	if (static_cast<unsigned int>(wParam) == trayIcon_->GetId())
	{
		switch (static_cast<unsigned int>(lParam))
		{
		case WM_LBUTTONDOWN:
		{
			CMenu menu;
			if (menu.LoadMenu(IDR_TRAY_MENU) == TRUE)
			{
				CPoint pt;
				::GetCursorPos(&pt);
				::SetForegroundWindow(m_hWnd);
				menu.GetSubMenu(0).TrackPopupMenu(
					TPM_BOTTOMALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, m_hWnd);
			}
			break;
		}
		case WM_LBUTTONDBLCLK:
		{
			MessageBox(_T("Left button db click"));
			break;
		}
		default:
			break;
		}
	}

	return 0;
}