import QtQuick 2.5
import QtQuick.Window 2.0
import "qrc:/qml"

Window {
    visible: true
    Flex {
        height: parent.height
        width: parent.width
        alignSelf: "center"
        justifyContent: "center"
        Text { height: 15; width: 15; text: "1" }
    }
}
