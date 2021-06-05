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
//   File: interface.hpp
//
// Author: $author$
//   Date: 8/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_CHARS_INTERFACE_HPP
#define _XOS_BASE_CHARS_INTERFACE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace chars {

///////////////////////////////////////////////////////////////////////
//  Class: interfacet
///////////////////////////////////////////////////////////////////////
template 
<typename Tchar = char, typename Tend_char = Tchar, 
 Tend_char Vend_char = 0, class Timplement = interface>

class _EXPORT_CLASS interfacet: virtual public Timplement {
public:
    typedef Timplement implements;
    
    typedef Tchar char_t;
    typedef Tend_char end_char_t;
    enum { end_char = Vend_char };
    
}; // class _EXPORT_CLASS interfacet
typedef interfacet<> interface;

} // namespace chars
} // namespace xos

#endif // _XOS_BASE_CHARS_INTERFACE_HPP 
