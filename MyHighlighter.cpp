//
// Created by Administrator on 24-7-21.
//

#include "MyHighlighter.h"

MyHighlighter::MyHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
    addNormalTextFormat();
}

void MyHighlighter::highlightBlock(const QString &text) {
    for (const HighlightRule &rule: highlightRules) {
        QRegularExpression re(rule.pattern);
        QRegularExpressionMatchIterator remi = re.globalMatch(text);
        while (remi.hasNext()) {    
            QRegularExpressionMatch rem = remi.next();
            int start = (int) rem.capturedStart();
            int count = (int) rem.capturedLength();
            setFormat(start, count, rule.format);
        }
    }

}

void MyHighlighter::addNormalTextFormat() {
    HighlightRule rule;
    rule.pattern = QRegularExpression("[a-z0-9A-Z]+");
    QTextCharFormat normalFormat;
    normalFormat.setFont(QFont(mFontFamily, mFontSize));
    normalFormat.setForeground(QColor(0, 100, 100));
    rule.format = normalFormat;
    highlightRules.append(rule);
}
