#ifndef KEYWORDHIGHLIGHT_H
#define KEYWORDHIGHLIGHT_H

#include <QObject>
#include <QWidget>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QDebug>
#include <QRegularExpressionMatch>
#include <QTextDocument>

class KeyWordHighLight : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit KeyWordHighLight(QTextDocument* parent = nullptr);
    QString colorText() const;
    void setColorText(const QString& colorText);

protected:
    void highlightBlock(const QString& text);
signals:
private:
    QString m_colorText;

};

#endif // KEYWORDHIGHLIGHT_H
