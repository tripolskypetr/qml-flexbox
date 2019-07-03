import QtQuick 2.5
import QtQuick.Layouts 1.1
import com.tripolskypetr.quitejs 1.0

Item {
    id: grid
    property var columnDefenition: []
    property var rowDefenition: []
    onChildrenChanged: updatePositions();

    FlexBackend{ id: backend }

    function updatePositions() {

        //var rootNode = backend.createNode();

        for (var i = 0; i < grid.children.length; ++i) {

            //var node = backend.createNode();

            grid.children[i].x = i*50;
            grid.children[i].y = i*60;
        }
    }

    Component.onCompleted: {
        var node = backend.createNode();
        node.flexGrow=1488;
        node.height = 14;
        node.setDisplayFlex();
        console.log(JSON.stringify(node))
    }
}
