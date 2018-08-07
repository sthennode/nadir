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
#ifndef _XOS_CONSOLE_OUT_IMPLEMENT_HPP
#define _XOS_CONSOLE_OUT_IMPLEMENT_HPP

#include "xos/console/file/out/implement.hpp"
#include "xos/console/out/interface.hpp"

namespace xos {
namespace console {
namespace out {

///////////////////////////////////////////////////////////////////////
//  Class: implementt
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = file::out::implementt<out::interface> >

class _EXPORT_CLASS implementt: virtual public Timplements {
public:
    typedef Timplements implements;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file };
    
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
    
    virtual ssize_t outf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        if ((format)) {
            va_start(va, format);
            count = this->outfv(format, va);
            va_end(va);
        }
        return count;
    }
    virtual ssize_t outl(const char_t* out, ...) {
        ssize_t count = 0;
        va_list va;
        if ((out)) {
            va_start(va, out);
            count = outlv(out, va);
            va_end(va);
        }
        return count;
    }
    virtual ssize_t outlln(const char_t* out, ...) {
        ssize_t count = 0, amount = 0;
        va_list va;
        if ((out)) {
            va_start(va, out);
            count = this->outlv(out, va);
            va_end(va);
        }
        if (0 <= (count)) {
            if (0 <= (amount = this->outln())) {
                count += amount;
            } else {
                count = amount;
            }
        }
        return count;
    }

    using implements::outfv;
    using implements::outlv;
    using implements::outln;
    using implements::out;
    using implements::out_flush;
    virtual ssize_t outfv(const char_t* format, va_list va) {
        ssize_t count = this->outfv(this->out_std_out(), format, va);
        return count;
    }
    virtual ssize_t outlv(const char_t* out, va_list va) {
        ssize_t count = this->outlv(this->out_std_out(), out, va);
        return count;
    }
    virtual ssize_t outln(const char_t* out, ssize_t length) {
        ssize_t count = this->outln(this->out_std_out(), out, length);
        return count;
    }
    virtual ssize_t outln(const char_t* out) {
        ssize_t count = this->outln(this->out_std_out(), out, -1);
        return count;
    }
    virtual ssize_t outln() {
        ssize_t count = this->outln(this->out_std_out());
        return count;
    }
    virtual ssize_t out(const char_t* out, ssize_t length) {
        ssize_t count = this->out(this->out_std_out(), out, length);
        return count;
    }
    virtual ssize_t out(const char_t* out) {
        ssize_t count = this->out(this->out_std_out(), out, -1);
        return count;
    }
    virtual ssize_t out_flush() {
        ssize_t count = this->out_flush(this->out_std_out());
        return count;
    }

protected:
    virtual file_t out_std_out() {
        return this->std_out();
    }
    virtual file_t std_out() const {
        return ((file_t)null_file);/*::stdout;*/
    }
}; // class _EXPORT_CLASS implementt
typedef implementt<> implement;

} // namespace out
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_OUT_IMPLEMENT_HPP 
