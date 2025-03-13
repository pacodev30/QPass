#pragma once

#include <QString>
#include <QJsonObject>


struct Entry
{
    QString _service;
    QString _username;
    QString _password;

    /**
     * @brief toJson
     * @return
     */
    QJsonObject toJson() const;

    /**
     * @brief fromJson
     * @param jObject
     * @return
     */
    static Entry fromJson(const QJsonObject &jObject);

};
