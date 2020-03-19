#ifndef VISUALS_H
#define VISUALS_H

#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QScrollBar>

namespace Visuals {
    inline namespace ScrollBars {
        void hideScrollBars(std::pair<QPlainTextEdit *, QPlainTextEdit *> textEdits, QTextBrowser *aboutBrowser) {
            textEdits.first->ensureCursorVisible();
            textEdits.first->setCenterOnScroll(true);

            textEdits.second->verticalScrollBar()->hide();
            textEdits.first->verticalScrollBar()->hide();

            aboutBrowser->verticalScrollBar()->hide();
        }

        void scrollToTheBottom(QPlainTextEdit *convertedText) {
            QScrollBar *scrollbar = convertedText->verticalScrollBar();
            bool scrollbarAtBottom  = (scrollbar->value() >= (scrollbar->maximum() - 4));
            convertedText->moveCursor(QTextCursor::End);
            if (scrollbarAtBottom)
                convertedText->ensureCursorVisible();
        }
    }
}

#endif // VISUALS_H
