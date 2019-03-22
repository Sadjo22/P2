#include "model.h"
#include "xmlio.h"
#include "aeronautic.h"
#include "engineering.h"
#include "computer_engineering.h"
#include "mechanical_engineering.h"
#include <QMessageBox>
#include <regex>



#include<QtAlgorithms>

Model::Model(){}


Model::~Model(){
    qDeleteAll(list);
}

void Model::saveToFile()const {
    XMLIO xmlio("../Progetto_Engineering/images/data.xml");
    xmlio.write(list);
}

void Model::loadFromFile() {
    XMLIO xmlio("../Progetto_Engineering/images/data.xml");
    list = xmlio.read();
}


void Model::AddFaculty(Engineering* eng){

     list.append(eng);
}


void Model::RemoveFaculty(int index){

 list.removeAt(index);
}

int Model::CountFaculties()const{

    return list.getSize();
}

const Engineering* Model::getFaculty(int indice)const{

     return list.At(indice);
}

// return true if the student number exist  otherwise false.
bool Model::match(const string& snum)const{
    for(auto it=list.begin(); it!= list.end();it++){
         Computer_Engineering* ptr= dynamic_cast<Computer_Engineering*>(*it);
         if(ptr){
            return ptr->getStudentNumber()== snum;
         }
         Mechanical_Engineering* pt= dynamic_cast<Mechanical_Engineering*>(*it);
         if(pt){
             return pt->getStudentNumber()== snum;
         }
         Aeronautic* aer= dynamic_cast<Aeronautic*>(*it);
         if(pt){
             return aer->getStudentNumber()== snum;
         }
    }
    return false;

}


// return a list if student name or student number mathimg the research.
Container<Engineering*> Model::searchStudent(const string& student)const{
    Container<Engineering*>std;
    for(auto it=list.begin();it!=list.end();it++){
        Computer_Engineering* ptr= dynamic_cast<Computer_Engineering*>(*it);
        if(ptr && (ptr->getStudentName() == student || ptr->getStudentNumber() == student)){
           std.append(ptr);
        }
        else{
            Mechanical_Engineering* pt= dynamic_cast<Mechanical_Engineering*>(*it);
            if(pt && (pt->getStudentName() == student || pt->getStudentNumber() == student)){
               std.append(pt);
            }
            else{
                Aeronautic* aer= dynamic_cast<Aeronautic*>(*it);
                if(aer && (aer->getStudentName() == student || aer->getStudentNumber() == student)){
                    std.append(aer);
                }
            }

        }

    }
    return std;
}

// INSERT THE STUDENT IN THE ADEQUATE FACULTY
void Model::settext(const string& sname,const string& snum,const string& fn,const string& loc,
                    int con , const string& dip, int math, int logic,const string& lt,int lts,int medC){

    regex b("(ENG)[0-9]{1,4}"); // REGULAR EXPRESSION TO USE (IT matches all the expression starting with ENG FOLLOW by 1 or 4 numbers between(0and 9))
    if(sname =="" || snum =="" || loc =="" || dip ==""){
             QMessageBox box(QMessageBox::Warning,"Filled all the fields", "*Fill out the empty field(s)", QMessageBox::Ok);
             box.exec();
   }
   else{
        if(!regex_match(snum,b)){
            QMessageBox box(QMessageBox::Warning,"Standard", "*The student Number doesn't match the standard."
                                                  "The Student Number should starts with ENG follow by one or four numbers.", QMessageBox::Ok);
            box.exec();
        }
        else{
            if((match(snum))){

                 QMessageBox box(QMessageBox::Warning,"Duplication", "*The student number cannot be duplicated.", QMessageBox::Ok);
                 box.exec();
            }
            else {
                if(fn=="Mechanical Engineering"){
                   Mechanical_Engineering* ptr = new Mechanical_Engineering(sname,snum,fn,loc,con,dip,math,logic);
                    if(ptr->access(math,logic)){
                        list.append(ptr);
                        QMessageBox box(QMessageBox::Information,"Success", "*Insertion has occurred successfully in Mechanical engineering.", QMessageBox::Ok);
                        box.exec();
                        return;
                    }
                    QMessageBox box(QMessageBox::Warning,"Failure", "*The matematic and logic score should be more o equal to 12 for access at this faculty.", QMessageBox::Ok);
                    box.exec();
                    return;

                }
                if(fn=="Computer Engineering"){
                    Computer_Engineering* ptr = new Computer_Engineering(sname,snum,fn,loc,con,dip,math,logic);
                     if(ptr->access(math,logic)){
                         list.append(ptr);
                         QMessageBox box(QMessageBox::Information,"Success", "*Insertion has occurred successfully in Computer engineering.", QMessageBox::Ok);
                         box.exec();
                         return;
                     }
                     QMessageBox box(QMessageBox::Warning,"Failure", "*The matematic and logic score should be more o equal to 14 for access at this faculty.", QMessageBox::Ok);
                     box.exec();
                     return;

                }
                if(fn=="Aeronautic"){
                    Aeronautic* ptr = new Aeronautic(sname,snum,fn,loc,con,dip,math,logic,lt,lts,medC);
                     if(ptr->access(lts,medC) && (lt !="None")){
                         list.append(ptr);
                         QMessageBox box(QMessageBox::Information,"Success", "*Insertion has occurred successfully in Aeronautic.", QMessageBox::Ok);
                         box.exec();
                         return;
                     }
                     QMessageBox box(QMessageBox::Warning,"Failure", "*The faculty is accessible at those studendent having a license with at least 24 .", QMessageBox::Ok);
                     box.exec();
                     return;
                }
            }
       }
   }
}


//list of student in mechanical engineering
Container<string> Model::Mec_StudentName()const{

    Container<string>student;

    for(auto it=list.begin(); it!= list.end();it++){

        Mechanical_Engineering* ptr= dynamic_cast<Mechanical_Engineering*>(*it);

        if(ptr && (ptr->getType() == "Mechanics")){
            student.append(ptr->getStudentName());
        }
    }
    return student;
}


//list of student in aeronautic
Container<string> Model::Aero_StudentName()const{

    Container<string>student;

    for(auto it=list.begin(); it!= list.end();it++){

        Aeronautic* ptr= dynamic_cast<Aeronautic*>(*it);
        if(ptr){
            student.append(ptr->getStudentName());
        }
    }
    return student;
}

// list of student in computer enginering
Container<string> Model::Comp_StudentName()const{

    Container<string>student;

    for(auto it=list.begin(); it!= list.end();it++){

        Computer_Engineering* ptr= dynamic_cast<Computer_Engineering*>(*it);
        if(ptr){

            student.append(ptr->getStudentName());
        }
    }
    return student;
}

