///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   Date: 4/25/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_VERSION_MAIN_HPP
#define XOS_APP_CONSOLE_VERSION_MAIN_HPP

#include "xos/app/console/version/main_opt.hpp"
#include "xos/lib/nadir/version.hpp"

namespace xos {
namespace app {
namespace console {
namespace version {

/// class maint
template <class TVersion = lib::nadir::version, class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef TVersion version_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
    }
public:

protected:
    /// ...run
    virtual int version_run(int argc, char_t** argv, char_t** env) {
        ::xos::lib::version::string_t string;
        const ::xos::lib::version& version = version_t::which();
        const ::xos::lib::version::char_t *chars = 0, *name = 0;
        int err = 0;
        if ((chars = version.to_chars(string)) && (name = version.name())) {
            this->outlln(name, " version = " , chars, "\n", null);
        } 
        return err;
    }
}; /// class maint
typedef maint<> main;

} /// namespace version
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_VERSION_MAIN_HPP 
