#pragma once
#include <QMainWindow>

class QStackedWidget;
class MainScreenWidget;
class ArraySequenceWidget;
class ListSequenceWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setupUI();
    void setupMenu();
    
    QStackedWidget *stackedWidget;
    MainScreenWidget *mainScreen;
    ArraySequenceWidget *arrayScreen;
    ListSequenceWidget *listScreen;
};