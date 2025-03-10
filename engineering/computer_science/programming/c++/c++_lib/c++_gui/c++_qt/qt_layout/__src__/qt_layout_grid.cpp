#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>


int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 0, 1);
    layout->addWidget(button3, 1, 0, 1, 2);
    layout->addWidget(button4, 2, 0);
    layout->addWidget(button5, 2, 1);

    window->setLayout(layout);
    window->show();

    return app.exec();
}

