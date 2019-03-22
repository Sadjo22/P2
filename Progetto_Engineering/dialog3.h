#ifndef DIALOG3_H
#define DIALOG3_H
#include<QDialog>
#include"mainwindow.h"
#include"model.h"
#include"engineering.h"


class Dialog3: public QDialog{

public:
    explicit Dialog3(QWidget *parent ,Container<Engineering*>);
    ~Dialog3()override{}

private:
    Container<Engineering*>eng;

private slots:
    void accept() override;
};


#endif // DIALOG3_H
