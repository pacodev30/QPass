#include "JsonTool.h"

QJsonObject JsonTool::readJson(const QString &filePath)
{
    QFile loadFile(filePath);

    if(!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("File not open");
        return QJsonObject();
    }

    QByteArray jsonData = loadFile.readAll();
    QJsonDocument jDoc = QJsonDocument::fromJson(jsonData);

    if(jDoc.isNull() || !jDoc.isObject())
    {
        qWarning("Doc is not valid");
        return QJsonObject();
    }

    return jDoc.object();
}

bool JsonTool::writeJson(const QString &filePath, QJsonObject &jObject)
{
    QFile writeFile(filePath);
    if(!writeFile.open(QIODevice::WriteOnly))
    {
        qWarning("File not loaded");
        return false;
    }

    QJsonDocument writingDoc(jObject);
    writeFile.write(writingDoc.toJson());
    writeFile.close();
    return true;
}

bool JsonTool::setValue(const QString &filePath, const QString &key, const QJsonValue &value)
{
    QJsonObject jObject = readJson(filePath);
    jObject[key] = value;
    return writeJson(filePath, jObject);
}

QJsonValue JsonTool::readKey(const QString &filePath, const QString &key)
{
    QJsonObject jObject = readJson(filePath);
    return jObject.value(key);
}

bool JsonTool::removeKey(const QString &filepath, const QString &key)
{
    QJsonObject jObject = readJson(filepath);
    if(jObject.contains(key))
    {
        jObject.remove(key);
        return writeJson(filepath, jObject);
    }
    return false;
}

void JsonTool::debugJsonObject(const QJsonObject &jObject)
{
    for(auto i = jObject.begin(); i != jObject.end(); i++)
    {
        qDebug() << i.key() << " -> " << i.value().toString();
    }
}

