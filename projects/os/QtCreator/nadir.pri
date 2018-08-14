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
# Os QtCreator .pri file for nadir
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
NADIR_OS = macosx
} else {
NADIR_OS = linux
}

#CONFIG += c++11
#CONFIG += c++0x

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${NADIR_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${NADIR_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${NADIR_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# crono
CRONO_THIRDPARTY_PKG_MAKE_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${NADIR_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_MAKE_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${NADIR_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PKG_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PKG_BLD = $${OTHER_BLD}/$${CRONO_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PRJ_BLD = $${OTHER_BLD}/$${CRONO_PRJ}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_BLD}/lib
CRONO_LIB = $${CRONO_PKG_BLD}/lib
#CRONO_LIB = $${CRONO_PRJ_BLD}/lib
#CRONO_LIB = $${NADIR_LIB}

# crono LIBS
#
crono_LIBS += \
-L$${CRONO_LIB}/lib$${CRONO_NAME} \
-l$${CRONO_NAME} \

########################################################################
# fila
FILA_THIRDPARTY_PKG_MAKE_BLD = $${FILA_THIRDPARTY_PKG}/build/$${NADIR_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_MAKE_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${NADIR_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PKG_BLD = $${FILA_THIRDPARTY_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PKG_BLD = $${OTHER_BLD}/$${FILA_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PRJ_BLD = $${OTHER_BLD}/$${FILA_PRJ}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
#FILA_LIB = $${FILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PKG_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_BLD}/lib
#FILA_LIB = $${FILA_PKG_BLD}/lib
FILA_LIB = $${FILA_PRJ_BLD}/lib
#FILA_LIB = $${NADIR_LIB}

# fila LIBS
#
fila_LIBS += \
-L$${FILA_LIB}/lib$${FILA_NAME} \
-l$${FILA_NAME} \

########################################################################
# nadir

# nadir INCLUDEPATH
#
nadir_INCLUDEPATH += \

# nadir DEFINES
#
nadir_DEFINES += \

# nadir LIBS
#
nadir_LIBS += \
$${rostra_LIBS} \
$${build_nadir_LIBS} \
-lpthread \
-ldl \

_nadir_LIBS += \
$${fila_LIBS} \
$${crono_LIBS} \

contains(NADIR_OS,linux) {
nadir_LIBS += \
-lrt
} else {
}

