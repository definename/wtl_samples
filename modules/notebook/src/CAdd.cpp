#include "pch.h"
#include "CAdd.h"
#include "Friend.h"

//////////////////////////////////////////////////////////////////////////
// Implementation of the CAdd class.
//

CAdd::CAdd(const FriendManagerPtr& managerAdd, const int& currentRow)
	: managerCMain_(managerAdd)
	, currentRow_(currentRow)
{

}

CAdd::~CAdd()
{

}

LRESULT CAdd::OnEditChange(WORD, WORD, HWND, BOOL&)
{
	if (DoDataExchange(TRUE))
	{
		if (std::wstring(nameStringCAdd_).empty() && std::wstring(phoneStringCAdd_).empty() 
			&& std::wstring(addrStringCAdd_).empty() && std::wstring(bdayStringCAdd_).empty())
		{
			EndDialog(this->m_hWnd, 0);
			return 0;
		}
		else
		{
			Friend f(
				(std::wstring(nameStringCAdd_)),
				(std::wstring(addrStringCAdd_)),
				(std::wstring(bdayStringCAdd_)),
				(std::wstring(phoneStringCAdd_)));

			if(currentRow_ == -1)
			{
				managerCMain_->AddFriend(f);
			}
			else
			{
				managerCMain_->SetFriend(currentRow_, f);
			}
		}
		DoDataExchange(FALSE);
	}
	EndDialog(this->m_hWnd, 0);

	return 0;
}

LRESULT CAdd::OnInitDialogCAdd(HWND, LPARAM)
{
	editAddressCAdd_ = GetDlgItem(IDC_INPUT_ADDR);
	editBdayCAdd_ = GetDlgItem(IDC_INPUT_BDAY);
	editFullName_ = GetDlgItem(IDC_INPUT_NAME);
	editPhoneCAdd_ = GetDlgItem(IDC_INPUT_PHONE);

	if(currentRow_ != -1)
	{
		Friend friendForPush(managerCMain_->GetFriend(this->currentRow_));
		editAddressCAdd_.SetWindowText(friendForPush.GetAddress().c_str());

		std::wstring  wstr = friendForPush.GetSurname();
		wstr.push_back(' ');
		wstr = wstr.append(friendForPush.GetName());
		wstr.push_back(' ');
		wstr = wstr.append(friendForPush.GetPatronymic());

		editBdayCAdd_.SetWindowText(friendForPush.GetBirthday().c_str());
		editFullName_.SetWindowText(wstr.c_str());
		editPhoneCAdd_.SetWindowText(friendForPush.GetPhone().c_str());
	}

	return 0;
}