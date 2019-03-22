#include "engineering.h"



Engineering::Engineering(const string& sname,const string& snum,const string& fn, const string& loc, int con):Student_name(sname), student_num(snum),
  FacultyName(fn),Location(loc),concorso(con){}


string Engineering::Educational_Pathway()const{

    return "Engineering faculties  has a duration of 3 years subdivided into 6 semesters. ";

}


string Engineering::getLocation()const{

    return Location;
}


int Engineering::has_Concorso()const{

    return concorso;
}

string Engineering::getStudentNumber()const{

    return  student_num;
}

string Engineering::getType()const{

    return "Engineering";
}

string Engineering::getStudentName()const{

    return  Student_name;
}

string Engineering::getFacultyName()const{

    return  FacultyName;
}
