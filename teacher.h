#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>

namespace Ui {
class Teacher;
}

class Teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();

private slots:
    void on_ComeBack_clicked();
    void on_pushButton_2_clicked();


    void on_StopButton_clicked();

private:
    bool flag_key_catch = false;
    int letter = 0;
    Ui::Teacher *ui;

protected:
    void keyPressEvent(QKeyEvent *e) override;
    bool get_flag();
    void change_flag();
};

#endif // TEACHER_H
