///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2018 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: main.cpp
//
// Author: $author$
//   Date: 7/31/2018
///////////////////////////////////////////////////////////////////////
#include "xos/console/main/main.hpp"
#include "xos/console/std/io.hpp"
#include "xos/console/logger.hpp"

namespace xos {
namespace console {
namespace main {


} // namespace main
} // namespace console
} // namespace xos

///////////////////////////////////////////////////////////////////////
// Function: main
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env) {
    int err = 0;
    ERR_LOG_DEBUG("try {...");
    try {
        ::xos::unlocked locked;
        ::xos::console::std::io io(locked);
        ::xos::console::logger logger(io);

        LOG_DEBUG("::xos::console::main::interface::main(argc, argv, env)...")
        err = ::xos::console::main::interface::main(argc, argv, env);
        LOG_DEBUG("...err = " << err << " on ::xos::console::main::interface::main(argc, argv, env)")
    } catch (...) {
        ERR_LOG_ERROR("...catch (...)");
        return 1;
    }
    ERR_LOG_DEBUG("...} try");
    return err;
}
