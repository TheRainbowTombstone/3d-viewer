#include "shape.h"

ShapeModel::ShapeModel(QObject *parent) : QAbstractListModel(parent) {}

int ShapeModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return m_list.count();
}

QVariant ShapeModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_list.size())
        return {};

    const Shape &s = m_list.at(index.row());
    switch (role) {
    case IdRole: return QVariant::fromValue<quint64>(s.id);
    case TypeRole: return s.type;
    case SizeXRole: return s.size.x();
    case SizeYRole: return s.size.y();
    case SizeZRole: return s.size.z();
    case XRole: return s.pos.x();
    case YRole: return s.pos.y();
    case ZRole: return s.pos.z();
    case RRole: return s.color.redF();
    case GRole: return s.color.greenF();
    case BRole: return s.color.blueF();
    default: return {};
    }
}

QHash<int, QByteArray> ShapeModel::roleNames() const {
    QHash<int, QByteArray> rn;
    rn[IdRole] = "id";
    rn[TypeRole] = "type";
    rn[SizeXRole] = "sizeX";
    rn[SizeYRole] = "sizeY";
    rn[SizeZRole] = "sizeZ";
    rn[XRole] = "x";
    rn[YRole] = "y";
    rn[ZRole] = "z";
    rn[RRole] = "r";
    rn[GRole] = "g";
    rn[BRole] = "b";
    return rn;
}

void ShapeModel::clear() {
    beginResetModel();
    m_list.clear();
    endResetModel();
}

void ShapeModel::addShape(const Shape &s) {
    beginInsertRows(QModelIndex(), m_list.count(), m_list.count());
    m_list.append(s);
    endInsertRows();
}

void ShapeModel::removeById(quint64 id) {
    for (int i = 0; i < m_list.size(); ++i) {
        if (m_list[i].id == id) {
            beginRemoveRows(QModelIndex(), i, i);
            m_list.removeAt(i);
            endRemoveRows();
            return;
        }
    }
}


