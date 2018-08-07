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
//   File: char.hpp
//
// Author: $author$
//   Date: 8/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_TO_CHAR_HPP
#define _XOS_BASE_TO_CHAR_HPP

#include "xos/base/base.hpp"
#include <string>

namespace xos {
namespace to {

///////////////////////////////////////////////////////////////////////
//  Class: chart
///////////////////////////////////////////////////////////////////////
template 
<typename TToChar, typename TChar,
 class TExtends = ::std::basic_string<TToChar>, 
 class TImplements = implement>

class _EXPORT_CLASS chart: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TToChar to_char_t;
    typedef TChar char_t;

    chart(const char_t& c) {
        transcode(c);
    }
    chart(size_t& count, const char_t* chars) {
        transcode(count, chars);
    }
    chart(const chart& copy): extends(copy) {
    }
    chart() {
    }
    virtual ~chart() {
    }

    virtual chart& transcode(const char_t& c) {
        to_char_t to = (to_char_t)c;
        this->assign(&to, 1);
        return *this;
    }
    virtual chart& transcode(size_t& count, const char_t* chars) {
        if ((chars)) {
            to_char_t to = (to_char_t)(*chars);
            this->assign(&to, 1);
            count = 1;
        }
        return *this;
    }
};

} // namespace to
} // namespace xos

#endif // _XOS_BASE_TO_CHAR_HPP 
