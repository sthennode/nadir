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
//   File: locked.hpp
//
// Author: $author$
//   Date: 8/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LOCKED_HPP
#define _XOS_BASE_LOCKED_HPP

#include "xos/base/exception.hpp"

namespace xos {

typedef int lock_status;
enum {
    unlock_success,
    lock_success = unlock_success,

    lock_failed,
    unlock_failed,
    
    lock_busy,
    lock_interrupted,
    lock_invalid,

    unlock_busy,
    unlock_interrupted,
    unlock_invalid
};

template <class Tstring>
inline const Tstring lock_status_to_stringt(lock_status status) {
    switch (status) {
    case lock_success: return Tstring("lock_success");

    case lock_failed: return Tstring("lock_failed");
    case unlock_failed: return Tstring("unlock_failed");

    case lock_busy: return Tstring("lock_busy");
    case lock_interrupted: return Tstring("lock_interrupted");
    case lock_invalid: return Tstring("lock_invalid");

    case unlock_busy: return Tstring("unlock_busy");
    case unlock_interrupted: return Tstring("unlock_interrupted");
    case unlock_invalid: return Tstring("unlock_invalid");
    }
    return Tstring("unknown");
}

///////////////////////////////////////////////////////////////////////
//  Class: lock_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = exception::implementt<lock_status>, 
 class Textends = exception::extendt<lock_status> >

class _EXPORT_CLASS lock_exceptiont: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;
    
    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    lock_exceptiont(status_t status): extends(status) {
    }
    lock_exceptiont(const lock_exceptiont &copy): extends(copy) {
    }
    virtual ~lock_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return lock_status_to_stringt<string_t>(this->status());
    }
};
typedef lock_exceptiont<> lock_exception;

///////////////////////////////////////////////////////////////////////
//  Class: lockedt
///////////////////////////////////////////////////////////////////////
template <class Timplements = implement>
class _EXPORT_CLASS lockedt: virtual public Timplements {
public:
    typedef Timplements implements;

    virtual bool lock() { 
        return false; 
    }
    virtual lock_status try_lock() { 
        return lock_failed; 
    }
    virtual lock_status untimed_lock() { 
        return lock_failed; 
    }
    virtual lock_status timed_lock(mseconds_t milliseconds) { 
        return lock_failed; 
    }
    virtual bool unlock() { 
        return false; 
    }
};
typedef lockedt<> locked;

///////////////////////////////////////////////////////////////////////
///  Class: unlockedt
///////////////////////////////////////////////////////////////////////
template <class Timplements = locked>
class _EXPORT_CLASS unlockedt: virtual public Timplements {
public:
    typedef Timplements implements;

    virtual bool lock() { 
        return true; 
    }
    virtual lock_status try_lock() { 
        return lock_success; 
    }
    virtual lock_status untimed_lock() { 
        return lock_success; 
    }
    virtual lock_status timed_lock(mseconds_t milliseconds) { 
        return lock_success; 
    }
    virtual bool unlock() { 
        return true; 
    }
};
typedef unlockedt<> unlocked;

///////////////////////////////////////////////////////////////////////
//  Class: lockt
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = implement, class Textends = extend>

class _EXPORT_CLASS lockt: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;

    lockt(locked& _locked): locked_(_locked) {
        if (!(locked_.lock())) {
            lock_exception e(lock_failed);
            throw (e);
        }
    }
    virtual ~lockt() {
        if (!(locked_.unlock())) {
            lock_exception e(unlock_failed);
            throw (e);
        }
    }
private:
    lockt(const lockt &copy) {
    }

protected:
    locked& locked_;
};
typedef lockt<> lock;

} // namespace xos

#endif // _XOS_BASE_LOCKED_HPP 
