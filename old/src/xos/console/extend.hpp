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
//   File: extend.hpp
//
// Author: $author$
//   Date: 8/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_EXTEND_HPP
#define _XOS_CONSOLE_EXTEND_HPP

#include "xos/console/implement.hpp"

namespace xos {
namespace console {

///////////////////////////////////////////////////////////////////////
//  Class: extendt
///////////////////////////////////////////////////////////////////////
template <class Timplements = implement, class Textends = base>

class _EXPORT_CLASS extendt: virtual public Timplements, public Textends {
public:
    typedef Timplements implements;
    typedef Textends extends;
    
    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file };
    
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    extendt() {
    }
    virtual ~extendt() {
    }
    
}; // class _EXPORT_CLASS extendt
typedef extendt<> extend;

} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_EXTEND_HPP 
