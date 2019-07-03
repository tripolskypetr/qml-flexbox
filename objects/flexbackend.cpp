#include "flexbackend.h"

namespace Quite {
namespace Objects {

/*****************************************************************************/

FlexBackend::FlexBackend(QObject *parent)
  : QObject(parent) {
    qDebug() << "FlexBackend ctor";
    config = new FlexConfig(this);
}

/*---------------------------------------------------------------------------*/

FlexBackend::~FlexBackend() {
    qDebug() << "FlexBackend dtor";
}

/*---------------------------------------------------------------------------*/

QVariant FlexBackend::createNode(QVariant config) {
    FlexConfig* object = qvariant_cast<FlexConfig*>(config);
    QVariant result;
    if (object==nullptr) {
        qCritical() << "FlexBackend createNode config not flexconfig*";
    } else {
        result = QVariant::fromValue(new FlexNode(object, this));
    }
    return result;
}

/*---------------------------------------------------------------------------*/

void FlexBackend::collectGarbage(QVariant rootNode) {
    FlexNode* node = qvariant_cast<FlexNode*>(rootNode);
    if (node==nullptr) {
        qCritical() << "FlexBackend collectGarbage node to FlexNode*";
    } else {
        node->deleteLater();
    }
}

/*---------------------------------------------------------------------------*/

QVariant FlexBackend::createConfig() {
    return QVariant::fromValue(new FlexConfig(this));
}

/*---------------------------------------------------------------------------*/

QVariant FlexBackend::createNode() {
    return QVariant::fromValue(new FlexNode(config, this));
}

/*****************************************************************************/

} // namespace Objects
} // namespace Quite
