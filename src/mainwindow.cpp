#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_model = new QStandardItemModel(this);
    QStringList labels;
    labels << "文件名" << "文件路径";
    m_model->setHorizontalHeaderLabels(labels);

    ui->lvData->setModel(m_model);
    m_suffixs << "txt";
    m_suffixs << "h";
    m_suffixs << "cpp";
    m_suffixs << "js";
    m_suffixs << "json";
    m_suffixs << "pas";
    QSettings ini(QApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
    ini.beginGroup("set");
    ui->edtPath->setText(ini.value("path").toString());
    ini.endGroup();

}

MainWindow::~MainWindow()
{
    QSettings ini(QApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
    ini.beginGroup("set");
    ini.setValue("path", ui->edtPath->text());
    ini.endGroup();
    delete ui;
}

bool MainWindow::hasFindKeyWord(QString filePath)
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QString s = readString(file.readAll());
    return s.indexOf(ui->edtSearch->text()) >= 0;
}


void MainWindow::on_btnOpen_clicked()
{
    QString path = QFileDialog::getExistingDirectory();
    if (path == "")
    {
        return;
    }
    ui->edtPath->setText(path);

}

void MainWindow::on_edtSearch_returnPressed()
{
    m_model->removeRows(0, m_model->rowCount());
    FileSeacher* fileSeacher = new FileSeacher(this);
    connect(fileSeacher, &FileSeacher::findFileInfo, this, [this](QString rootPath, QFileInfo & fileInfo)
    {

        QString suffix = fileInfo.suffix().toLower();
        if ((fileInfo.isFile()) && (m_suffixs.contains(suffix)))
        {
            ui->lblStatus->setText("检索" + fileInfo.absoluteFilePath());
            if (hasFindKeyWord(fileInfo.absoluteFilePath()))
            {
                QList<QStandardItem*> items;
                QStandardItem* item = nullptr;
                item = new QStandardItem();
                item->setText(fileInfo.fileName());
                item->setData(fileInfo.absoluteFilePath());
                items << item;

                item = new QStandardItem();
                item->setText(fileInfo.absolutePath());
                items << item;

                m_model->appendRow(items);


            }

        }
        QApplication::processEvents();

    });
    fileSeacher->startSearch(ui->edtPath->text());

    delete fileSeacher;
    ui->lblStatus->setText("");


}




void MainWindow::on_lvData_doubleClicked(const QModelIndex& index)
{
    if (!index.isValid())
    {
        return;
    }

    int row = index.row();
    QString filePath = m_model->item(row)->data().toString();
    ShowFileWindow* showFileWindow = new ShowFileWindow(this);
    showFileWindow->setAttribute(Qt::WA_DeleteOnClose);
    showFileWindow->setFilePath(filePath);
    showFileWindow->setKeyword(ui->edtSearch->text());
    showFileWindow->show();

}
