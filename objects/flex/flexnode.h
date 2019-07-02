#ifndef FLEXNODE_H
#define FLEXNODE_H

#include <QtDebug>
#include <QObject>
#include <QSharedPointer>

#include "objects/flex/flexconfig.h"
#include "third_party/yoga/Yoga.h"

namespace Quite {
namespace Objects {
namespace Flex {

/*****************************************************************************/

class FlexNode : public QObject {
  Q_OBJECT
  private:
    YGNodeRef node;
    FlexConfig* config;
  public:
    FlexNode(FlexConfig* config, QObject* parent = nullptr);
    virtual ~FlexNode();
    YGNodeRef getNode();
  public slots:
    void setChildren(FlexNode* node);
    void removeChildren(FlexNode* node);
    void setFlexGrow(int v);
    void setFlexShrink(int v);
    /* height */
    void setHeightAuto();
    void setHeight(int point);
    void setHeightPercent(int percent);
    /* width */
    void setWidthAuto();
    void setWidth(int point);
    void setWidthPercent(int percent);
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
    /* align items */
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




};

/*****************************************************************************/

} // namespace Flex
} // namespace Objects
} // namespace Quite

#endif // FLEXNODE_H
