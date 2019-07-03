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

void FlexNode::setChildren(QVariant node) {
    FlexNode* object = qvariant_cast<FlexNode*>(node);
    if (object==nullptr) {
        qCritical() << "FlexNode setChildren child not flexnode*";
    } else {
        object->setParent(this);
        std::vector<YGNodeRef> child = { object->getNode() };
        YGNodeSetChildren(this->node,child);
    }
}

/*---------------------------------------------------------------------------*/

void FlexNode::removeChildren(QVariant node) {
    FlexNode* object = qvariant_cast<FlexNode*>(node);
    if (object==nullptr) {
        qCritical() << "FlexNode removeChildren child not flexnode*";
    } else {
        object->setParent(nullptr);
        YGNodeRemoveChild(this->node, object->getNode());
    }
}

/*---------------------------------------------------------------------------*/

void FlexNode::setFlexGrow(int v) {
    YGNodeStyleSetFlexGrow(node, static_cast<float>(v));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getFlexGrow() {
    return static_cast<int>(YGNodeStyleGetFlexGrow(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getFlexShrink() {
    return static_cast<int>(YGNodeStyleGetFlexShrink(node));
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

void FlexNode::setMinHeight(int point) {
    YGNodeStyleSetMinHeight(node, static_cast<float>(point));
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

void FlexNode::setMinHeightPercent(int percent) {
    YGNodeStyleSetMinHeightPercent(node, static_cast<float>(percent));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setWidth(int points) {
    YGNodeStyleSetWidth(node, static_cast<float>(points));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMinWidth(int point) {
    YGNodeStyleSetMinWidth(node, static_cast<float>(point));
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

void FlexNode::setMinWidthPercent(int percent) {
    YGNodeStyleSetMinWidthPercent(node, static_cast<float>(percent));
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

void FlexNode::setMarginTop(int point) {
    YGNodeStyleSetMargin(node, YGEdgeTop, static_cast<float>(point));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginTopPercent(int percent) {
    YGNodeStyleSetMarginPercent(
        node,
        YGEdgeTop,
        static_cast<float>(percent)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginLeft(int point) {
    YGNodeStyleSetMargin(node, YGEdgeLeft, static_cast<float>(point));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginLeftPercent(int percent) {
    YGNodeStyleSetMarginPercent(node, YGEdgeLeft, static_cast<float>(percent));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginRight(int point) {
    YGNodeStyleSetMargin(node, YGEdgeRight, static_cast<float>(point));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginRightPercent(int percent) {
    YGNodeStyleSetMarginPercent(
        node,
        YGEdgeRight,
        static_cast<float>(percent)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginBottom(int point) {
    YGNodeStyleSetMargin(node, YGEdgeBottom, static_cast<float>(point));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginBottomPercent(int percent) {
    YGNodeStyleSetMarginPercent(
        node,
        YGEdgeBottom,
        static_cast<float>(percent)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setPaddingTop(int point) {
    YGNodeStyleSetPadding(
        node,
        YGEdgeTop,
        static_cast<float>(point)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setPaddingLeft(int point) {
    YGNodeStyleSetPadding(
        node,
        YGEdgeLeft,
        static_cast<float>(point)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setPaddingRight(int point) {
    YGNodeStyleSetPadding(
        node,
        YGEdgeRight,
        static_cast<float>(point)
                );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setPaddingBottom(int point) {
    YGNodeStyleSetPadding(
        node,
        YGEdgeBottom,
        static_cast<float>(point)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setPaddingTopPercent(int percent) {
    YGNodeStyleSetPaddingPercent(
        node,
        YGEdgeTop,
        static_cast<float>(percent)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setPaddingLeftPercent(int percent) {
    YGNodeStyleSetPaddingPercent(
        node,
        YGEdgeLeft,
        static_cast<float>(percent)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setPaddingRightPercent(int percent) {
    YGNodeStyleSetPaddingPercent(
        node,
        YGEdgeRight,
        static_cast<float>(percent)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::setPaddingBottomPercent(int percent) {
    YGNodeStyleSetPaddingPercent(
        node,
        YGEdgeBottom,
        static_cast<float>(percent)
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::calculateLayoutLtr(int width, int height) {
    YGNodeCalculateLayout(
        node,
        static_cast<float>(width),
        static_cast<float>(height),
        YGDirectionLTR
    );
}

/*---------------------------------------------------------------------------*/

void FlexNode::calculateLayoutRtl(int width, int height) {
    YGNodeCalculateLayout(
        node,
        static_cast<float>(width),
        static_cast<float>(height),
        YGDirectionRTL
    );
}

/*---------------------------------------------------------------------------*/

int FlexNode::getHeight() {
    return static_cast<int>(YGNodeLayoutGetHeight(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getWidth() {
    return static_cast<int>(YGNodeLayoutGetWidth(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getTop() {
    return static_cast<int>(YGNodeLayoutGetTop(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getLeft() {
    return static_cast<int>(YGNodeLayoutGetLeft(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getRight() {
    return static_cast<int>(YGNodeLayoutGetRight(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getBottom() {
    return static_cast<int>(YGNodeLayoutGetBottom(node));
}

/*---------------------------------------------------------------------------*/

void FlexNode::setJustifySpaceAround() {
    YGNodeStyleSetJustifyContent(node, YGJustifySpaceAround);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setJustifySpaceEvenly() {
    YGNodeStyleSetJustifyContent(node, YGJustifySpaceEvenly);
}

/*****************************************************************************/

} // namespace Flex
} // namespace Objects
} // namespace Quite

