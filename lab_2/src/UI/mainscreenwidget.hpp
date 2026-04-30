#pragma once
#include <QWidget>

class QLabel;
class QPushButton;

class MainScreenWidget : public QWidget {
    Q_OBJECT
public:
    explicit MainScreenWidget(QWidget *parent = nullptr);

private slots:

private:
    void setupUI();
    QLabel *statusLabel;
    QPushButton *btn1;
    QPushButton *btn2;
};