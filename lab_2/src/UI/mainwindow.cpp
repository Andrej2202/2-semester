#include "mainwindow.hpp"
#include "mainscreenwidget.hpp"
#include "arraysequencewidget.hpp"
#include "listsequencewidget.hpp"

#include <QStackedWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUI();
    setupMenu();
}

void MainWindow::setupUI() {
    setWindowTitle("Lab 2 - GUI");
    resize(500, 350);
    
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);
    
    mainScreen = new MainScreenWidget(this);
    arrayScreen = new ArraySequenceWidget(this);
    listScreen = new ListSequenceWidget(this);
    
    stackedWidget->addWidget(mainScreen);
    stackedWidget->addWidget(arrayScreen);
    stackedWidget->addWidget(listScreen);
    
    stackedWidget->setCurrentWidget(mainScreen);
}

void MainWindow::setupMenu() {
    QMenu *seqMenu = menuBar()->addMenu("Sequence");
    QAction *MainMenuAction = seqMenu->addAction("Main menu");
    QAction *arrayAction = seqMenu->addAction("ArraySequence");
    QAction *listAction = seqMenu->addAction("ListSequence");
    QAction *exitAction = seqMenu->addAction("Exit");
    
    connect(MainMenuAction, &QAction::triggered, [this]() {
        stackedWidget->setCurrentWidget(mainScreen);
    });
    connect(arrayAction, &QAction::triggered, [this]() {
        stackedWidget->setCurrentWidget(arrayScreen);
    });
    connect(listAction, &QAction::triggered, [this]() {
        stackedWidget->setCurrentWidget(listScreen);
    });

    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
}