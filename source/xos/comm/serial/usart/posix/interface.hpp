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
#ifndef XOS_COMM_SERIAL_USART_POSIX_INTERFACE_HPP
#define XOS_COMM_SERIAL_USART_POSIX_INTERFACE_HPP

#include "xos/platform/posix/comm/serial/usart.hpp"
#include "xos/comm/serial/usart/interface.hpp"
#include "xos/base/logger.hpp"

namespace xos {
namespace comm {
namespace serial {
namespace usart {
namespace posix {

typedef int device_t;
enum { invalid_device = -1 };

typedef device_t device_attached_t;
typedef int device_unattached_t;
enum { device_unattached = invalid_device };
     
/// class interfacet
template 
<class TImplements = usart::interfacet<>, 
 class TExtends = openedt<device_attached_t, device_unattached_t, device_unattached> >
class exported interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacet derives; 
    
    typedef typename extends::attached_t attached_t;
    typedef typename extends::unattached_t unattached_t;
    enum { unattached = extends::unattached };

    /// constructors / destructor
    interfacet(const char* path, int oflag)
    : baud_(DEFAULT_COMM_SERIAL_USART_BAUD), parity_(DEFAULT_COMM_SERIAL_USART_PARITY), 
      bits_(DEFAULT_COMM_SERIAL_USART_BITS), stop_bits_(DEFAULT_COMM_SERIAL_USART_STOP_BITS),
      timeout_(DEFAULT_COMM_SERIAL_USART_TIMEOUT), minimum_(DEFAULT_COMM_SERIAL_USART_MINIMUM),
      rtscts_(DEFAULT_COMM_SERIAL_USART_RTSCTS), xonxoff_(DEFAULT_COMM_SERIAL_USART_XONXOFF),
      rtscts_on_(DEFAULT_COMM_SERIAL_USART_RTSCTS_ON), xonxoff_on_(DEFAULT_COMM_SERIAL_USART_XONXOFF_ON) {
        if (!(this->open(path, oflag))) {
            throw (open_exception(open_failed));
        }
    }
    interfacet(const char* path)
    : baud_(DEFAULT_COMM_SERIAL_USART_BAUD), parity_(DEFAULT_COMM_SERIAL_USART_PARITY), 
      bits_(DEFAULT_COMM_SERIAL_USART_BITS), stop_bits_(DEFAULT_COMM_SERIAL_USART_STOP_BITS),
      timeout_(DEFAULT_COMM_SERIAL_USART_TIMEOUT), minimum_(DEFAULT_COMM_SERIAL_USART_MINIMUM),
      rtscts_(DEFAULT_COMM_SERIAL_USART_RTSCTS), xonxoff_(DEFAULT_COMM_SERIAL_USART_XONXOFF),
      rtscts_on_(DEFAULT_COMM_SERIAL_USART_RTSCTS_ON), xonxoff_on_(DEFAULT_COMM_SERIAL_USART_XONXOFF_ON) {
        if (!(this->open(path))) {
            throw (open_exception(open_failed));
        }
    }
    interfacet(const interfacet& copy)
    : extends(copy),
      baud_(DEFAULT_COMM_SERIAL_USART_BAUD), parity_(DEFAULT_COMM_SERIAL_USART_PARITY), 
      bits_(DEFAULT_COMM_SERIAL_USART_BITS), stop_bits_(DEFAULT_COMM_SERIAL_USART_STOP_BITS),
      timeout_(DEFAULT_COMM_SERIAL_USART_TIMEOUT), minimum_(DEFAULT_COMM_SERIAL_USART_MINIMUM),
      rtscts_(DEFAULT_COMM_SERIAL_USART_RTSCTS), xonxoff_(DEFAULT_COMM_SERIAL_USART_XONXOFF),
      rtscts_on_(DEFAULT_COMM_SERIAL_USART_RTSCTS_ON), xonxoff_on_(DEFAULT_COMM_SERIAL_USART_XONXOFF_ON){
    }
    interfacet()
    : baud_(DEFAULT_COMM_SERIAL_USART_BAUD), parity_(DEFAULT_COMM_SERIAL_USART_PARITY), 
      bits_(DEFAULT_COMM_SERIAL_USART_BITS), stop_bits_(DEFAULT_COMM_SERIAL_USART_STOP_BITS),
      timeout_(DEFAULT_COMM_SERIAL_USART_TIMEOUT), minimum_(DEFAULT_COMM_SERIAL_USART_MINIMUM),
      rtscts_(DEFAULT_COMM_SERIAL_USART_RTSCTS), xonxoff_(DEFAULT_COMM_SERIAL_USART_XONXOFF),
      rtscts_on_(DEFAULT_COMM_SERIAL_USART_RTSCTS_ON),  xonxoff_on_(DEFAULT_COMM_SERIAL_USART_XONXOFF_ON) {
    }
    virtual ~interfacet() {
        if (!(this->closed())) {
            throw (open_exception(close_failed));
        }
    }

    /// open...
    using extends::open;
    virtual bool open(const char* path) {
        attached_t detached = (attached_t)unattached;
        if ((attached_t)unattached != (detached = this->open_attached(path))) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    virtual bool open(const char* path, int oflag) {
        attached_t detached = (attached_t)unattached;
        if ((attached_t)unattached != (detached = this->open_attached(path, oflag))) {
            this->set_is_open();
            return true;
        }
        return false;
    }

    /// send... / recv...
    using implements::send;
    virtual ssize_t send(const void* buf, size_t len, send_flags_t flags) {
        attached_t detached = (attached_t)unattached;
        if ((attached_t)unattached != (detached = this->attached_to())) {
            if ((buf) && (len)) {
                ssize_t amount = 0;
                if (0 <= (amount = ::write(detached, buf, len))) {
                    return amount;
                } else {
                    LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::write(detached = " << detached << ", buf = " << const_pointer_to_string(buf) << ", len = " << len << ")");
                }
            }
        }
        return -1;
    }
    using implements::recv;
    virtual ssize_t recv(void* buf, size_t len, recv_flags_t flags) {
        attached_t detached = (attached_t)unattached;
        if ((attached_t)unattached != (detached = this->attached_to())) {
            if ((buf) && (len)) {
                ssize_t amount = 0;
                if (0 <= (amount = ::read(detached, buf, len))) {
                    return amount;
                } else {
                    LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::read(detached = " << detached << ", buf = " << pointer_to_string(buf) << ", len = " << len << ")");
                }
            }
        }
        return -1;
    }

    /// open.../ close...
    using extends::open_attached;
    virtual attached_t open_attached(const char* path) {
        attached_t detached = (attached_t)unattached;
        if ((this->closed())) {
            if ((attached_t)unattached != (detached = open_detached(path))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t open_attached(const char* path, int oflag) {
        attached_t detached = (attached_t)unattached;
        if ((this->closed())) {
            if ((attached_t)unattached != (detached = open_detached(path, oflag))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t open_detached() const {
        attached_t detached = (attached_t)unattached;
        const char* path = DEFAULT_COMM_SERIAL_USART_DEVICE_PATHNAME;
        detached = this->open_detached(path);
        return detached;
    }
    virtual attached_t open_detached(const char* path) const {
        attached_t detached = (attached_t)unattached;
        int oflag = O_RDWR | O_NOCTTY| O_NDELAY;
        detached = this->open_detached(path, oflag);
        return detached;
    }
    virtual attached_t open_detached(const char* path, int oflag) const {
        attached_t detached = (attached_t)unattached;

        if ((path) && (path[0])) {

            LOGGER_IS_LOGGED_DEBUG("::open(path = \"" << path << "\", oflag = " << oflag << ")...");
            if (0 > (detached = ::open(path, oflag))) {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::open(path = \"" << path << "\", oflag = " << oflag << ")");
                detached = (attached_t)unattached;
            } else {
                LOGGER_IS_LOGGED_DEBUG("..." << detached << " = ::open(path = \"" << path << "\", oflag = " << oflag << ")");
                configure_detached(detached);
            }
        }
        return detached;
    }
    virtual bool configure_detached(attached_t detached) const {
        if ((attached_t)unattached != (detached)) {
            struct termios& tio = this->tio();
            int err = 0;

            /// Clear all of the bits in the termio structure.
            ///
            ::memset(&tio, 0, sizeof(struct termios));

            /// Set the port to ignore modem control lines and enable
            /// reading.
            ///
            tio.c_cflag |= CLOCAL | CREAD;

            /// Set the baud rate for the port.
            ///
            tio.c_cflag |= this->baud();
#if defined(BSD)
            cfsetospeed(&tio, this->baud());
            cfsetispeed(&tio, this->baud());
#endif /// defined(BSD)

            /// Set the parity for the port.
            ///
            tio.c_cflag |= this->parity();

            /// Set the data bits for the port.
            ///
            tio.c_cflag |= this->bits();

            /// Set the stop bits for the port.
            ///
            tio.c_cflag |= this->stop_bits();

            /// Set hardware flow control.
            ///
            tio.c_cflag |= this->rtscts();

            /// Set software flow control.
            ///
            tio.c_iflag |= this->xonxoff();

            /// Set the timeout value for read when there are no
            /// characters on the port.
            ///
            tio.c_cc[VTIME] = this->timeout();

            /// Set the minimum number of characters that must be present
            /// before read() returns.
            ///
            tio.c_cc[VMIN] = this->minimum();

            /// Configure the port using the tty values.
            ///
            LOGGER_IS_LOGGED_DEBUG("::tcsetattr(" << detached << ", TCSANOW, &tio)...");
            if ((err = ::tcsetattr(detached, TCSANOW, &tio))) {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::tcsetattr(" << detached << ", TCSANOW, &tio)");
            } else {
                LOGGER_IS_LOGGED_DEBUG("...::tcsetattr(" << detached << ", TCSANOW, &tio)");
            }
        }
        return false;
    }
    virtual bool close_detached(attached_t detached) const {
        if ((attached_t)unattached != (detached)) {
            int err = 0;
            
            LOGGER_IS_LOGGED_DEBUG("::close(" << detached << ")...");
            if ((err = ::close(detached))) {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::close(" << detached << ")");
            } else {
                LOGGER_IS_LOGGED_DEBUG("...::close(" << detached << ")");
                return true;
            }
        }
        return false;
    }

    /// ...baud
    virtual int& set_baud(int to) {
        int& baud = this->baud();
        baud = to;
        return baud;
    }
    virtual int& baud() const {
        return (int&)baud_;
    }
    /// ...parity
    virtual int& set_parity(int to) {
        int& parity = this->parity();
        parity = to;
        return parity;
    }
    virtual int& parity() const {
        return (int&)parity_;
    }

    /// ...bits
    virtual int& set_bits(int to) {
        int& bits = this->bits();
        bits = to;
        return bits;
    }
    virtual int& bits() const {
        return (int&)bits_;
    }
    /// ...stop_bits
    virtual int& set_stop_bits(int to) {
        int& stop_bits = this->stop_bits();
        stop_bits = to;
        return stop_bits;
    }
    virtual int& stop_bits() const {
        return (int&)stop_bits_;
    }

    /// ...rtscts...
    virtual int& set_rtscts(int to) {
        int& rtscts = this->rtscts();
        rtscts = to;
        return rtscts;
    }
    virtual int& rtscts() const {
        return (int&)rtscts_;
    }
    virtual bool& set_rtscts_on(bool to) {
        bool& rtscts_on = this->rtscts_on();
        int& rtscts = this->rtscts();
        rtscts = (rtscts_on = to)?(PLATFORM_COMM_SERIAL_USART_RTSCTS):(0);
        return rtscts_on;
    }
    virtual bool& rtscts_on() const {
        return (bool&)rtscts_on_;
    }

    /// ...xonxoff...
    virtual int& set_xonxoff(int to) {
        int& xonxoff = this->xonxoff();
        xonxoff = to;
        return xonxoff;
    }
    virtual int& xonxoff() const {
        return (int&)xonxoff_;
    }
    virtual bool& set_xonxoff_on(bool to) {
        bool& xonxoff_on = this->xonxoff_on();
        int& xonxoff = this->xonxoff();
        xonxoff = (xonxoff_on = to)?(PLATFORM_COMM_SERIAL_USART_XONXOFF):(0);
        return xonxoff_on;
    }
    virtual bool& xonxoff_on() const {
        return (bool&)xonxoff_on_;
    }
    
    /// ...timeout...
    virtual int& set_timeout(int to) {
        int& timeout = this->timeout();
        timeout = to;
        return timeout;
    }
    virtual int& timeout() const {
        return (int&)timeout_;
    }

    /// ...minimum...
    virtual int& set_minimum(int to) {
        int& minimum = this->minimum();
        minimum = to;
        return minimum;
    }
    virtual int& minimum() const {
        return (int&)minimum_;
    }

    /// tio
    virtual struct termios& tio() const {
        return (struct termios&)tio_;
    }

protected:
    int baud_, parity_, bits_, stop_bits_, timeout_, minimum_, xonxoff_, rtscts_;
    bool rtscts_on_, xonxoff_on_;
    struct termios tio_;
}; /// class interfacet
typedef interfacet<> interface;

} /// namespace posix
} /// namespace usart
} /// namespace serial
} /// namespace comm
} /// namespace xos

#endif /// XOS_COMM_SERIAL_USART_POSIX_INTERFACE_HPP
