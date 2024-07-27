#pragma once

#include "ui_mytextedit.h"
#include "MyHighlighter.h"
#include <iostream>
#include <QWidget>

namespace Ui {
class MyTextEdit;
}

class MyTextEdit : public QWidget {
    Q_OBJECT

public:
    explicit MyTextEdit(QWidget *parent = nullptr);
    ~MyTextEdit() override;

private slots:
    void textEditHScrollBarChanged();
    void scrollBarChanged();
    void textEditVScrollBarChanged();
    void textBrowserVScrollBarChanged();
    void onTextChanged();

private:
    void initConnect();
    void initFont();
    void initHighlighter();

private:
    Ui::MyTextEdit *ui;
};

