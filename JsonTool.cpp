#include "JsonTool.h"

QJsonObject JsonTool::readJson(const QString &filePath)
{
    QFile loadFile(filePath);

    if(!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("File can't open");
        return QJsonObject();
    }

    QByteArray jsonData = loadFile.readAll();
    QJsonDocument jDoc = QJsonDocument::fromJson(jsonData);

    if(jDoc.isNull() || !jDoc.isObject())
    {
        qWarning("Json is not valid");
        return QJsonObject();
    }

    return jDoc.object();
}

bool JsonTool::writeJson(const QString &filePath, QJsonObject &jObject)
{
    QFile writeFile(filePath);
    if(!writeFile.open(QIODevice::WriteOnly))
    {
        qWarning("File can't loaded");
        return false;
    }

    QJsonDocument jDoc(jObject);
    writeFile.write(jDoc.toJson());
    writeFile.close();
    return true;
}


