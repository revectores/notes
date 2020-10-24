#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>


int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    window->setLayout(layout);
    window->show();

    return app.exec();
}
