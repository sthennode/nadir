///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 4/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MAIN_HPP
#define _XOS_CONSOLE_MAIN_HPP

#include "xos/console/std/output.hpp"
#include "xos/console/std/error.hpp"

namespace xos {
namespace console {

typedef std::output main_implementt_out_implements;
typedef std::error main_implementt_err_implements;
typedef implement_base main_implementt_in_implements;
///////////////////////////////////////////////////////////////////////
///  Class: main_implementt
///////////////////////////////////////////////////////////////////////
template 
<class TOutImplements = main_implementt_out_implements,
 class TErrImplements = main_implementt_err_implements,
 class TInImplements = main_implementt_in_implements>
class _EXPORT_CLASS main_implementt
: virtual public TOutImplements, 
  virtual public TErrImplements, 
  virtual public TInImplements {
public:
    typedef TOutImplements implements;
    typedef typename implements::string_t string_t;
    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file};
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
};
typedef main_implementt<> main_implement;

typedef main_implement maint_implements;
typedef base maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = maint_implements, class TExtends = maint_extends>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename implements::string_t string_t;
    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file};
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    maint() {
        maint*& the_main = derives::the_main();
        if (!(the_main)) {
            the_main = this;
        }
    }
    virtual ~maint() {
        maint*& the_main = derives::the_main();
        if ((the_main) && (this == the_main)) {
            the_main = 0;
        }
    }
private:
    maint(const maint &copy) {
    }

public:
    static int the_main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        maint* the_main = 0;
        if ((the_main = derives::the_main())) {
            if (!(err = the_main->before(argc, argv, env))) {
                int err2 = 0;
                err = (*the_main)(argc, argv, env);
                if ((err2 = the_main->after(argc, argv, env))) {
                    if (!err) err = err2;
                }
            }
        }
        return err;
    }
    
protected:
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

    virtual int operator()(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->before_run(argc, argv, env))) {
            int err2 = 0;
            err = this->run(argc, argv, env);
            if ((err2 = this->after_run(argc, argv, env))) {
                if (!err) err = err2;
            }
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

    static maint*& the_main() {
        static maint* the_main = 0;
        return the_main;
    }
};
typedef maint<> main;

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_MAIN_HPP 
