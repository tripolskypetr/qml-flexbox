#ifndef FLEXNODE_H
#define FLEXNODE_H

#include <QtDebug>
#include <QObject>
#include <QVariant>
#include <QSharedPointer>

#include "objects/flex/flexconfig.h"
#include "third_party/yoga/Yoga.h"

namespace Quite {
namespace Objects {
namespace Flex {

/*****************************************************************************/

class FlexNode : public QObject {
  Q_OBJECT
  Q_PROPERTY(int flexGrow READ getFlexGrow WRITE setFlexGrow)
  private:
    YGNodeRef node;
    FlexConfig* config;
  public:
    FlexNode(FlexConfig* config, QObject* parent = nullptr);
    virtual ~FlexNode();
    YGNodeRef getNode();
  public slots:
    /* child */
    void setChildren(QVariant node);
    void removeChildren(QVariant node);
    /* flex */
    int getFlexGrow();
    int getFlexShrink();
    void setFlexGrow(int v);
    void setFlexShrink(int v);
    /* height */
    void setHeightAuto();
    void setHeight(int point);
    void setMinHeight(int point);
    void setHeightPercent(int percent);
    void setMinHeightPercent(int percent);
    /* width */
    void setWidthAuto();
    void setWidth(int point);
    void setMinWidth(int point);
    void setWidthPercent(int percent);
    void setMinWidthPercent(int percent);
    /* display */
    void setDisplayNone();
    void setDisplayFlex();
    /* flex-direction */
    void setFlexDirectionRow();
    void setFlexDirectionColumn();
    void setFlexDirectionRowReverse();
    void setFlexDirectionColumnReverse();
    /* justify-content */
    void setJustifyCenter();
    void setJustifyFlexEnd();
    void setJustifyFlexStart();
    void setJustifySpaceAround();
    void setJustifySpaceEvenly();
    void setJustifySpaceBetween();
    /* align-content */
    void setAlignContentAuto();
    void setAlignContentCenter();
    void setAlignContentFlexEnd();
    void setAlignContentStretch();
    void setAlignContentBaseline();
    void setAlignContentFlexStart();
    void setAlignContentSpaceAround();
    void setAlignContentSpaceBetween();
    /* align-items */
    void setAlignItemsAuto();
    void setAlignItemsCenter();
    void setAlignItemsFlexEnd();
    void setAlignItemsStretch();
    void setAlignItemsBaseline();
    void setAlignItemsFlexStart();
    void setAlignItemsSpaceAround();
    void setAlignItemsSpaceBetween();
    /* align-self */
    void setAlignSelfAuto();
    void setAlignSelfCenter();
    void setAlignSelfFlexEnd();
    void setAlignSelfStretch();
    void setAlignSelfBaseline();
    void setAlignSelfFlexStart();
    void setAlignSelfSpaceAround();
    void setAlignSelfSpaceBetween();
    /* flex-wrap */
    void setWrap();
    void setNoWrap();
    void setWrapReverser();
    /* margin */
    void setMarginTop(int point);
    void setMarginLeft(int point);
    void setMarginRight(int point);
    void setMarginBottom(int point);
    void setMarginTopPercent(int percent);
    void setMarginLeftPercent(int percent);
    void setMarginRightPercent(int percent);
    void setMarginBottomPercent(int percent);
    /* padding */
    void setPaddingTop(int point);
    void setPaddingLeft(int point);
    void setPaddingRight(int point);
    void setPaddingBottom(int point);
    void setPaddingTopPercent(int percent);
    void setPaddingLeftPercent(int percent);
    void setPaddingRightPercent(int percent);
    void setPaddingBottomPercent(int percent);
    /* calculate */
    int getTop();
    int getLeft();
    int getRight();
    int getWidth();
    int getBottom();
    int getHeight();
    void calculateLayoutRtl(int width, int height);
    void calculateLayoutLtr(int width, int height);
};

/*****************************************************************************/

} // namespace Flex
} // namespace Objects
} // namespace Quite

#endif // FLEXNODE_H
