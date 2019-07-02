#include "flexconfig.h"

namespace Quite {
namespace Objects {
namespace Flex {

/*****************************************************************************/

FlexConfig::FlexConfig(QObject *parent)
  : QObject(parent) {
    qDebug() << "FlexConfig ctor";
    config = YGConfigNew();
}

/*---------------------------------------------------------------------------*/

FlexConfig::~FlexConfig() {
    qDebug() << "FlexConfig dtor";
    YGConfigFree(config);
}

/*---------------------------------------------------------------------------*/

YGConfigRef FlexConfig::getConfig() const {
    return config;
}

/*****************************************************************************/

} // namespace Flex
} // namespace Objects
} // namespace Quite
