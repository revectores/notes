# Qt

### 1. Demo Program

The minimal program of Qt 

```c
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    return app.exec();
}
```

The `QApplication` object take care of the input arguments and event loop, which is launched by invoking `app.exec()` method. Since no window or event handler is created, the program will just run the infinite loop without any responding.

```c
#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QPushButton button ("Hello world !");
    button.show();

	return app.exec();
}
```



### 2. Compile process

Since it's tedious to write makefile for complex Qt project, Qt provides the tool called `qmake` to allow user to use a project description file with extension `.pro` to generate makefile automatically.



















