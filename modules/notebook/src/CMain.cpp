#include "pch.h"
#include "CMain.h"
#include "CAdd.h"
#include "Friend.h"

//////////////////////////////////////////////////////////////////////////
// Implementation of the CMain class.
//

CMain::CMain()
	: currentRow_(-1)
	, managerCMain_(new FriendManager("text_arch.dat"))
{ }

CMain::~CMain()
{ }

LRESULT CMain::OnAbout(WORD, WORD, HWND, BOOL&)
{
	MessageBox(
		_T("WTL based program \"Notebook\" which will display and store contact information."),
		_T("About"),
		MB_OK | MB_ICONQUESTION);
	return 0;
}

LRESULT CMain::OnAdd(WORD, WORD, HWND, BOOL&)
{
	CAdd dlg(managerCMain_, -1);
	dlg.DoModal();

	listView_.DeleteAllItems();

	for(size_t index = 0; index != managerCMain_->GetNoteBookSize(); index++)
	{
		try 
		{
			Friend friendForPush(managerCMain_->GetFriend(index));

			std::wstring  wstr = friendForPush.GetSurname();
			wstr.push_back(' ');
			wstr = wstr.append(friendForPush.GetName());
			wstr.push_back(' ');
			wstr = wstr.append(friendForPush.GetPatronymic());

			listView_.InsertItem(index, wstr.c_str());
			listView_.SetItemText(index, 1, friendForPush.GetPhone().c_str());
		}
		catch(const std::exception& e)
		{
			::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
		}
	}
	currentRow_ = -1;

	return 0;
}

LRESULT CMain::OnAddrBdayChange(WORD, WORD, HWND, BOOL&)
{
	if(DoDataExchange(TRUE) && currentRow_ != -1)
	{
		try 
		{
			Friend friendForPush(managerCMain_->GetFriend(currentRow_));
			friendForPush.SetAddress(std::wstring(addrStringCMain_));
			friendForPush.SetBirthday(std::wstring(bdayStringCMain_));
			managerCMain_->SetFriend(currentRow_, friendForPush);
		}
		catch(const std::exception& e)
		{
			::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
		}
	}
	return 0;
}

LRESULT CMain::OnCatchRowClickAndDClick(WORD, LPNMHDR pNMHDR, BOOL&)
{
	NMITEMACTIVATE* plvdi = (NMITEMACTIVATE*) pNMHDR;

	switch(((NMHDR*)pNMHDR)->code)
	{
	case NM_CLICK:
		{
			currentRow_ = plvdi->iItem;
			if(currentRow_ >= 0)
			{
				try 
				{
					Friend friendForPush(managerCMain_->GetFriend(plvdi->iItem));
					editAddressCMain_.SetWindowTextW(friendForPush.GetAddress().c_str());
					editBdayCMain_.SetWindowTextW(friendForPush.GetBirthday().c_str());
				}
				catch(const std::exception& e)
				{
					::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
				}
			}
			break;
		}

	case NM_DBLCLK:
		{
			currentRow_ = plvdi->iItem;
			if(currentRow_ >= 0)
			{
				try 
				{
					CAdd dlg(managerCMain_, currentRow_);
					dlg.DoModal();

					listView_.DeleteAllItems();

					for(size_t index = 0; index != managerCMain_->GetNoteBookSize(); index++)
					{
						try 
						{
							Friend friendForPush(managerCMain_->GetFriend(index));

							std::wstring  wstr = friendForPush.GetSurname();
							wstr.push_back(' ');
							wstr = wstr.append(friendForPush.GetName());
							wstr.push_back(' ');
							wstr = wstr.append(friendForPush.GetPatronymic());

							listView_.InsertItem(index, wstr.c_str());
							listView_.SetItemText(index, 1, friendForPush.GetPhone().c_str());
						}
						catch(const std::exception& e)
						{
							::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
						}
					}
				}
				catch(const std::exception& e)
				{
					::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
				}
			}
			break;
		}
	}

	return 0;
}

LRESULT CMain::OnExit(WORD, WORD, HWND, BOOL&)
{
	EndDialog(this->m_hWnd, 0);
	return 0;
}

LRESULT CMain::OnInitDialogCMain(HWND, LPARAM)
{
	listView_ = GetDlgItem(IDC_LIST1);

	CRect rect;
	listView_.GetClientRect(rect);
	int width = rect.right-rect.left;

	listView_.InsertColumn(0, _T("Name"), LVCFMT_LEFT, width / 2, 0);
	listView_.InsertColumn(1, _T("Phone"), LVCFMT_LEFT, width / 2, 1);

	try 
	{
		managerCMain_->Load();
	}
	catch(const std::exception& e)
	{
		::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
	}

	Friend friendForPush;
	for(size_t index = 0; index != managerCMain_->GetNoteBookSize(); index++)
	{
		try 
		{
			friendForPush = managerCMain_->GetFriend(index);
			std::wstring  wstr = friendForPush.GetSurname();
			wstr.push_back(' ');
			wstr = wstr.append(friendForPush.GetName());
			wstr.push_back(' ');
			wstr = wstr.append(friendForPush.GetPatronymic());

			listView_.InsertItem(index, (LPCTSTR)wstr.c_str());
			listView_.SetItemText(index, 1, (LPCTSTR)friendForPush.GetPhone().c_str());
		}
		catch(const std::exception& e)
		{
			::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
		}
	}

	listView_.SetExtendedListViewStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	editAddressCMain_ = GetDlgItem(IDC_EDIT_ADDR);
	editBdayCMain_ = GetDlgItem(IDC_EDIT_BDAY);

	DlgResize_Init();

	return 0;
}

LRESULT CMain::OnRemove(WORD, WORD, HWND, BOOL&)
{
	if(currentRow_ >= 0)
	{
		try
		{
			managerCMain_->Remove(currentRow_);
			listView_.DeleteItem(currentRow_);
			currentRow_ = -1;
			editAddressCMain_.SetWindowTextW(TEXT(""));
			editBdayCMain_.SetWindowTextW(TEXT(""));
		}
		catch(const std::exception& e)
		{
			::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
		}
	}
	return 0;
}

LRESULT CMain::OnSave(WORD, WORD, HWND, BOOL&)
{
	try
	{
		managerCMain_->Save();
	}
	catch(const std::exception& e)
	{
		::MessageBoxA(m_hWnd, e.what(), "Error", MB_OK | MB_ICONHAND);
	}
	return 0;
}