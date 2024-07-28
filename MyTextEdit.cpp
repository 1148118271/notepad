#include "MyTextEdit.h"

MyTextEdit::MyTextEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyTextEdit)
{
    ui->setupUi(this);

    // 绑定滚动条
    initConnect();

    // 初始化字体
    initFont();

    // 初始化高亮
    initHighlighter();

}

MyTextEdit::~MyTextEdit() {
    delete ui;
}

void MyTextEdit::textEditHScrollBarChanged() {
    ui->horizontalScrollBar->setMinimum(ui->textEdit->horizontalScrollBar()->minimum());
    ui->horizontalScrollBar->setMaximum(ui->textEdit->horizontalScrollBar()->maximum());
    ui->horizontalScrollBar->setPageStep(ui->textEdit->horizontalScrollBar()->pageStep());
    ui->horizontalScrollBar->setValue(ui->textEdit->horizontalScrollBar()->value());
}

void MyTextEdit::scrollBarChanged() {
    ui->textEdit->horizontalScrollBar()->setValue(ui->horizontalScrollBar->value());
}

void MyTextEdit::initConnect() {
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
    connect(ui->textEdit->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textEditHScrollBarChanged()));
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(scrollBarChanged()));
    connect(ui->textEdit->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textEditVScrollBarChanged()));
    connect(ui->textBrowser->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textBrowserVScrollBarChanged()));
}

void MyTextEdit::initFont() {
    QFont font("Consolas", 14);
    ui->textEdit->setFont(font);
    ui->textBrowser->setFont(font);
}

void MyTextEdit::onTextChanged() {

    int lineCountOfTextEdit = ui->textEdit->document()->lineCount();
    if (ui->textBrowser->toPlainText().isEmpty()) {
        ui->textBrowser->setText("1\n");
        return;
    }
    QString text = ui->textBrowser->toPlainText();
    int lineCountOfTextBrowser = text.trimmed().split("\n").length();
    if (lineCountOfTextBrowser > lineCountOfTextEdit) {
        for (int i = lineCountOfTextBrowser; i > lineCountOfTextEdit; --i)
            text.chop((QString::number(i) + "\n").length());
    }
    else if(lineCountOfTextBrowser < lineCountOfTextEdit) {
        for (int i = lineCountOfTextBrowser; i < lineCountOfTextEdit; ++i)
            text += QString::number(i + 1) + "\n";
    }
    ui->textBrowser->setMaximumWidth(QString::number(lineCountOfTextEdit).length() * 10 + 25);
    ui->textBrowser->setText(text);
}

void MyTextEdit::textEditVScrollBarChanged() {
    ui->textBrowser->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->value());
}

void MyTextEdit::textBrowserVScrollBarChanged() {
    ui->textEdit->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->value());
}

void MyTextEdit::initHighlighter() {
    new MyHighlighter(ui->textEdit->document());
}

