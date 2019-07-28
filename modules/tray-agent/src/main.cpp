#include "pch.h"
#include "App.h"
#include "Utils.h"

CAppModule _Module;

int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_HIDE)
{
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	App app;
	if (app.Create(nullptr, CWindow::rcDefault, _T(""), WS_OVERLAPPEDWINDOW/*WS_POPUP, WS_EX_TOOLWINDOW*/) == nullptr)
	{
		ATLTRACE(_T("Main window creation failed!\n"));
		return 0;
	}
	app.ShowWindow(nCmdShow);

	int nRet = theLoop.Run();
	_Module.RemoveMessageLoop();

	return nRet;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR, int)
{
	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_COOL_CLASSES);

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = EXIT_FAILURE;
	try
	{
		CHandle event;
		if (!utils::IsOneInstance(event.m_h, L"Local\\TrayAgent"))
			throw std::runtime_error("One instance is already started");

		nRet = Run();
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error occurred: " << e.what();
	}

	_Module.Term();
	::CoUninitialize();

	return nRet;
}