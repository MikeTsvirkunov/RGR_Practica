#include "teacher.h"
#include "ui_teacher.h"
#include "mainwindow.h"
#include <string.h>
#include "stdlib.h"
#include <time.h>
#include <QString>
#include <QDebug>
#include <QKeyEvent>



using namespace std;

class StringShow{
private:
    string str;
    string const letters[26] = {"q", "w", "e", "r", "t", "y", "u", "i", "o", "p",
                          "a", "s", "d", "f", "g", "h", "j", "k", "l", "z",
                          "x", "c", "v", "b", "n", "m"};
    float *t_ind;
    int max_len;
    int flag;

public:
    StringShow(string str2="start", int max_l=10){
        str = str2;
        t_ind = new float[max_l-1];
        max_len = max_l;
        for (int i = 0; max_l>i; i++) t_ind[i] = 1.15;
        flag = 0;
    }

    void gen(){
        flag = 0;
        str = "";
        srand(time(NULL));
        for (int i = 0; max_len>i; i++) str += letters[0 + rand() % (26)];
    }

    string get(){
        return str;
    }

    int get_int_present(){
        return int(str[flag]);
    }

    string get_str_present(){
        string x = "";
        for (int i=0; flag>=i; i++) x+=str[i];
        return x;
    }

    void move_flag_up(){
        flag++;
        if (flag == max_len) flag = 0;
    }
    void move_flag_down(){
        flag--;
        if (flag == max_len) flag = max_len-1;
    }
};


StringShow str = StringShow();

Teacher::Teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
}

Teacher::~Teacher()
{
    delete ui;
}

void Teacher::on_ComeBack_clicked()
{
    hide();
    MainWindow *mw = new MainWindow(this);
    mw->show();
}


void Teacher::keyPressEvent(QKeyEvent *e){
    letter = int(e->key());
    if (flag_key_catch){
//        qDebug()<<letter<<" "<<str.get_int_present();
        if (str.get() == str.get_str_present()){
            str.gen();
            ui->ShowLabel->setText(QString::fromStdString(str.get()));
            ui->ShowLabel->setStyleSheet("font-size: 22pt");
            ui->InputLabel->setText("");
            ui->InputLabel->setStyleSheet("background-color: white; font-size: 22pt");

        }
        else{
            if (letter == str.get_int_present()-32){
                ui->InputLabel->setText(QString::fromStdString(str.get_str_present()));
                ui->InputLabel->setStyleSheet("background-color: green; font-size: 22pt");
                str.move_flag_up();

            }
            else{
                ui->InputLabel->setStyleSheet("background-color: red; font-size: 22pt");
            }
        }
    }
}

bool Teacher::get_flag(){
    return flag_key_catch;
}

void Teacher::change_flag(){
    flag_key_catch = not(flag_key_catch);
}

void Teacher::on_pushButton_2_clicked()
{
    str.gen();
    ui->ShowLabel->setText(QString::fromStdString(str.get()));
    ui->ShowLabel->setStyleSheet("font-size: 22pt");
    flag_key_catch = true;
}


void Teacher::on_StopButton_clicked()
{
    flag_key_catch = false;
}

