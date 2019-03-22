#include "dialog2.h"
#include<QLabel>
#include<QLayout>
#include<QVBoxLayout>
#include<QRect>
#include<QMenuBar>
#include<QFont>
#include<QListWidget>

Dialog2::Dialog2(QWidget* parent,const Engineering* ptr):QDialog(parent),eng(ptr){



     if(eng->getFacultyName()=="Mechanical Engineering"){
        setWindowTitle(tr("Mechanical Engineering Information"));
        setWindowIcon(QIcon(":/imag/images/mecanical.png"));
     }
     if(eng->getFacultyName() == "Computer Engineering"){
        setWindowTitle(tr("Computer Engineering Information"));
        setWindowIcon(QIcon(":/imag/images/comp.png"));
     }
     if(eng->getFacultyName() == "Aeronautic"){
        setWindowTitle(tr("Aeronautic Information"));
        setWindowIcon(QIcon(":/imag/images/aero.png"));
     }


     QPalette pal = palette();
     pal.setColor(QPalette::Background,Qt::darkCyan);
     setPalette(pal);

         QVBoxLayout* lay=new QVBoxLayout(this);
         QListWidget* wid= new QListWidget();
         wid->addItem(QString::fromStdString("Head of dipartment Name: ")+QString::fromStdString(" ") +QString::fromStdString(eng->getResponsibleName()));
         wid->addItem(QString::fromStdString("Faculty Location: ")+QString::fromStdString(" ") + QString::fromStdString(eng->getLocation()));
         wid->addItem(QString::fromStdString(eng->Educational_Pathway()));
         wid->addItem(QString::fromStdString(eng->Academic_Employment_Opportunities()));
         wid->addItem(QString::fromStdString(eng->Professional_Employment_Opportunities()));

         for(int i=0; i<4;i++)
            lay->addWidget(wid);

}


void Dialog2::accept(){
   close();
}
