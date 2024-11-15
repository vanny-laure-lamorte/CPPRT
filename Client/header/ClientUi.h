#ifndef CLIENTUI_H
#define CLIENTUI_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include "Client.h"
#include "../src/ui_clientUi.h"

class clientUi : public QMainWindow {
    Q_OBJECT

public:
    explicit clientUi(QWidget *parent = nullptr);

private slots:
    void sendMessage();
    void displayMessage(const QString &message);

private:
    Client *client;
    Ui::ClientUi *ui;
    QVBoxLayout *messageDisplay;
    QLineEdit *messageInput;
    QPushButton *sendButton;
};

#endif // CLIENTUI_H
