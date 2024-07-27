//
// Created by Administrator on 24-7-21.
//
#pragma once

#include <QObject>
#include <QSyntaxHighlighter>
#include <qregularexpression.h>

class MyHighlighter: public QSyntaxHighlighter {

public:
    explicit MyHighlighter(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;

private:

    QString mFontFamily = "Consolas";
    int mFontSize = 14;

    int offset = 0;

    struct HighlightRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QVector<HighlightRule> highlightRules;

    void addNormalTextFormat();

};
