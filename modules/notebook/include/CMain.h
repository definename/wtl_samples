#pragma once

#include "FriendManager.h"

//////////////////////////////////////////////////////////////////////////
// Interface of the CMain class.
//

class CMain
	: public CSimpleDialog<IDD_DIALOG1>
	, public CDialogResize<CMain>
	, public CWinDataExchange<CMain>
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	CMain();
	//! Destructor.
	~CMain();

	//
	// Public interface.
	//
public:
	BEGIN_MSG_MAP_EX(CMain)
		MSG_WM_INITDIALOG(OnInitDialogCMain)
		NOTIFY_ID_HANDLER(IDC_LIST1, OnCatchRowClickAndDClick)
		COMMAND_HANDLER(ID_EXIT, BN_CLICKED, OnExit)
		COMMAND_HANDLER(ID_SAVE, BN_CLICKED, OnSave)
		COMMAND_HANDLER(ID_ABOUT, BN_CLICKED, OnAbout)
		COMMAND_HANDLER(IDC_REC_ADD, BN_CLICKED, OnAdd)
		COMMAND_HANDLER(IDC_REC_DELETE, BN_CLICKED, OnRemove)
		COMMAND_RANGE_CODE_HANDLER(IDC_EDIT_ADDR, IDC_EDIT_BDAY, EN_CHANGE, OnAddrBdayChange)
		CHAIN_MSG_MAP(CDialogResize<CMain>)
		CHAIN_MSG_MAP(CSimpleDialog<IDD_DIALOG1>)
	END_MSG_MAP()
	
	BEGIN_DLGRESIZE_MAP(CMain)
		DLGRESIZE_CONTROL(IDC_LIST1, DLSZ_SIZE_X | DLSZ_SIZE_Y)
		DLGRESIZE_CONTROL(IDC_REC_ADD, DLSZ_MOVE_X | DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDC_REC_DELETE, DLSZ_MOVE_X | DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDC_STATIC2, DLSZ_MOVE_X)
		DLGRESIZE_CONTROL(IDC_STATIC3, DLSZ_MOVE_X)
		DLGRESIZE_CONTROL(IDC_EDIT_ADDR, DLSZ_MOVE_X)
		DLGRESIZE_CONTROL(IDC_EDIT_BDAY, DLSZ_MOVE_X)
	END_DLGRESIZE_MAP()

	BEGIN_DDX_MAP(CMain)
		DDX_TEXT(IDC_EDIT_ADDR, addrStringCMain_)
		DDX_TEXT(IDC_EDIT_BDAY, bdayStringCMain_)
	END_DDX_MAP()

	//! Access to about menu item.
	LRESULT OnAbout(WORD, WORD, HWND, BOOL&);
	//! Handler add button - add record to list-view.
	LRESULT OnAdd(WORD, WORD, HWND, BOOL&);
	//! Handler changing edit controls: address and birthday.
	LRESULT OnAddrBdayChange(WORD, WORD, HWND, BOOL&);
	//! Catch click and double click on list-view row and set current item index.
	LRESULT OnCatchRowClickAndDClick(WORD, LPNMHDR, BOOL&);
	//! Exit from dialog.
	LRESULT OnExit(WORD, WORD, HWND, BOOL&);
	//! Dialog initialization.
	LRESULT OnInitDialogCMain(HWND, LPARAM);
	//! Handler delete button - delete record from list-view.
	LRESULT OnRemove(WORD, WORD, HWND, BOOL&);
	//! Save menu item - serialization.
	LRESULT OnSave(WORD, WORD, HWND, BOOL&);

	//
	// Private data members.
	//
private:
	//! Data from address edit controls.
	CString addrStringCMain_;
	//! Data from birthday edit controls.
	CString bdayStringCMain_;
	//! Index of current row in list-view.
	int currentRow_;
	//! Address edit controls.
	CEdit editAddressCMain_;
	//! Birthday edit controls.
	CEdit editBdayCMain_;
	//! List-View Control.
	CListViewCtrl listView_;
	//! Shared pointer on FriendManager
	FriendManagerPtr managerCMain_;

};