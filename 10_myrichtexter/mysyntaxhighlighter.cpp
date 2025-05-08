#include "mysyntaxhighlighter.h"
#include <QFont>

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument* parent):QSyntaxHighlighter(parent)
{

}

void MySyntaxHighlighter::highlightBlock(const QString& text)
{
    QTextCharFormat my_format;
    my_format.setFont(QFont("微软雅黑"));
    my_format.setFontWeight(QFont::Bold);
    my_format.setForeground(Qt::green);

    //匹配char
    QString pattern = "\\bchar\\b";
    QRegExp express(pattern);
    int index = text.indexOf(express);
    while(index>0)
    {
        int matchlen = express.matchedLength();
        setFormat(index,matchlen,my_format);
        index=text.indexOf(express,index+matchlen);
    }
}
