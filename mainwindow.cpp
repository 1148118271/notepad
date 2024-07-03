#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow() {
    delete ui;
}

// 新建文件
void MainWindow::on_new_file_triggered() {
    qDebug() << "onNewFile";
    this->currentFile.clear();
    this->ui->plainTextEdit->setPlainText("");
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
    this->ui->plainTextEdit->setPlainText(in.readAll());
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
    out << this->ui->plainTextEdit->toPlainText();
    file.close();
}

void MainWindow::on_save_as_triggered() {

}


void MainWindow::on_paste_triggered() {

}


void MainWindow::on_cut_triggered() {

}


void MainWindow::on_copy_triggered() {

}


void MainWindow::on_bolder_triggered() {

}


void MainWindow::on_italic_triggered() {

}


void MainWindow::on_underline_triggered() {

}

