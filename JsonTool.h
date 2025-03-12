#pragma once

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>


class JsonTool
{
public:
    static QJsonObject readJson(const QString &filePath);
    static bool writeJson(const QString &filePath, QJsonObject &jObject);
    static bool setValue(const QString &filePath, const QString &key, const QJsonValue &value);

    static QJsonValue readKey(const QString &filePath, const QString &key);
    static bool removeKey(const QString &filepath, const QString &key);

    static void debugJsonObject(const QJsonObject &jObject);
};
