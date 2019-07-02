import QtQuick 2.5
import QtQuick.Layouts 1.1
import com.tripolskypetr.quitejs 1.0

Item {
    id: grid
    property var columnDefenition: []
    property var rowDefenition: []
    onChildrenChanged: updatePositions();

    FlexBackend{id: backend}

    function updatePositions() {
        for (var i = 0; i < grid.children.length; ++i) {
            grid.children[i].x = i*50;
            grid.children[i].y = i*60;
        }
    }

    Component.onCompleted: {
        var config = backend.createConfig();
        var node = backend.createNode(config);
        backend.createNode(1);
    }
}
