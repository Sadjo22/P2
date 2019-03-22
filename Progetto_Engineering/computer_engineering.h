#ifndef COMPUTER_ENGINEERING_H
#define COMPUTER_ENGINEERING_H
#include"engineering.h"


class Computer_Engineering:public Engineering
{
private:
    string Degree;
    int mathScore;
    int logicScore;
public:
    Computer_Engineering(const string&, const string&, const string&, const string&, int, const string&, int, int);
    ~Computer_Engineering();
    static int mathematics;
    static int logics;
    static string respo;
    virtual bool access(int,int)const override;
    virtual string Academic_Employment_Opportunities()const override;
    virtual string Professional_Employment_Opportunities()const override;
    virtual string Educational_Pathway()const override;
    virtual string getResponsibleName()const;
    string getDiploma()const;
    int getMathScore()const;
    int getLogicScore()const;
    virtual string getType()const override;

};

#endif // COMPUTER_ENGINEERING_H
