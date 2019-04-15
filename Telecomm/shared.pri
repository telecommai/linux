#动态库路径Linux64DLL

#第三方路径
LIB_3RDPARTY_PATH = "$$LIB_64_LINUX/"

# 生成静态库l
TEMPLATE = app
CONFIG += staticlib debug_and_release
CONFIG(debug,debug|release){
    !win32 {
        QMAKE_LFLAGS += -rdynamic
    }
    TARGET = Telecomm
    MOC_DIR += ./GeneratedFiles/debug
    OBJECTS_DIR += debug
    LIB_64_LINUX = "../Debug"
}else{
    TARGET = Telecomm
    MOC_DIR += ./GeneratedFiles/release
    OBJECTS_DIR += release
     LIB_64_LINUX = "../Release"
}

# 动态库
#TEMPLATE = lib dll

# 生成目录
DESTDIR ="$$LIB_64_LINUX"
LIBS += -L"$$LIB_64_LINUX"

UI_DIR = $$_PRO_FILE_PWD_
RCC_DIR = ./GeneratedFiles

win32 {
    #    多核编译
    QMAKE_CXXFLAGS += /MP

    #解决#include <windows.h> 和#include <winsock2.h>的问题
    DEFINES += WIN32_LEAN_AND_MEAN

    #处理error: C2338: <hash_map> is deprecated and will be REMOVED
    DEFINES += _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

    #Windows系统相关，需要处理的代码
   # DEFINES += __WINDOWS_CHANGE_
}

#解决%lld警告的问题    printf("num is %"PRIu64"\n", big);
DEFINES += __STDC_FORMAT_MACROS

greaterThan(QT_MAJOR_VERSION,4):QT += widgets

# required for the navel spatial index lib:
!win32 {
    DEFINES += PTHREADS
    DEFINES += HAVE_PTHREAD_H
}

win32-msvc2013 {
    DEFINES += _CRT_SECURE_NO_WARNINGS
}


