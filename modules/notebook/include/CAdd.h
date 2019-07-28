#pragma once

#include "FriendManager.h"

//////////////////////////////////////////////////////////////////////////
// Interface of the CAdd class.
//

class CAdd
	: public CSimpleDialog<IDD_DIALOG2>
	, public CWinDataExchange<CAdd>
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor
	CAdd(const FriendManagerPtr&, const int&);
	//! Destructor
	~CAdd();

	//
	// Public interface.
	//
public:
	BEGIN_MSG_MAP_EX(CAdd)
		MSG_WM_INITDIALOG(OnInitDialogCAdd)
		COMMAND_HANDLER(IDOK, BN_CLICKED, OnEditChange)
		CHAIN_MSG_MAP(CSimpleDialog<IDD_DIALOG2>)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CAdd)
		DDX_TEXT(IDC_INPUT_ADDR, addrStringCAdd_)
		DDX_TEXT(IDC_INPUT_BDAY, bdayStringCAdd_)
		DDX_TEXT(IDC_INPUT_NAME, nameStringCAdd_)
		DDX_TEXT(IDC_INPUT_PHONE, phoneStringCAdd_)
	END_DDX_MAP()

	//! Handler changing edit controls
	LRESULT OnEditChange(WORD, WORD, HWND, BOOL&);
	//! Dialog initialization.
	LRESULT OnInitDialogCAdd(HWND, LPARAM);

	//
	// Private data members.
	//
private:
	//! Data from address edit controls.
	CString addrStringCAdd_;
	//! Data from birthday edit controls.
	CString bdayStringCAdd_;
	//! Index of current row in list-view.
	int currentRow_;
	//! Full name Edit controls
	CEdit editFullName_;
	//! Address edit controls
	CEdit editAddressCAdd_;
	//! Birthday edit controls
	CEdit editBdayCAdd_;
	//! Phone edit controls
	CEdit editPhoneCAdd_;
	//! Shared pointer on FriendManager.
	FriendManagerPtr managerCMain_;
	//! Data from full name edit controls.
	CString nameStringCAdd_;
	//! Data from phone edit controls.
	CString phoneStringCAdd_;
};