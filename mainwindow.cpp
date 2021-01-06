#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include "vehicule.h"
#include "equipement.h"
#include "connexion.h"
#include <QMessageBox>
#include <QComboBox>
#include <QTabWidget>
#include <QObject>
#include <QSqlTableModel>
#include <QTextDocument>
#include <QTextStream>
#include<QMenu>
#include<QDialogButtonBox>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QFile>
#include <QIntValidator>
#include <QSound>
#include "stat.h"
#include "email.h"
#include <QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    son=new QSound("C:/Users/Amira/Documents/smart_municipality1/amira.wav");
    //ui->tableView

   //ui->ID_E->setValidator->(new QIntValidator(100, 999, this));
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_ajouter_clicked()
{

    int ID_E=ui->lineEdit_ID->text().toInt();
    QString NOM=ui->lineEdit_Nom->text();
    QString REFERENCE=ui->lineEdit_Ref->text();
    equipement e(ID_E,NOM,REFERENCE);
    bool test=e.ajouter();
    if(test)
    {
        ui->tableView->setModel(e.Afficher());

        QMessageBox::information(nullptr, QObject::tr("Ajout equipement"),
                    QObject::tr("ajout avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout equipement"),
                    QObject::tr("Ajout échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


 }









void MainWindow::on_pushButton_ajouter_2_clicked()
{

    int ID_V=ui->lineEdit_IDV ->text().toInt();
    QString NOM=ui->lineEdit_NOMV->text();
    QString REFERENCE=ui->lineEdit_refv ->text();
    vehicule v(ID_V,NOM,REFERENCE);
    bool test=v.ajouter();
    if(test)
    {
        ui->tableView_2->setModel(v.Afficher());

        QMessageBox::information(nullptr, QObject::tr("Ajout vehicule"),
                    QObject::tr("ajout avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout vehicule"),
                    QObject::tr("Ajout échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}








void MainWindow::on_pushButton_supprimer_e_clicked()
{
    int ID_E=ui->lineEdit_suppe ->text().toInt();



            bool test=e.supprimer(ID_E);
            if(test)
               {
                ui->tableView->setModel(e.Afficher());

               QMessageBox::information(nullptr,"SUPRESSION","supprimé.");}
            else
               QMessageBox::information(nullptr,"SUPRESSION","probleme suppresion");
               }









void MainWindow::on_pushButton_supprimer_v_clicked()
{

    int ID_V=ui->lineEdit_suppv ->text().toInt();


            bool test=v.supprimer(ID_V);
            if(test)
               {
                ui->tableView_2->setModel(v.Afficher());
               QMessageBox::information(nullptr,"SUPRESSION","supprimé.");}
            else
               QMessageBox::critical(nullptr,"SUPRESSION","probleme suppresion");


}



void MainWindow::on_pushButton_afficher_clicked()
{

    ui->tableView_2->setModel(v.Afficher());

}




void MainWindow::on_pushButton_afficher_2_clicked()
{
    ui->tableView->setModel(e.Afficher());



}




void MainWindow::on_pushButton_4_clicked()
{
    int ID_E=ui->lineEdit_7 ->text().toInt();
    QString NOM=ui->lineEdit_9->text();
    QString REFERENCE=ui->lineEdit_10 ->text();
    vehicule e(ID_E,NOM,REFERENCE);
    bool test=e.modifier(ID_E,NOM,REFERENCE);
    if(test)
    {
        ui->tableView_3->setModel(e.Afficher());

        QMessageBox::information(nullptr, QObject::tr("modifier vehicule"),
                    QObject::tr("modification avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier vehicule"),
                    QObject::tr("modification échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_5_clicked()
{
    int ID_V=ui->lineEdit->text().toInt();
    QString NOM=ui->lineEdit_2->text();
    QString REFERENCE=ui->lineEdit_3 ->text();
    vehicule v(ID_V,NOM,REFERENCE);
    bool test=v.modifier(ID_V,NOM,REFERENCE);
    if(test)
    {
        ui->tableView_4->setModel(v.Afficher_vehicule());

        QMessageBox::information(nullptr, QObject::tr("modifier vehicule"),
                    QObject::tr("modification avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier vehicule"),
                    QObject::tr("modification échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}





void MainWindow::on_pushButton_2_clicked()
{
email e;
e.exec();
       }

void MainWindow::on_pushButton_7_clicked()
{
   Stat s;
   s.exec();

}

void MainWindow::on_play_clicked()
{
    son->play();

}

void MainWindow::on_mute_clicked()
{
    son->stop();
}

void MainWindow::on_pushButton_8_clicked()
{

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    ui->vcher->setDisabled(false);
         QString nom=arg1;
    ui->checkBox->setDisabled(false);

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
         int ID_V=arg1;
         QString    NOM;
         QString REFERENCE;

         vehicule v(ID_V,NOM,REFERENCE);

               bool test=v.recherche(arg1,NOM,REFERENCE);
                if(test)
                   {
                    ui->tableView_5->setModel(v.Afficher());
                   }
}








