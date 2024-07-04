#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow() {
    delete ui;
}

// 新建文件
void MainWindow::on_new_file_triggered() {
    this->currentFile.clear();
    this->ui->textEdit->setText("");
}

// 打开文件
void MainWindow::on_open_file_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "警告", "文件无法打开" + file.errorString());
        return;
    }
    this->currentFile = fileName;
    qDebug() << "file name: " << fileName;
    setWindowTitle(fileName);
    QTextStream in(&file);
    this->ui->textEdit->setPlainText(in.readAll());
    file.close();
}

// 保存文件
void MainWindow::on_save_file_triggered() {
    if (currentFile.isEmpty()) {
        currentFile = QFileDialog::getSaveFileName(this, "保存文件");
    }
    QFile file(currentFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "警告", "无法保存文件:" + file.errorString());
        return;
    }
    setWindowTitle(currentFile);
    QTextStream out(&file);
    out << this->ui->textEdit->toPlainText();
    file.close();
}

// 另存为
void MainWindow::on_save_as_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, "另存为");
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "警告", "无法保存文件:" + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    out << this->ui->textEdit->toPlainText();
    file.close();
}


void MainWindow::on_paste_triggered() {
    this->ui->textEdit->paste();
}


void MainWindow::on_cut_triggered() {
    this->ui->textEdit->cut();
}


void MainWindow::on_copy_triggered() {
    this->ui->textEdit->copy();
}

// 粗体
void MainWindow::on_bolder_triggered(bool bolder) {
    this->ui->textEdit->setFontWeight(bolder ? QFont::Bold : QFont::Normal);
}

// 斜体
void MainWindow::on_italic_triggered(bool italic) {
    this->ui->textEdit->setFontItalic(italic);
}

// 下划线
void MainWindow::on_underline_triggered(bool underline) {
    this->ui->textEdit->setFontUnderline(underline);
}

// 撤销
void MainWindow::on_undo_triggered() {
    this->ui->textEdit->undo();
}

// 取消撤销
void MainWindow::on_redo_triggered() {
    this->ui->textEdit->redo();
}

// 字体
void MainWindow::on_font_triggered() {
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected) {
        this->ui->textEdit->setFont(font);
    }
}

// 关于
void MainWindow::on_about_triggered() {
    QMessageBox::about(this, "关于", "这是我的文本编辑器，欢迎学习和使用！");
}

// 退出
void MainWindow::on_exit_triggered() {
    QCoreApplication::exit();
}

