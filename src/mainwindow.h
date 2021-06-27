#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardItemModel>
#include "./api/file/fileseacher.h"
#include <QSettings>
#include <QTextCodec>
#include "./api/file/ioutils.h"
#include "windows/showfilewindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    bool hasFindKeyWord(QString filePath);
private slots:
    void on_btnOpen_clicked();

    void on_edtSearch_returnPressed();

    void on_lvData_doubleClicked(const QModelIndex& index);

private:
    Ui::MainWindow* ui;
    QStandardItemModel* m_model;
    QStringList m_suffixs;

};
#endif // MAINWINDOW_H
