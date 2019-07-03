import QtQuick 2.10
import QtQuick.Layouts 1.1
import com.tripolskypetr.quitejs 1.0

Item {
    id: flex

    property int minHeight: 0
    property int minWidth: 0

    property int flexShrink: 0
    property int flexGrow: 0

    property int marginTop: 0
    property int marginLeft: 0
    property int marginRight: 0
    property int marginBottom: 0

    property int paddingTop: 0
    property int paddingLeft: 0
    property int paddingRight: 0
    property int paddingBottom: 0

    property string alignContent: "auto"
    property string alignItems: "auto"
    property string alignSelf: "auto"

    property string justifyContent: "spaceBetween"

    property string display: "flex"

    property string flexWrap: "noWrap"

    FlexBackend{ id: backend }

    function isFlex(child) {
        if (typeof child.flexShrink === 'undefined') {
            return false;
        } else if (typeof child.flexGrow === 'undefined') {
            return false;
        } else if (typeof child.minHeight === 'undefined') {
            return false;
        } else if (typeof child.minWidth === 'undefined') {
            return false;
        } else if (typeof child.marginTop === 'undefined') {
            return false;
        } else if (typeof child.marginLeft === 'undefined') {
            return false;
        } else if (typeof child.marginRight === 'undefined') {
            return false;
        } else if (typeof child.marginBottom === 'undefined') {
            return false;
        } else if (typeof child.paddingTop === 'undefined') {
            return false;
        } else if (typeof child.paddingLeft === 'undefined') {
            return false;
        } else if (typeof child.paddingRight === 'undefined') {
            return false;
        } else if (typeof child.paddingBottom === 'undefined') {
            return false;
        } else if (typeof child.alignContent === 'undefined') {
            return false;
        } else if (typeof child.alignItems === 'undefined') {
            return false;
        } else if (typeof child.alignSelf === 'undefined') {
            return false;
        } else if (typeof child.justifyContent === 'undefined') {
            return false;
        } else if (typeof child.display === 'undefined') {
            return false;
        } else if (typeof child.flexWrap === 'undefined') {
            return false;
        }  else {
            return true;
        }
    }

    function setAlignContent(child, node) {
        var align = child.alignContent;
        if (align === "auto") {
            node.setAlignContentAuto();
        } else if (align === "flexStart") {
            node.setAlignContentFlexStart();
        } else if (align === "center") {
            node.setAlignContentCenter();
        } else if (align === "flexEnd") {
            node.setAlignContentFlexEnd();
        } else if (align === "stretch") {
            node.setAlignContentStretch();
        } else if (align === "baseline") {
            node.setAlignContentBaseline();
        } else if (align === "spaceBetween") {
            node.setAlignContentSpaceBetween();
        } else if (align === "spaceAround") {
            node.setAlignContentSpaceAround();
        } else {
            debugger;
        }
    }

    function setAlignItems(child, node) {
        var align = child.alignItems;
        if (align === "auto") {
            node.setAlignItemsAuto();
        } else if (align === "flexStart") {
            node.setAlignItemsFlexStart();
        } else if (align === "center") {
            node.setAlignItemsCenter();
        } else if (align === "flexEnd") {
            node.setAlignItemsFlexEnd();
        } else if (align === "stretch") {
            node.setAlignItemsStretch();
        } else if (align === "baseline") {
            node.setAlignItemsBaseline();
        } else if (align === "spaceBetween") {
            node.setAlignItemsSpaceBetween();
        } else if (align === "spaceAround") {
            node.setAlignItemsSpaceAround();
        } else {
            debugger;
        }
    }

    function setAlignSelf(child, node) {
        var align = child.alignSelf;
        if (align === "auto") {
            node.setAlignSelfAuto();
        } else if (align === "flexStart") {
            node.setAlignSelfFlexStart();
        } else if (align === "center") {
            node.setAlignSelfCenter();
        } else if (align === "flexEnd") {
            node.setAlignSelfFlexEnd();
        } else if (align === "stretch") {
            node.setAlignSelfStretch();
        } else if (align === "baseline") {
            node.setAlignSelfBaseline();
        } else if (align === "spaceBetween") {
            node.setAlignSelfSpaceBetween();
        } else if (align === "spaceAround") {
            node.setAlignSelfSpaceAround();
        } else {
            debugger;
        }
    }

    function setDisplay(child, node) {
        var display = child.display;
        if (display==="flex") {
            node.setDisplayFlex();
        } else if (display==="none") {
            node.setDisplayNone();
        } else {
            debugger;
        }
    }

    function setJustifyContent(child, node){
        var justify = child.justifyContent;
        if (justify==="center") {
            node.setJustifyCenter();
        } else if (justify==="flexEnd") {
            node.setJustifyFlexEnd();
        } else if (justify==="flexStart") {
            node.setJustifyFlexStart();
        } else if (justify==="spaceAround") {
            node.setJustifySpaceAround();
        } else if (justify==="spaceEvenly") {
            node.setJustifySpaceEvenly();
        } else if (justify==="spaceBetween") {
            node.setJustifySpaceBetween();
        } else {
            debugger;
        }
    }

    function setFlexWrap(child, node){
        var wrap = child.flexWrap;
        if (wrap==="wrap") {
            node.setWrap();
        } else if (wrap==="noWrap") {
            node.setNoWrap();
        } else if (wrap==="wrapReverser") {
            node.setWrapReverser();
        } else {
            debugger;
        }
    }

    function updatePositions() {

        var rootNode = backend.createNode();
        var childs = []
        var nodes = []

        for (var i = 0; i < flex.children.length; ++i) {
            var node = backend.createNode();
            var child = flex.children[i];
            if (isFlex(child)) {
                setJustifyContent(child, node);
                setAlignContent(child, node);
                setAlignItems(child, node);
                setAlignSelf(child, node);
                setFlexWrap(child, node);
                setDisplay(child, node);
            } else {
                node.height = child.height;
                node.width = child.width;
            }
            childs.push(child);
            nodes.push(node);
            rootNode.appendChildren(node);
            //grid.children[i].x = i*50;
            //grid.children[i].y = i*60;
        }
    }

    Component.onCompleted: updatePositions();
    onChildrenChanged: updatePositions();
}
