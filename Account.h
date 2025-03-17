#pragma once
#include <Includes.h>
#include <QString>
#include <QJsonObject>


struct Account
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
    static Account fromJson(const QJsonObject &jObject);

};
