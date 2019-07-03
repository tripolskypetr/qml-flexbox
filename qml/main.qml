import QtQuick 2.5
import QtQuick.Window 2.0
import "qrc:/qml"

Window {
    visible: true
    Rectangle {
        color: "green"
        height: 200
        width: 200
        Flex {
            alignSelf: "center"
            justifyContent: "center"
            height: 200
            width: 200
            Text { height: 15; width: 15; text: "1" }
        }
    }


}
