#include "mainscreenwidget.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>

MainScreenWidget::MainScreenWidget(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void MainScreenWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    statusLabel = new QLabel("Главный экран", this);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("font-size: 14px; margin: 10px;");
    layout->addWidget(statusLabel);
    
    btn1 = new QPushButton("Кнопка", this);
    btn2 = new QPushButton("Кнопка", this);
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addStretch();
    
    connect(btn1, &QPushButton::clicked, []() {QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=dQw4w9WgXcQ"));});
    connect(btn2, &QPushButton::clicked, []() {QDesktopServices::openUrl(QUrl("https://youtu.be/MGkWSAnoDOI?si=CxyoFWje5JS7oBR7&t=299"));});
}