#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digit_pressed();
    void operator_pressed();
    void on_clear_clicked();
    void on_equals_clicked();

private:
    Ui::MainWindow *ui;
    double firstNum;
    bool userIsTypingSecondNum;
    QString pendingOperator;
};
#endif // MAINWINDOW_H
