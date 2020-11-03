#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlDatabase mydb;
    void closeDB();
    bool openDB();

private slots:

    void on_pushButtonConn_clicked();

    void on_pushButtonNabial_clicked();

    void on_pushButtonNapoje_clicked();

    void on_pushButtonMakarony_clicked();

    void on_pushButtonSlodycze_clicked();

    void on_pushButtonOK_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
