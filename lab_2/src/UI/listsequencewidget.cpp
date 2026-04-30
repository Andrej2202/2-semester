#include "listsequencewidget.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox> 

ListSequenceWidget::ListSequenceWidget(QWidget *parent) : QWidget(parent){
    setupUI();
}

void ListSequenceWidget::setupUI() {
    mainLayout = new QVBoxLayout(this);
    FirstList = std::make_unique<MutableListSequence<int>>();
    SecondList = std::make_unique<MutableListSequence<int>>();

    // 🔹 Поле ввода
    inputEdit = new QLineEdit(this);
    inputEdit->setPlaceholderText("Введите данные (число или индекс,значение)");
    inputEdit->setClearButtonEnabled(true);
    mainLayout->addWidget(inputEdit);

    // 🔹 Селектор операции
    opSelector = new QComboBox(this);
    opSelector->addItems({
        "1. Добавить в конец 1 листа(append)",
        "2. Добавить в начало 1 листа(prepend)",
        "3. Вставить по индексу 1 лист(формат: индекс,значение)",
        "4. Добавить в конец 2 листа(append)",
        "5. Добавить в начало 2 листа(prepend)",
        "6. Вставить по индексу 2 лист(формат: индекс,значение)"
    });
    opSelector->setCurrentIndex(0);
    mainLayout->addWidget(opSelector);

    
    auto* btnLayout = new QHBoxLayout();
    btnClear1   = new QPushButton("Очистить 1 лист", this);
    btnClear2  = new QPushButton("Очистить 2 лист", this);
    btnLayout->addWidget(btnClear1);
    btnLayout->addWidget(btnClear2);
    mainLayout->addLayout(btnLayout);

    btnConcat = new QPushButton("Сконкатенировать", this);
    mainLayout->addWidget(btnConcat);

    statusLabel = new QLabel("Готов к работе", this);
    statusLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(statusLabel);



    // 🔹 Подключения
    connect(btnClear1, &QPushButton::clicked, this, [this](){
        onClearList(1);
    });
    connect(btnClear2, &QPushButton::clicked, this, [this](){
        onClearList(2);
    });
    connect(btnConcat, &QPushButton::clicked, this, &ListSequenceWidget::Concatination);
    connect(inputEdit, &QLineEdit::returnPressed, this, &ListSequenceWidget::onEnterPressed);
}


void ListSequenceWidget::onEnterPressed() {
    if (!FirstList) return;
    QString input = inputEdit->text().trimmed();
    int op = opSelector->currentIndex();
    bool ok;

    switch (op) {
        case 0: { // APPEND firrst
            if (input.isEmpty()) { updateStatus("Введите число"); return; }
            int val = input.toInt(&ok);
            if (!ok) { updateStatus("Ожидается целое число"); return; }
            FirstList->Append(val);
            break;
        }
        case 1: { // PREPEND firrst
            if (input.isEmpty()) { updateStatus("Введите число"); return; }
            int val = input.toInt(&ok);
            if (!ok) { updateStatus("Ожидается целое число"); return; }
            FirstList->Prepend(val);
            break;
        }
        case 2: { // INSERT AT firrst
            auto parts = input.split(',', Qt::SkipEmptyParts);
            if (parts.size() != 2) {
                updateStatus("Формат: индекс,значение (например: 2,42)");
                return;
            }
            int idx = parts[0].toInt(&ok);
            if (!ok) { updateStatus("Неверный индекс"); return; }
            int val = parts[1].toInt(&ok);
            if (!ok) { updateStatus("Неверное значение"); return; }
            if (idx < 0 || idx > FirstList->GetLength()) {
                updateStatus(QString("Индекс вне диапазона (0..%1)").arg(FirstList->GetLength()));
                return;
            }
            FirstList->InsertAt(idx, val);
            break;
        }

        case 3: { // APPEND seq
            if (input.isEmpty()) { updateStatus("Введите число"); return; }
            int val = input.toInt(&ok);
            if (!ok) { updateStatus("Ожидается целое число"); return; }
            SecondList->Append(val);
            break;
        }
        case 4: { // PREPEND seq
            if (input.isEmpty()) { updateStatus("Введите число"); return; }
            int val = input.toInt(&ok);
            if (!ok) { updateStatus("Ожидается целое число"); return; }
            SecondList->Prepend(val);
            break;
        }
        case 5: { // INSERT AT seq
            auto parts = input.split(',', Qt::SkipEmptyParts);
            if (parts.size() != 2) {
                updateStatus("Формат: индекс,значение (например: 2,42)");
                return;
            }
            int idx = parts[0].toInt(&ok);
            if (!ok) { updateStatus("Неверный индекс"); return; }
            int val = parts[1].toInt(&ok);
            if (!ok) { updateStatus("Неверное значение"); return; }
            if (idx < 0 || idx > SecondList->GetLength()) {
                updateStatus(QString("Индекс вне диапазона (0..%1)").arg(SecondList->GetLength()));
                return;
            }
            SecondList->InsertAt(idx, val);
            break;
        }
    }

    showListState();
    inputEdit->clear();
    inputEdit->setFocus();
}

QString ListSequenceWidget::printAll(int var) const{
    if(var == 1){
        if (FirstList->GetLength() == 0) return "Список пуст";
        QString res = "{";
        size_t size_ = FirstList->GetLength();
        for (size_t i = 0; i < size_; ++i) {
            res += QString::number(static_cast<int>(FirstList->Get(i))); 
            if (i < size_ - 1) res += ", ";
        }
        res += "}";
        return res;
    }
    else{
        if (SecondList->GetLength() == 0) return "Список пуст";
        QString res = "{";
        size_t size_ = SecondList->GetLength();
        for (size_t i = 0; i < size_; ++i) {
            res += QString::number(static_cast<int>(SecondList->Get(i))); 
            if (i < size_ - 1) res += ", ";
        }
        res += "}";
        return res;
    }
}

void ListSequenceWidget::onClearList(int var) {
    if(var == 1){
        FirstList = std::make_unique<MutableListSequence<int>>();
        updateStatus("Список очищен");
    }
    else{
        SecondList = std::make_unique<MutableListSequence<int>>();
        updateStatus("Список очищен");
    }
    
}

void ListSequenceWidget::Concatination() {
    //FirstList = std::make_unique<MutableListSequence<int>>(FirstList->Concat(SecondList.get()));
    Sequence<int>* merged = FirstList->Concat(SecondList.get());
    FirstList.reset(static_cast<MutableListSequence<int>*>(merged));
    showListState();
}

void ListSequenceWidget::updateStatus(const QString& msg) {
    if (statusLabel) statusLabel->setText(msg);
}


void ListSequenceWidget::showListState() {
    if (!FirstList || !SecondList) return;
    
    QString content1 = printAll(1);
    int size1 = FirstList->GetLength();
    QString content2 = printAll(2);
    int size2 = SecondList->GetLength();
    
    updateStatus(QString("Размер 1: %1 \n Содержимое 1: %2 \n\nРазмер 2: %3 \n Содержимое 2: %4").arg(size1).arg(content1).arg(size2).arg(content2));
}
