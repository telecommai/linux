#include <QtWidgets/QApplication>
#include <QResource>
#include <qsharedmemory.h>
#include "opobjectmanager.h"
#include "inline_mac.h"
#include "myapplication.h"
#include "mycommonstyle.h"
/*#include <client/mac/handler/exception_handler.h>

bool minidumpCB(const char* dump_path, const char* id, void* context, bool succeeded)
{
    if (succeeded)
    {
     //   qDebug() << "Mini Dump file: " << id << ".dump Path: " << dump_path ;
    }
    return succeeded;
}*/

void initEnv()
{
    //将默认启动的webengine的exe名字改为OpenPlanetHelper.exe
    QString webEngineViewProcessPath = QCoreApplication::applicationDirPath() + "/libexec/" + "QtWebEngineProcess";
    qDebug()<<" webEngineViewProcessPath "<<webEngineViewProcessPath;
    qputenv("QTWEBENGINEPROCESS_PATH", webEngineViewProcessPath.toLocal8Bit());
   // qDebug()<< "webEngineViewProcessPath" << qgetenv("QTWEBENGINEPROCESS_PATH");
}

int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    myApplication imchat(argc, argv);
#ifdef Q_OS_LINUX
   //initEnv();
#endif
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    imchat.setStyle(new MyProxyStyle);
  //  google_breakpad::ExceptionHandler eh(QDir::currentPath().toStdString(), NULL, minidumpCB, NULL, true, NULL);
    QResource::registerResource("resources.rcc");
    imchat.setQuitOnLastWindowClosed(false);
    OPObjectManager objectManager;

    QObject::connect(&imchat,SIGNAL(sigClickedDock()),&objectManager,SIGNAL(sigClickedDock()));
    QObject::connect(&imchat,SIGNAL(sigGlobalMouseMouse()),&objectManager,SIGNAL(sigGlobalMouseMouse()));

    objectManager.InitApp();
    AppConfig appConfig = objectManager.readAppConf(); //读取配置文件

    objectManager.initLanguage();

    //载入代理设置。
    LoginDatabaseOperaShareLib *database = new LoginDatabaseOperaShareLib;
    QString strPath = getResourcePath() + "database//common.db";
    database->ConnectLoginDB(strPath, "Login");
    NetWorkProxyInfo info = database->GetNetWorkProxyInfoDB();
    if (info.proxyModel != 0)
    {
        if (!info.strAddress.isEmpty() && info.strPort != "0")
        {
            QNetworkProxy proxy;
            proxy.setType(QNetworkProxy::HttpProxy);
            proxy.setHostName(info.strAddress);
            proxy.setPort(info.strPort.toInt());
            proxy.setUser(info.strUserName);
            proxy.setPassword(info.strUserPwd);
            QNetworkProxy::setApplicationProxy(proxy);
        }
    }
    delete database;
    objectManager.update();     //判断是否升级
    int nFlag = imchat.exec();
    return nFlag;
}
