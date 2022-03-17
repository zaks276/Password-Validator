#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void checkPassword();

private:
    Ui::MainWindow *ui;
    //static QRegularExpression rule1_1;
    //static QRegularExpression rule1_2;
    //static QRegularExpression rule2;
    //static QRegularExpression rule3;
};

#endif // MAINWINDOW_H
