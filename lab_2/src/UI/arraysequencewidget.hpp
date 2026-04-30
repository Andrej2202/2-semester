#pragma once
#include <QWidget>
#include <QString>
#include <memory>
#include <QComboBox>
#include <MutableArraySequence.hpp>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QListWidget;
class QLabel;
class QVBoxLayout;
QT_END_NAMESPACE


class ArraySequenceWidget : public QWidget {
    Q_OBJECT
public:
    explicit ArraySequenceWidget(QWidget *parent = nullptr);

private slots:
    void onEnterPressed();
    void onClearList(int var);
    void Concatination();


private:
    void setupUI();
    void updateStatus(const QString& msg);
    QString printAll(int var) const;
    void showListState();

    QLineEdit*   inputEdit;
    QComboBox*   opSelector;
    QPushButton* btnClear1;
    QPushButton* btnClear2;
    QPushButton* btnConcat;
    QLabel*      statusLabel;
    QVBoxLayout* mainLayout;

    std::unique_ptr<MutableArraySequence<int>> FirstArray;
    std::unique_ptr<MutableArraySequence<int>> SecondArray;
};