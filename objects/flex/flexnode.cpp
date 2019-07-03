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

void FlexNode::appendChildren(QVariant node) {
    FlexNode* object = qvariant_cast<FlexNode*>(node);
    std::vector<YGNodeRef> tmp;
    if (object==nullptr) {
        qCritical() << "FlexNode setChildren child not flexnode*";
    } else {
        child.append(object);
        QLinkedList<FlexNode*>::iterator i;
        for (i = child.begin(); i != child.end(); i++) {
            FlexNode* it = (*i);
            tmp.push_back(it->getNode());
        }
        YGNodeSetChildren(this->node,tmp);
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

int FlexNode::getHeight() {
    return static_cast<int>(YGNodeStyleGetHeight(node).value);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMinHeight(int point) {
    YGNodeStyleSetMinHeight(node, static_cast<float>(point));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getWidth() {
    return static_cast<int>(YGNodeStyleGetWidth(node).value);
}

/*---------------------------------------------------------------------------*/

int FlexNode::getMinWidth() {
    return static_cast<int>(YGNodeStyleGetMinWidth(node).value);
}

/*---------------------------------------------------------------------------*/

int FlexNode::getMinHeight() {
    return static_cast<int>(YGNodeStyleGetMinHeight(node).value);
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

int FlexNode::getMarginTop() {
    return static_cast<int>(YGNodeStyleGetMargin(node, YGEdgeTop).value);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginLeft(int point) {
    YGNodeStyleSetMargin(node, YGEdgeLeft, static_cast<float>(point));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getMarginLeft() {
    return static_cast<int>(YGNodeStyleGetMargin(node, YGEdgeLeft).value);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginRight(int point) {
    YGNodeStyleSetMargin(node, YGEdgeRight, static_cast<float>(point));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getMarginRight() {
    return static_cast<int>(YGNodeStyleGetMargin(node, YGEdgeRight).value);
}

/*---------------------------------------------------------------------------*/

void FlexNode::setMarginBottom(int point) {
    YGNodeStyleSetMargin(node, YGEdgeBottom, static_cast<float>(point));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getPaddingTop() {
    return static_cast<int>(YGNodeStyleGetPadding(node, YGEdgeTop).value);
}

/*---------------------------------------------------------------------------*/

int FlexNode::getMarginBottom() {
    return static_cast<int>(YGNodeStyleGetMargin(node, YGEdgeBottom).value);
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

int FlexNode::getPaddingLeft() {
    return static_cast<int>(YGNodeStyleGetPadding(node, YGEdgeLeft).value);
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

int FlexNode::getPaddingRight() {
    return static_cast<int>(YGNodeStyleGetPadding(node, YGEdgeRight).value);
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

int FlexNode::getPaddingBottom() {
    return static_cast<int>(YGNodeStyleGetPadding(node, YGEdgeBottom).value);
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

int FlexNode::getLayoutHeight() {
    return static_cast<int>(YGNodeLayoutGetHeight(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getLayoutWidth() {
    return static_cast<int>(YGNodeLayoutGetWidth(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getLayoutTop() {
    return static_cast<int>(YGNodeLayoutGetTop(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getLayoutLeft() {
    return static_cast<int>(YGNodeLayoutGetLeft(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getLayoutRight() {
    return static_cast<int>(YGNodeLayoutGetRight(node));
}

/*---------------------------------------------------------------------------*/

int FlexNode::getLayoutBottom() {
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

