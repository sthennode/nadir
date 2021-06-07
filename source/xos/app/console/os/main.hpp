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
///   File: main.hpp
///
/// Author: $author$
///   Date: 12/26/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_OS_MAIN_HPP
#define XOS_APP_CONSOLE_OS_MAIN_HPP

#include "xos/app/console/os/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace os {

/// class maint
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): run_(0) {
    }

protected:
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        if ((run_)) {
            return (this->*run_)(argc, argv, env);
        }
        return default_run(argc, argv, env);
    }
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        return this->derived_run(argc, argv, env);
    }

    /// ...run
    virtual int derived_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int os_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int posix_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int linux_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int solaris_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int osx_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int ios_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int mach_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int windows_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }

    /// to...run
    virtual int to_derived_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int to_os_run(int argc, char_t** argv, char_t** env) {
        int err = this->os_run(argc, argv, env);
        return err;
    }
    virtual int to_posix_run(int argc, char_t** argv, char_t** env) {
        int err = this->to_derived_run(argc, argv, env);
        return err;
    }
    virtual int to_linux_run(int argc, char_t** argv, char_t** env) {
        int err = this->to_derived_run(argc, argv, env);
        return err;
    }
    virtual int to_solaris_run(int argc, char_t** argv, char_t** env) {
        int err = this->to_derived_run(argc, argv, env);
        return err;
    }
    virtual int to_osx_run(int argc, char_t** argv, char_t** env) {
        int err = this->to_derived_run(argc, argv, env);
        return err;
    }
    virtual int to_ios_run(int argc, char_t** argv, char_t** env) {
        int err = this->to_derived_run(argc, argv, env);
        return err;
    }
    virtual int to_mach_run(int argc, char_t** argv, char_t** env) {
        int err = this->to_derived_run(argc, argv, env);
        return err;
    }
    virtual int to_windows_run(int argc, char_t** argv, char_t** env) {
        int err = this->to_derived_run(argc, argv, env);
        return err;
    }

    /// on_..._option
    virtual int on_windows_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::windows_run;
        return err;
    }
    virtual int on_osx_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::osx_run;
        return err;
    }
    virtual int on_linux_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::linux_run;
        return err;
    }
    virtual int on_posix_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::posix_run;
        return err;
    }
    virtual int on_mach_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::mach_run;
        return err;
    }
    virtual int on_solaris_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::solaris_run;
        return err;
    }
    virtual int on_osos_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::os_run;
        return err;
    }
    virtual int on_osnone_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::derived_run;
        return err;
    }

    /// on_to_..._option
    virtual int on_to_windows_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::to_windows_run;
        return err;
    }
    virtual int on_to_osx_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::to_osx_run;
        return err;
    }
    virtual int on_to_linux_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::to_linux_run;
        return err;
    }
    virtual int on_to_posix_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::to_posix_run;
        return err;
    }
    virtual int on_to_mach_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::to_mach_run;
        return err;
    }
    virtual int on_to_solaris_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::to_solaris_run;
        return err;
    }
    virtual int on_to_osos_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::to_os_run;
        return err;
    }
    virtual int on_to_osnone_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::to_derived_run;
        return err;
    }

}; /// class maint
typedef maint<> main;

} /// namespace os
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_OS_MAIN_HPP
