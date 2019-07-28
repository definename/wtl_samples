#include "pch.h"
#include "TrayIcon.h"

class App : public CWindowImpl<App>
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	App() = default;
	//! Destructor.
	~App();

	//
	// Public types
	//
public:
	//! Tray icon pointer type.
	typedef std::shared_ptr<TrayIcon> TrayIconPtr;

	//
	// Message map.
	//
private:
	// Message map.
	BEGIN_MSG_MAP(App)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER_EX(TrayIcon::WM_TRAY_ICON, OnTray)
	END_MSG_MAP()

	//
	// Event handlers.
	//
private:
	//! On close event handler.
	LRESULT OnClose(UINT, WPARAM, LPARAM, BOOL&);
	//! On command event handler.
	LRESULT OnCommand(UINT, WPARAM, LPARAM, BOOL&);
	//! On create handler.
	LRESULT OnCreate(UINT, WPARAM, LPARAM, BOOL&);
	//! On destroy handler.
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
	//! On tray icon handler
	LRESULT OnTray(UINT, WPARAM, LPARAM);

	//
	// Private data members.
	//
private:
	//! Tray icon pointer.
	TrayIconPtr trayIcon_;
};