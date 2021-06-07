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
///   File: io.hpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CONSOLE_IO_HPP
#define XOS_CONSOLE_IO_HPP

#include "xos/base/to_string.hpp"
#include "xos/base/locked.hpp"
#include <stdarg.h>
#include <stdio.h>

namespace xos {
namespace console {

/// in...
file_t std_in();
ssize_t inf(const char *format, ...);
ssize_t infv(const char *format, va_list va);
ssize_t in(char *what, size_t size);
ssize_t inf(file_t f, const char *format, ...);
ssize_t infv(file_t f, const char *format, va_list va);
ssize_t in(file_t f, char *what, size_t size);

/// out...
file_t std_out();
ssize_t outlln(const char *what, ...);
ssize_t outllnv(const char *what, va_list va);
ssize_t outl(const char *what, ...);
ssize_t outlv(const char *what, va_list va);
ssize_t outf(const char *format, ...);
ssize_t outfv(const char *format, va_list va);
ssize_t out(const char *what, size_t length);
ssize_t out(const char *what);
ssize_t outlln(file_t f, const char *what, ...);
ssize_t outllnv(file_t f, const char *what, va_list va);
ssize_t outl(file_t f, const char *what, ...);
ssize_t outlv(file_t f, const char *what, va_list va);
ssize_t outf(file_t f, const char *format, ...);
ssize_t outfv(file_t f, const char *format, va_list va);
ssize_t outln(file_t f, const char *what, size_t length);
ssize_t outln(file_t f, const char *what);
ssize_t out(file_t f, const char *what, size_t length);
ssize_t out(file_t f, const char *what);
ssize_t outln(file_t f);
ssize_t out_flush(file_t f);

/// err...
file_t std_err();
ssize_t errlln(const char *what, ...);
ssize_t errl(const char *what, ...);
ssize_t errllnv(const char *what, va_list va);
ssize_t errlv(const char *what, va_list va);
ssize_t errf(const char *format, ...);
ssize_t errfv(const char *format, va_list va);
ssize_t err(const char *what, size_t length);
ssize_t err(const char *what);

/// class iot
template 
<typename TChar = char, typename TFile = FILE*, 
 class TLocked = locked, class TImplements = TLocked>

class exported iot: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef iot derives;

    typedef TFile file_t;
    typedef int null_file_t;
    enum { null_file = 0 };

    typedef stringt<TChar> string_t;
    typedef TChar char_t;
    typedef char_t end_char_t;
    enum { end_char = 0 };

    typedef char_t what_t;
    typedef char_t sized_t;
    
public:
    /// in...
    virtual ssize_t inf(const sized_t *format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = this->infv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t infv(const sized_t *format, va_list va) {
        return 0;
    }
    virtual ssize_t in(what_t *what, size_t size) {
        file_t f = in_std_in();
        return in(f, what, size);
    }
    virtual ssize_t in(file_t in, what_t *what, size_t size) {
        return console::in(in, what, size);
    }
protected:
    virtual file_t in_std_in() {
        return std_in();
    }
    virtual file_t std_in() const {
        return (file_t)stdin;
    }

public:
    /// out...
    virtual ssize_t outln(const string_t& chars) {
        ssize_t count = outln(chars.chars(), chars.length());
        return count;
    }
    virtual ssize_t out(const string_t& chars) {
        ssize_t count = out(chars.chars(), chars.length());
        return count;
    }
    virtual ssize_t outlln(const what_t *what, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, what);
        count = this->outllnv(what, va);
        va_end(va);
        return count;
    }
    virtual ssize_t outl(const what_t *what, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, what);
        count = this->outlv(what, va);
        va_end(va);
        return count;
    }
    virtual ssize_t outllnv(const what_t *what, va_list va) {
        file_t f = out_std_out();
        return console::outllnv(f, what, va);
    }
    virtual ssize_t outlv(const what_t *what, va_list va) {
        file_t f = out_std_out();
        return console::outlv(f, what, va);
    }
    virtual ssize_t outf(const sized_t *format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = this->outfv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t outfv(const sized_t *format, va_list va) {
        return 0;
    }
    virtual ssize_t outXln(const void* out, size_t length, bool upper_case = true) {
        file_t f = out_std_out();
        return outxln(f, out, length, upper_case);
    }
    virtual ssize_t outX(const void* out, size_t length, bool upper_case = true) {
        file_t f = out_std_out();
        return outx(f, out, length, upper_case);
    }
    virtual ssize_t outxln(const void* out, size_t length, bool upper_case = false) {
        file_t f = out_std_out();
        return outxln(f, out, length, upper_case);
    }
    virtual ssize_t outx(const void* out, size_t length, bool upper_case = false) {
        file_t f = out_std_out();
        return outx(f, out, length, upper_case);
    }
    virtual ssize_t out64ln(const void* out, size_t length) {
        file_t f = out_std_out();
        return out64ln(f, out, length);
    }
    virtual ssize_t out64(const void* out, size_t length) {
        file_t f = out_std_out();
        return out64(f, out, length);
    }
    virtual ssize_t outln(const what_t *what, size_t length) {
        file_t f = out_std_out();
        return console::outln(f, what, length);
    }
    virtual ssize_t outln(const what_t *what) {
        file_t f = out_std_out();
        return console::outln(f, what);
    }
    virtual ssize_t out(const what_t *what, size_t length) {
        file_t f = out_std_out();
        return console::out(f, what, length);
    }
    virtual ssize_t out(const what_t *what) {
        file_t f = out_std_out();
        return console::out(f, what);
    }
    virtual ssize_t outln() {
        file_t f = out_std_out();
        return console::outln(f);
    }
    virtual ssize_t out_flush() {
        file_t f = out_std_out();
        return console::out_flush(f);
    }
protected:
    virtual file_t out_std_out() {
        return std_out();
    }
    virtual file_t std_out() const {
        return (file_t)stdout;
    }

public:
    /// err...
    virtual ssize_t errln(const string_t& chars) {
        ssize_t count = errln(chars.chars(), chars.length());
        return count;
    }
    virtual ssize_t err(const string_t& chars) {
        ssize_t count = err(chars.chars(), chars.length());
        return count;
    }
    virtual ssize_t errlln(const what_t *what, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, what);
        count = this->errllnv(what, va);
        va_end(va);
        return count;
    }
    virtual ssize_t errl(const what_t *what, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, what);
        count = this->errlv(what, va);
        va_end(va);
        return count;
    }
    virtual ssize_t errllnv(const what_t *what, va_list va) {
        file_t f = err_std_err();
        return console::outllnv(f, what, va);
    }
    virtual ssize_t errlv(const what_t *what, va_list va) {
        file_t f = err_std_err();
        return console::outlv(f, what, va);
    }
    virtual ssize_t errf(const sized_t *format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = this->errfv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t errfv(const sized_t *format, va_list va) {
        file_t f = err_std_err();
        return console::outfv(f, format, va);
    }
    virtual ssize_t errXln(const void* out, size_t length, bool upper_case = true) {
        file_t f = err_std_err();
        return outxln(f, out, length, upper_case);
    }
    virtual ssize_t errX(const void* out, size_t length, bool upper_case = true) {
        file_t f = err_std_err();
        return outx(f, out, length, upper_case);
    }
    virtual ssize_t errxln(const void* out, size_t length, bool upper_case = false) {
        file_t f = err_std_err();
        return outxln(f, out, length, upper_case);
    }
    virtual ssize_t errx(const void* out, size_t length, bool upper_case = false) {
        file_t f = err_std_err();
        return outx(f, out, length, upper_case);
    }
    virtual ssize_t err64ln(const void* out, size_t length) {
        file_t f = err_std_err();
        return out64ln(f, out, length);
    }
    virtual ssize_t err64(const void* out, size_t length) {
        file_t f = err_std_err();
        return out64(f, out, length);
    }
    virtual ssize_t errln(const what_t *what, size_t length) {
        file_t f = err_std_err();
        return console::outln(f, what, length);
    }
    virtual ssize_t errln(const what_t *what) {
        file_t f = err_std_err();
        return console::outln(f, what);
    }
    virtual ssize_t err(const what_t *what, size_t length) {
        file_t f = err_std_err();
        return console::out(f, what, length);
    }
    virtual ssize_t err(const what_t *what) {
        file_t f = err_std_err();
        return console::out(f, what);
    }
    virtual ssize_t errln() {
        file_t f = err_std_err();
        return console::outln(f);
    }
    virtual ssize_t err_flush() {
        file_t f = err_std_err();
        return console::out_flush(f);
    }
protected:
    virtual file_t err_std_err() {
        return std_err();
    }
    virtual file_t std_err() const {
        return (file_t)stderr;
    }

protected:
    /// outx...
    virtual ssize_t outxln(file_t f, const void* out, size_t length, bool upper_case = false) const {
        ssize_t count = 0, amount = 0;
        if (0 <= (amount = this->outx(f, out, length, upper_case))) {
            count += amount;
            if (0 <= (amount = console::outln(f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t outx(file_t f, const void* out, size_t length, bool upper_case = false) const {
        ssize_t count = 0; const uint8_t* bytes = 0;

        if ((bytes = (const uint8_t*)(out)) && (length)) {
            ssize_t amount = 0; uint8_t b = 0; char_t x[2];

            for (; 0 < length; --length) {
                b = (*bytes++);
                x[0] = dtox(b >> 4, upper_case);
                x[1] = dtox(b & 15, upper_case);

                if (0 < (amount = console::out(f, x, 2))) {
                    count += amount;
                } else {
                    return amount;
                }
            }
        }
        return count;
    }
    /// dtox / xtod
    virtual char_t dtox(uint8_t d, bool upper_case = false) const {
        char a = (upper_case)?('A'):('a'); char_t x = (char_t)(0);
        if ((0 <= d) && (9 >= d)) {
            x = (char_t)(('0') +  d);
        } else {
            if ((10 <= d) && (15 >= d)) {
                x = (char_t)((a) + (d - 10));
            } else {
                x = invalid_dtox(d);
            }
        }
        return x;
    }
    virtual int8_t xtod(const char_t& x) const {
        int8_t d = -1;
        if (((char_t)('A') <= x) && ((char_t)('F') >= x)) {
            d = ((x - (char_t)('A')) + 10);
        } else {
            if (((char_t)('a') <= x) && ((char_t)('f') >= x)) {
                d = ((x - (char_t)('a')) + 10);
            } else  {
                if (((char_t)('0') <= x) && ((char_t)('9') >= x)) {
                    d = ((x - (char_t)('0')));
                } else {
                    d = invalid_xtod(x);
                }
            }
        }
        return d;
    }
    virtual char_t invalid_dtox(uint8_t d) const {
        return (char_t)(0);
    }
    virtual int8_t invalid_xtod(const char_t& x) const {
        return (int8_t)(-1);
    }

    /// out64...
    virtual ssize_t out64ln(file_t f, const void* out, size_t length) {
        ssize_t count = 0, amount = 0;

        if (0 <= (amount = this->out64(f, out, length))) {
            count += amount;
            if (0 <= (amount = console::outln(f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t out64(file_t f, const void* out, size_t length) {
        ssize_t count = 0;
        const uint8_t* byte = 0;

        if ((byte = (const uint8_t*)(out)) && (length)) {
            ssize_t amount = 0;
            uint8_t b = 0, carry = 0, shift = 0;
            if (0 <= length) {
                for (carry = 0, shift = 2; 0 < length; --length, ++byte) {
                    b = (*byte);
                    if (0 > (amount = this->put64(f, b, carry, shift))) {
                        return amount;
                    }
                    count += amount;
                }
            } else {
                for (carry = 0, shift = 2; (b = (*byte)); ++byte) {
                    if (0 > (amount = this->put64(f, b, carry, shift))) {
                        return amount;
                    }
                    count += amount;
                }
            }
            if ((2 != (shift))) {
                if (0 > (amount = this->put64_end(f, carry, shift))) {
                    return amount;
                }
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t put64(file_t f, uint8_t b, uint8_t& carry, uint8_t& shift) {
        const uint8_t mask = ((uint8_t)-1);
        ssize_t count = 0, amount = 0;
        sized_t x = (sized_t)(0);
        x = (sized_t)(this->dtob64(carry | (b >> shift)));
        if (0 > (amount = console::out(f, (const what_t*)(&x), 1))) {
            return amount;
        }
        count += amount;
        carry = (b & (mask >> (8 - shift))) << (6 - shift);
        if (6 > (shift)) {
            shift += 2;
        } else {
            x = (sized_t)(this->dtob64(carry));
            if (0 > (amount = console::out(f, (const what_t*)(&x), 1))) {
                return amount;
            }
            count += amount;
            carry = 0;
            shift = 2;
        }
        return count;
    }
    virtual ssize_t put64_end(file_t f, uint8_t& carry, uint8_t& shift) {
        ssize_t count = 0, amount = 0;
        sized_t x = (sized_t)(0);
        x = (sized_t)(this->dtob64(carry));
        if (0 > (amount = console::out(f, (const what_t*)(&x), 1))) {
            return amount;
        }
        count += amount;
        for (x = ((sized_t)'='); shift != 2;) {
            if (0 > (amount = console::out(f, (const what_t*)(&x), 1))) {
                return amount;
            }
            count += amount;
            if (6 > (shift)) {
                shift += 2;
            } else {
                shift = 2;
            }
        }
        return count;
    }
    /// ...dtob64 / ...b64tod
    virtual char_t dtob64(uint8_t d) const {
        char_t x = (char_t)(0);
        if ((0 <= d) && (25 >= d)) {
            x = (char_t)(('A') + d);
        } else {
            if ((26 <= d) && (51 >= d)) {
                x = (char_t)(('a') + (d - 26));
            } else {
                if ((52 <= d) && (61 >= d)) {
                    x = (char_t)(('0') + (d - 52));
                } else {
                    if ((62 == d)) {
                        x = (char_t)(('+'));
                    } else {
                        if ((63 == d)) {
                            x = (char_t)(('/'));
                        } else {
                            x = invalid_dtob64(d);
                        }
                    }
                }
            }
        }
        return x;
    }
    virtual int8_t b64tod(const char_t& x) const {
        int8_t d = (int8_t)(0);
        if (((char_t)('A') <= x) && ((char_t)('Z') >= x)) {
            d = (x - (char_t)('A'));
        } else {
            if (((char_t)('a') <= x) && ((char_t)('z') >= x)) {
                d = ((x - (char_t)('a')) + 26);
            } else {
                if (((char_t)('0') <= x) && ((char_t)('9') >= x)) {
                    d = ((x - (char_t)('0')) + 52);
                } else {
                    if (((char_t)('+') == x)) {
                        d = (62);
                    } else {
                        if (((char_t)('/') == x)) {
                            d = (63);
                        } else {
                            d = invalid_b64tod(x);
                        }
                    }
                }
            }
        }
        return d;
    }
    virtual char_t invalid_dtob64(uint8_t d) const {
        return (char_t)(0);
    }
    virtual int8_t invalid_b64tod(const char_t& x) const {
        return (int8_t)(-1);
    }
}; /// class iot
typedef iot<> io;

} /// namespace console
} /// namespace xos

#endif /// ndef XOS_CONSOLE_IO_HPP
