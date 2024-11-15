#include "../header/ClientUi.h"
// #include "ui_clientUi.h"
#include <QLabel>
#include <QDebug>

// Constructor to initialize UI and connections
clientUi::clientUi(QWidget *parent)
    : QMainWindow(parent), client(new Client(this)), ui(new Ui::ClientUi)
{
    ui->setupUi(this);

    connect(ui->messageInput, &QLineEdit::returnPressed, this, &clientUi::sendMessage);
    connect(ui->sendButton, &QPushButton::clicked, this, &clientUi::sendMessage);

    messageDisplay = ui->messageDisplay;
    messageInput = ui->messageInput;
    sendButton = ui->sendButton;

    connect(client, &Client::messageReceived, this, &clientUi::displayMessage);
}

// Function to send a message from input field using Client function
void clientUi::sendMessage()
{
    QString message = messageInput->text();
    if (!message.isEmpty()) {
        messageInput->clear();
        client->sendMessage(message);
    }
}

// Function to display a received message
void clientUi::displayMessage(const QString &message)
{
    QLabel *messageLabel = new QLabel(message);
    messageDisplay->addWidget(messageLabel);
}
