#include "showfilewindow.h"
#include "ui_showfilewindow.h"

ShowFileWindow::ShowFileWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ShowFileWindow)
{
    ui->setupUi(this);

}

ShowFileWindow::~ShowFileWindow()
{
    delete ui;
}

QString ShowFileWindow::filePath() const
{
    return m_filePath;
}

void ShowFileWindow::setFilePath(const QString& filePath)
{
    m_filePath = filePath;
    setWindowTitle(m_filePath);
    QString s = readString(m_filePath);
    ui->edtInfo->setText(s);
}

KeyWordHighLight* ShowFileWindow::keywordHightLight() const
{
    return m_keywordHightLight;
}

void ShowFileWindow::setKeywordHightLight(KeyWordHighLight* keywordHightLight)
{
    m_keywordHightLight = keywordHightLight;
}

QString ShowFileWindow::keyword() const
{
    return m_keyword;
}

void ShowFileWindow::setKeyword(const QString& keyword)
{
    m_keyword = keyword;
    m_keywordHightLight = new KeyWordHighLight(ui->edtInfo->document());
    m_keywordHightLight->setColorText(m_keyword);
}
