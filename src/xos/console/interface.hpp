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
#ifndef _XOS_CONSOLE_INTERFACE_HPP
#define _XOS_CONSOLE_INTERFACE_HPP

#include "xos/console/file/interface.hpp"
#include "xos/console/in/interface.hpp"
#include "xos/console/out/interface.hpp"
#include "xos/console/err/interface.hpp"

namespace xos {
namespace console {

///////////////////////////////////////////////////////////////////////
//  Class: interfacet
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = file::interface, 
 class Tin_implements = in::interface, 
 class Tout_implements = out::interface, 
 class Terr_implements = err::interface>

class _EXPORT_CLASS interfacet
: virtual public Timplements, 
  virtual public Tin_implements, 
  virtual public Tout_implements, 
  virtual public Terr_implements {
public:
    typedef Timplements implements;
    typedef Tin_implements in_implements;
    typedef Tout_implements out_implements;
    typedef Terr_implements err_implements;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file };
    
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };
    
}; // class _EXPORT_CLASS interfacet
typedef interfacet<> interface;

} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_INTERFACE_HPP 
