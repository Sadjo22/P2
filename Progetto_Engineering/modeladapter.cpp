#include "modeladapter.h"
#include "model.h"
#include "engineering.h"
#include "mechanical_engineering.h"
#include "computer_engineering.h"
#include "aeronautic.h"

#include <QFont>
#include <QBrush>
#include <QIcon>

ModelAdapter::ModelAdapter(QObject* parent) :
    QAbstractListModel(parent),
    model(new Model()) {}

ModelAdapter::~ModelAdapter() {
    delete model;
}

/*
 * Ritorna la dimensione (numero di righe) del modello
 */
int ModelAdapter::rowCount(const QModelIndex &) const {

    return model->CountFaculties();
}



QVariant ModelAdapter::data(const QModelIndex& index, int role) const {

         if (!index.isValid() || index.row() >= model->CountFaculties())
             return QVariant();


        if (role == Qt::DisplayRole) {
             const Engineering* pt =  model->getFaculty(index.row());
             const string snum= pt->getStudentNumber();
             const string fn= pt->getFacultyName();

             return QString::fromStdString("Faculty Name: ")+  QString::fromStdString(fn)+ QString::fromStdString("   ")+QString::fromStdString("Student Number: ")+ QString::fromStdString(snum);
        }

        if(role == Qt::DecorationRole){
            const string pt = (model->getFaculty(index.row())->getType());
            if(pt=="Aeronautic"){
                QIcon graybackground(QIcon(":/imag/images/aero.png"));
                return graybackground;
            }
            
            if(pt=="Mechanics"){
                QIcon graybackground(QIcon(":/imag/images/mecanical.png"));
                return graybackground;
            }
            
            if(pt=="Informatic"){
                QIcon graybackground(QIcon(":/imag/images/comp.png"));
                return graybackground;
            }
        }


   if (role == Qt::BackgroundRole) {
       const string pt = (model->getFaculty(index.row())->getType());
       if(pt=="Aeronautic"){
           QBrush graybackground(Qt::darkGray);
           return graybackground;
       }

       if(pt=="Informatic"){

           QBrush lightbackground(Qt::lightGray);
           return lightbackground;
      }

       if(pt=="Mechanics"){

           QBrush whitebackground(Qt::white);
           return whitebackground;
       }

   }
   return QVariant();
}



void ModelAdapter::saveToFile() const {
    model->saveToFile();
}



bool ModelAdapter::removeRows(int begin, int count, const QModelIndex& parent) {
    beginRemoveRows(parent, begin, begin + count -1);
    model->RemoveFaculty(begin);
    endRemoveRows();
    return true;
}



  //upload the model in memory by reading data from xml file.

void ModelAdapter::loadFromFile() {
    model->loadFromFile();
}


void ModelAdapter::insertrow(int indice,const string& sname,const string& snum,const string& fn, const string& loc,
                             int con , const string& dip, int math, int logic,const string& lt,int lts,int medC){
    beginInsertRows(QModelIndex(),indice,indice);
    model->settext(sname,snum,fn,loc,con,dip,math,logic,lt,lts,medC);
    endInsertRows();
}


Model* ModelAdapter::getModel()const{

    return model;
}

