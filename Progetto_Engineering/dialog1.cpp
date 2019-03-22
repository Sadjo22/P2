#include "dialog1.h"
#include<QLabel>
#include<QLayout>
#include<QVBoxLayout>
#include<QRect>
#include<QMenuBar>
#include<QFont>
#include<QListWidget>


dialog1::dialog1 (QWidget* parent, Container<string>mo):QDialog(parent),cont(mo){


     setWindowTitle(tr("Faculty Students name"));
     setWindowIcon(QIcon(":/imag/images/eng.jpeg"));
     setGeometry(250,250,250,250);
     QPalette pal = palette();
     pal.setColor(QPalette::Background,Qt::darkCyan);
     setPalette(pal);

    QListWidget* wid= new QListWidget();


     int y= cont.getSize();
     wid->addItem(QString::fromStdString("Numero di studenti iscritti: ")+QString::fromStdString(" ")
                  + QString::fromStdString(to_string(cont.getSize())));

     for(int i=0; i<y; i++){

         wid->addItem(QString::fromStdString(cont.At(i)));
     }

     QVBoxLayout* lay=new QVBoxLayout(this);
     for(int i=0; i<y+1; i++)
       lay->addWidget(wid);

}


void dialog1::accept(){
   close();
}

