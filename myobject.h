#pragma once

#include <QString>
#include <QMetaType>

struct MyObject {
    int id;
    int a;
    double b;
    QString c;
};

Q_DECLARE_METATYPE(MyObject)
