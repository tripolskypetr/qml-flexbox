#ifndef FLEXCONFIG_H
#define FLEXCONFIG_H

#include <QtDebug>
#include <QObject>

#include "third_party/yoga/Yoga.h"

namespace Quite {
namespace Objects {
namespace Flex {

/*****************************************************************************/

class FlexConfig : public QObject {
  Q_OBJECT
  private:
    YGConfigRef config;
  public:
    explicit FlexConfig(QObject* parent = nullptr);
    virtual ~FlexConfig();
    YGConfigRef getConfig() const;
};

/*****************************************************************************/

} // namespace Flex
} // namespace Objects
} // namespace Quite

#endif // FLEXCONFIG_H
