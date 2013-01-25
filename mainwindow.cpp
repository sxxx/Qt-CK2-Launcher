#include "mainwindow.h"
#include "ui_mainwindow.h"

#define CK2_LAUNCHER_CONF "qtck2launcher.ini"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSettings Settings(CK2_LAUNCHER_CONF, QSettings::IniFormat);

    QObject::connect(ui->webView, SIGNAL(loadFinished(bool)), SLOT(onLoadFinished(bool)));
    QObject::connect(ui->buttonReg, SIGNAL(clicked()), this, SLOT(onClick_register()));
    QObject::connect(ui->buttonRun, SIGNAL(clicked()), this, SLOT(onClick_run()));
    // Load launcher page
    ui->webView->load(QUrl(Settings.value("launcherurl").toString()));
    // Disable context menu
    ui->webView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->webView->show();

    foreach(QString modName, listFiles(QDir::homePath() + Settings.value("configpath").toString() + "/mod/", "*.mod"))
    {
        QString modIniName = getName(QDir::homePath() + Settings.value("configpath").toString() + "/mod/", modName);

        QString modIniName2 = modIniName;
        modIniName2 += "_n";

        if (!Settings.contains(modIniName2))
        {
            Settings.setValue(modIniName2, modName);
            Settings.setValue(modName, Qt::Unchecked);
        }

        QListWidgetItem *itemOne = new QListWidgetItem(
            modIniName,
            ui->modList);
        if (Settings.value(modName) == Qt::Checked)
            itemOne->setCheckState(Qt::Checked);
        else
            itemOne->setCheckState(Qt::Unchecked);
        itemOne->setSelected(-1);
    }







    foreach(QString dlcName, listFiles(QDir::homePath() + Settings.value("gamepath").toString() + "/dlc/", "*.dlc"))
    {
        QString dlcIniName = getName(QDir::homePath() + Settings.value("gamepath").toString() + "/dlc/", dlcName);

        QString dlcIniName2 = dlcIniName;
        dlcIniName2 += "_n";


        if (!Settings.contains(dlcIniName2))
        {
            Settings.setValue(dlcIniName2, dlcName);
            Settings.setValue(dlcName, Qt::Checked);
        }

        QListWidgetItem *itemOne = new QListWidgetItem(
            dlcIniName,
            ui->dlcList);
        if (Settings.value(dlcName) == Qt::Checked)
            itemOne->setCheckState(Qt::Checked);
        else
            itemOne->setCheckState(Qt::Unchecked);
        itemOne->setSelected(-1);
    }

    // register clicks
    QObject::connect(ui->modList, SIGNAL(itemChanged(QListWidgetItem *)), this, SLOT(on_list_itemChangedMod(QListWidgetItem *)));
    QObject::connect(ui->dlcList, SIGNAL(itemChanged(QListWidgetItem *)), this, SLOT(on_list_itemChangedDLC(QListWidgetItem *)));

}

QStringList MainWindow::listFiles(QString directory, QString extension)
{
    QDir modDir(directory);
    QStringList filters;
    filters << extension;
    return modDir.entryList(filters, QDir::Files);
}

QString MainWindow::getName(QString iniDir, QString iniName)
{
    //qDebug() << iniName;
    QSettings ini(iniDir.append(iniName), QSettings::IniFormat);

    if (ini.value("name").toString() == "")
        return iniName;
    else
        return ini.value("name").toString();
}

void MainWindow::on_list_itemChangedMod(QListWidgetItem* changed)
{
    QSettings Settings(CK2_LAUNCHER_CONF, QSettings::IniFormat);
    bool checked = changed->checkState() == Qt::Checked;
    int index = 0;
    for (; ui->modList->item(index) != changed; index++) ;

    QString modName = Settings.value(changed->text() + "_n").toString();
    if (checked)
    {
        Settings.setValue(modName, Qt::Checked);
    }
    else
    {
        Settings.setValue(modName, Qt::Unchecked);
    }
    Settings.sync();
}

void MainWindow::on_list_itemChangedDLC(QListWidgetItem* changed)
{
    QSettings Settings(CK2_LAUNCHER_CONF, QSettings::IniFormat);
    bool checked = changed->checkState() == Qt::Checked;
    int index = 0;
    for (; ui->dlcList->item(index) != changed; index++) ;

    QString modName = Settings.value(changed->text() + "_n").toString();
    if (checked)
    {
        Settings.setValue(modName, Qt::Checked);
    }
    else
    {
        Settings.setValue(modName, Qt::Unchecked);
    }
    Settings.sync();
}

void MainWindow::onLoadFinished(bool okay)
{
  if ( ! okay )
  {
      ui->webView->load(QUrl("launcher/launcher.html"));
  }
}

void MainWindow::onClick_register()
{
    QSettings Settings(CK2_LAUNCHER_CONF, QSettings::IniFormat);
    QDesktopServices::openUrl(QUrl(Settings.value("registerurl").toString(), QUrl::TolerantMode));
}

void MainWindow::onClick_run()
{
    QSettings Settings(CK2_LAUNCHER_CONF, QSettings::IniFormat);
    QString program = Settings.value("runBinary").toString();
    QStringList arguments;

    // Check current status
    QStringList keysList = Settings.allKeys();
    foreach(QString key, keysList)
    {
        if (key.right(4) == ".mod" && Settings.value(key) == Qt::Checked)
        {
            arguments << "-mod=mod/" + key;
        }
        else if (key.right(4) == ".dlc" && Settings.value(key) == Qt::Unchecked)
        {
            arguments << "-exclude_dlc=dlc/" + key;
        }
    }

    QProcess *gameProcess = new QProcess();
    gameProcess->start(program, arguments);
    gameProcess->closeWriteChannel();

    // Quit after CK2 running
    QApplication::quit();

}

MainWindow::~MainWindow()
{
    delete ui;
}
