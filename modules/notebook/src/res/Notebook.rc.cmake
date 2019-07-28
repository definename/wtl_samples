// Microsoft Visual C++ generated resource script.
//
#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
//
// Icon
//

// Icon with lowest ID value placed first to ensure application icon
// remains consistent on all systems.
IDI_ICON                ICON                    "@CMAKE_CURRENT_LIST_DIR@/src/res/Carrot.ico"

#define APSTUDIO_READONLY_SYMBOLS
/////////////////////////////////////////////////////////////////////////////
//
// Generated from the TEXTINCLUDE 2 resource.
//
#include "afxres.h"

/////////////////////////////////////////////////////////////////////////////
#undef APSTUDIO_READONLY_SYMBOLS

/////////////////////////////////////////////////////////////////////////////
// Russian (Russia) resources

#if !defined(AFX_RESOURCE_DLL) || defined(AFX_TARG_RUS)
LANGUAGE LANG_RUSSIAN, SUBLANG_DEFAULT

#ifdef APSTUDIO_INVOKED
/////////////////////////////////////////////////////////////////////////////
//
// TEXTINCLUDE
//

1 TEXTINCLUDE 
BEGIN
    "resource.h\0"
END

2 TEXTINCLUDE 
BEGIN
    "#include ""afxres.h""\r\n"
    "\0"
END

3 TEXTINCLUDE 
BEGIN
    "\r\n"
    "\0"
END

#endif    // APSTUDIO_INVOKED


/////////////////////////////////////////////////////////////////////////////
//
// Dialog
//

IDD_DIALOG1 DIALOGEX 0, 0, 567, 162
STYLE DS_SETFONT | DS_FIXEDSYS | DS_CENTERMOUSE | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME
CAPTION "Notebook"
MENU IDR_MENU1
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    CONTROL         "",IDC_LIST1,"SysListView32",LVS_REPORT | LVS_ALIGNLEFT | LVS_NOSORTHEADER | WS_BORDER,7,7,297,127
    DEFPUSHBUTTON   "Add",IDC_REC_ADD,201,141,50,14
    PUSHBUTTON      "Remove",IDC_REC_DELETE,255,141,49,14
    LTEXT           "Address:",IDC_STATIC2,315,7,30,8
    LTEXT           "Birthday:",IDC_STATIC3,315,37,30,8
    EDITTEXT        IDC_EDIT_ADDR,315,17,245,13,ES_AUTOHSCROLL
    EDITTEXT        IDC_EDIT_BDAY,315,48,245,14,ES_AUTOHSCROLL
END


/////////////////////////////////////////////////////////////////////////////
//
// DESIGNINFO
//

#ifdef APSTUDIO_INVOKED
GUIDELINES DESIGNINFO
BEGIN
    IDD_DIALOG1, DIALOG
    BEGIN
        LEFTMARGIN, 7
        RIGHTMARGIN, 560
        VERTGUIDE, 7
        VERTGUIDE, 201
        VERTGUIDE, 251
        VERTGUIDE, 255
        VERTGUIDE, 304
        VERTGUIDE, 315
        TOPMARGIN, 7
        BOTTOMMARGIN, 155
        HORZGUIDE, 7
        HORZGUIDE, 14
        HORZGUIDE, 17
        HORZGUIDE, 30
        HORZGUIDE, 37
        HORZGUIDE, 45
        HORZGUIDE, 48
        HORZGUIDE, 62
        HORZGUIDE, 134
        HORZGUIDE, 141
        HORZGUIDE, 155
    END
END
#endif    // APSTUDIO_INVOKED


/////////////////////////////////////////////////////////////////////////////
//
// Menu
//

IDR_MENU1 MENU
BEGIN
    MENUITEM "Exit",                        ID_EXIT
    MENUITEM "Save",                        ID_SAVE
    MENUITEM "About",                       40004
END

#endif    // Russian (Russia) resources
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Ukrainian (Ukraine) resources

#if !defined(AFX_RESOURCE_DLL) || defined(AFX_TARG_UKR)
LANGUAGE LANG_UKRAINIAN, SUBLANG_DEFAULT

/////////////////////////////////////////////////////////////////////////////
//
// Dialog
//

IDD_DIALOG2 DIALOGEX 0, 0, 351, 101
STYLE DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "Add new record"
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    RTEXT           "Surname Name Patronymic:",IDC_STATIC,7,12,91,8
    RTEXT           "Cell phone numbe:",IDC_STATIC,7,30,91,8
    RTEXT           "Address:",IDC_STATIC,7,48,91,8
    RTEXT           "Birthday:",IDC_STATIC,7,66,91,8
    EDITTEXT        IDC_INPUT_NAME,101,7,243,13,ES_AUTOHSCROLL
    EDITTEXT        IDC_INPUT_PHONE,101,24,243,14,ES_AUTOHSCROLL
    EDITTEXT        IDC_INPUT_ADDR,101,42,243,14,ES_AUTOHSCROLL
    EDITTEXT        IDC_INPUT_BDAY,101,60,243,14,ES_AUTOHSCROLL
    DEFPUSHBUTTON   "Push",IDOK,294,81,50,13
    PUSHBUTTON      "Exit",IDCANCEL,240,81,50,13
END


/////////////////////////////////////////////////////////////////////////////
//
// DESIGNINFO
//

#ifdef APSTUDIO_INVOKED
GUIDELINES DESIGNINFO
BEGIN
    IDD_DIALOG2, DIALOG
    BEGIN
        LEFTMARGIN, 7
        RIGHTMARGIN, 344
        VERTGUIDE, 98
        VERTGUIDE, 101
        VERTGUIDE, 290
        VERTGUIDE, 294
        TOPMARGIN, 7
        BOTTOMMARGIN, 94
        HORZGUIDE, 20
        HORZGUIDE, 24
        HORZGUIDE, 38
        HORZGUIDE, 42
        HORZGUIDE, 56
        HORZGUIDE, 60
        HORZGUIDE, 74
        HORZGUIDE, 81
    END
END
#endif    // APSTUDIO_INVOKED

#endif    // Ukrainian (Ukraine) resources
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


#ifndef APSTUDIO_INVOKED
/////////////////////////////////////////////////////////////////////////////
//
// Generated from the TEXTINCLUDE 3 resource.
//


/////////////////////////////////////////////////////////////////////////////
#endif    // not APSTUDIO_INVOKED

