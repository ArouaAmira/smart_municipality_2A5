#include "equipement.h"
#include <QMessageBox>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

equipement::equipement()
{
ID_E=0;
NOM="";
REFERENCE="";
}


equipement::equipement(int id,QString nom,QString reference)
{
ID_E=id;
NOM=nom;
REFERENCE=reference;
}

int equipement::getID_E()
{return ID_E;}

QString equipement::get_NOM()
{return NOM;}


QString equipement::get_REFERENCE()
{return REFERENCE;}


void equipement::setid_e(int id_e) {this->ID_E=id_e;}
void equipement::setnom(QString nom) {this->NOM=nom;}
void equipement::setreference(QString reference) {this->REFERENCE=reference;}







bool equipement::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(ID_E);
    query.prepare("INSERT INTO  equipement(ID_E,NOM,REFERENCE) VALUES(:ID_E, :NOM,  :REFERENCE)");
    query.bindValue(":ID_E",res);
    query.bindValue(":NOM",NOM);
    query.bindValue(":REFERENCE",REFERENCE);

    return query.exec();
}



QSqlQueryModel * equipement::Afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from equipement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REFERENCE"));


    return model;
}



bool equipement::modifier(int, QString, QString)
{
    QSqlQuery query;
    QString Mid= QString::number(ID_E);

    query.prepare("update equipement set nom=:nom,reference=:reference where id_e=:id_e");
    query.bindValue(":id_e", Mid);
    query.bindValue(":nom", NOM);
    query.bindValue(":reference", REFERENCE);
    return query.exec();
}


QSqlQueryModel * equipement::afficher_equipement()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select ID_E from equipement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));


            return model;


}


bool equipement::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("delete from equipement where ID_E= :ID_E ");
    query.bindValue(":ID_E", res);

    return    query.exec();
}




QSqlQueryModel * equipement::recherche(const QString &ress)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from equipement where ((ID_E || NOM|| REFERENCE) LIKE '%"+ress+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_e"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("reference "));

    return model;
}






QSqlQueryModel *  equipement::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from equipement order by "+critere+" "+mode+"");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
    return model;
}











