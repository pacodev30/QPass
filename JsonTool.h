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
};
