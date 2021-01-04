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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   ui->ID_E->setValidator->(new QIntValidator(100, 999, this));
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
        ui->tableView_4->setModel(v.Afficher());

        QMessageBox::information(nullptr, QObject::tr("modifier vehicule"),
                    QObject::tr("modification avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier vehicule"),
                    QObject::tr("modification échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_cherche_v_clicked(const QString &arg1)
{
    QString q=arg1;
       if(q=="")
       {
           ui->tableView_5->setModel(v.Afficher());
       }
       else {ui->tableView_5->setModel(v.recherche(q));}


}




void MainWindow::on_pushButton_2_clicked()
{

        QString strStream;
                                   QTextStream out(&strStream);
                                   const int rowCount = ui->tableView->model()->rowCount();
                                   const int columnCount =ui->tableView->model()->columnCount();

                                   out <<  "<html>\n"
                                           "<head>\n"
                                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                           <<  QString("<title>%1</title>\n").arg("Equipement")
                                           <<  "</head>\n"
                                           "<body bgcolor=#ffffff link=#5000A0>\n"
                                               "<img src='C:/Users/asus/Desktop/logo.jpg' width='100' height='100'>\n"
                                               "<h1>Equipement </h1>"



                                               "<table border=1 cellspacing=0 cellpadding=2>\n";


                                   // headers
                                       out << "<thead><tr bgcolor=#f0f0f0>";
                                       for (int column = 0; column < columnCount; column++)
                                           if (!ui->tableView->isColumnHidden(column))
                                               out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                       out << "</tr></thead>\n";
                                       // data table
                                          for (int row = 0; row < rowCount; row++) {
                                              out << "<tr>";
                                              for (int column = 0; column < columnCount; column++) {
                                                  if (!ui->tableView->isColumnHidden(column)) {
                                                      QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                                      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                  }
                                              }
                                              out << "</tr>\n";
                                          }
                                          out <<  "</table>\n"
                                              "</body>\n"
                                              "</html>\n";
                                          QTextDocument * document = new  QTextDocument ();

                               document->setHtml(strStream);



                               //QPrinter printer(QPrinter::PrinterResolution);

                                                         //  document-> setHtml (strStream);

                                                         //  QPrinter QPrinter;

                                                         //  QPrintDialog * dialog = new  QPrintDialog (& QPrinter, NULL );
                                                          // if (dialog-> exec () == QDialog::Accepted) {
                                                             //  document-> print (& QPrinter);}
    }

void MainWindow::on_pushButton_7_clicked()
{
    =new statistique(this);

}
