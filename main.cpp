#include "mainwindow.h"
#include <QtDebug>
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"
#include "vehicule.h"
#include "equipement.h"


int main(int argc, char *argv[])
{  QApplication a(argc, argv);
    QApplication::setStyle("plastique");
    Connexion c;


  bool test=c.ouvrirConnexion();
  MainWindow w;
  if(test)
  {w.show();

      QMessageBox::information(nullptr, QObject::tr("database is  open"),
                  QObject::tr("connection avec succées.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();}
