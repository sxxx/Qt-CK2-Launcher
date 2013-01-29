#ifndef FIRSTDIALOG_H
#define FIRSTDIALOG_H

#include <QDialog>
#include <QComboBox>

// Store configs
#include <QSettings>
// Filesystem access
#include <QDir>
// Dir choosing
#include <QFileDialog>
// Debug
#include <QDebug>

namespace Ui {
class FirstDialog;
}

class FirstDialog : public QDialog
{
    Q_OBJECT
    
public:
    bool dialogCompleted;
    explicit FirstDialog(QWidget *parent = 0);
    ~FirstDialog();
    
private:
    Ui::FirstDialog *ui;
    void checkAddItem(QComboBox* combo, QString item);

private slots:
    void checkedNoSteam(bool toggled);
    void indexChangedSteam(int newIndex);
    void buttonClickedBrowseSteam();
    void buttonClickedBrowseGame();
    void buttonClickedBrowseConfig();
    void buttonClickedOk();
};

#endif // FIRSTDIALOG_H
