#include "Entry.h"

QJsonObject Entry::toJson() const
{
    QJsonObject jObject;
    jObject["Service"] = _service;
    jObject["Username"] = _username;
    jObject["Password"] = _password;
    return jObject;
}

Entry Entry::fromJson(const QJsonObject &jObject)
{
    return
    {
        jObject["Service"].toString(),
        jObject["Username"].toString(),
        jObject["Service"].toString()
    };
}
