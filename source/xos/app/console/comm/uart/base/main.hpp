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
///   File: main.hpp
///
/// Author: $author$
///   Date: 3/19/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_COMM_UART_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_COMM_UART_BASE_MAIN_HPP

#include "xos/app/console/comm/uart/base/main_opt.hpp"
#include "xos/comm/serial/usart/posix/interface.hpp"

namespace xos {
namespace app {
namespace console {
namespace comm {
namespace uart {
namespace base {

/// class maint
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
    typedef xos::comm::serial::usart::posix::interface uart_t;

    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = default_run(argc, argv, env);
        return err;
    }
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool opened = false;
        uart_t& uart = this->uart();

        if ((argc > optind)) {
            const char_t* arg = 0;
            if ((argv) && (arg = argv[optind]) && (arg[0])) {
                opened = uart.open(arg);
            } else {
                opened = uart.open();
            }
        } else {
            opened = uart.open();
        }

        if ((opened)) {

            uart.send("Hello\r\n", 8);
            uart.close();
        }
        return err;
    }

    virtual uart_t& uart() const {
        return (uart_t&)uart_;
    }

protected:
    uart_t uart_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace uart
} /// namespace comm
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_COMM_UART_BASE_MAIN_HPP
