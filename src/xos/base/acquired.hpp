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
//   File: acquired.hpp
//
// Author: $author$
//   Date: 8/16/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ACQUIRED_HPP
#define _XOS_BASE_ACQUIRED_HPP

#include "xos/base/exception.hpp"

namespace xos {

typedef int acquire_status;
enum {
    release_success,
    acquire_success = release_success,

    acquire_failed,
    release_failed,
    
    acquire_busy,
    acquire_interrupted,
    acquire_invalid,

    release_busy,
    release_interrupted,
    release_invalid
};

template <class Tstring>
inline const Tstring acquire_status_to_stringt(acquire_status status) {
    switch (status) {
    case acquire_success: return Tstring("acquire_success");

    case acquire_failed: return Tstring("acquire_failed");
    case release_failed: return Tstring("release_failed");

    case acquire_busy: return Tstring("acquire_busy");
    case acquire_interrupted: return Tstring("acquire_interrupted");
    case acquire_invalid: return Tstring("acquire_invalid");

    case release_busy: return Tstring("release_busy");
    case release_interrupted: return Tstring("release_interrupted");
    case release_invalid: return Tstring("release_invalid");
    }
    return Tstring("unknown");
}

///////////////////////////////////////////////////////////////////////
//  Class: acquire_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = exception::implementt<acquire_status>, 
 class Textends = exception::extendt<acquire_status> >

class _EXPORT_CLASS acquire_exceptiont: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;
    
    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    acquire_exceptiont(status_t status): extends(status) {
    }
    acquire_exceptiont(const acquire_exceptiont &copy): extends(copy) {
    }
    virtual ~acquire_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return acquire_status_to_stringt<string_t>(this->status());
    }
}; // class _EXPORT_CLASS acquire_exceptiont

typedef acquire_exceptiont<> acquire_exception;

///////////////////////////////////////////////////////////////////////
//  Class: acquiredt
///////////////////////////////////////////////////////////////////////
template <class Timplements = implement>
class _EXPORT_CLASS acquiredt: virtual public Timplements {
public:
    typedef Timplements implements;

    virtual bool acquire() { 
        return false; 
    }
    virtual bool release() { 
        return false; 
    }
    virtual acquire_status try_acquire() { 
        return acquire_failed; 
    }
    virtual acquire_status untimed_acquire() { 
        return acquire_failed; 
    }
    virtual acquire_status timed_acquire(mseconds_t milliseconds) { 
        return acquire_failed; 
    }
}; // class _EXPORT_CLASS acquiredt

typedef acquiredt<> acquired;

///////////////////////////////////////////////////////////////////////
//  Class: releasedt
///////////////////////////////////////////////////////////////////////
template <class Timplements = acquired>
class _EXPORT_CLASS releasedt: virtual public Timplements {
public:
    typedef Timplements implements;

    virtual bool acquire() { 
        return true; 
    }
    virtual bool realease() { 
        return true; 
    }
    virtual acquire_status try_acquire() { 
        return acquire_success; 
    }
    virtual acquire_status untimed_acquire() { 
        return acquire_success; 
    }
    virtual acquire_status timed_acquire(mseconds_t milliseconds) { 
        return acquire_success; 
    }
}; // class _EXPORT_CLASS releasedt

typedef releasedt<> released;

///////////////////////////////////////////////////////////////////////
//  Class: acquiret
///////////////////////////////////////////////////////////////////////
template <class Timplements = implement, class Textends = extend>
class _EXPORT_CLASS acquiret: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;

    acquiret(acquired& _acquired, mseconds_t time): acquired_(_acquired) {
        if (acquire_success != (acquired_.timed_acquire(time))) {
            throw (acquire_exception(acquire_failed));
        }
    }
    acquiret(acquired& _acquired): acquired_(_acquired) {
        if (!(acquired_.acquire())) {
            throw (acquire_exception(acquire_failed));
        }
    }
    virtual ~acquiret() {
    }
private:
    acquiret(const acquiret &copy) {
        throw (exception::base(exception::unexpected));
    }

protected:
    acquired& acquired_;
}; // class _EXPORT_CLASS acquiret

typedef acquiret<> acquire;

///////////////////////////////////////////////////////////////////////
//  Class: releaset
///////////////////////////////////////////////////////////////////////
template <class Timplements = implement, class Textends = extend>
class _EXPORT_CLASS releaset: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;

    releaset(acquired& _acquired): acquired_(_acquired) {
        if (!(acquired_.release())) {
            throw (acquire_exception(release_failed));
        }
    }
    virtual ~releaset() {
    }
private:
    releaset(const releaset &copy) {
        throw (exception::base(exception::unexpected));
    }

protected:
    acquired& acquired_;
}; // class _EXPORT_CLASS releaset

typedef releaset<> release;

} // namespace xos

#endif // _XOS_BASE_ACQUIRED_HPP 
