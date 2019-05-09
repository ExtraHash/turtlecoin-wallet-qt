#pragma once

#include <QObject>
#include <QString>

#include <WalletBackend/WalletBackend.h>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
    std::shared_ptr<WalletBackend> m_walletBackend;
};
