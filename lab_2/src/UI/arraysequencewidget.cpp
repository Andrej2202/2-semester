#include "arraysequencewidget.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox> 

ArraySequenceWidget::ArraySequenceWidget(QWidget *parent) : QWidget(parent){
    setupUI();
}

void ArraySequenceWidget::setupUI() {
    mainLayout = new QVBoxLayout(this);
    FirstArray = std::make_unique<MutableArraySequence<int>>();
    SecondArray = std::make_unique<MutableArraySequence<int>>();

    inputEdit = new QLineEdit(this);
    inputEdit->setPlaceholderText("Введите данные (число или индекс,значение)");
    inputEdit->setClearButtonEnabled(true);
    mainLayout->addWidget(inputEdit);

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


    connect(btnClear1, &QPushButton::clicked, this, [this](){
        onClearList(1);
    });
    connect(btnClear2, &QPushButton::clicked, this, [this](){
        onClearList(2);
    });
    connect(btnConcat, &QPushButton::clicked, this, &ArraySequenceWidget::Concatination);
    connect(inputEdit, &QLineEdit::returnPressed, this, &ArraySequenceWidget::onEnterPressed);
}


void ArraySequenceWidget::onEnterPressed() {
    if (!FirstArray) return;
    QString input = inputEdit->text().trimmed();
    int op = opSelector->currentIndex();
    bool ok;

    switch (op) {
        case 0: { // APPEND firrst
            if (input.isEmpty()) { updateStatus("Введите число"); return; }
            int val = input.toInt(&ok);
            if (!ok) { updateStatus("Ожидается целое число(адекватных размеров)"); return; }
            FirstArray->Append(val);
            break;
        }
        case 1: { // PREPEND firrst
            if (input.isEmpty()) { updateStatus("Введите число"); return; }
            int val = input.toInt(&ok);
            if (!ok) { updateStatus("Ожидается целое число(адекватных размеров)"); return; }
            FirstArray->Prepend(val);
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
            if (idx < 0 || idx > FirstArray->GetLength()) {
                updateStatus(QString("Индекс вне диапазона (0..%1)").arg(FirstArray->GetLength()));
                return;
            }
            FirstArray->InsertAt(val, idx);
            break;
        }

        case 3: { // APPEND seq
            if (input.isEmpty()) { updateStatus("Введите число"); return; }
            int val = input.toInt(&ok);
            if (!ok) { updateStatus("Ожидается целое число(адекватных размеров)"); return; }
            SecondArray->Append(val);
            break;
        }
        case 4: { // PREPEND seq
            if (input.isEmpty()) { updateStatus("Введите число"); return; }
            int val = input.toInt(&ok);
            if (!ok) { updateStatus("Ожидается целое число(адекватных размеров)"); return; }
            SecondArray->Prepend(val);
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
            if (idx < 0 || idx > SecondArray->GetLength()) {
                updateStatus(QString("Индекс вне диапазона (0..%1)").arg(SecondArray->GetLength()));
                return;
            }
            SecondArray->InsertAt(val, idx);
            break;
        }
    }

    showListState();
    inputEdit->clear();
    inputEdit->setFocus();
}

QString ArraySequenceWidget::printAll(int var) const{
    if(var == 1){
        if (FirstArray->GetLength() == 0) return "Список пуст";
        QString res = "{";
        size_t size_ = FirstArray->GetLength();
        for (size_t i = 0; i < size_; ++i) {
            res += QString::number(static_cast<int>(FirstArray->Get(i))); 
            if (i < size_ - 1) res += ", ";
        }
        res += "}";
        return res;
    }
    else{
        if (SecondArray->GetLength() == 0) return "Список пуст";
        QString res = "{";
        size_t size_ = SecondArray->GetLength();
        for (size_t i = 0; i < size_; ++i) {
            res += QString::number(static_cast<int>(SecondArray->Get(i))); 
            if (i < size_ - 1) res += ", ";
        }
        res += "}";
        return res;
    }
}

void ArraySequenceWidget::onClearList(int var) {
    if(var == 1){
        FirstArray = std::make_unique<MutableArraySequence<int>>();
    }
    else{
        SecondArray = std::make_unique<MutableArraySequence<int>>();
    }
    showListState();
}

void ArraySequenceWidget::Concatination() {
    //FirstArray = std::make_unique<MutableArraySequence<int>>(FirstArray->Concat(SecondArray.get()));
    Sequence<int>* merged = FirstArray->Concat(SecondArray.get());
    FirstArray.reset(static_cast<MutableArraySequence<int>*>(merged));
    showListState();
}

void ArraySequenceWidget::updateStatus(const QString& msg) {
    if (statusLabel) statusLabel->setText(msg);
}


void ArraySequenceWidget::showListState() {
    if (!FirstArray || !SecondArray) return;
    
    QString content1 = printAll(1);
    int size1 = FirstArray->GetLength();
    QString content2 = printAll(2);
    int size2 = SecondArray->GetLength();
    
    updateStatus(QString("Размер 1: %1 \n Содержимое 1: %2 \n\nРазмер 2: %3 \n Содержимое 2: %4").arg(size1).arg(content1).arg(size2).arg(content2));
}
