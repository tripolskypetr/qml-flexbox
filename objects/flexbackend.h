#ifndef FLEXBACKEND_H
#define FLEXBACKEND_H

#include <QtDebug>
#include <QObject>
#include <QVariant>
#include <QQmlContext>

#include "objects/flex/flexconfig.h"
#include "objects/flex/flexnode.h"

#include "third_party/yoga/Yoga.h"

using namespace Quite::Objects::Flex;

namespace Quite {
namespace Objects {

/*****************************************************************************/

/*namespace FlexEnums {
    Q_NAMESPACE
    enum Wrap {
        NoWrap,
        Wrap,
        WrapReverse
    };
    enum FlexDirection {
        FlexDirectionColumn,
        FlexDirectionColumnReverse,
        FlexDirectionRow,
        FlexDirectionRowReverse
    };
}*/

/*****************************************************************************/

class FlexBackend : public QObject {
  Q_OBJECT
  private:
    FlexConfig* config;
  public:
    explicit FlexBackend(QObject* parent = nullptr);
    virtual ~FlexBackend();
  public slots:
    QVariant createConfig();
    QVariant createNode();
    QVariant createNode(QVariant config);
};

/*****************************************************************************/

} // namespace Objects
} // namespace Quite

#endif // FLEXBACKEND_H
