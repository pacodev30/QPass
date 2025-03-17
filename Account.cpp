#include "Account.h"

QJsonObject Account::toJson() const
{
    QJsonObject jObject;
    jObject[SERVICE] = _service;
    jObject[USERNAME] = _username;
    jObject[PASSWORD] = _password;
    return jObject;
}

Account Account::fromJson(const QJsonObject &jObject)
{
    return
    {
        jObject[SERVICE].toString(),
        jObject[USERNAME].toString(),
        jObject[PASSWORD].toString()
    };
}
