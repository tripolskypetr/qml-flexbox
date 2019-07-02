import QtQuick 2.5
import QtQuick.Window 2.0
import "qrc:/qml"

Window {
    visible: true
    Flex {
        anchors.fill: parent
        columnDefenition : ["auto", "1fr", "auto"]
        rowDefenition: ["auto", "1fr", "auto"]
        Text { text: "1"; }
        Text { text: "1"; }
        Text { text: "1"; }
        Text { text: "1"; }
    }
}
