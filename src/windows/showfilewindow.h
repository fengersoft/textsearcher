#ifndef SHOWFILEWINDOW_H
#define SHOWFILEWINDOW_H

#include <QMainWindow>
#include "../api/file/ioutils.h"
#include "../objects/keywordhighlight.h"

namespace Ui
{
class ShowFileWindow;
}

class ShowFileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowFileWindow(QWidget* parent = nullptr);
    ~ShowFileWindow();

    QString filePath() const;
    void setFilePath(const QString& filePath);

    KeyWordHighLight* keywordHightLight() const;
    void setKeywordHightLight(KeyWordHighLight* keywordHightLight);

    QString keyword() const;
    void setKeyword(const QString& keyword);

private:
    Ui::ShowFileWindow* ui;
    QString m_filePath;
    KeyWordHighLight* m_keywordHightLight;
    QString m_keyword;
};

#endif // SHOWFILEWINDOW_H
