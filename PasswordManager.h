#pragma once
#include <Account.h>
#include <QJsonArray>

class PasswordManager
{
public:
    explicit PasswordManager(const QString &filePath);

    /**
     * @brief loadFromJson
     * @return
     */
    bool loadFromJson();

    /**
     * @brief saveToJson
     * @return
     */
    bool saveToJson();

    /**
     * @brief addAccount
     * @param newAccount
     * @return
     */
    bool addAccount(const Account &newAccount);

    /**
     * @brief removeAccount
     * @param service
     * @return
     */
    bool removeAccount(const QString &service);

    /**
     * @brief getAccount
     * @param service
     * @return
     */
    Account getAccount(const QString &service) const;

    /**
     * @brief getAllAccounts
     * @return
     */
    QList<Account> getAllAccounts() const;

private:
    QString _filePath;
    QList<Account> _accounts;
};
