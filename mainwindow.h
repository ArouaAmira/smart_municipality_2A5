#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "equipement.h"
#include "vehicule.h"
#include <QMainWindow>
#include "connexion.h"
#include <QIntValidator>
#include <QFile>

#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //void on_pushButton_8_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_ajouter_2_clicked();

    //void on_pushButton_14_clicked();

    void on_pushButton_supprimer_e_clicked();

    void on_pushButton_supprimer_v_clicked();


    void on_pushButton_afficher_clicked();

    void on_pushButton_afficher_2_clicked();

    //void on_pushButton_10_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


   void on_pushButton_cherche_v_clicked(const QString &);


   void on_pushButton_2_clicked();

   void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    equipement e;
    vehicule v;

};
#endif // MAINWINDOW_H
