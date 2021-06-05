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
//   File: implement.hpp
//
// Author: $author$
//   Date: 8/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_IMPLEMENT_HPP
#define _XOS_CONSOLE_IMPLEMENT_HPP

#include "xos/console/interface.hpp"
#include "xos/console/in/implement.hpp"
#include "xos/console/out/implement.hpp"
#include "xos/console/err/implement.hpp"

namespace xos {
namespace console {

///////////////////////////////////////////////////////////////////////
//  Class: implementt
///////////////////////////////////////////////////////////////////////
template 
<class Timplements = interface, 
 class Tin_implements = in::implement, 
 class Tout_implements = out::implement, 
 class Terr_implements = err::implement>

class _EXPORT_CLASS implementt
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
    
}; // class _EXPORT_CLASS implementt
typedef implementt<> implement;

} // namespace console
} // namespace xos

#endif // _XOS_CONSOLE_IMPLEMENT_HPP 
