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
//   File: logged.hpp
//
// Author: $author$
//   Date: 8/10/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LOGGED_HPP
#define _XOS_BASE_LOGGED_HPP

#include "xos/base/base.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
//  Class: loggedt
///////////////////////////////////////////////////////////////////////
template <class Timplements = implement>
class _EXPORT_CLASS loggedt: virtual public Timplements {
public:
    typedef Timplements implements;

    virtual bool set_is_logged(bool to = true) {
        return is_logged();
    }
    virtual bool is_logged() const {
        return true;
    }
    virtual bool set_is_err_logged(bool to = true) {
        return is_err_logged();
    }
    virtual bool is_err_logged() const {
        return true;
    }
}; // class _EXPORT_CLASS loggedt

typedef loggedt<> logged;

///////////////////////////////////////////////////////////////////////
//  Class: logged_extendt
///////////////////////////////////////////////////////////////////////
template <class Timplements = logged, class Textends = extend>
class _EXPORT_CLASS logged_extendt: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;

    logged_extendt(bool is_logged, bool is_err_logged): is_logged_(is_logged), is_err_logged_(is_err_logged) {
    }
    logged_extendt(bool is_logged): is_logged_(is_logged), is_err_logged_(true) {
    }
    logged_extendt(): is_logged_(true), is_err_logged_(true) {
    }

    virtual bool set_is_logged(bool to = true) {
        is_logged_ = to;
        return is_logged();
    }
    virtual bool is_logged() const {
        return is_logged_;
    }
    virtual bool set_is_err_logged(bool to = true) {
        is_err_logged_ = to;
        return is_err_logged();
    }
    virtual bool is_err_logged() const {
        return is_err_logged_;
    }
    
protected:
    bool is_logged_, is_err_logged_;
}; // class _EXPORT_CLASS logged_extendt

typedef logged_extendt<> logged_extend;

} // namespace xos

#endif // _XOS_BASE_LOGGED_HPP 
