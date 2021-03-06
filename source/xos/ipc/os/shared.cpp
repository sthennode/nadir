///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: shared.cpp
///
/// Author: $author$
///   Date: 1/14/2020
///////////////////////////////////////////////////////////////////////
#include "xos/ipc/os/shared.hpp"

#if defined(WINDOWS)  
#include "xos/ipc/microsoft/windows/shared.cpp"
#elif defined(APPLEOSX)  
#include "xos/ipc/apple/osx/shared.cpp"
#elif defined(APPLEIOS)  
#include "xos/ipc/apple/ios/shared.cpp"
#elif defined(SOLARIS)  
#include "xos/ipc/oracle/solaris/shared.cpp"
#elif defined(MACH)  
#include "xos/ipc/mach/shared.cpp"
#elif defined(LINUX)  
#include "xos/ipc/linux/shared.cpp"
#else /// defined(LINUX)  
#include "xos/ipc/posix/shared.cpp"
#endif /// defined(LINUX) 

namespace xos {
namespace ipc {
namespace os {

} /// namespace os
} /// namespace ipc
} /// namespace xos
