#pragma once

#include <QString>
#include <QJsonObject>


struct Entry
{
    QString _service;
    QString _username;
    QString _password;

    QJsonObject toJson() const;
    static Entry fromJson(const QJsonObject &jObject);

};
