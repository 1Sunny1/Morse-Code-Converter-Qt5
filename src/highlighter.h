#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class Highlighter final : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit    Highlighter(bool* toText, QTextDocument *parent = nullptr);

protected:
    void        highlightBlock(const QString &text) override;

private:
    bool *      toText;
};

#endif // HIGHLIGHTER_H
