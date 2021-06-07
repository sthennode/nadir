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
///   File: shared.hpp
///
/// Author: $author$
///   Date: 1/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_IPC_OS_SHARED_HPP
#define XOS_IPC_OS_SHARED_HPP

#include "xos/ipc/os/os.hpp"

#if defined(WINDOWS)  
#include "xos/ipc/microsoft/windows/shared.hpp"
#elif defined(APPLEOSX)  
#include "xos/ipc/apple/osx/shared.hpp"
#elif defined(APPLEIOS)  
#include "xos/ipc/apple/ios/shared.hpp"
#elif defined(SOLARIS)  
#include "xos/ipc/oracle/solaris/shared.hpp"
#elif defined(MACH)  
#include "xos/ipc/mach/shared.hpp"
#elif defined(LINUX)  
#include "xos/ipc/linux/shared.hpp"
#else /// defined(LINUX)  
#include "xos/ipc/posix/shared.hpp"
#endif /// defined(LINUX) 

namespace xos {
namespace ipc {
namespace os {

typedef os::shared shared;

} /// namespace os
} /// namespace ipc
} /// namespace xos

#endif /// ndef XOS_IPC_OS_SHARED_HPP
