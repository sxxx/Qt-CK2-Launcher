#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
// Move window in center of screen
#include <QDesktopWidget>
// Store configs
#include <QSettings>
// Filesystem access
#include <QDir>
#include <QFile>
// Paradox News in Launcher
#include <QWebView>
#include <QUrl>
// Run game
#include <QProcess>
// Debug
#include <QDebug>

// for test
#include <QFileInfo>
#include <QMessageBox>
#include <QDesktopServices>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit    MainWindow(QWidget *parent = 0);
               ~MainWindow();


private:
    Ui::MainWindow *ui;

    QStringList listFiles(QString directory, QString extension);
    QString     getName(QString iniDir, QString iniName);

private slots:
    void        onClick_register();
    void        onClick_run();
    void        onLoadFinished(bool okay);
    void        on_list_itemChangedMod(QListWidgetItem* changed);
    void        on_list_itemChangedDLC(QListWidgetItem* changed);
};

#endif // MAINWINDOW_H
