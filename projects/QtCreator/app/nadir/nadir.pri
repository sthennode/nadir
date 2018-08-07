########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: nadir.pri
#
# Author: $author$
#   Date: 7/30/2018
#
# QtCreator .pri file for nadir executable nadir
########################################################################

########################################################################
# nadir

# nadir_exe TARGET
#
nadir_exe_TARGET = nadir

# nadir_exe INCLUDEPATH
#
nadir_exe_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# nadir_exe DEFINES
#
nadir_exe_DEFINES += \
$${nadir_DEFINES} \

########################################################################
# nadir_exe OBJECTIVE_HEADERS
#
#nadir_exe_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/nadir/base/Base.hh \

# nadir_exe OBJECTIVE_SOURCES
#
#nadir_exe_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/nadir/base/Base.mm \

########################################################################
# nadir_exe HEADERS
#
nadir_exe_HEADERS += \
$${NADIR_SRC}/xos/base/to/char.hpp \
$${NADIR_SRC}/xos/base/std/string.hpp \
$${NADIR_SRC}/xos/base/exception.hpp \
$${NADIR_SRC}/xos/base/locked.hpp \
$${NADIR_SRC}/xos/console/file/interface.hpp \
$${NADIR_SRC}/xos/console/file/in/implement.hpp \
$${NADIR_SRC}/xos/console/file/out/implement.hpp \
$${NADIR_SRC}/xos/console/file/implement.hpp \
$${NADIR_SRC}/xos/console/in/interface.hpp \
$${NADIR_SRC}/xos/console/out/interface.hpp \
$${NADIR_SRC}/xos/console/err/interface.hpp \
$${NADIR_SRC}/xos/console/interface.hpp \
$${NADIR_SRC}/xos/console/in/implement.hpp \
$${NADIR_SRC}/xos/console/out/implement.hpp \
$${NADIR_SRC}/xos/console/err/implement.hpp \
$${NADIR_SRC}/xos/console/implement.hpp \
$${NADIR_SRC}/xos/console/extend.hpp \
$${NADIR_SRC}/xos/console/std/io.hpp \
$${NADIR_SRC}/xos/console/io.hpp \
$${NADIR_SRC}/xos/console/main/main.hpp \

# nadir_exe SOURCES
#
nadir_exe_SOURCES += \
$${NADIR_SRC}/xos/base/to/char.cpp \
$${NADIR_SRC}/xos/base/std/string.cpp \
$${NADIR_SRC}/xos/base/exception.cpp \
$${NADIR_SRC}/xos/base/locked.cpp \
$${NADIR_SRC}/xos/console/interface.cpp \
$${NADIR_SRC}/xos/console/implement.cpp \
$${NADIR_SRC}/xos/console/extend.cpp \
$${NADIR_SRC}/xos/console/io.cpp \
$${NADIR_SRC}/xos/console/main/main.cpp \

########################################################################
# nadir_exe FRAMEWORKS
#
nadir_exe_FRAMEWORKS += \
$${nadir_FRAMEWORKS} \

# nadir_exe LIBS
#
nadir_exe_LIBS += \
$${nadir_LIBS} \

