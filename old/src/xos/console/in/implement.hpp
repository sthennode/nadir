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
#ifndef _XOS_CONSOLE_IN_IMPLEMENT_HPP
#define _XOS_CONSOLE_IN_IMPLEMENT_HPP

#include "xos/console/file/in/implement.hpp"
#include "xos/console/in/interface.hpp"

namespace xos {
namespace console {
namespace in {

///////////////////////////////////////////////////////////////////////
//  Class: implementt
///////////////////////////////////////////////////////////////////////
template <class Timplements = file::in::implementt<in::interface> >
class _EXPORT_CLASS implementt: virtual public Timplements {
public:
    typedef Timplements implements;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file };
    
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
    
    virtual ssize_t inf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        if ((format)) {
            va_start(va, format);
            count = this->infv(format, va);
            va_end(va);
        }
        return count;
    }

    using implements::infv;
    using implements::inln;
    using implements::in;
    using implements::in_fill;
    virtual ssize_t infv(const char_t* format, va_list va) {
        ssize_t count = infv(this->in_std_in(), format, va);
        return count;
    }
    virtual ssize_t inln(char_t* in, size_t size, const char_t& eol) {
        ssize_t count = this->inln(this->in_std_in(), in, size, eol);
        return count;
    }
    virtual ssize_t inln(char_t* in, size_t size) {
        ssize_t count = this->inln(this->in_std_in(), in, size);
        return count;
    }
    virtual ssize_t inln(const char_t& eol) {
        ssize_t count = this->inln(this->in_std_in(), eol);
        return count;
    }
    virtual ssize_t inln() {
        ssize_t count = this->inln(this->in_std_in());
        return count;
    }
    virtual ssize_t in(char_t* in, size_t size) {
        ssize_t count = this->in(this->in_std_in(), in, size);
        return count;
    }
    virtual ssize_t in_fill() {
        ssize_t count = this->in_fill(this->in_std_in());
        return count;
    }

protected:
    virtual file_t in_std_in() {
        return this->std_in();
    }
    virtual file_t std_in() const {
        return ((file_t)null_file);/*::stdin;*/
    }
}; // class _EXPORT_CLASS implementt
typedef implementt<> implement;

} // namespace in
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_IN_IMPLEMENT_HPP 
