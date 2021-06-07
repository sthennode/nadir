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
///   File: connection.hpp
///
/// Author: $author$
///   Date: 3/22/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_COMM_CONNECTION_HPP
#define XOS_COMM_CONNECTION_HPP

#include "xos/comm/endpoint.hpp"

namespace xos {
namespace comm {

/// class connectiont
template <class TImplements = loggedt<> >
class exported connectiont: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef connectiont derives; 
    
    /// constructors / destructor
    virtual ~connectiont() {
    }

    /// send... / recv...
    virtual ssize_t send(const void* buf, size_t len) {
        return send(buf, len, send_flags_default);
    }
    virtual ssize_t recv(void* buf, size_t len) {
        return recv(buf, len, recv_flags_default);
    }
    virtual ssize_t send(const void* buf, size_t len, send_flags_t flags) {
        return -1;
    }
    virtual ssize_t recv(void* buf, size_t len, recv_flags_t flags) {
        return -1;
    }

}; /// class connectiont
typedef connectiont<> connection;

namespace extended {
/// class connectiont
template <class TExtends = extend, class TImplements = comm::connectiont<> >
class exported connectiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef connectiont derives; 
    
    /// constructors / destructor
    connectiont(const connectiont& copy): extends(copy) {
    }
    connectiont() {
    }
    virtual ~connectiont() {
    }
}; /// class connectiont
typedef connectiont<> connection;
} /// namespace extended

} /// namespace comm
} /// namespace xos

#endif /// XOS_COMM_CONNECTION_HPP
