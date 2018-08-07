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
//   File: base.hpp
//
// Author: $author$
//   Date: 7/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_BASE_HPP
#define _XOS_BASE_BASE_HPP

#include "xos/platform/platform.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
//  Class: interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS interface {
public:
    typedef char char_t;
    typedef char_t end_char_t;
    enum { end_char = 0 };
    
    virtual ~interface() {
    }
}; // class _EXPORT_CLASS interface

///////////////////////////////////////////////////////////////////////
//  Class: implement
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS implement: virtual public interface {
public:
    typedef interface implements;

    virtual ~implement() {
    }
}; // class _EXPORT_CLASS implement

///////////////////////////////////////////////////////////////////////
//  Class: extend
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS extend: virtual public implement {
public:
    typedef implement implements;

    extend() {
    }
    virtual ~extend() {
    }
}; // class _EXPORT_CLASS extend

///////////////////////////////////////////////////////////////////////
//  Class: derive
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS derive: virtual public implement, public extend {
public:
    typedef implement implements;
    typedef extend extends;

    derive() {
    }
    virtual ~derive() {
    }
}; // class _EXPORT_CLASS derive

typedef implement implement_base;
typedef derive base;

} // namespace xos

#endif // _XOS_BASE_BASE_HPP 
