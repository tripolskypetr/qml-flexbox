import QtQuick 2.5
import QtQuick.Window 2.0

Window {
    visible: true

    /*
     * Layout Wrapper. Do not delete if you are using
     * layout tools other than flexbox
     * anchors.fill, Layout.fillHeight, Layout.fillWidth...
     */
    Item {
        anchors.fill: parent

        Flex {
            height: parent.height
            width: parent.width
            alignSelf: "center"
            justifyContent: "center"
            Text { height: 15; width: 15; text: "1" }
        }
    }
}
