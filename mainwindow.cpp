#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include "ellipse.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(820,840);
    ui->setupUi(this);

    //Setting up the graphicsscene
    scene->setSceneRect(0, 0, 800, 600);

    //add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    view->show();

    //Adding a combobox for selecting shape
    selector->addItem("Rectangle"); 
    selector->addItem("Ellipse"); 
    selector->addItem("Line");

    //Create erase button
    QPushButton *erase = new QPushButton("Erase", this);
    erase->setGeometry(730, 0, 80, 40);
    erase->setCheckable(true);
    connect(erase, &QPushButton::clicked, scene, &QGraphicsScene::clear);

    //Adjusts QLineEdit Widgets

    x->setPlaceholderText("x position");
    y->setPlaceholderText("y position");
    width->setPlaceholderText("width");
    height->setPlaceholderText("height");

    //Creating Draw Button
    QPushButton *draw = new QPushButton("Draw", this);
    draw->setCheckable(true);
    connect(draw, SIGNAL(clicked()), this, SLOT(drawButtonClicked()));
    //Creating a layout
    QGridLayout *layout = new QGridLayout;
    //Add widgets to layout
    layout->addWidget(view);
    layout->addWidget(x);
    layout->addWidget(y);
    layout->addWidget(width);
    layout->addWidget(height);
    layout->addWidget(draw);
    layout->addWidget(erase);
    layout->addWidget(selector);
    this->centralWidget()->setLayout(layout);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawButtonClicked()
{
    int rx = x->displayText().toInt();
    int ry = y->displayText().toInt();
    int rwidth = width->displayText().toInt();
    int rheight = height->displayText().toInt();
    string rselect = selector->currentText().toStdString();
    qDebug() << rselect;
    cout << rselect;
    scene->clear();
    
    //Create Item
    if (rselect == "Rectangle") {
        Rectangle* rect = new Rectangle();
        rect->setRect(0, 0, rwidth, rheight);
        scene->addItem(rect);
        rect->setPos(rx, ry);
        rect->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        rect->setFlag(QGraphicsItem::ItemIsFocusable);
        rect->setFocus();
    }
    else if (rselect == "Ellipse") {
        Ellipse* ellipse = new Ellipse();
        ellipse->setRect(0, 0, rwidth, rheight);
        scene->addItem(ellipse);
        ellipse->setPos(rx, ry);
        ellipse->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        ellipse->setFlag(QGraphicsItem::ItemIsFocusable);
        ellipse->setFocus();

        

    }
}
