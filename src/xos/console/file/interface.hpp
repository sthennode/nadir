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
#ifndef _XOS_CONSOLE_FILE_INTERFACE_HPP
#define _XOS_CONSOLE_FILE_INTERFACE_HPP

#include "xos/base/chars/interface.hpp"
#include "xos/base/locked.hpp"

namespace xos {
namespace console {
namespace file {

///////////////////////////////////////////////////////////////////////
//  Class: interfacet
///////////////////////////////////////////////////////////////////////
template 
<class Timplement = chars::interface, 
 typename Tfile = FILE*, typename Tnull_file = int, Tnull_file Vnull_file = 0,
 class Timplements = unlockedt<Timplement> >
class _EXPORT_CLASS interfacet: virtual public Timplements {
public:
    typedef Timplements implements;
    
    typedef Tfile file_t;
    typedef Tnull_file null_file_t;
    enum { null_file = Vnull_file };

    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
    
}; // class _EXPORT_CLASS interfacet
typedef interfacet<> interface;

} // namespace file
} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_FILE_INTERFACE_HPP 
