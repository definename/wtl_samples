#pragma once

//////////////////////////////////////////////////////////////////////////
// STL includes and definitions.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//////////////////////////////////////////////////////////////////////////
// ATL includes and definitions.
//

#include <atlbase.h>
#include <atlstr.h>
#include <atltypes.h>

//////////////////////////////////////////////////////////////////////////
// WTL includes and definitions.
//

#include <wtl/atlapp.h>
#include <wtl/atlctrls.h>
#include <wtl/atlcrack.h>
#include <wtl/atlframe.h>
#include <wtl/atlddx.h>

extern CAppModule _Module;

//////////////////////////////////////////////////////////////////////////
// boost includes and definitions.
//

#include "boost/algorithm/string.hpp"
#include "boost/algorithm/string/detail/classification.hpp"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/filesystem/path.hpp>
#include "boost/lexical_cast.hpp"
#include <boost/serialization/vector.hpp>
#include "boost/shared_ptr.hpp"

//type of archive file name
typedef const boost::filesystem::path FileNameType;

//////////////////////////////////////////////////////////////////////////
// Resource header file that include definitions for the resources used in project
//

#include "resource.h"
