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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 5/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_READER_HPP
#define _XOS_IO_READER_HPP

#include "xos/io/sequence.hpp"

namespace xos {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = sequence>

class _EXPORT_CLASS readert: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    typedef typename implements::endof_t endof_t;
    static const endof_t endof = implements::endof;

    virtual ssize_t read(what_t* what, size_t size) {
        ssize_t count = 0;
        return count;
    }    
};
typedef readert<sequence> reader;

typedef readert<char_sequence> char_reader;
typedef readert<tchar_sequence> tchar_reader;
typedef readert<wchar_sequence> wchar_reader;

typedef readert<byte_sequence> byte_reader;
typedef readert<word_sequence> word_reader;

} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_READER_HPP 
