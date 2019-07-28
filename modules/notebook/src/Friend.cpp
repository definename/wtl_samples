#include "pch.h"
#include "Friend.h"

//////////////////////////////////////////////////////////////////////////
// Implementation of the Friend class.
//

Friend::Friend()
{

}

Friend::Friend(
	const std::wstring& fullName,
	const std::wstring& address,
	const std::wstring& birthday,
	const std::wstring& phone)
	: address_(address)
	, birthday_(birthday)
	, phone_(phone)
{
	std::vector<std::wstring> splitFullName;
	boost::algorithm::split(splitFullName, fullName, boost::algorithm::is_any_of(" "));
	
	size_t index = 0;
	while(index != splitFullName.size())
	{
		switch(index)
		{
		case 0:
			surname_ = splitFullName[index];
			index ++;
			break;
		case 1:
			name_ = splitFullName[index];
			index ++;
			break;
		case 2:
			patronymic_ = splitFullName[index];
			index ++;
			break;
		default:
			index ++;
			break;
		}
	}
}

Friend::~Friend()
{

}

std::wstring Friend::GetAddress() const
{
	return address_;
}

std::wstring Friend::GetBirthday() const
{
	return birthday_;
}

std::wstring Friend::GetName() const
{
	return name_;
}

std::wstring Friend::GetPatronymic() const
{
	return patronymic_;
}

std::wstring Friend::GetPhone() const
{
	return phone_;
}

std::wstring Friend::GetSurname() const
{
	return surname_;
}

void Friend::SetAddress(const std::wstring& fAddress)
{
	address_ = fAddress;
}

void Friend::SetBirthday(const std::wstring& fBday)
{
	birthday_ = fBday;
}

void Friend::SetName(const std::wstring& fName)
{
	name_ = fName;
}

void Friend::SetPatronymic(const std::wstring& fPatronymic)
{
	patronymic_ = fPatronymic;
}

void Friend::SetPhone(const std::wstring& fPhone)
{
	phone_ = fPhone;
}

void Friend::SetSurname(const std::wstring& fSurname)
{
	surname_ = fSurname;
}