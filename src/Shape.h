#pragma once
#include <QAbstractListModel>
#include <QVector3D>
#include <QColor>
#include <QString>
#include <QList>

struct Shape {
    quint32 id;
    QString type;
    QVector3D size;
    QVector3D pos;
    QColor color;
};

class ShapeModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        TypeRole,
        SizeXRole,
        SizeYRole,
        SizeZRole,
        XRole,
        YRole,
        ZRole,
        RRole,
        GRole,
        BRole
    };

    explicit ShapeModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void clear();
    void addShape(const Shape &s);
    void removeById(quint64 id);

private:
    QList<Shape> m_list;
};
