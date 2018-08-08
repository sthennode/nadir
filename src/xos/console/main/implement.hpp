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
//   File: implement.hpp
//
// Author: $author$
//   Date: 8/7/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MAIN_IMPLEMENT_HPP
#define _XOS_CONSOLE_MAIN_IMPLEMENT_HPP

#include "xos/console/main/interface.hpp"
#include "xos/console/std/implement.hpp"

namespace xos {
namespace console {
namespace main {

///////////////////////////////////////////////////////////////////////
//  Class: implementt
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = main::interface, 
 class Tconsole_implements = console::std::implement>

class _EXPORT_CLASS implementt
: virtual public Tconsole_implements, virtual public Timplements {
public:
    typedef Tconsole_implements console_implements;
    typedef Timplements implements;
    typedef implements interface;

    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
    
protected:
    virtual int operator()(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_run(argc, argv, env))) {
            if (!(err = run(argc, argv, env))) {
            } else {
            }
            if (!(err2 = after_run(argc, argv, env))) {
            } else {
                if (!err) err = err2;
            }
        } else {
        }
        return err;
    }
    virtual int before(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
}; // class _EXPORT_CLASS implementt

typedef implementt<> implement;

} // namespace main
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_MAIN_IMPLEMENT_HPP 
