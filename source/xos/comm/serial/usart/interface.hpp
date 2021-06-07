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
///   Date: 3/19/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_COMM_SERIAL_USART_INTERFACE_HPP
#define XOS_COMM_SERIAL_USART_INTERFACE_HPP

#include "xos/base/logged.hpp"
#include "xos/base/opened.hpp"

#define DEFAULT_COMM_SERIAL_USART_DEVICE_PATHNAME \
    DEFAULT_PLATFORM_COMM_SERIAL_USART_DEVICE_PATH \
    DEFAULT_PLATFORM_COMM_SERIAL_USART_DEVICE_NAME \

#define DEFAULT_COMM_SERIAL_USART_BAUD      PLATFORM_COMM_SERIAL_USART_BAUD_115200
#define DEFAULT_COMM_SERIAL_USART_PARITY    PLATFORM_COMM_SERIAL_USART_PARITY_NONE
#define DEFAULT_COMM_SERIAL_USART_BITS      PLATFORM_COMM_SERIAL_USART_BITS_8
#define DEFAULT_COMM_SERIAL_USART_STOP_BITS PLATFORM_COMM_SERIAL_USART_STOP_BITS_1

#define DEFAULT_COMM_SERIAL_USART_RTSCTS_ON true
#define DEFAULT_COMM_SERIAL_USART_XONXOFF_ON false

#define DEFAULT_COMM_SERIAL_USART_RTSCTS \
    ((DEFAULT_COMM_SERIAL_USART_RTSCTS_ON)?(PLATFORM_COMM_SERIAL_USART_RTSCTS):(0))

#define DEFAULT_COMM_SERIAL_USART_XONXOFF \
    ((DEFAULT_COMM_SERIAL_USART_XONXOFF_ON)?(PLATFORM_COMM_SERIAL_USART_XONXOFF):(0))

#define DEFAULT_COMM_SERIAL_USART_TIMEOUT 0
#define DEFAULT_COMM_SERIAL_USART_MINIMUM 0

namespace xos {
namespace comm {
namespace serial {
namespace usart {

/// enum send_flags_t
typedef int send_flags_t;
enum {
    send_flags_default = 0
}; /// enum send_flags_t

typedef int recv_flags_t;
enum {
    recv_flags_default = 0
};

/// class interfacet
template <class TImplements = loggedt<opener> >
class exported interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef interfacet derives; 
    
    /// constructors / destructor
    virtual ~interfacet() {
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

}; /// class interfacet
typedef interfacet<> interface;

} /// namespace usart
} /// namespace serial
} /// namespace comm
} /// namespace xos

#endif /// XOS_COMM_SERIAL_USART_INTERFACE_HPP
