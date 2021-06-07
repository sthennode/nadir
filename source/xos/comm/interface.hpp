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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 3/22/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_COMM_INTERFACE_HPP
#define XOS_COMM_INTERFACE_HPP

#include "xos/comm/endpoint.hpp"
#include "xos/comm/transport.hpp"
#include "xos/base/opened.hpp"

namespace xos {
namespace comm {

/// class interfacet
template <class TEndpoint = endpointt<>, class TImplements = loggedt<openert<> > >
class exported interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef interfacet derives; 
    
    typedef comm::send_flags_t send_flags_t;
    enum { send_flags_default = comm::send_flags_default};
    
    typedef comm::recv_flags_t recv_flags_t;
    enum { recv_flags_default = comm::recv_flags_default};
    
    typedef TEndpoint endpoint_t;
    
    /// constructors / destructor
    virtual ~interfacet() {
    }

    /// send... / recv...
    virtual ssize_t sendto(const void* buf, size_t len, const endpoint_t& ep) {
        return sendto(buf, len, send_flags_default, ep);
    }
    virtual ssize_t recvfrom(void* buf, size_t len, const endpoint_t& ep) {
        return recvfrom(buf, len, recv_flags_default, ep);
    }
    virtual ssize_t sendto(const void* buf, size_t len, send_flags_t flags, const endpoint_t& ep) {
        return -1;
    }
    virtual ssize_t recvfrom(void* buf, size_t len, recv_flags_t flags, const endpoint_t& ep) {
        return -1;
    }

}; /// class interfacet
typedef interfacet<> interface;

namespace extended {
/// class interfacet
template <class TExtends = extend, class TImplements = comm::interfacet<> >
class exported interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacet derives; 
    
    /// constructors / destructor
    interfacet(const interfacet& copy): extends(copy) {
    }
    interfacet() {
    }
    virtual ~interfacet() {
    }
}; /// class interfacet
typedef interfacet<> interface;
} /// namespace extended

} /// namespace comm
} /// namespace xos

#endif /// XOS_COMM_INTERFACE_HPP
