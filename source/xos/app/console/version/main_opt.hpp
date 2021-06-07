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
///   Date: 4/25/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_VERSION_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_VERSION_MAIN_OPT_HPP

#include "xos/app/console/main.hpp"

#define XOS_VERSION_MAIN_VERSION_OPT "version"
#define XOS_VERSION_MAIN_VERSION_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_VERSION_MAIN_VERSION_OPTARG_RESULT 0
#define XOS_VERSION_MAIN_VERSION_OPTARG ""
#define XOS_VERSION_MAIN_VERSION_OPTUSE "Library version"
#define XOS_VERSION_MAIN_VERSION_OPTVAL_S "v"
#define XOS_VERSION_MAIN_VERSION_OPTVAL_C 'v'
#define XOS_VERSION_MAIN_VERSION_OPTION \
   {XOS_VERSION_MAIN_VERSION_OPT, \
    XOS_VERSION_MAIN_VERSION_OPTARG_REQUIRED, \
    XOS_VERSION_MAIN_VERSION_OPTARG_RESULT, \
    XOS_VERSION_MAIN_VERSION_OPTVAL_C}, \

#define XOS_VERSION_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_VERSION_MAIN_VERSION_OPTVAL_S \

#define XOS_VERSION_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_VERSION_MAIN_VERSION_OPTION \

#define XOS_VERSION_MAIN_OPTIONS_CHARS \
    XOS_VERSION_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_VERSION_MAIN_OPTIONS_OPTIONS \
    XOS_VERSION_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_CONSOLE_MAIN_OPTIONS_OPTIONS

#define XOS_VERSION_MAIN_USAGE_OPTIONS_CHARS \
    XOS_VERSION_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_CONSOLE_MAIN_USAGE_OPTIONS_CHARS

#define XOS_VERSION_MAIN_USAGE_OPTIONS_OPTIONS \
    XOS_VERSION_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_CONSOLE_MAIN_USAGE_OPTIONS_OPTIONS

#define XOS_VERSION_MAIN_ARUMENTS_CHARS 0
#define XOS_VERSION_MAIN_ARUMENTS_ARGS 0


#define XOS_APP_CONSOLE_VERSION_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_VERSION_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_VERSION_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_VERSION_MAIN_OPTIONS_OPTIONS_EXTEND \

#define XOS_APP_CONSOLE_VERSION_MAIN_OPTIONS_CHARS \
   XOS_VERSION_MAIN_USAGE_OPTIONS_CHARS \
    
#define XOS_APP_CONSOLE_VERSION_MAIN_OPTIONS_OPTIONS \
   XOS_VERSION_MAIN_USAGE_OPTIONS_OPTIONS \
   
#define XOS_APP_CONSOLE_VERSION_MAIN_ARGS 0
#define XOS_APP_CONSOLE_VERSION_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace version {

/// class main_optt
template <class TExtends = console::main, class TImplements = typename TExtends::implements>
class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
    }
public:

protected:
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = default_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_version_run(argc, argv, env);
        return err;
    }

    /// ...version_run
    virtual int version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_version_run(argc, argv, env))) {
            int err2 = 0;
            err = version_run(argc, argv, env);
            if ((err2 = after_version_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_version_run;
        return err;
    }
    virtual int before_set_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_version_run(argc, argv, env))) {
            int err2 = 0;
            err = set_version_run(argc, argv, env);
            if ((err2 = after_set_version_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...option...
    virtual int on_version_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = all_set_version_run(argc, argv, env);
        return err;
    }
    virtual const char_t* version_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        chars = XOS_VERSION_MAIN_VERSION_OPTUSE;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_VERSION_MAIN_VERSION_OPTVAL_C:
            err = this->on_version_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_VERSION_MAIN_VERSION_OPTVAL_C:
            chars = version_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_VERSION_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_VERSION_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& args) {
        args = XOS_VERSION_MAIN_ARUMENTS_ARGS;
        return XOS_VERSION_MAIN_ARUMENTS_CHARS;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace version
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_VERSION_MAIN_OPT_HPP 
