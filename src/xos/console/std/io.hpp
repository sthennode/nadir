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
//   File: io.hpp
//
// Author: $author$
//   Date: 8/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_STD_IO_HPP
#define _XOS_CONSOLE_STD_IO_HPP

#include "xos/console/io.hpp"

namespace xos {
namespace console {
namespace std {

///////////////////////////////////////////////////////////////////////
//  Class: iot
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = console::io, class Textends = extend>

class _EXPORT_CLASS iot: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file };
    
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    iot(locked& _locked): locked_(_locked) {
    }
    iot(): locked_((locked&)*this) {
    }
    virtual ~iot() {
    }
    
protected:
    virtual ssize_t in(file_t f, char_t* in, size_t size, size_t space) const {
        ssize_t count = 0;
        if ((in) && (size) && (space) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount = ::fread(in, size, space, f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual file_t std_in() const {
        return ::stdin;
    }
    
protected:
    using implements::out_implements::out;
    using implements::out_implements::out_flush;
    virtual ssize_t out(file_t f, const char_t* out, size_t size, size_t length) const {
        ssize_t count = 0;
        if ((out) && (size) && (length) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount = ::fwrite(out, size, length, f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t out_flush(file_t f) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            int err = 0;
            if ((err = ::fflush(f))) {
                count = -1;
            }
        }
        return count;
    }
    virtual file_t std_out() const {
        return ::stdout;
    }
    
protected:
    using implements::err;
    using implements::err_flush;
    virtual ssize_t err(file_t f, const char_t* out, size_t size, size_t length) const {
        ssize_t count = 0;
        if ((out) && (size) && (length) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount = ::fwrite(out, size, length, f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t err_flush(file_t f) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            int err = 0;
            if ((err = ::fflush(f))) {
                count = -1;
            }
        }
        return count;
    }
    virtual file_t std_err() const {
        return ::stderr;
    }
    
protected:
    locked& locked_;
}; // class _EXPORT_CLASS iot

typedef iot<> io_extends;
///////////////////////////////////////////////////////////////////////
//  Class: io
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS io: public io_extends {
public:
    typedef io_extends extends;

    io(locked& _locked): extends(_locked) {}
    io() {}
    
protected:
    using in_implements::infv;
    virtual ssize_t infv(file_t f, const char_t* format, va_list va) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file)) && (format)) {
            ssize_t amount = 0;
            if (0 < (amount = ::vfscanf(f, format, va))) {
                count += amount;
            }
        }
        return count;
    }
    
protected:
    using out_implements::outfv;
    virtual ssize_t outfv(file_t f, const char_t* format, va_list va) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file)) && (format)) {
            ssize_t amount = 0;
            if (0 < (amount = ::vfprintf(f, format, va))) {
                count += amount;
            }
        }
        return count;
    }
};

} // namespace std
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_STD_IO_HPP 
