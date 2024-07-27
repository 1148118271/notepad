//
// Created by Administrator on 24-7-21.
//

#include <iostream>
#include "MyHighlighter.h"

MyHighlighter::MyHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
    addNormalTextFormat();
}

void MyHighlighter::highlightBlock(const QString &text) {
    for (const HighlightRule &rule: highlightRules) {
        QRegularExpression re(rule.pattern);
        std::cout <<"offset: " << offset << std::endl;
        QRegularExpressionMatch rem = re.match(text);
        if (!rem.hasMatch())
            continue;
        // TODO 待完善
//        while (true) {
//            int start = (int) rem.capturedStart();
//            std::cout << "start: " << start << std::endl;
//            int count = (int) rem.capturedLength();
//            std::cout << "count: " << count << std::endl;
//            int end = (int) rem.capturedEnd();
//            std::cout << "end: " << end << std::endl;
//            setFormat(start, count, rule.format);
//        }
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
