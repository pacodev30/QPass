#include "PasswordManager.h"

PasswordManager::PasswordManager(const QString &filePath)
    : _filePath(filePath)
{

}

bool PasswordManager::loadFromJson()
{
    QJsonObject loadObject = JsonTool::readJson(_filePath);
    if(loadObject.isEmpty())
        return false;

    QJsonArray accountsArray = loadObject[ACCOUNTS].toArray();
    _accounts.clear();

    for(const QJsonValue &value : std::as_const(accountsArray))
    {
        _accounts.append(Account::fromJson(value.toObject()));
    }
    return true;
}

bool PasswordManager::saveToJson()
{
    QJsonArray accountsArray;
    for (const Account &account : std::as_const(_accounts))
    {
        accountsArray.append(account.toJson());
    }

    QJsonObject jObj;
    jObj[ACCOUNTS] = accountsArray;

    return JsonTool::writeJson(_filePath, jObj);
}

bool PasswordManager::addAccount(const Account &newAccount)
{
    for(const Account &account : _accounts)
    {
        if(account._service == newAccount._service)
        {
            qWarning() << account._service + " already exists";
            return false;
        }
    }
    _accounts.append(newAccount);
    return saveToJson();
}

bool PasswordManager::removeAccount(const QString &service)
{
    for(int i = 0; i < _accounts.size(); i++)
    {
        if(_accounts.at(i)._service == service)
        {
            _accounts.removeAt(i);
            return saveToJson();
        }
    }
    return false;
}

Account PasswordManager::getAccount(const QString &service) const
{
    for(const Account &account : _accounts)
    {
        if(account._service == service)
        {
            return account;
        }
    }
    return {};
}

QList<Account> PasswordManager::getAllAccounts() const
{
    return _accounts;
}


