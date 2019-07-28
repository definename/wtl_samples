#pragma once

namespace utils
{

bool IsOneInstance(HANDLE& event, std::wstring const& eventName)
{
	bool result = true;

	event = ::CreateEvent(nullptr, FALSE, FALSE, eventName.c_str());
	DWORD error = ::GetLastError();
	if (!event || error == ERROR_INVALID_HANDLE || error == ERROR_ALREADY_EXISTS)
	{
		::CloseHandle(event);
		event = nullptr;

		result = false;
	}

	return result;
}

}