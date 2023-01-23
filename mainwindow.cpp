#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(820,700);
    ui->setupUi(this);

    //Creating and placing the scene
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    //Create Item
    Rectangle *rect = new Rectangle();
    rect->setRect(0,0, 100,100);

    //adding item to scene
    scene->addItem(rect);



    //add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(800,600);
    view->show();

    rect->setPos(view->width()/2 - rect->rect().width()/2, view->height()/2 - rect->rect().height()/2);
    rect->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
    //Create erase button
    QPushButton *erase = new QPushButton("Erase", this);
    erase->setGeometry(730, 0, 80, 40);
    erase->setCheckable(true);
    connect(erase, &QPushButton::clicked, scene, &QGraphicsScene::clear);

    //Create text input
    QLineEdit *x = new QLineEdit(this);
    x->setGeometry(10,0,60,40);
    x->setText("X Position");

    QLineEdit *y = new QLineEdit(this);
    y->setGeometry(70,0,60,40);
    y->setText("Y Position");

    QLineEdit *width = new QLineEdit(this);
    width->setGeometry(130,0,60,40);
    width->setText("Width");

    QLineEdit *height = new QLineEdit(this);
    height->setGeometry(190,0,60,40);
    height->setText("Height");

    //Creating Draw Button
    QPushButton *draw = new QPushButton("Draw", this);
    draw->setGeometry(250, 0, 80, 40);
    draw->setCheckable(true);
    std::vector<int> sizeArray;
    //connect(draw, SIGNAL(clicked(true)), this, SLOT(drawButtonClicked(true,x,y,width,height,sizeArray)));
    //connect(draw, &QPushButton::clicked, this, MainWindow::drawButtonClicked(true, x, y, width, height, sizeArray));
    qDebug()<< sizeArray;
    //Creating a layout
    QHBoxLayout *layout = new QHBoxLayout;

    //Add widgets to layout
    layout->addWidget(view);
    //layout->addWidget(x);
    this->centralWidget()->setLayout(layout);
    //Make item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::drawButtonClicked(bool checked, QLineEdit x, QLineEdit y, QLineEdit width, QLineEdit height, std::vector<int>& vector)
{
    
    if (checked) {
        int rx = x.displayText().toInt();
        int ry = y.displayText().toInt();
        int rwidth = width.displayText().toInt();
        int rheight = height.displayText().toInt();
        vector.push_back(rx); vector.push_back(ry); vector.push_back(rwidth); vector.push_back(rheight);
        
    }
}*/

