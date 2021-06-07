///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: address.hpp
///
/// Author: $author$
///   Date: 3/22/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_COMM_ADDRESS_HPP
#define XOS_COMM_ADDRESS_HPP

#include "xos/base/logged.hpp"

namespace xos {
namespace comm {

/// enum address_family_t
typedef int address_family_t;
enum { address_family_unspec = 0 }; /// enum address_family_t

/// enum address_version_t
typedef int address_version_t;
enum { address_version_unspec = 0 }; /// enum address_version_t

/// enum send_flags_t
typedef int send_flags_t;
enum {
    send_flags_default = 0
}; /// enum send_flags_t

/// enum  recv_flags_t
typedef int recv_flags_t;
enum {
    recv_flags_default = 0
}; /// enum  recv_flags_t

/// class addresst
template 
<typename TFamily = address_family_t, TFamily VFamilyUnspec = address_family_unspec,
 typename TVersion = address_version_t, TVersion VVersionUnspec = address_version_unspec,
 class TImplements = loggedt<> >
class exported addresst: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef addresst derives; 
    
    typedef TFamily family_t;
    enum { family_unspec = VFamilyUnspec };
    
    typedef TVersion version_t;
    enum { version_unspec = VVersionUnspec };

    /// constructors / destructor
    virtual ~addresst() {
    }

    /// family /  version
    virtual family_t family() const {
        return family_unspec;
    }
    virtual version_t version() const {
        return version_unspec;
    }
}; /// class addresst
typedef addresst<> address;

namespace extended {
/// class addresst
template <class TExtends = extend, class TImplements = comm::addresst<> >
class exported addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef addresst derives; 
    
    typedef typename implements::family_t family_t;
    enum { family_unspec = implements::family_unspec };
    
    typedef typename implements::version_t version_t;
    enum { version_unspec = implements::version_unspec };

    /// constructors / destructor
    addresst(const addresst& copy): extends(copy) {
    }
    addresst() {
    }
    virtual ~addresst() {
    }
}; /// class addresst
typedef addresst<> address;
} /// namespace extended

} /// namespace comm
} /// namespace xos

#endif /// XOS_COMM_ADDRESS_HPP
