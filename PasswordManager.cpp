#include "PasswordManager.h"

PasswordManager::PasswordManager(QWidget *parent)
    : QWidget{parent}
{}

Account PasswordManager::getAccount(const QString &filepath, const QString &service)
{
    QJsonObject jObject = JsonTool::readJson(filepath);
    QJsonArray accountsArray = jObject[ACCOUNTS].toArray();

    for(const QJsonValue &entry : std::as_const(accountsArray))
    {
        Account account = Account::fromJson(entry.toObject());
        if(account._service == service)
            return account;
    }
    return {};
}

bool PasswordManager::addAccount(const QString &filepath, const Account &account)
{
    QJsonObject jObject = JsonTool::readJson(filepath);
    QJsonArray accountsArray = jObject[ACCOUNTS].toArray();

    accountsArray.append(account.toJson());
    jObject[ACCOUNTS] = accountsArray;
    JsonTool::writeJson(filepath, jObject);
    return true;
}

bool PasswordManager::removeAccount(const QString &filePath, const QString &service)
{
    QJsonObject rootObject = JsonTool::readJson(filePath);
    QJsonArray accounts = rootObject[ACCOUNTS].toArray();
    QJsonArray newAccounts;

    for (const QJsonValue &entry : std::as_const(accounts))
    {
        Account account = Account::fromJson(entry.toObject());
        if (account._service != service)
        {
            newAccounts.append(account.toJson());
        }
    }
    rootObject[ACCOUNTS] = newAccounts;
    return JsonTool::writeJson(filePath, rootObject);
}
