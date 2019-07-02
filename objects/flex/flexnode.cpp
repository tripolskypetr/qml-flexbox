#include "flexnode.h"

namespace Quite {
namespace Objects {
namespace Flex {

/*****************************************************************************/

FlexNode::FlexNode(FlexConfig* config, QObject* parent)
  : QObject(parent) {
    qDebug() << "FlexNode ctor";
    node = YGNodeNewWithConfig(config->getConfig());
    this->config = config;
}

/*---------------------------------------------------------------------------*/

FlexNode::~FlexNode() {
    qDebug() << "FlexNode dtor";
    YGNodeFree(node);
}

/*---------------------------------------------------------------------------*/

YGNodeRef FlexNode::getNode() {
    return node;
}

/*---------------------------------------------------------------------------*/

void FlexNode::setChildren(FlexNode *node) {
    std::vector<YGNodeRef> child = { node->getNode() };
    YGNodeSetChildren(this->node,child);
}

/*---------------------------------------------------------------------------*/

void FlexNode::removeChildren(FlexNode *node) {
    YGNodeRemoveChild(this->node, node->getNode());
}

/*---------------------------------------------------------------------------*/

void FlexNode::setFlexGrow(int v) {
    YGNodeStyleSetFlexGrow(node, static_cast<float>(v));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setFlexShrink(int v){
    YGNodeStyleSetFlexShrink(node, static_cast<float>(v));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setHeight(int points) {
    YGNodeStyleSetHeight(node, static_cast<float>(points));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setHeightAuto() {
    YGNodeStyleSetHeightAuto(node);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setHeightPercent(int percent) {
    YGNodeStyleSetHeightPercent(node, static_cast<float>(percent));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setWidth(int points) {
    YGNodeStyleSetWidth(node, static_cast<float>(points));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setWidthAuto() {
    YGNodeStyleSetWidthAuto(node);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setWidthPercent(int percent) {
    YGNodeStyleSetWidthPercent(node, static_cast<float>(percent));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setDisplayNone() {
    YGNodeStyleSetDisplay(node, YGDisplayNone);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setDisplayFlex() {
    YGNodeStyleSetDisplay(node, YGDisplayFlex);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setFlexDirectionRow() {
    YGNodeStyleSetFlexDirection(node, YGFlexDirectionRow);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setFlexDirectionRowReverse() {
    YGNodeStyleSetFlexDirection(node, YGFlexDirectionRowReverse);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setFlexDirectionColumn() {
    YGNodeStyleSetFlexDirection(node, YGFlexDirectionColumn);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setFlexDirectionColumnReverse() {
    YGNodeStyleSetFlexDirection(node, YGFlexDirectionColumnReverse);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setJustifyFlexStart() {
    YGNodeStyleSetJustifyContent(node, YGJustifyFlexStart);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setJustifyCenter() {
    YGNodeStyleSetJustifyContent(node, YGJustifyCenter);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setJustifyFlexEnd(){
    YGNodeStyleSetJustifyContent(node, YGJustifyFlexEnd);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setJustifySpaceBetween() {
    YGNodeStyleSetJustifyContent(node, YGJustifySpaceBetween);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignContentAuto() {
    YGNodeStyleSetAlignContent(node, YGAlignAuto);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignContentCenter() {
    YGNodeStyleSetAlignContent(node, YGAlignCenter);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignContentFlexEnd() {
    YGNodeStyleSetAlignContent(node, YGAlignFlexEnd);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignContentStretch() {
    YGNodeStyleSetAlignContent(node, YGAlignStretch);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignContentBaseline() {
    YGNodeStyleSetAlignContent(node, YGAlignBaseline);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignContentFlexStart() {
    YGNodeStyleSetAlignContent(node, YGAlignFlexStart);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignContentSpaceAround() {
    YGNodeStyleSetAlignContent(node, YGAlignSpaceAround);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignContentSpaceBetween() {
    YGNodeStyleSetAlignContent(node, YGAlignSpaceBetween);
}

void FlexNode::setAlignItemsAuto() {
    YGNodeStyleSetAlignItems(node, YGAlignAuto);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignItemsCenter() {
    YGNodeStyleSetAlignItems(node, YGAlignCenter);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignItemsFlexEnd() {
    YGNodeStyleSetAlignItems(node, YGAlignCenter);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignItemsStretch() {
    YGNodeStyleSetAlignItems(node, YGAlignStretch);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignItemsBaseline() {
    YGNodeStyleSetAlignItems(node, YGAlignBaseline);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignItemsFlexStart() {
    YGNodeStyleSetAlignItems(node, YGAlignFlexStart);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignItemsSpaceAround() {
    YGNodeStyleSetAlignItems(node, YGAlignSpaceAround);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignItemsSpaceBetween() {
    YGNodeStyleSetAlignItems(node, YGAlignSpaceBetween);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignSelfAuto() {
    YGNodeStyleSetAlignItems(node, YGAlignAuto);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignSelfCenter() {
    YGNodeStyleSetAlignItems(node, YGAlignCenter);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignSelfFlexEnd() {
    YGNodeStyleSetAlignItems(node, YGAlignFlexEnd);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignSelfStretch() {
    YGNodeStyleSetAlignItems(node, YGAlignStretch);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignSelfBaseline() {
    YGNodeStyleSetAlignItems(node, YGAlignBaseline);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignSelfFlexStart() {
    YGNodeStyleSetAlignItems(node, YGAlignFlexStart);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignSelfSpaceAround(){
    YGNodeStyleSetAlignItems(node, YGAlignSpaceAround);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setAlignSelfSpaceBetween() {
    YGNodeStyleSetAlignItems(node, YGAlignSpaceBetween);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setWrap() {
    YGNodeStyleSetFlexWrap(node, YGWrapWrap);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setNoWrap() {
    YGNodeStyleSetFlexWrap(node, YGWrapNoWrap);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setWrapReverser() {
    YGNodeStyleSetFlexWrap(node, YGWrapWrapReverse);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setJustifySpaceAround() {
    YGNodeStyleSetJustifyContent(node, YGJustifySpaceAround);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setJustifySpaceEvenly() {
    YGNodeStyleSetJustifyContent(node, YGJustifySpaceEvenly);
}

/*---------------------------------------------------------------------------*/


/*****************************************************************************/

} // namespace Flex
} // namespace Objects
} // namespace Quite

