#include "HomePage.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;


    HomePage MainWindow;
    MainWindow.show();
    return a.exec();
}
