#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextEdit>
class MainWindow : public QMainWindow
{
Q_OBJECT
public: QTextEdit * text1 = new QTextEdit;
explicit MainWindow(QWidget *parent = 0);
signals:
public slots:
// vot zdes objyavlyaem slot
    void okClicked();
};
#endif // MAINWINDOW_H
