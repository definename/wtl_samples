#if _MSC_VER >= 1400
#include "atlres.h"
#else
#include "afxres.h"
#endif

#if !defined(AFX_RESOURCE_DLL) || defined(AFX_TARG_ENU)
#ifdef _WIN32
LANGUAGE LANG_ENGLISH, SUBLANG_ENGLISH_US
#pragma code_page(1252)
#endif //_WIN32
#endif

VS_VERSION_INFO VERSIONINFO
 FILEVERSION @VERSION_MAJOR@,@VERSION_MINOR@,@VERSION_BUILD@,@VERSION_FILE_REVISION@
 PRODUCTVERSION @VERSION_MAJOR@.@VERSION_MINOR@.@VERSION_BUILD@.@VERSION_REVISION@
 FILEFLAGSMASK 0x17L
#ifdef _DEBUG
 FILEFLAGS 0x1L
#else
 FILEFLAGS 0x0L
#endif
 FILEOS 0x4L
 FILETYPE 0x1L
 FILESUBTYPE 0x0L
BEGIN
	BLOCK "StringFileInfo"
	BEGIN
		BLOCK "040904b0"
		BEGIN
			VALUE "CompanyName", "@VERSION_COMPANY_NAME@"
			VALUE "FileDescription", "@VERSION_FILE_DESC@"
			VALUE "FileVersion", "@VERSION_MAJOR@.@VERSION_MINOR@.@VERSION_BUILD@.@VERSION_FILE_REVISION@"
			VALUE "InternalName", "@VERSION_INTERNAL_NAME@"
			VALUE "LegalCopyright", "@VERSION_COPYRIGHT@"
			VALUE "OriginalFilename", "@VERSION_ORIGINAL_FILENAME@"
			VALUE "ProductName", "@VERSION_PRODUCT_NAME@"
			VALUE "ProductVersion", "@VERSION_MAJOR@.@VERSION_MINOR@.@VERSION_BUILD@.@VERSION_REVISION@"
		END
	END
	BLOCK "VarFileInfo"
	BEGIN
		VALUE "Translation", 0x409, 1200
	END
END