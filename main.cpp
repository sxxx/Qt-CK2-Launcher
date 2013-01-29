#include <QtGui/QApplication>
#include "mainwindow.h"
// Move window in center of screen
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    // Used by QSettings
    QCoreApplication::setOrganizationName   ("qtck2launcher");
    QCoreApplication::setApplicationName    ("qtck2launcher");
    QCoreApplication::setApplicationVersion ("29-01-2013 release 2");

    QApplication a(argc, argv);

    MainWindow w;

    // Open window in center of screen
    QRect r = w.geometry();
    r.moveCenter(QApplication::desktop()->availableGeometry().center());
    w.setGeometry(r);
    w.show();

    return a.exec();
}

