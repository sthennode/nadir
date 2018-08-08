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
//   File: interface.hpp
//
// Author: $author$
//   Date: 8/7/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MAIN_INTERFACE_HPP
#define _XOS_CONSOLE_MAIN_INTERFACE_HPP

#include "xos/console/std/interface.hpp"

namespace xos {
namespace console {
namespace main {

///////////////////////////////////////////////////////////////////////
//  Class: interfacet
///////////////////////////////////////////////////////////////////////
template <class Tinterface = console::std::interface>
class _EXPORT_CLASS interfacet: virtual public Tinterface {
public:
    typedef Tinterface implements;

    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
    
    static int main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        interfacet* main = 0;

        if ((main = interfacet::main())) {
            if (!(err = main->before(argc, argv, env))) {
                int err2 = 0;

                if ((err = (*main)(argc, argv, env))) {
                }
                if ((err2 = main->after(argc, argv, env))) {
                    if (!err) err = err2;
                }
            }
        }
        return err;
    }
protected:
    static interfacet*& main() {
        static interfacet* main = 0;
        return main;
    }

    virtual int operator()(int argc, char_t** argv, char_t** env) = 0;
    virtual int before(int argc, char_t** argv, char_t** env) = 0;
    virtual int after(int argc, char_t** argv, char_t** env) = 0;

    virtual int run(int argc, char_t** argv, char_t** env) = 0;
    virtual int before_run(int argc, char_t** argv, char_t** env) = 0;
    virtual int after_run(int argc, char_t** argv, char_t** env) = 0;
}; // class _EXPORT_CLASS interfacet

typedef interfacet<> interface;

} // namespace main
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_MAIN_INTERFACE_HPP 
