#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Минимальный Qt UI");
    window.resize(320, 180);

    auto layout = new QVBoxLayout(&window);

    auto label = new QLabel("Лабораторная №2", &window);
    auto runBtn = new QPushButton("Запустить тест", &window);
    auto exitBtn = new QPushButton("Выход", &window);

    layout->addWidget(label);
    layout->addWidget(runBtn);
    layout->addWidget(exitBtn);

    QObject::connect(runBtn, &QPushButton::clicked, []() {
        qDebug() << "[UI] Запуск тестов последовательностей...";
    });

    QObject::connect(exitBtn, &QPushButton::clicked, &app, &QApplication::quit);

    window.show();
    return app.exec();
}