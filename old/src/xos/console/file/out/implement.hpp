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
#ifndef _XOS_CONSOLE_FILE_OUT_IMPLEMENT_HPP
#define _XOS_CONSOLE_FILE_OUT_IMPLEMENT_HPP

#include "xos/console/file/interface.hpp"

namespace xos {
namespace console {
namespace file {
namespace out {

///////////////////////////////////////////////////////////////////////
//  Class: implementt
///////////////////////////////////////////////////////////////////////
template <class Timplements = interface>
class _EXPORT_CLASS implementt: virtual public Timplements {
public:
    typedef Timplements implements;
    
    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file };

    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
    
protected:
    virtual ssize_t outlv(file_t f, const char_t* out, va_list va) const {
        ssize_t count = 0;
        ssize_t amount = 0;
        for (count = 0; out; count += amount) {
            if (0 > (amount = this->out(f, out))) {
                return amount;
            }
            out = va_arg(va, const char_t*);
        }
        return count;
    }
    virtual ssize_t outln(file_t f, const char_t* out, ssize_t length) const {
        ssize_t count = 0;
        ssize_t amount;
        if (0 <= (amount = this->out(f, out, length))) {
            count += amount;
            if (0 <= (amount = this->outln(f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t outln(file_t f, const char_t* out) const {
        ssize_t count = this->outln(f, out, -1);
        return count;
    }
    virtual ssize_t outln(file_t f) const {
        const char_t ln = ((char_t)'\n');
        ssize_t count = this->out(f, &ln, 1);
        return count;
    }
    virtual ssize_t out(file_t f, const char_t* out, ssize_t length) const {
        ssize_t count = 0;
        if ((out) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 <= (length)) {
                if (0 < (amount = this->out(f, out, sizeof(char_t), length))) {
                    count += amount;
                }
            } else {
                for (; *out; ++out) {
                    if (0 < (amount = this->out(f, out, sizeof(char_t), 1))) {
                        count += amount;
                        continue;
                    }
                    break;
                }
            }
        }
        return count;
    }
    virtual ssize_t out(file_t f, const char_t* out) const {
        ssize_t count = this->out(f, out, -1);
        return count;
    }
    virtual ssize_t out(file_t f, const char_t* out, size_t size, size_t length) const {
        ssize_t count = 0;
        if ((out) && (size) && (length) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount /*= ::fwrite(out, sizeof(char_t), length, f)*/)) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t outfv(file_t f, const char_t* format, va_list va) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file)) && (format)) {
            ssize_t amount = 0;
            if (0 < (amount /*= ::vfprintf(f, format, va)*/)) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t out_flush(file_t f) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            int err = 0;
            if ((err /*= ::fflush(f)*/)) {
                count = -1;
            }
        }
        return count;
    }
}; // class _EXPORT_CLASS implementt
typedef implementt<> implement;

} // namespace out
} // namespace file
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_FILE_OUT_IMPLEMENT_HPP 
