#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QMainWindow>

namespace Ui {
class MainFrame;
}

class MainFrame : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainFrame(QWidget *parent = 0);
    ~MainFrame();

private slots:
    void on_inputUsername_returnPressed();

    void on_inputPassword_returnPressed();

private:
    Ui::MainFrame *ui;
    QString username;
    QString password;
};

#endif // MAINFRAME_H
