#include "dialog3.h"
#include<QLabel>
#include<QLayout>
#include<QVBoxLayout>
#include<QRect>
#include<QMenuBar>
#include<QFont>
#include<QListWidget>

Dialog3::Dialog3(QWidget* parent,Container<Engineering*>ptr):QDialog(parent),eng(ptr){


     setWindowTitle(tr("list of student(s)."));
     setWindowIcon(QIcon(":/imag/images/info.jpg"));
     QPalette pal = palette();
     pal.setColor(QPalette::Background,Qt::darkCyan);
     setPalette(pal);


         QListWidget* wid= new QListWidget();


         for(int i=0; i<eng.getSize();i++)
            wid->addItem(QString::fromStdString("Student name: " + eng.At(i)->getStudentName()) + QString::fromStdString("   ") +
                         QString::fromStdString("Student number: "+ eng.At(i)->getStudentNumber())  + QString::fromStdString("   ") +
                         QString::fromStdString("Faculty: "+ eng.At(i)->getFacultyName()));

         QVBoxLayout* lay=new QVBoxLayout(this);
         for(int i=0; i<eng.getSize()+1; i++)
            lay->addWidget(wid);

}


void Dialog3::accept(){
   close();
}
