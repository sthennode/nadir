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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CONSOLE_LOGGER_HPP
#define XOS_CONSOLE_LOGGER_HPP

#include "xos/logger/implement.hpp"
#include "xos/console/io.hpp"

namespace xos {
namespace console {

/// class loggert
template 
<class TExtends = logger::instance, 
 class TImplements = typename TExtends::implement>

class exported loggert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef loggert derives;

    typedef typename extends::lock_status lock_status;
    enum { lock_success = extends::lock_success, 
           lock_failed = extends::lock_failed };
    
    typedef typename extends::message_t message_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    loggert(int argc, char_t** argv, char_t** env): io_(this_io_), locked_(io_) {
    }
    loggert(console::io& io): io_(io), locked_(io_) {
    }
    loggert(xos::locked &locked, xos::logger::levels enabled_for): extends(enabled_for), io_(this_io_), locked_(locked) {
    }
    loggert(xos::locked &locked): io_(this_io_), locked_(locked) {
    }
    loggert(xos::logger::levels enabled_for): extends(enabled_for), io_(this_io_), locked_(io_) {
    }
    loggert(): io_(this_io_), locked_(io_) {
    }
    virtual ~loggert() {
    }
private:
    loggert(const loggert& copy): io_(this_io_), locked_(io_) {
        throw exception(exception_unexpected);
    }

protected:
    /// log...
    virtual ssize_t logfv(const char_t* format, va_list va) {
        ssize_t count = 0;
        count = io_.errfv(format, va);
        return count;
    }
    virtual ssize_t log(const char_t* chars) {
        ssize_t count = 0;
        count = io_.err(chars);
        return count;
    }
    virtual ssize_t log_flush() {
        ssize_t count = 0;
        count = io_.err_flush();
        return count;
    }

    /// ...lock / ...unlock
    virtual bool lock() { 
        return locked_.lock(); 
    }
    virtual lock_status try_lock() { 
        return locked_.try_lock(); 
    }
    virtual lock_status untimed_lock() { 
        return locked_.untimed_lock(); 
    }
    virtual lock_status timed_lock(mseconds_t milliseconds) { 
        return locked_.timed_lock(milliseconds); 
    }
    virtual bool unlock() { 
        return locked_.unlock(); 
    }

protected:
    console::io this_io_, &io_;
    xos::locked &locked_;
}; /// class loggert
typedef loggert<> logger;

} /// namespace console
} /// namespace xos

#endif /// ndef XOS_CONSOLE_LOGGER_HPP
