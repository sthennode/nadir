///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: input.hpp
///
/// Author: $author$
///   Date: 4/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_STD_INPUT_HPP
#define _XOS_CONSOLE_STD_INPUT_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace console {
namespace std {

typedef input inputt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: inputt
///////////////////////////////////////////////////////////////////////
template <class TImplements = inputt_implements>
class _EXPORT_CLASS inputt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef inputt<> input;

typedef input inputt_implements;
typedef input_extend inputt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: inputt
///////////////////////////////////////////////////////////////////////
template <class TImplements = inputt_implements, class TExtends = inputt_extends>
class _EXPORT_CLASS inputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    inputt(const inputt &copy) {
    }
    inputt() {
    }
    virtual ~inputt() {
    }
};
typedef inputt<> input;

} /// namespace std
} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_STD_INPUT_HPP 
        

