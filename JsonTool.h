#pragma once

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>


class JsonTool
{
public:
    /**
     * @brief readJson
     * @param filePath
     * @return
     */
    static QJsonObject readJson(const QString &filePath);

    /**
     * @brief writeJson
     * @param filePath
     * @param jObject
     * @return
     */
    static bool writeJson(const QString &filePath, QJsonObject &jObject);

    /**
     * @brief setValue
     * @param filePath
     * @param key
     * @param value
     * @return
     */
    static bool setValue(const QString &filePath, const QString &key, const QJsonValue &value);

    /**
     * @brief readKey
     * @param filePath
     * @param key
     * @return
     */
    static QJsonValue readKey(const QString &filePath, const QString &key);

    /**
     * @brief removeKey
     * @param filepath
     * @param key
     * @return
     */
    static bool removeKey(const QString &filepath, const QString &key);

    /**
     * @brief debugJsonObject
     * @param jObject
     */
    static void debugJsonObject(const QJsonObject &jObject);
};
