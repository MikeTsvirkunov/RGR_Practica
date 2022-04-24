#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QDialog>
#include <QPainter>

namespace Ui {
class Graphic;
}

class Graphic : public QDialog
{
    Q_OBJECT

public:
    explicit Graphic(QWidget *parent = nullptr);
    ~Graphic();

private:
    Ui::Graphic *ui;

protected:
    void paintEvent(QPaintEvent *) override;
private slots:
    void on_pushButton_clicked();
};

#endif // GRAPHIC_H
