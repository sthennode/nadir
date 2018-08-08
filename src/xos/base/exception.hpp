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
//   File: exception.hpp
//
// Author: $author$
//   Date: 8/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_EXCEPTION_HPP
#define _XOS_BASE_EXCEPTION_HPP

#include "xos/base/std/string.hpp"

namespace xos {
namespace exception {

typedef int status;
enum {
    success,
    failed
};

template <class Tstring>
inline Tstring status_to_stringt(exception::status status) {
    switch (status) {
    case success: return Tstring("success");
    case failed: return Tstring("failed");
    }
    return Tstring("unknown");
}

///////////////////////////////////////////////////////////////////////
//  Class: implementt
///////////////////////////////////////////////////////////////////////
template 
<typename Tstatus = status, typename Tchar = char, 
 class Tstring = std::string::extendt<Tchar>,
 class Timplements = implement>

class _EXPORT_CLASS implementt: virtual public Timplements {
public:
    typedef Timplements implements;

    typedef Tstatus status_t;
    typedef Tstring string_t;
    typedef Tchar char_t;

    virtual string_t status_to_string() const {
        return exception::status_to_stringt<string_t>(this->status());
    }
    virtual status_t status() const { 
        return failed; 
    }
    virtual operator status_t() const {
        return status(); 
    }
};

///////////////////////////////////////////////////////////////////////
///  Class: extendt
///////////////////////////////////////////////////////////////////////
template 
<typename Tstatus = status,
 class Timplements = implementt<Tstatus>, 
 class Textends = extend>

class _EXPORT_CLASS extendt: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;

    typedef Tstatus status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    extendt(status_t status): status_(status) {
    }
    extendt(const extendt &copy): status_(copy.status_) {
    }
    virtual ~extendt() {
    }

    virtual status_t status() const { 
        return status_; 
    }
protected:
    status_t status_;
};

typedef extendt<> base;

} // namespace exception
} // namespace xos

#endif // _XOS_BASE_EXCEPTION_HPP 
