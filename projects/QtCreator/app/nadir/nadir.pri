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
#   File: nadir.pri
#
# Author: $author$
#   Date: 6/5/2021
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
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_NADIR_MAIN_INSTANCE \

########################################################################
# nadir_exe OBJECTIVE_HEADERS
#
#nadir_exe_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/xos/app/console/nadir/main.hh \

# nadir_exe OBJECTIVE_SOURCES
#
#nadir_exe_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/xos/app/console/nadir/main.mm \

########################################################################
# nadir_exe HEADERS
#
nadir_exe_HEADERS += \
$${NADIR_SRC}/xos/app/console/nadir/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/nadir/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# nadir_exe SOURCES
#
nadir_exe_SOURCES += \
$${NADIR_SRC}/xos/app/console/nadir/main_opt.cpp \
$${NADIR_SRC}/xos/app/console/nadir/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# nadir_exe FRAMEWORKS
#
nadir_exe_FRAMEWORKS += \
$${nadir_FRAMEWORKS} \

# nadir_exe LIBS
#
nadir_exe_LIBS += \
$${nadir_LIBS} \


