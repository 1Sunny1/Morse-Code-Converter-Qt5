#include "highlighter.h"

Highlighter::Highlighter(bool* toText_,QTextDocument *parent) :
    QSyntaxHighlighter{parent}
    , toText{toText_} {}

void Highlighter::highlightBlock(const QString &text) {
    if (*toText) {
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        format.setForeground(QColor{128,0,0});
        QBrush brush{QColor{250,147,147}};
        format.setBackground(brush);

        QRegularExpression expression("[^._/ ]");
        QRegularExpressionMatchIterator i = expression.globalMatch(text);
        while (i.hasNext()) {
          QRegularExpressionMatch match = i.next();
          setFormat(match.capturedStart(), match.capturedLength(), format);
        }
    }
}
