#include "vehicule.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

vehicule::vehicule()
{
ID_V=0;
NOM="";
REFERENCE="";
}


vehicule::vehicule(int id_v,QString nom,QString reference)
{
ID_V=id_v;
NOM=nom;
REFERENCE=reference;
}


int vehicule::getID_V()
{ return ID_V;}
QString vehicule::get_NOM()
{return NOM;}
QString vehicule::get_REFERENCE()
{return REFERENCE;}


void vehicule::setid_v(int id_v) {this->ID_V=id_v;}
void vehicule::setnom(QString nom) {this->NOM=nom;}
void vehicule::setreference(QString reference) {this->REFERENCE=reference;}









bool vehicule::ajouter()
{
    QSqlQuery query;
    QString ress=QString::number(ID_V);
    query.prepare("INSERT INTO  vehicule(ID_V,NOM,REFERENCE) VALUES(:ID_V, :NOM, :REFERENCE)");
    query.bindValue(":ID_V",ress);
    query.bindValue(":NOM",NOM);
    query.bindValue(":REFERENCE",REFERENCE);

    return query.exec();
}



QSqlQueryModel * vehicule::Afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REFERENCE"));


    return model;
}

QSqlQueryModel * vehicule::Afficher_vehicule()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
    return model;


}

bool vehicule::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("delete from vehicule where ID_V= :ID_V ");
    query.bindValue(":ID_V", res);

    return    query.exec();
}





bool vehicule::modifier(int, QString, QString)
{
    QSqlQuery query;
    QString Mid= QString::number(ID_V);

    query.prepare("update vehicule set nom=:nom,reference=reference where id_v=:id_v");
    query.bindValue(":id_v", Mid);
    query.bindValue(":nom", NOM);
    query.bindValue(":reference",REFERENCE);
    return query.exec();
}






QSqlQueryModel * vehicule::recherche(const QString &ress)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from CIT where ((ID_V || NOM|| REFERENCE) LIKE '%"+ress+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_v"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("reference "));

    return model;
}










