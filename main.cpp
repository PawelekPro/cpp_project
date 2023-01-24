#include "HomePage.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    /* Disabled QuitOnLastWindowClosed to avoid the dialog closing after QMessageBox is closed. */
    qApp->setQuitOnLastWindowClosed(false);
    QApplication app(argc, argv);

    QTranslator translator;
    HomePage MainWindow;

    /* The Main window must handle the close event manually to avoid the program running after closing it. */
        QObject::connect(&MainWindow, &HomePage::exited, &app, &QApplication::quit);

    MainWindow.show();

    int ret;
    try
    {
        ret = app.exec();
    }
    catch(const std::bad_alloc &)
    {
        // cleaning up here (e.g. saving the session) and closing config files (if such are used).
        return EXIT_FAILURE; // exit the application
    }
    return ret;
}
