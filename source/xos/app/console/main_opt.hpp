///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 3/6/2020, 5/11/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_MAIN_OPT_HPP

#include "xos/console/getopt/main.hpp"

#define XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS_EXTEND \

#define XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_CONSOLE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {

/// class main_optt
template 
<class TExtends = xos::console::getopt::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...default_run
    virtual int default_run(int argc, char_t** argv, char** env) {
        int err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_default_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_default_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_default_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_default_run(argc, argv, env))) {
            int err2 = 0;
            err = default_run(argc, argv, env);
            if ((err2 = after_default_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_MAIN_OPT_HPP 
