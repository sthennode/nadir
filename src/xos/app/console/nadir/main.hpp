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
//   File: main.hpp
//
// Author: $author$
//   Date: 8/7/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_NADIR_MAIN_HPP
#define _XOS_APP_CONSOLE_NADIR_MAIN_HPP

#include "xos/mt/apple/mach/semaphore.hpp"
#include "xos/console/main/extend.hpp"
#include "xos/logger/interface.hpp"

namespace xos {
namespace app {
namespace console {
namespace nadir {

///////////////////////////////////////////////////////////////////////
//  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public xos::console::main::implement, public xos::console::main::extend {
public:
    typedef xos::console::main::implement implements;
    typedef xos::console::main::extend extends;

    main() {
    }
    virtual ~main() {
    }
private:
    main(const main& copy) {
        LOG_ERROR("...unexpected throw (exception::base(exception::failed))...");
        throw (exception::base(exception::failed));
    }
    
protected:
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        try {
            mt::apple::mach::semaphore acquired;
            try {
                xos::acquire acquire(acquired);
                outlln("hello", NULL);
                try {
                    xos::release release(acquired);
                } catch (...) {
                    LOG_ERROR("...catch (...)");
                    err = 1;
                }
            } catch (...) {
                LOG_ERROR("...catch (...)");
                err = 1;
            }
        } catch (...) {
            LOG_ERROR("...catch (...)");
            err = 1;
        }
        return err;
    }
}; // class _EXPORT_CLASS main

} // namespace nadir
} // namespace console
} // namespace app
} // namespace xos

#endif // _XOS_APP_CONSOLE_NADIR_MAIN_HPP 
