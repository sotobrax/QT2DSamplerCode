#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QInputDialog>
#include <QLineEdit>
#include <iostream>
#include <string>
#include <vector>
#include <QDebug>
#include <QComboBox>
#include <QMouseEvent>
#include <QPainter>
#include "pointline.h"
#include "circle.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createLayout();

    void createLineLayout();
    void createCircleofLinesLayout();

private:
    Ui::MainWindow *ui;
    QComboBox* selector = new QComboBox(this);
    QLineEdit* x = new QLineEdit(this);
    QLineEdit* y = new QLineEdit(this);
    QLineEdit* width = new QLineEdit(this);
    QLineEdit* height = new QLineEdit(this);
    QLineEdit* radius = new QLineEdit(this);
    QGraphicsScene* scene = new QGraphicsScene(this);
    QGridLayout* layout = new QGridLayout;
    QGraphicsView* view = new QGraphicsView(scene);
    QPushButton* erase = new QPushButton("Erase", this);
    QPushButton* draw = new QPushButton("Draw", this);
    PointLine* pointLine = new PointLine();
    Circle *circle = new Circle();
    QComboBox* color = new QComboBox(this);
private slots:
    void drawButtonClicked();
    void selectorBoxChanged();
    void eraseClicked();

};









