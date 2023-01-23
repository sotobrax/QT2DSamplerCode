#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(820,700);
    ui->setupUi(this);

    //Setting up the graphicsscene
    scene->setSceneRect(0, 0, 800, 600);

    //add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(800,600);
    view->show();


    //Create erase button
    QPushButton *erase = new QPushButton("Erase", this);
    erase->setGeometry(730, 0, 80, 40);
    erase->setCheckable(true);
    connect(erase, &QPushButton::clicked, scene, &QGraphicsScene::clear);

    //Adjusts QLineEdit Widgets
    x->setGeometry(10,0,60,40);
    x->setPlaceholderText("x position");
    y->setGeometry(70,0,60,40);
    y->setPlaceholderText("y position");


    width->setGeometry(130,0,60,40);
    width->setPlaceholderText("width");

    height->setGeometry(190,0,60,40);
    height->setPlaceholderText("height");

    //Creating Draw Button
    QPushButton *draw = new QPushButton("Draw", this);
    draw->setGeometry(250, 0, 80, 40);
    draw->setCheckable(true);
    connect(draw, SIGNAL(clicked()), this, SLOT(drawButtonClicked()));


    //Creating a layout
    QHBoxLayout *layout = new QHBoxLayout;

    //Add widgets to layout
    layout->addWidget(view);
    //layout->addWidget(x);
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
    scene->clear();
    
    //Create Item
    Rectangle* rect = new Rectangle();
    rect->setRect(0, 0, rwidth, rheight);
    scene->addItem(rect);
    rect->setPos(rx, ry);
    rect->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    
    
}
