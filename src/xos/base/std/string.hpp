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
//   File: string.hpp
//
// Author: $author$
//   Date: 7/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_STD_STRING_HPP
#define _XOS_BASE_STD_STRING_HPP

#include "xos/base/to/char.hpp"
#include <string>
#include <sstream>

namespace xos {
namespace std {
namespace string {

///////////////////////////////////////////////////////////////////////
//  Class: extendt
///////////////////////////////////////////////////////////////////////
template 
<typename Tchar = char,
 class Tchar_to = to::chart<Tchar, char>,
 class Twchar_to = to::chart<Tchar, wchar_t>,
 class Tstring = ::std::basic_string<Tchar>,
 class Tsstream = ::std::basic_stringstream<Tchar>,
 class Timplement = implement, class Textend = Tstring>

class _EXPORT_CLASS extendt: virtual public Timplement, public Textend {
public:
    typedef Timplement implements;
    typedef Textend extends;

    typedef Tchar char_t;
    typedef Tchar_to char_to_t;
    typedef Twchar_to wchar_to_t;
    typedef Tstring string_t;
    typedef Tsstream sstream_t;
    
    extendt(const char* chars, size_t length) {
        append(chars, length);
    }
    extendt(const char* chars) {
        append(chars);
    }
    extendt(const wchar_t* chars, size_t length) {
        append(chars, length);
    }
    extendt(const wchar_t* chars) {
        append(chars);
    }
    extendt(const extendt& copy): extends(copy) {
    }
    extendt() {
    }
    virtual ~extendt() {
    }

    virtual extendt& assign(const extendt& s) {
        this->clear();
        return append(s);
    }
    virtual extendt& assign(const char& c) {
        this->clear();
        return append(c);
    }
    virtual extendt& assign(const char* chars) {
        this->clear();
        return append(chars);
    }
    virtual extendt& assign(const char* chars, size_t length) {
        this->clear();
        return append(chars, length);
    }
    virtual extendt& assignl(const char* chars, ...) {
        va_list va; va_start(va, chars);
        assignv(chars, va);
        va_end(va);
        return *this;
    }
    virtual extendt& assignv(const char* chars, va_list va) {
        this->clear();
        return appendv(chars, va);
    }

    virtual extendt& assign(const wchar_t& c) {
        this->clear();
        return append(c);
    }
    virtual extendt& assign(const wchar_t* chars) {
        this->clear();
        return append(chars);
    }
    virtual extendt& assign(const wchar_t* chars, size_t length) {
        this->clear();
        return append(chars, length);
    }
    virtual extendt& assignl(const wchar_t* chars, ...) {
        va_list va; va_start(va, chars);
        assignv(chars, va);
        va_end(va);
        return *this;
    }
    virtual extendt& assignv(const wchar_t* chars, va_list va) {
        this->clear();
        return appendv(chars, va);
    }

    virtual extendt& append(const extendt& s) {
        return append(s.chars());
    }
    virtual extendt& append(const char& c) {
        return append(&c, 1);
    }
    virtual extendt& append(const char* chars) {
        if ((chars) && (*chars)) {
            char_to_t to;
            for (; *chars; ++chars) {
                extends::append(to.transcode(*chars));
            }
        }
        return *this;
    }
    virtual extendt& append(const char* chars, size_t length) {
        if ((chars) && (length)) {
            char_to_t to;
            for (; length; --length, ++chars) {
                extends::append(to.transcode(*chars));
            }
        }
        return *this;
    }
    virtual extendt& appendl(const char* chars, ...) {
        va_list va; va_start(va, chars);
        appendv(chars, va);
        va_end(va);
        return *this;
    }
    virtual extendt& appendv(const char* chars, va_list va) {
        if ((chars)) {
            do { append(chars);
            } while ((chars = va_arg(va, const char*)));
        }
        return *this;
    }

    virtual extendt& append(const wchar_t& c) {
        return append(&c, 1);
    }
    virtual extendt& append(const wchar_t* chars) {
        if ((chars) && (*chars)) {
            wchar_to_t to;
            for (; *chars; ++chars) {
                extends::append(to.transcode(*chars));
            }
        }
        return *this;
    }
    virtual extendt& append(const wchar_t* chars, size_t length) {
        if ((chars) && (length)) {
            wchar_to_t to;
            for (; length; --length, ++chars) {
                extends::append(to.transcode(*chars));
            }
        }
        return *this;
    }
    virtual extendt& appendl(const wchar_t* chars, ...) {
        va_list va; va_start(va, chars);
        appendv(chars, va);
        va_end(va);
        return *this;
    }
    virtual extendt& appendv(const wchar_t* chars, va_list va) {
        if ((chars)) {
            do { append(chars);
            } while ((chars = va_arg(va, const wchar_t*)));
        }
        return *this;
    }

    virtual extendt& assign_pointer(const const_pointer_t& c) {
        this->clear();
        return append_pointer(c);
    }
    virtual extendt& assign_pointer(const pointer_t& c) {
        this->clear();
        return append_pointer(c);
    }
    virtual extendt& assign_signed(const signed& c) {
        this->clear();
        return append_signed(c);
    }
    virtual extendt& assign_unsigned(const unsigned& c) {
        this->clear();
        return append_unsigned(c);
    }
    virtual extendt& assign_bool(const bool& c) {
        this->clear();
        return append_bool(c);
    }
    virtual extendt& assign_int(const int& c) {
        this->clear();
        return append_int(c);
    }
    virtual extendt& assign_float(const float& c) {
        this->clear();
        return append_float(c);
    }
    virtual extendt& assign_double(const double& c) {
        this->clear();
        return append_double(c);
    }

    virtual extendt& append_pointer(const const_pointer_t& c) {
        sstream_t ss; ss << c;
        extends::append(ss.str());
        return *this;
    }
    virtual extendt& append_pointer(const pointer_t& c) {
        sstream_t ss; ss << c;
        extends::append(ss.str());
        return *this;
    }
    virtual extendt& append_signed(const signed& c) {
        sstream_t ss; ss << c;
        extends::append(ss.str());
        return *this;
    }
    virtual extendt& append_unsigned(const unsigned& c) {
        sstream_t ss; ss << c;
        extends::append(ss.str());
        return *this;
    }
    virtual extendt& append_bool(const bool& c) {
        sstream_t ss; ss << c;
        extends::append(ss.str());
        return *this;
    }
    virtual extendt& append_int(const int& c) {
        sstream_t ss; ss << c;
        extends::append(ss.str());
        return *this;
    }
    virtual extendt& append_float(const float& c) {
        sstream_t ss; ss << c;
        extends::append(ss.str());
        return *this;
    }
    virtual extendt& append_double(const double& c) {
        sstream_t ss; ss << c;
        extends::append(ss.str());
        return *this;
    }

    virtual extendt& operator << (const pointer_t& c) {
        append_pointer(c);
        return *this;
    }
    virtual extendt& operator << (const signed& c) {
        append_signed(c);
        return *this;
    }
    virtual extendt& operator << (const unsigned& c) {
        append_unsigned(c);
        return *this;
    }
    virtual extendt& operator << (const bool& c) {
        append_bool(c);
        return *this;
    }
    virtual extendt& operator << (const float& c) {
        append_float(c);
        return *this;
    }
    virtual extendt& operator << (const double& c) {
        append_double(c);
        return *this;
    }

    virtual signed to_signed() const {
        signed to = 0;
        sstream_t ss(*this);
        ss >> to;
        return to;
    }
    virtual unsigned to_unsigned() const {
        unsigned to = 0;
        sstream_t ss(*this);
        ss >> to;
        return to;
    }
    virtual bool to_bool() const {
        bool to = 0;
        sstream_t ss(*this);
        ss >> to;
        return to;
    }

    virtual const char_t* has_chars(size_t& length) const {
        length = this->length();
        return has_chars();
    }
    virtual const char_t* has_chars() const {
        if ((this->length())) {
            return this->c_str();
        }
        return 0;
    }
    virtual const char_t* chars(size_t& length) const {
        length = this->length();
        return chars();
    }
    virtual const char_t* chars() const {
        return this->c_str();
    }
}; // class _EXPORT_CLASS extendt

} // namespace string

typedef string::extendt<char> char_string;
typedef string::extendt<tchar_t> tchar_string;
typedef string::extendt<wchar_t> wchar_string;

} // namespace std
} // namespace xos

#endif // _XOS_BASE_STD_STRING_HPP 
