#pragma once
#include <QObject>
#include "shape.h"

class SceneManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(ShapeModel* model READ model CONSTANT)
public:
    explicit SceneManager(QObject *parent = nullptr);
    ShapeModel* model() { return &m_model; }

    Q_INVOKABLE void addShapes(const QString &type, int w, int h, int d, int count);
    Q_INVOKABLE void clearAll();
    Q_INVOKABLE void delById(quint64 id);
    Q_INVOKABLE void pick(quint64 id);

signals:
    void shapeAdded(QVariant p);
    void shapeRemoved(QVariant id);
    void shapePicked(QVariant id);

private:
    ShapeModel m_model;
};
