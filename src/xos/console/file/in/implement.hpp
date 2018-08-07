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
#ifndef _XOS_CONSOLE_FILE_IN_IMPLEMENT_HPP
#define _XOS_CONSOLE_FILE_IN_IMPLEMENT_HPP

#include "xos/console/file/interface.hpp"

namespace xos {
namespace console {
namespace file {
namespace in {

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
    virtual ssize_t inln(file_t f, char_t* in, size_t size) const {
        const char_t eol = ((char_t)'\n');
        ssize_t count = this->inln(f, in, size, eol);
        return count;
    }
    virtual ssize_t inln(file_t f, char_t* in, size_t size, const char_t& eol) const {
        ssize_t count = 0;
        if ((in) && (size) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            for (size_t length = size; length; --length, ++in) {
                if (0 < (amount = this->in(f, in, 1))) {
                    if (eol != *in) {
                        count += amount;
                        continue;
                    }
                }
                break;
            }
        }
        return count;
    }
    virtual ssize_t inln(file_t f) const {
        const char_t eol = ((char_t)'\n');
        ssize_t count = this->inln(f, eol);
        return count;
    }
    virtual ssize_t inln(file_t f, const char_t& eol) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            char_t in = 0;
            ssize_t amount = 0;
            while (0 < (amount = this->in(f, &in, 1))) {
                if (eol != in) {
                    count += amount;
                    continue;
                }
                break;
            }
        }
        return count;
    }
    virtual ssize_t in(file_t f, char_t* in, size_t size) const {
        ssize_t count = 0;
        if ((in) && (size) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount = this->in(f, in, sizeof(char_t), size))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t infv(file_t f, const char_t* format, va_list va) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file)) && (format)) {
            ssize_t amount = 0;
            if (0 < (amount /*= ::vfscanf(f, format, va)*/)) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t in(file_t f, char_t* in, size_t size, size_t space) const {
        ssize_t count = 0;
        if ((in) && (size) && (space) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount /*= ::fread(in, size, space, f)*/)) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t in_fill(file_t f) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            int err = 0;
            if ((err /*= ::ffill(f)*/)) {
                count = -1;
            }
        }
        return count;
    }
}; // class _EXPORT_CLASS implementt
typedef implementt<> implement;

} // namespace in
} // namespace file
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_FILE_IN_IMPLEMENT_HPP 
