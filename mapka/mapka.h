#ifndef MAPKA_H
#define MAPKA_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>

namespace Ui {
class Mapka;
}

class Mapka : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Mapka(QWidget *parent = 0);
    ~Mapka();

    QGraphicsScene Scena;

    QGraphicsEllipseItem *Robot1;
    QGraphicsEllipseItem *Robot2;

    int krok;
    QTransform Przesuniecie;
    
private slots:

    void on_gora_clicked();

    void on_prawo_clicked();

    void on_dol_clicked();

    void on_lewo_clicked();

    void on_Zoom_valueChanged(int value);

private:
    Ui::Mapka *ui;
};

#endif // MAPKA_H
