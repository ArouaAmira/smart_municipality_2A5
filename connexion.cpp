#include "connexion.h"
#include <QSqlError>

//test Tutoriel GIT



Connexion::Connexion(){}

bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("projet_2A");
                           db.setUserName("amira");//inserer nom de l'utilisateur
                           db.setPassword("557200");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur ParamÃ©tres"+db.lastError().text());
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
