#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QtView.h"
#include <fstream>



int main(int argc, char *argv[])
{
    std::ofstream fout;
    fout.open("selection.log");
    fout.clear();
    fout.close();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<QtView>("tprk.engine", 1, 0, "QtView");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}