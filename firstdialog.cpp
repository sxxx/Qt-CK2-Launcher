#include "firstdialog.h"
#include "ui_firstdialog.h"

FirstDialog::FirstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstDialog)
{
    ui->setupUi(this);

    // Set default paths
    ui->comboBoxPathSteam   ->addItem(QDir::homePath()+"/Steam/");
    ui->comboBoxPathSteam   ->addItem(QDir::homePath()+"/.local/share/Steam/");
    ui->comboBoxPathConfig  ->addItem(QDir::homePath()+"/Documents/Paradox Interactive/Crusader Kings II/");
}



void FirstDialog::checkedNoSteam(bool toggled)
{
    ui->comboBoxPathSteam       ->setDisabled(toggled);
    ui->buttonBrowsePathSteam   ->setDisabled(toggled);
}

void FirstDialog::indexChangedSteam(int newIndex)
{
    QString newPath = ui->comboBoxPathSteam->itemText(newIndex)+"SteamApps/common/Crusader Kings II/";
    checkAddItem(ui->comboBoxPathGame, newPath);
}

void FirstDialog::buttonClickedBrowseSteam()
{
    QString directory = QFileDialog::getExistingDirectory(this,tr("Choose Directory"));
    if (directory.length())
        checkAddItem(ui->comboBoxPathSteam, directory);
}

void FirstDialog::buttonClickedBrowseGame()
{
    QString directory = QFileDialog::getExistingDirectory(this,tr("Choose Directory"));
    if (directory.length())
        checkAddItem(ui->comboBoxPathGame, directory);
}

void FirstDialog::buttonClickedBrowseConfig()
{
    QString directory = QFileDialog::getExistingDirectory(this,tr("Choose Directory"));
    if (directory.length())
        checkAddItem(ui->comboBoxPathConfig, directory);
}

void FirstDialog::buttonClickedOk()
{
    QSettings settings;
    settings.setValue("userOptions/isNoSteam",      ui->checkBoxNoSteam->isChecked());
    settings.setValue("userOptions/noAdvancedMode", ui->checkBoxAdvancedMode->isChecked());
    settings.setValue("userOptions/pathSteam",      ui->comboBoxPathSteam->currentText());
    settings.setValue("userOptions/pathGame",       ui->comboBoxPathGame->currentText());
    settings.setValue("userOptions/pathConfig",     ui->comboBoxPathConfig->currentText());

    // Static parameters
    settings.setValue("internal/isConfigured", true);
    settings.setValue("internal/urlLauncher", "http://www.paradoxplaza.com/in-game/ck2/launcher.html");
    settings.setValue("internal/urlRegister", "http://forum.paradoxplaza.com/forum/mygames.php");
    settings.setValue("internal/executableName", "ck2");

    dialogCompleted = true;
    this->close();
}



void FirstDialog::checkAddItem(QComboBox* combo, QString text)
{
    int index = combo->findText(text);
    if (index == -1) {
       combo->addItem(text);
       index = combo->findText(text);
    }

    combo->setCurrentIndex(index);
}



FirstDialog::~FirstDialog()
{
    delete ui;
}
