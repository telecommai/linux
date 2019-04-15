QT += core network gui-private widgets sql webenginewidgets xml multimedia multimediawidgets quick quickwidgets quickcontrols2 x11extras

CONFIG   += C++11
CONFIG += X11
LIBS+=-ldl
CONFIG(debug,debug|release){
       LIBS += -L$$PWD/../SharedLib_mac/OPObjectManager/lib/ -lOPObjectManagerD \
       -L$$PWD/../SharedLib_mac/LoginDatabaseOperaShareLib/lib/ -lLoginDatabaseOperaShareLibD \
       -L$$PWD/../SharedLib_mac/IMDataManagerShareLib/lib/ -lIMDataManagerShareLibD \
       -L$$PWD/../SharedLib_mac/OPDataManager/lib/ -lOPDataManagerD \
       -L$$PWD/../SharedLib_mac/SettingsManagerShareLib/lib/ -lSettingsManagerShareLibD \
       -L$$PWD/../SharedLib_mac/IMDataBaseOperaInfo/lib/ -lIMDataBaseOperaInfoD \
       -L$$PWD/../SharedLib_mac/OPWindowsManagerShareLib/lib/ -lOPWindowsManagerShareLibD \
       -L$$PWD/../SharedLib_mac/IMRequestBuddyInfo/lib/ -lIMRequestBuddyInfoD \
       -L$$PWD/../SharedLib_mac/IMSocketNetWorkShareLib/lib/ -lIMSocketNetWorkShareLibD \
       -L$$PWD/../SharedLib_mac/HttpNetWorkShareLib/lib/ -lHttpNetWorkShareLibD \
       -L$$PWD/../SharedLib_mac/ScreenCutShareLib/lib/ -lScreenCutShareLibD \
       -L$$PWD/../SharedLib_mac/ReadAppConfig/lib/ -lReadAppConfigD \
       -L$$PWD/../SharedLib_mac/BaseUI/lib/ -lBaseUIShareLibD \
       -L$$PWD/../SharedLib_mac/botan/lib/ -lbotan-2 \
       -L$$PWD/../SharedLib_mac/openssl/lib/ -lssl \
       -L$$PWD/../SharedLib_mac/openssl/lib/ -lcrypto \
       -L$$PWD/../SharedLib_mac/OPDateBaseShareLib/lib -lOPDatebaseShareLibD \
       -L$$PWD/../SharedLib_mac/OPMainMangerShareLib/lib/ -lOPMainManagerShareLibD \
       -L$$PWD/../SharedLib_mac/OPMainWidget/lib/ -lOPMainWidgetShareLibD \
       -L$$PWD/../SharedLib_mac/ScanQRLoginShareLib/lib/ -lScanQRLoginShareLibD \
       -L$$PWD/../SharedLib_mac/OPRequestShareLib/lib/ -lOPRequestShareLibD \
       -L$$PWD/../SharedLib_mac/OPRecoveryWalletShareLib/lib/ -lOPRecoveryWalletShareLibD \
       -L$$PWD/../SharedLib_mac/ChatWidget/lib/ -lChatWidgetShareLibD \
       -L$$PWD/../SharedLib_mac/WebObjectShareLib/lib/ -lWebObjectShareLibD \
       -L$$PWD/../SharedLib_mac/AlphabeticalSortSharedLib/lib/ -lAlphabeticalSortSharedLibD \
       -L$$PWD/../SharedLib_mac/ContactsWidget/lib/ -lContactsWidgetShareLibD \
       -L$$PWD/../SharedLib_mac/UpdateShareLib/lib/ -lUpdateShareLibD \
       -L$$PWD/../SharedLib_mac/ewalletShareLib/lib/ -leWalletLibD \
       -L$$PWD/../SharedLib_mac/createAddWidgetShareLib/lib/ -lCreateAddWidgetShareLibD \
       -L$$PWD/../SharedLib_mac/QxtGlobalShortCut/lib/ -lQxtGlobalShortCutD \
       -L$$PWD/../SharedLib_mac/IMDownLoadHeaderImg/lib/ -lIMDownLoadHeaderImgD \
       -L$$PWD/../SharedLib_mac/BaseUI/lib/ -lBaseUIShareLibD \
       -L$$PWD/../SharedLib_mac/VideoPlayShareLib/lib/ -lVideoPlayShareLibD \
       -L$$PWD/../SharedLib_mac/ContactsProfileShareLib/lib/ -lContactsProfileShareLibD \
       -L$$PWD/../SharedLib_mac/UpdateShareLib/lib/ -lUpdateShareLibD \
       -L$$PWD/../SharedLib_mac/QRenCodeShareLib/lib/ -lQRenCodeShareLibD \
       -L$$PWD/../SharedLib_mac/SqlLiteShareLib/lib/ -lSqlLiteShareLibD \
       -L$$PWD/../SharedLib_mac/MacUpdate/lib/ -lMacUpdateD \
       -L$$PWD/../SharedLib_mac/IMSocketDataBaseShareLib/lib -lIMSocketDataBaseShareLibD \
       -L$$PWD/../SharedLib_mac/SocketNetWorkShareLib/lib/ -lSocketNetWorkShareLibD \
       -L$$PWD/../SharedLib_mac/BaseUI/lib/ -lBaseUIShareLibD \
       -L$$PWD/../SharedLib_mac/qrencode/lib/ -lqrencode
}else
{
        LIBS += -L$$PWD/../SharedLib/OPObjectManager/lib/ -lOPObjectManager \
        -L$$PWD/../SharedLib/LoginDatabaseOperaShareLib/lib/ -lLoginDatabaseOperaShareLib \
        -L$$PWD/../SharedLib/IMDataManagerShareLib/lib/ -lIMDataManagerShareLib \
        -L$$PWD/../SharedLib/OPDataManager/lib/ -lOPDataManager \
        -L$$PWD/../SharedLib/SettingsManagerShareLib/lib/ -lSettingsManagerShareLib \
        -L$$PWD/../SharedLib/IMDataBaseOperaInfo/lib/ -lIMDataBaseOperaInfo \
        -L$$PWD/../SharedLib/OPWindowsManagerShareLib/lib/ -lOPWindowsManagerShareLib \
        -L$$PWD/../SharedLib/IMRequestBuddyInfo/lib/ -lIMRequestBuddyInfo \
        -L$$PWD/../SharedLib/IMSocketNetWorkShareLib/lib/ -lIMSocketNetWorkShareLib \
        -L$$PWD/../SharedLib/HttpNetWorkShareLib/lib/ -lHttpNetWorkShareLib \
        -L$$PWD/../SharedLib/ScreenCutShareLib/lib/ -lScreenCutShareLib \
        -L$$PWD/../SharedLib/ReadAppConfig/lib/ -lReadAppConfig \
        -L$$PWD/../SharedLib/BaseUI/lib/ -lBaseUIShareLib \
        -L$$PWD/../SharedLib/botan/lib/ -lbotan-2 \
        -L$$PWD/../SharedLib/openssl/lib/ -lssl \
        -L$$PWD/../SharedLib/openssl/lib/ -lcrypto \
        -L$$PWD/../SharedLib/OPDateBaseShareLib/lib -lOPDatebaseShareLib \
        -L$$PWD/../SharedLib/OPMainMangerShareLib/lib/ -lOPMainManagerShareLib \
        -L$$PWD/../SharedLib/OPMainWidget/lib/ -lOPMainWidgetShareLib \
        -L$$PWD/../SharedLib/ScanQRLoginShareLib/lib/ -lScanQRLoginShareLib \
        -L$$PWD/../SharedLib/OPRequestShareLib/lib/ -lOPRequestShareLib \
        -L$$PWD/../SharedLib/OPRecoveryWalletShareLib/lib/ -lOPRecoveryWalletShareLib \
        -L$$PWD/../SharedLib/ChatWidget/lib/ -lChatWidgetShareLib \
        -L$$PWD/../SharedLib/WebObjectShareLib/lib/ -lWebObjectShareLib \
        -L$$PWD/../SharedLib/AlphabeticalSortSharedLib/lib/ -lAlphabeticalSortSharedLib \
        -L$$PWD/../SharedLib/ContactsWidget/lib/ -lContactsWidgetShareLib \
        -L$$PWD/../SharedLib/UpdateShareLib/lib/ -lUpdateShareLib \
        -L$$PWD/../SharedLib/ewalletShareLib/lib/ -leWalletLib \
        -L$$PWD/../SharedLib/createAddWidgetShareLib/lib/ -lCreateAddWidgetShareLib \
        -L$$PWD/../SharedLib/QxtGlobalShortCut/lib/ -lQxtGlobalShortCut \
        -L$$PWD/../SharedLib/IMDownLoadHeaderImg/lib/ -lIMDownLoadHeaderImg \
        -L$$PWD/../SharedLib/BaseUI/lib/ -lBaseUIShareLib \
        -L$$PWD/../SharedLib/VideoPlayShareLib/lib/ -lVideoPlayShareLib \
        -L$$PWD/../SharedLib/ContactsProfileShareLib/lib/ -lContactsProfileShareLib \
        -L$$PWD/../SharedLib/UpdateShareLib/lib/ -lUpdateShareLib \
        -L$$PWD/../SharedLib/QRenCodeShareLib/lib/ -lQRenCodeShareLib \
        -L$$PWD/../SharedLib/SqlLiteShareLib/lib/ -lSqlLiteShareLib \
        -L$$PWD/../SharedLib/MacUpdate/lib/ -lMacUpdate \
        -L$$PWD/../SharedLib/IMSocketDataBaseShareLib/lib -lIMSocketDataBaseShareLib \
        -L$$PWD/../SharedLib/SocketNetWorkShareLib/lib/ -lSocketNetWorkShareLib \
        -L$$PWD/../SharedLib/BaseUI/lib/ -lBaseUIShareLib \
        -L$$PWD/../SharedLib/qrencode/lib/ -lqrencode
}

INCLUDEPATH += ../SharedLib/openssl/include \
    ../SharedLib/common \
    ../SharedLib/qrencode/include \
    ../SharedLib/AlphabeticalSortSharedLib/include \
    ../SharedLib/SqlLiteShareLib/include \
    ../SharedLib/QRenCodeShareLib/include \
    ../SharedLib/VideoPlayShareLib/include \
    ../SharedLib/SocketNetWorkShareLib/include \
    ../SharedLib/ReadAppConfig/include \
    ../SharedLib/OPDataManager/include \
    ../SharedLib/BaseUI/include \
    ../SharedLib/HttpNetWorkShareLib/include \
    ../SharedLib/IMDataManagerShareLib/include \
    ../SharedLib/IMDataBaseOperaInfo/include \
    ../SharedLib/IMSocketDataBaseShareLib/include \
    ../SharedLib/OPDateBaseShareLib/include \
    ../SharedLib/LoginDatabaseOperaShareLib/include \
    ../SharedLib/OPRecoveryWalletShareLib/include \
    ../SharedLib/OPRequestShareLib/include \
    ../SharedLib/IMDownLoadHeaderImg/include \
    ../SharedLib/IMRequestBuddyInfo/include \
    ../SharedLib/IMSocketNetWorkShareLib/include \
    ../SharedLib/ContactsProfileShareLib/include \
    ../SharedLib/ContactsWidget/include \
    ../SharedLib/ChatWidget/include \
    ../SharedLib/UpdateShareLib/include \
    ../SharedLib/ewalletShareLib/include \
    ../SharedLib/ScanQRLoginShareLib/include \
    ../SharedLib/createAddWidgetShareLib/include \
    ../SharedLib/OPMainWidget/include \
    ../SharedLib/OPWindowsManagerShareLib/include \
    ../SharedLib/OPMainMangerShareLib/include \
    ../SharedLib/OPObjectManager/include \
    ../SharedLib/botan/include/botan-2 \
    ../SharedLib/OPObjectManager/include \
    ../SharedLib/WebObjectShareLib/include \
    ../SharedLib/ScreenCutShareLib/include \
    ../SharedLib/MacUpdate/include \
    ../SharedLib/breakpad/include \
    ../SharedLib/SettingsManagerShareLib/include
include(OpenPlanet.pri)
include(shared.pri)

HEADERS += \
    myapplication.h

SOURCES += \
    myapplication.cpp \
    main.cpp

DISTFILES +=

RESOURCES += telecomm.qrc
