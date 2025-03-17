#pragma once
#include <Account.h>
#include <QWidget>
#include <QJsonArray>

class PasswordManager : public QWidget
{
    Q_OBJECT
public:
    explicit PasswordManager(QWidget *parent = nullptr);

    static bool addAccount(const QString &filepath, const Account &account);
    static Account getAccount(const QString &filepath, const QString &service);
    static bool removeAccount(const QString &filePath, const QString &service);
};
