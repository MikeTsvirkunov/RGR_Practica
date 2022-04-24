#include "graphic.h"
#include "ui_graphic.h"
#include <QWidget>
#include <QDebug>
#include <fstream>
#include <vector>
#include <string.h>
#include <QString>
#include <mainwindow.h>>

using namespace std;

Graphic::Graphic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphic)
{
    ui->setupUi(this);
}

Graphic::~Graphic()
{
    delete ui;
}

int sr_znach(vector <int> x){
    int c = 0;
    for (int i=0; i < x.size()-1; i++) c+=x[i];
    return c/x.size();
}

int max_znach(vector <int> x){
    int c = x[1];
    for (int i=0; i < x.size()-1; i++) if (c< abs(x[i])) c=x[i];
    return c;
}

void Graphic::paintEvent(QPaintEvent *)
{
    int max_wid = width()-93;
    QPainter paint;
    vector <int> dots_graph;
    ifstream file("t_v.txt");
    string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
                qDebug() << QString::fromStdString(line);
                if (stoi(line) < 0) dots_graph.push_back(abs(stoi(line)));
        }
    }
    int sr_line = abs(sr_znach(dots_graph));
    int h = abs(max_znach(dots_graph));
    int x1, y1, x2, y2;

    file.close();
    paint.begin(this);
    QPen pen;
    for (int i=1; i<dots_graph.size(); i++){
//        update();
        x1 = ((i-1) * max_wid / dots_graph.size());
        y1 = abs(height() * (height()-dots_graph[i-1]) / h);
        x2 = ((i) * max_wid / dots_graph.size());
        y2 = abs(height() * (height()-dots_graph[i]) / h);
        qDebug()<<x1<<" "<<y1<<" / "<<x2<<" "<<y2;
        if (y1 < y2) pen.setColor(Qt::red);
        else if(y1 == y2) pen.setColor(Qt::yellow);
        else pen.setColor(Qt::green);
        pen.setWidth(5);
        paint.setPen(pen);
        paint.drawLine(x1, y1, x2, y2);
    }
    /*pen.setColor(Qt::red);
    pen.setStyle(Qt::DashDotDotLine);
    pen.setWidth(5);
    paint.setPen(pen);
    paint.drawLine(0, 0, width(), height());
    pen.setColor(Qt::green);
    paint.setPen(pen);
    paint.drawLine(0, 0, max_wid, height())*/;
    paint.end();

}




void Graphic::on_pushButton_clicked()
{
    hide();
    MainWindow *mw = new MainWindow(this);
    mw->show();
}

