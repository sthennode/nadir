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
//   Date: 8/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_ERR_IMPLEMENT_HPP
#define _XOS_CONSOLE_ERR_IMPLEMENT_HPP

#include "xos/console/err/interface.hpp"

namespace xos {
namespace console {
namespace err {

///////////////////////////////////////////////////////////////////////
//  Class: implementt
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = file::out::implementt<err::interface> >

class _EXPORT_CLASS implementt: virtual public Timplements {
public:
    typedef Timplements implements;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file };
    
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
    
    virtual ssize_t errf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        if ((format)) {
            va_start(va, format);
            count = this->errfv(format, va);
            va_end(va);
        }
        return count;
    }
    virtual ssize_t errl(const char_t* out, ...) {
        ssize_t count = 0;
        va_list va;
        if ((out)) {
            va_start(va, out);
            count = errlv(out, va);
            va_end(va);
        }
        return count;
    }
    virtual ssize_t errlln(const char_t* out, ...) {
        ssize_t count = 0, amount = 0;
        va_list va;
        if ((out)) {
            va_start(va, out);
            count = this->errlv(out, va);
            va_end(va);
        }
        if (0 <= (count)) {
            if (0 <= (amount = this->errln())) {
                count += amount;
            } else {
                count = amount;
            }
        }
        return count;
    }

    virtual ssize_t errfv(const char_t* format, va_list va) {
        ssize_t count = this->outfv(this->out_std_err(), format, va);
        return count;
    }
    virtual ssize_t errlv(const char_t* out, va_list va) {
        ssize_t count = this->outlv(this->out_std_err(), out, va);
        return count;
    }
    virtual ssize_t errln(const char_t* out, ssize_t length) {
        ssize_t count = this->outln(this->out_std_err(), out, length);
        return count;
    }
    virtual ssize_t errln(const char_t* out) {
        ssize_t count = this->outln(this->out_std_err(), out, -1);
        return count;
    }
    virtual ssize_t errln() {
        ssize_t count = this->outln(this->out_std_err());
        return count;
    }
    virtual ssize_t err(const char_t* out, ssize_t length) {
        ssize_t count = this->out(this->out_std_err(), out, length);
        return count;
    }
    virtual ssize_t err(const char_t* out) {
        ssize_t count = this->out(this->out_std_err(), out);
        return count;
    }
    virtual ssize_t err_flush() {
        ssize_t count = this->out_flush(this->out_std_err());
        return count;
    }

protected:
    virtual file_t out_std_err() {
        return this->std_err();
    }
    virtual file_t std_err() const {
        return ((file_t)null_file);/*::stderr;*/
    }
}; // class _EXPORT_CLASS implementt
typedef implementt<> implement;

} // namespace err
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_ERR_IMPLEMENT_HPP 
