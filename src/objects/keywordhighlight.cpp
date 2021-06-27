#include "keywordhighlight.h"

KeyWordHighLight::KeyWordHighLight(QTextDocument* parent) : QSyntaxHighlighter(parent)
{

}

void KeyWordHighLight::highlightBlock(const QString& text)
{
    if (text == "")
    {
        return;
    }
    if (m_colorText == "")
    {
        return;
    }
    int n = 0;
    int i = -1;
    do
    {
        i = text.indexOf(m_colorText, n);
        if (i >= 0)
        {
            QTextCharFormat format;
            format.setBackground(QBrush(QColor(255, 255, 0)));

            setFormat(i, m_colorText.length(), format);
            n = i + m_colorText.length();
        }

    }
    while (i >= 0);



}

QString KeyWordHighLight::colorText() const
{
    return m_colorText;
}

void KeyWordHighLight::setColorText(const QString& colorText)
{
    m_colorText = colorText;

}
