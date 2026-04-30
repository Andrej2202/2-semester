#pragma once
#include <QWidget>

class QLabel;
class QPushButton;

class ArraySequenceWidget : public QWidget {
    Q_OBJECT
public:
    explicit ArraySequenceWidget(QWidget *parent = nullptr);

private slots:
    void onProcess();

private:
    void setupUI();
    QLabel *statusLabel;
};