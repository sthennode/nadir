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
///   File: io.cpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#include "xos/console/io.hpp"

namespace xos {
namespace console {

/// class iot

/// in...
file_t std_in() {
    return (file_t)stdin;
}
ssize_t inf(const char *format, ...) {
    ssize_t count = 0;
    va_list va;
    va_start(va, format);
    count = infv(std_in(), format, va);
    va_end(va);
    return count;
}
ssize_t infv(const char *format, va_list va) {
    ssize_t count = 0;
    count = infv(std_in(), format, va);
    return count;
}
ssize_t in(char *what, size_t size) {
    ssize_t count = 0;
    count = in(std_in(), what, size);
    return count;
}
ssize_t inf(file_t f, const char *format, ...) {
    ssize_t count = 0;
    va_list va;
    va_start(va, format);
    count = infv(f, format, va);
    va_end(va);
    return count;
}
ssize_t infv(file_t f, const char *format, va_list va) {
    ssize_t count = 0;
    if ((f != ((file_t)null)) && (format)) {
        count = ::vfscanf(f, format, va);
    }
    return count;
}
ssize_t in(file_t f, char *what, size_t size) {
    ssize_t count = 0;
    if ((f != ((file_t)null)) && (what)) {
        count = ::fread(what, sizeof(char), size, f);
    }
    return count;
}

/// out...
file_t std_out() {
    return (file_t)stdout;
}
ssize_t outlln(const char *what, ...) {
    ssize_t count = 0;
    va_list va;
    va_start(va, what);
    count = outllnv(what, va);
    va_end(va);
    return count;
}
ssize_t outl(const char *what, ...) {
    ssize_t count = 0;
    va_list va;
    va_start(va, what);
    count = outlv(what, va);
    va_end(va);
    return count;
}
ssize_t outllnv(const char *what, va_list va) {
    return outllnv(std_out(), what, va);
}
ssize_t outlv(const char *what, va_list va) {
    return outlv(std_out(), what, va);
}
ssize_t outf(const char *format, ...) {
    ssize_t count = 0;
    va_list va;
    va_start(va, format);
    count = outfv(format, va);
    va_end(va);
    return count;
}
ssize_t outfv(const char *format, va_list va) {
    return outfv(std_out(), format, va);
}
ssize_t out(const char *what, size_t length) {
    return out(std_out(), what, length);
}
ssize_t out(const char *what) {
    return out(std_out(), what);
}
ssize_t outllnv(file_t f, const char *what, va_list va) {
    ssize_t count = 0, amount = 0;
    if (0 <= (count = outlv(f, what, va))) {
        if (0 <= (amount = outln(f))) {
            count += amount;
        } else {
            count = amount;
        }
    }
    return count;
}
ssize_t outlv(file_t f, const char *what, va_list va) {
    typedef const char *what_t;
    ssize_t count = 0, amount = 0;
    for (count = 0; what; count += amount) {
        if (0 > (amount = out(f, what))) {
            return amount;
        }
        what = va_arg(va, what_t);
    }
    return count;
}
ssize_t outfv(file_t f, const char *format, va_list va) {
    ssize_t count = 0;
    if ((f != ((file_t)null)) && (format)) {
        count = ::vfprintf(f, format, va);
    }
    return count;
}
ssize_t outln(file_t f, const char *what, size_t length) {
    ssize_t count = 0;
    if (0 <= (count = out(f, what, length))) {
        ssize_t amount = 0;
        if (0 <= (amount = outln(f))) {
            count += amount;
        } else {
            count = amount;
        }
    }
    return count;
}
ssize_t outln(file_t f, const char *what) {
    ssize_t count = 0;
    if (0 <= (count = out(f, what))) {
        ssize_t amount = 0;
        if (0 <= (amount = outln(f))) {
            count += amount;
        } else {
            count = amount;
        }
    }
    return count;
}
ssize_t out(file_t f, const char *what, size_t length) {
    ssize_t count = 0;
    if ((f != ((file_t)null)) && (what)) {
        count = ::fwrite(what, sizeof(char), length, f);
    }
    return count;
}
ssize_t out(file_t f, const char *what) {
    ssize_t count = 0;
    if ((f != ((file_t)null)) && (what)) {
        ssize_t amount = 0;
        for (char c = *(what); c; c = *(++what), count += amount) {
            if (0 >= (amount = out(f, &c, 1))) {
                return amount;
            }
        }
    }
    return count;
}
ssize_t outln(file_t f) {
    ssize_t count = 0;
    if ((f != ((file_t)null))) {
        static const char lf = '\n';
        count = ::fwrite(&lf, sizeof(char), 1, f);
    }
    return count;
}
ssize_t out_flush(file_t f) {
    ssize_t count = 0;
    if ((f != ((file_t)null))) {
        count = ::fflush(f);
    }
    return count;
}

/// err...
file_t std_err() {
    return (file_t)stderr;
}
ssize_t errlln(const char *what, ...) {
    ssize_t count = 0;
    va_list va;
    va_start(va, what);
    count = errllnv(what, va);
    va_end(va);
    return count;
}
ssize_t errl(const char *what, ...) {
    ssize_t count = 0;
    va_list va;
    va_start(va, what);
    count = errlv(what, va);
    va_end(va);
    return count;
}
ssize_t errllnv(const char *what, va_list va) {
    return outllnv(std_err(), what, va);
}
ssize_t errlv(const char *what, va_list va) {
    return outlv(std_err(), what, va);
}
ssize_t errf(const char *format, ...) {
    ssize_t count = 0;
    va_list va;
    va_start(va, format);
    count = errfv(format, va);
    va_end(va);
    return count;
}
ssize_t errfv(const char *format, va_list va) {
    return outfv(std_err(), format, va);
}
ssize_t err(const char *what, size_t length) {
    return out(std_err(), what, length);
}
ssize_t err(const char *what) {
    return out(std_err(), what);
}

} /// namespace console
} /// namespace xos
