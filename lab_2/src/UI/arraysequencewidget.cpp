#include "arraysequencewidget.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

ArraySequenceWidget::ArraySequenceWidget(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void ArraySequenceWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    statusLabel = new QLabel("📊 Array Sequence\nРабота с массивами", this);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("font-size: 14px; margin: 10px;");
    layout->addWidget(statusLabel);
    
    QPushButton *btn = new QPushButton("Обработать массив", this);
    layout->addWidget(btn);
    layout->addStretch();
    
    connect(btn, &QPushButton::clicked, this, &ArraySequenceWidget::onProcess);
}

void ArraySequenceWidget::onProcess() {
    QMessageBox::information(this, "Array", "Массив обработан!");
}