#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>

#include "objects/flexbackend.h"

using namespace Quite::Objects;
using namespace Quite::Objects::Flex;

/*****************************************************************************/

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<FlexBackend>(
        "com.tripolskypetr.quitejs",
        1, 0,
        "FlexBackend"
    );

    QQmlApplicationEngine engine;
    engine.load(QUrl(
        QStringLiteral("qrc:/qml/example.qml"))
    );

    return app.exec();
}

/*****************************************************************************/
