#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>

#include "square.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget w;
    QPushButton start("Start", &w);
    w.setFixedSize(640, 480);
    start.setGeometry(10,10, 80,30);

    w.show();



    QGraphicsScene scene;
    Square box;
    Square* square = new Square();
    square->setRect(0, 0, 50, 50);

    scene.addItem(square);

    QGraphicsView view(&scene);
    view.setBackgroundBrush(Qt::white);
    view.setWindowTitle("Tank Demo");
    view.setGeometry(100, 100, 600, 600);

    view.show();

    square->setFlag(QGraphicsItem::ItemIsFocusable);

    square->setFocus();


    return app.exec();
}
