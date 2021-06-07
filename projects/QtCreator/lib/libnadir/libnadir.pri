########################################################################
# Copyright (c) 1988-2021 $organization$
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
#   File: libnadir.pri
#
# Author: $author$
#   Date: 6/5/2021
#
# QtCreator .pri file for nadir library libnadir
########################################################################

########################################################################
# libnadir

# libnadir TARGET
#
libnadir_TARGET = nadir
libnadir_TEMPLATE = lib
libnadir_CONFIG += staticlib

# libnadir INCLUDEPATH
#
libnadir_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# libnadir DEFINES
#
libnadir_DEFINES += \
$${nadir_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_NADIR_VERSION_BUILD=6/5/2021 \

########################################################################
# libnadir OBJECTIVE_HEADERS
#
#libnadir_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/xos/app/console/nadir/main.hh \

# libnadir OBJECTIVE_SOURCES
#
#libnadir_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/xos/app/console/nadir/main.mm \

########################################################################
# libnadir HEADERS
#
libnadir_HEADERS += \
$${NADIR_SRC}/xos/lib/nadir/version.hpp \

# libnadir SOURCES
#
libnadir_SOURCES += \
$${NADIR_SRC}/xos/lib/nadir/version.cpp \

########################################################################


