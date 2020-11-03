#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/mazur/Documents/projekt01/APProducts/APProducts.db");

    if(!mydb.open())
       ui->labelDB->setText("Failed to open the database");
    else
       ui->labelDB->setText("Connected");

    openDB();
    QSqlQueryModel *modal = new QSqlQueryModel;
    modal->setQuery("SELECT Nazwa_kategorii FROM Categories");
    modal->setHeaderData(0, Qt::Horizontal, tr("Nazwa kategorii"));
    ui->tableViewCategories->setModel(modal);
    closeDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeDB(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

bool MainWindow::openDB(){
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/mazur/Documents/projekt01/APProducts/APProducts.db");

        if(!mydb.open()){
           qDebug()<<"Failed to open the database"<<mydb.lastError();
           return false;
        }
        else{
           qDebug()<<"Connected.";
           return true;
        }
}

void MainWindow::on_pushButtonNabial_clicked()
{
    openDB();
    QSqlQueryModel *modal = new QSqlQueryModel;
    modal->setQuery("SELECT ID_Product, Nazwa FROM Product Where ID_categories='1'");
    modal->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modal->setHeaderData(1, Qt::Horizontal, tr("Nazwa produktu"));
    ui->tableViewProduct->setModel(modal);
    closeDB();
}

void MainWindow::on_pushButtonNapoje_clicked()
{
    openDB();
    QSqlQueryModel *modal = new QSqlQueryModel;
    modal->setQuery("SELECT ID_Product, Nazwa FROM Product Where ID_categories='2'");
    modal->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modal->setHeaderData(1, Qt::Horizontal, tr("Nazwa produktu"));
    ui->tableViewProduct->setModel(modal);
    closeDB();

}

void MainWindow::on_pushButtonMakarony_clicked()
{
    openDB();
    QSqlQueryModel *modal = new QSqlQueryModel;
    modal->setQuery("SELECT ID_Product, Nazwa FROM Product Where ID_categories='3'");
    modal->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modal->setHeaderData(1, Qt::Horizontal, tr("Nazwa produktu"));
    ui->tableViewProduct->setModel(modal);
    closeDB();
}

void MainWindow::on_pushButtonSlodycze_clicked()
{
    openDB();
    QSqlQueryModel *modal = new QSqlQueryModel;
    modal->setQuery("SELECT ID_Product, Nazwa FROM Product Where ID_categories='4'");
    modal->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modal->setHeaderData(1, Qt::Horizontal, tr("Nazwa produktu"));
    ui->tableViewProduct->setModel(modal);
    closeDB();
}

void MainWindow::on_pushButtonOK_clicked()
{
    openDB();

    QString ID;
    ID=ui->lineEdit->text();

    if(!mydb.isOpen()){
        qDebug()<<"Nie udało się otworzyć bazy danych";
        return;
    }
    if(ID=='1'){
        QSqlQueryModel *modal = new QSqlQueryModel;
        modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='1'");
        modal->setHeaderData(0, Qt::Horizontal, tr("Skład produktu"));
        ui->tableViewIngredients->setModel(modal);

        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='1'");
        ui->tableViewCalorieChart->setModel(model);

        closeDB();

        QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/maslo.jpg");
        ui->labelPhoto_2->setPixmap(pix);

    }
    else{
        if(ID=='2'){
        QSqlQueryModel *modal = new QSqlQueryModel;
        modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='2'");
        modal->setHeaderData(0, Qt::Horizontal, tr("Skład produktu"));
        ui->tableViewIngredients->setModel(modal);

        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='2'");
        ui->tableViewCalorieChart->setModel(model);

        closeDB();

        QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/czekolada.png");
        ui->labelPhoto_2->setPixmap(pix);

        }
        else{
            if(ID=='3'){
            QSqlQueryModel *modal = new QSqlQueryModel;
            modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='3'");
            ui->tableViewIngredients->setModel(modal);

            QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='3'");
            ui->tableViewCalorieChart->setModel(model);

            closeDB();

            QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/cola.jpg");
            ui->labelPhoto_2->setPixmap(pix);

            }
            else{
                if(ID=='4'){
                QSqlQueryModel *modal = new QSqlQueryModel;
                modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='4'");
                modal->setHeaderData(0, Qt::Horizontal, tr("Skład produktu"));
                ui->tableViewIngredients->setModel(modal);

                QSqlQueryModel *model = new QSqlQueryModel;
                model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='4'");
                ui->tableViewCalorieChart->setModel(model);

                closeDB();

                QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/ciastka.png");
                ui->labelPhoto_2->setPixmap(pix);

                }
                else{
                    if(ID=='5'){
                    QSqlQueryModel *modal = new QSqlQueryModel;
                    modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='5'");
                    ui->tableViewIngredients->setModel(modal);

                    QSqlQueryModel *model = new QSqlQueryModel;
                    model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='5'");
                    ui->tableViewCalorieChart->setModel(model);

                    closeDB();

                        QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/kokardki.png");
                        ui->labelPhoto_2->setPixmap(pix);

                    }
                    else{
                        if(ID=='6'){
                        QSqlQueryModel *modal = new QSqlQueryModel;
                        modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='6'");
                        modal->setHeaderData(0, Qt::Horizontal, tr("Skład produktu"));
                        ui->tableViewIngredients->setModel(modal);

                        QSqlQueryModel *model = new QSqlQueryModel;
                        model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='6'");
                        ui->tableViewCalorieChart->setModel(model);

                        closeDB();

                        QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/swiderki.jpg");
                        ui->labelPhoto_2->setPixmap(pix);

                        }
                        else{
                            if(ID=='7'){
                            QSqlQueryModel *modal = new QSqlQueryModel;
                            modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='7'");
                            ui->tableViewIngredients->setModel(modal);

                            QSqlQueryModel *model = new QSqlQueryModel;
                            model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='7'");
                            ui->tableViewCalorieChart->setModel(model);

                            closeDB();

                            QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/lipton.jpg");
                            ui->labelPhoto_2->setPixmap(pix);

                            }
                            else{
                                if(ID=='8'){
                                QSqlQueryModel *modal = new QSqlQueryModel;
                                modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='8'");
                                modal->setHeaderData(0, Qt::Horizontal, tr("Skład produktu"));
                                ui->tableViewIngredients->setModel(modal);

                                QSqlQueryModel *model = new QSqlQueryModel;
                                model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='8'");
                                ui->tableViewCalorieChart->setModel(model);

                                closeDB();

                                QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/mleko.jpg");
                                ui->labelPhoto_2->setPixmap(pix);

                                }
                                else{
                                    if(ID=='9'){
                                    QSqlQueryModel *modal = new QSqlQueryModel;
                                    modal->setQuery("SELECT sklad FROM Ingredients Where ID_ing='9'");
                                    modal->setHeaderData(0, Qt::Horizontal, tr("Skład produktu"));
                                    ui->tableViewIngredients->setModel(modal);

                                    QSqlQueryModel *model = new QSqlQueryModel;
                                    model->setQuery("SELECT Wartosc_energetyczna, Tluszcz, Weglowodany, Blonnik, Bialko, Sol FROM CalorieChart Where ID_calorieChart='9'");
                                    ui->tableViewCalorieChart->setModel(model);

                                    closeDB();

                                    QPixmap pix("C:/Users/mazur/Documents/projekt01/APProducts/sok.png");
                                    ui->labelPhoto_2->setPixmap(pix);
                                    }
                                    else{
                                    ui->labelPhoto_2->clear();
                                    ui->labelError->setText("Podałeś Złe ID!");
                                    }
                                }
                            }
                         }
                      }
                   }
               }
          }
    }


}
