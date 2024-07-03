#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


private slots:
    void on_new_file_triggered();

    void on_open_file_triggered();

    void on_save_as_triggered();

    void on_save_file_triggered();

    void on_paste_triggered();

    void on_cut_triggered();

    void on_copy_triggered();

    void on_bolder_triggered();

    void on_italic_triggered();

    void on_underline_triggered();

private:
    Ui::MainWindow *ui;

    QString currentFile;

};


