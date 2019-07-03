#ifndef FLEXNODE_H
#define FLEXNODE_H

#include <QtDebug>
#include <QObject>
#include <QVariant>
#include <QJSValue>

#include "objects/flex/flexconfig.h"
#include "third_party/yoga/Yoga.h"

namespace Quite {
namespace Objects {
namespace Flex {

/*****************************************************************************/

class FlexNode : public QObject {
  Q_OBJECT

  Q_PROPERTY(int flexShrink READ getFlexShrink WRITE setFlexShrink)
  Q_PROPERTY(int flexGrow READ getFlexGrow WRITE setFlexGrow)

  Q_PROPERTY(int minHeight READ getHeight WRITE setHeight)
  Q_PROPERTY(int height READ getHeight WRITE setHeight)
  Q_PROPERTY(int minWidth READ getWidth WRITE setWidth)
  Q_PROPERTY(int width READ getWidth WRITE setWidth)

  Q_PROPERTY(int marginTop READ getMarginTop WRITE setMarginTop)
  Q_PROPERTY(int marginLeft READ getMarginLeft WRITE setMarginLeft)
  Q_PROPERTY(int marginRight READ getMarginRight WRITE setMarginRight)
  Q_PROPERTY(int marginBottom READ getMarginBottom WRITE setMarginBottom)

  Q_PROPERTY(int paddingTop READ getPaddingTop WRITE setPaddingTop)
  Q_PROPERTY(int paddingLeft READ getPaddingLeft WRITE setPaddingLeft)
  Q_PROPERTY(int paddingRight READ getPaddingRight WRITE setPaddingRight)
  Q_PROPERTY(int paddingBottom READ getPaddingBottom WRITE setPaddingBottom)

  Q_PROPERTY(int layoutTop READ getLayoutTop)
  Q_PROPERTY(int layoutLeft READ getLayoutLeft)
  Q_PROPERTY(int layoutRight READ getLayoutRight)
  Q_PROPERTY(int layoutBottom READ getLayoutBottom)

  private:
    YGNodeRef node;
    FlexConfig* config;
  public:
    FlexNode(FlexConfig* config, QObject* parent = nullptr);
    virtual ~FlexNode();
    YGNodeRef getNode();
  public slots:
    /* child */
    Q_INVOKABLE void appendChildren(QVariant children);
    /* flex */
    int getFlexGrow();
    int getFlexShrink();
    void setFlexGrow(int v);
    void setFlexShrink(int v);
    /* height */
    int getHeight();
    int getMinHeight();
    void setHeight(int point);
    void setMinHeight(int point);
    /* width */
    int getWidth();
    int getMinWidth();
    void setWidth(int point);
    void setMinWidth(int point);
    /* display */
    Q_INVOKABLE void setDisplayNone();
    Q_INVOKABLE void setDisplayFlex();
    /* flex-direction */
    Q_INVOKABLE void setFlexDirectionRow();
    Q_INVOKABLE void setFlexDirectionColumn();
    Q_INVOKABLE void setFlexDirectionRowReverse();
    Q_INVOKABLE void setFlexDirectionColumnReverse();
    /* justify-content */
    Q_INVOKABLE void setJustifyCenter();
    Q_INVOKABLE void setJustifyFlexEnd();
    Q_INVOKABLE void setJustifyFlexStart();
    Q_INVOKABLE void setJustifySpaceAround();
    Q_INVOKABLE void setJustifySpaceEvenly();
    Q_INVOKABLE void setJustifySpaceBetween();
    /* align-content */
    Q_INVOKABLE void setAlignContentAuto();
    Q_INVOKABLE void setAlignContentCenter();
    Q_INVOKABLE void setAlignContentFlexEnd();
    Q_INVOKABLE void setAlignContentStretch();
    Q_INVOKABLE void setAlignContentBaseline();
    Q_INVOKABLE void setAlignContentFlexStart();
    Q_INVOKABLE void setAlignContentSpaceAround();
    Q_INVOKABLE void setAlignContentSpaceBetween();
    /* align-items */
    Q_INVOKABLE void setAlignItemsAuto();
    Q_INVOKABLE void setAlignItemsCenter();
    Q_INVOKABLE void setAlignItemsFlexEnd();
    Q_INVOKABLE void setAlignItemsStretch();
    Q_INVOKABLE void setAlignItemsBaseline();
    Q_INVOKABLE void setAlignItemsFlexStart();
    Q_INVOKABLE void setAlignItemsSpaceAround();
    Q_INVOKABLE void setAlignItemsSpaceBetween();
    /* align-self */
    Q_INVOKABLE void setAlignSelfAuto();
    Q_INVOKABLE void setAlignSelfCenter();
    Q_INVOKABLE void setAlignSelfFlexEnd();
    Q_INVOKABLE void setAlignSelfStretch();
    Q_INVOKABLE void setAlignSelfBaseline();
    Q_INVOKABLE void setAlignSelfFlexStart();
    Q_INVOKABLE void setAlignSelfSpaceAround();
    Q_INVOKABLE void setAlignSelfSpaceBetween();
    /* flex-wrap */
    Q_INVOKABLE void setWrap();
    Q_INVOKABLE void setNoWrap();
    Q_INVOKABLE void setWrapReverser();
    /* margin */
    int getMarginTop();
    int getMarginLeft();
    int getMarginRight();
    int getMarginBottom();
    void setMarginTop(int point);
    void setMarginLeft(int point);
    void setMarginRight(int point);
    void setMarginBottom(int point);
    /* padding */
    int getPaddingTop();
    int getPaddingLeft();
    int getPaddingRight();
    int getPaddingBottom();
    void setPaddingTop(int point);
    void setPaddingLeft(int point);
    void setPaddingRight(int point);
    void setPaddingBottom(int point);
    /* calculate */
    int getLayoutTop();
    int getLayoutLeft();
    int getLayoutRight();
    int getLayoutWidth();
    int getLayoutBottom();
    int getLayoutHeight();
    Q_INVOKABLE void calculateLayoutRtl(int width, int height);
    Q_INVOKABLE void calculateLayoutLtr(int width, int height);
  private:
    static bool tryCast(QJSValue src, FlexNode*& dst);
};

/*****************************************************************************/

} // namespace Flex
} // namespace Objects
} // namespace Quite

#endif // FLEXNODE_H
