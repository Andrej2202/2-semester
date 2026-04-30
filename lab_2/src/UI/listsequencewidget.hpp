#pragma once
#include <QWidget>
#include <QString>
#include <memory>
#include <QComboBox>
#include <MutableListSequence.hpp>

QT_BEGIN_NAMESPACE
class QLineEdit;      // ← Добавили
class QPushButton;
class QListWidget;
class QLabel;
class QVBoxLayout;
QT_END_NAMESPACE


class ListSequenceWidget : public QWidget {
    Q_OBJECT
public:
    explicit ListSequenceWidget(QWidget *parent = nullptr);

private slots:
    void onEnterPressed();   // ← единственный слот для ввода
    void onClearList(int var);
    void Concatination();


private:
    void setupUI();
    void updateStatus(const QString& msg);
    QString printAll(int var) const;
    void showListState();

    // ... старые виджеты ...
    QLineEdit*   inputEdit;
    QComboBox*   opSelector;
    QPushButton* btnClear1;
    QPushButton* btnClear2;
    QPushButton* btnConcat;
    QLabel*      statusLabel;
    QVBoxLayout* mainLayout;

    std::unique_ptr<MutableListSequence<int>> FirstList;
    std::unique_ptr<MutableListSequence<int>> SecondList;
};