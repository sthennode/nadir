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
//   File: attached.hpp
//
// Author: $author$
//   Date: 8/9/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ATTACHED_HPP
#define _XOS_BASE_ATTACHED_HPP

#include "xos/base/exception.hpp"

namespace xos {

typedef int attach_status;
enum {
    detach_success,
    attach_success = detach_success,
    attach_failed,
    detach_failed
};

template <class Tstring>
inline const Tstring attach_status_to_stringt(attach_status status) {
    switch (status) {
    case attach_success: return Tstring("attach_success");
    case attach_failed: return Tstring("attach_failed");
    case detach_failed: return Tstring("detach_failed");
    }
    return Tstring("unknown");
}

///////////////////////////////////////////////////////////////////////
//  Class: attach_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = exception::implementt<attach_status>, 
 class Textends = exception::extendt<attach_status> >

class _EXPORT_CLASS attach_exceptiont: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;
    
    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    attach_exceptiont(status_t status): extends(status) {
    }
    attach_exceptiont(const attach_exceptiont &copy): extends(copy) {
    }
    virtual ~attach_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return attach_status_to_stringt<string_t>(this->status());
    }
};
typedef attach_exceptiont<> attach_exception;

///////////////////////////////////////////////////////////////////////
//  Class: attachert
///////////////////////////////////////////////////////////////////////
template 
<typename Tattached = pointer_t, 
 typename Tunattached = int, Tunattached Vunattached = 0,
 class Timplements = implement>

class _EXPORT_CLASS attachert: virtual public Timplements {
public:
    typedef Timplements implements;

    typedef Tattached attached_t;
    typedef Tunattached unattached_t;
    enum { unattached = Vunattached };

    virtual bool detached() {
        if (((attached_t)unattached) != (this->attached_to())) {
            if (((attached_t)unattached) != (this->detach())) {
                return true;
            }
            return false;
        }
        return true;
    }
    virtual attached_t attach(attached_t detached) {
        return ((attached_t)unattached);
    }
    virtual attached_t detach() {
        return ((attached_t)unattached);
    }
    virtual attached_t attached_to() const {
        return ((attached_t)unattached);
    }
};
typedef attachert<> attacher;

///////////////////////////////////////////////////////////////////////
//  Class: attachedt
///////////////////////////////////////////////////////////////////////
template 
<typename Tattached = pointer_t, 
 typename Tunattached = int, Tunattached Vunattached = 0,
 class Timplement = implement, class Textends = extend,
 class Timplements = attachert<Tattached, Tunattached, Vunattached, implement> >

class _EXPORT_CLASS attachedt: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;

    typedef typename implements::attached_t attached_t;
    typedef typename implements::unattached_t unattached_t;
    enum { unattached = implements::unattached };

    attachedt(attached_t detached): attached_to_(detached) {
    }
    attachedt(const attachedt &copy): attached_to_(copy.attached_to()) {
    }
    attachedt(): attached_to_((attached_t)unattached) {
    }
    virtual ~attachedt() {
        if (!(this->detached())) {
            throw (attach_exception(detach_failed));
        }
    }

    virtual attached_t attach(attached_t detached) {
        attached_to_ = detached;
        return attached_to_;
    }
    virtual attached_t detach() {
        attached_t detached = attached_to_;
        attached_to_ = ((attached_t)unattached);
        return detached;
    }
    virtual attached_t attached_to() const {
        return attached_to_;
    }

protected:
    attached_t attached_to_;
};
typedef attachedt<> attached;

} // namespace xos

#endif // _XOS_BASE_ATTACHED_HPP 
