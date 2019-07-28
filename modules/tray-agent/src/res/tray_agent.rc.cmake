// Microsoft Visual C++ generated resource script.
//
#include "@CMAKE_CURRENT_LIST_DIR@/include/resource.h"

#define APSTUDIO_READONLY_SYMBOLS
/////////////////////////////////////////////////////////////////////////////
//
// Generated from the TEXTINCLUDE 2 resource.
//
#include "windows.h"

/////////////////////////////////////////////////////////////////////////////
#undef APSTUDIO_READONLY_SYMBOLS

/////////////////////////////////////////////////////////////////////////////
// English (United States) resources

#if !defined(AFX_RESOURCE_DLL) || defined(AFX_TARG_ENU)
LANGUAGE LANG_ENGLISH, SUBLANG_ENGLISH_US

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
    "#include ""windows.h""\r\n"
    "\0"
END

3 TEXTINCLUDE 
BEGIN
    "\r\n"
    "\0"
END

#endif    // APSTUDIO_INVOKED


//////////////////////////////////////////////////////////////////////////////
//
// ICON
//

IDI_CONNECTED                ICON                    "@CMAKE_CURRENT_LIST_DIR@/src/res/Connected.ico"

IDI_DISCONNECTED             ICON                    "@CMAKE_CURRENT_LIST_DIR@/src/res/Disconnected.ico"


/////////////////////////////////////////////////////////////////////////////
//
// Menu
//

IDR_TRAY_MENU MENU
BEGIN
    POPUP "TrayMenu"
    BEGIN
        MENUITEM "Preferences",                 ID_PREFERENCES
        MENUITEM "Exit",                        ID_EXIT
    END
END


#endif    // English (United States) resources
/////////////////////////////////////////////////////////////////////////////



#ifndef APSTUDIO_INVOKED
/////////////////////////////////////////////////////////////////////////////
//
// Generated from the TEXTINCLUDE 3 resource.
//


/////////////////////////////////////////////////////////////////////////////
#endif    // not APSTUDIO_INVOKED

