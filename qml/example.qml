import QtQuick 2.5
import QtQuick.Window 2.0

Window {
    visible: true
    height: 400
    width: 675
    Rectangle {
        anchors.fill: parent
        color: "cyan"
        Flex {
            height: parent.height
            width: parent.width
            flexDirection: "row"
            flexWrap: "wrap"
            justifyContent: "spaceAround"
            alignItems: "center"
            alignSelf: "center"
            alignContent: "stretch"
            flexShrink: 10
            Rectangle { color: "green"; height: 150; width: 150 }
            Rectangle { color: "green"; height: 150; width: 150 }
            Rectangle { color: "green"; height: 150; width: 150 }
            Rectangle { color: "green"; height: 150; width: 150 }
            Rectangle { color: "green"; height: 150; width: 150 }
            Rectangle { color: "green"; height: 150; width: 150 }
            Rectangle { color: "green"; height: 150; width: 150 }
        }
    }
}
