#include "aeronautic.h"

Aeronautic::Aeronautic(const string& sname,const string& snum,const string& fn, const string& loc, int con , const string& dip, int math, int logic,const string& lt,int lts,int medC):
    Mechanical_Engineering(sname,snum,fn,loc,con,dip,math,logic),Stud_name(sname),stud_num(snum),Laurea_Triennale(lt),LaureaScore(lts),concorsoScore(medC){}


Aeronautic::~Aeronautic(){}

string Aeronautic::responsiblename="Ndoumen Nya Yannick";


string Aeronautic::getResponsibleName()const{
    return responsiblename;
}


bool Aeronautic::access(int lts, int con)const{

    return (lts>=24 && lts<=30 && con >=12 && con <=20);
}


string Aeronautic::Academic_Employment_Opportunities()const{

        return "Academic Employment Opportunities: Fullfil your study in Doctorate degree as researcher in aerospace o aeronautical.";
}


string Aeronautic::Professional_Employment_Opportunities()const{

    return "Professional Employment Opportunities: Work in aerospace as engineer or the aviation field.";
}


string Aeronautic::Educational_Pathway()const{

    return "Educational Pathway: The formation has a duration of 36 months.And the access is only for those students having a Degrre in mechanical Engineering.";

}


string Aeronautic::getLaureaTriennale()const{

    return Laurea_Triennale;
}


int Aeronautic::getLaureaScore()const{

    return LaureaScore;
}


int Aeronautic::getConcorsoScore()const{

    return concorsoScore;
}


string Aeronautic::getType()const{

    return "Aeronautic";
}

string Aeronautic::getStudentName()const{

    return Stud_name;
}

string Aeronautic::getStudentNumber()const{

    return stud_num;
}

string Aeronautic::getFacultyName()const{

    return Engineering::getFacultyName();
}

