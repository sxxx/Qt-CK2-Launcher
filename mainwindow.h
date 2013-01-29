#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
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

// Save state on close
#include <QCloseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QHash<QString, QHash<QString,QVariant> > data;
    QSettings *settings;
    explicit    MainWindow(QWidget *parent = 0);
               ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList listFiles(QString directory, QString extension);
    QString     extractName(QString iniDir, QString iniName);
    void        loadStyles();

private slots:
    void        listItemChanged(QListWidgetItem* changed);
    void        buttonClickedRegister();
    void        buttonClickedRun();
    void        webviewLoadFinished(bool status);
};

#endif // MAINWINDOW_H
