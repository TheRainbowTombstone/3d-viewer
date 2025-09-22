
#include "scene_manager.h"
#include <QRandomGenerator>

SceneManager::SceneManager(QObject *parent)
    : QObject(parent) {}

void SceneManager::addShapes(const QString &type, int w, int h, int d, int count) {
    for (int i = 0; i < count; ++i) {
        Shape s;
        s.id = QRandomGenerator::global()->generate();
        s.type = type;
        s.size = QVector3D(w, h, d);

        float px = qRound(((QRandomGenerator::global()->generateDouble() * 400.0) - 200.0) * 100.0) / 100.0;
        float pz = qRound(((QRandomGenerator::global()->generateDouble() * 400.0) - 200.0) * 100.0) / 100.0;
        float py = h / 2.0f;
        s.pos = QVector3D(px, py, pz);

        s.color = QColor::fromRgbF(
            QRandomGenerator::global()->generateDouble(),
            QRandomGenerator::global()->generateDouble(),
            QRandomGenerator::global()->generateDouble()
        );

        m_model.addShape(s);

        QVariantMap map;
        map["id"] = QVariant::fromValue<quint64>(s.id);
        map["type"] = s.type;
        map["sizeX"] = s.size.x();
        map["sizeY"] = s.size.y();
        map["sizeZ"] = s.size.z();
        map["posX"] = s.pos.x();
        map["posY"] = s.pos.y();
        map["posZ"] = s.pos.z();
        map["r"] = s.color.redF();
        map["g"] = s.color.greenF();
        map["b"] = s.color.blueF();

        emit shapeAdded(QVariant(map));
    }
}

void SceneManager::clearAll() {
    QList<quint64> ids;
    for (int i = 0; i < m_model.rowCount(); ++i)
        ids.append(m_model.data(m_model.index(i), ShapeModel::IdRole).toULongLong());

    m_model.clear();
    for (auto id : ids) emit shapeRemoved(id);
}

void SceneManager::delById(quint64 id) {
    m_model.removeById(id);
    emit shapeRemoved(QVariant(id));
}


void SceneManager::pick(quint64 id) {
    emit shapePicked(QVariant(id));
}
