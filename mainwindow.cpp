#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include "ellipse.h"
#include "pointline.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(820,840);
    ui->setupUi(this);
    setMouseTracking(true);
    
    
    //Setting up the graphicsscene
    scene->setSceneRect(0, 0, 800, 600);
    
 
  
    //Setting up graphicsview
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    view->show();


    //Adding a combobox for selecting shape
    selector->addItem("Rectangle");
    selector->addItem("Ellipse"); 
    selector->addItem("Line");
    for (int i = 0; i < selector->count(); i++) {
        selector->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    //Create erase button
    
    erase->setGeometry(730, 0, 80, 40);
    erase->setCheckable(true);
    connect(erase, &QPushButton::clicked, scene, &QGraphicsScene::clear);

    //Adjusts QLineEdit Widgets

    x->setPlaceholderText("x position");
    y->setPlaceholderText("y position");
    width->setPlaceholderText("width");
    height->setPlaceholderText("height");

    //Creating Draw Button

    draw->setCheckable(true);
    connect(draw, SIGNAL(clicked()), this, SLOT(drawButtonClicked()));

    //Add widgets to layout
    createLayout();

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

        deleteLayout();
        createLayout();
        Rectangle* rect = new Rectangle();
        rect->setRect(0, 0, rwidth, rheight);
        scene->addItem(rect);
        rect->setPos(rx, ry);
        rect->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        rect->setFlag(QGraphicsItem::ItemIsFocusable);
        rect->setFocus();
    }
    else if (rselect == "Ellipse") {
        //pointLine->hide();
        deleteLayout();
        createLayout();
        Ellipse* ellipse = new Ellipse();
        ellipse->setRect(0, 0, rwidth, rheight);
        scene->addItem(ellipse);
        ellipse->setPos(rx, ry);
        ellipse->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        ellipse->setFlag(QGraphicsItem::ItemIsFocusable);
        ellipse->setFocus();

        

    }
    else if (rselect == "Line") {
        
        QPoint pos(rx, ry);
        PointLine* pointLine = new PointLine(pos, rwidth);
        pointLine->setWindowTitle("Line");
        pointLine->resize(800, 600);
        layout->replaceWidget(view, pointLine);
        pointLine->show();
        connect(draw, SLOT(clicked), pointLine, SLOT(hide()));

        

    }
}
void MainWindow::createLayout() {
    layout->addWidget(view);
    layout->addWidget(x);
    layout->addWidget(y);
    layout->addWidget(width);
    layout->addWidget(height);
    layout->addWidget(draw);
    layout->addWidget(erase);
    layout->addWidget(selector);
}
void MainWindow::deleteLayout() {
    for (int i = 0; i < layout->count(); i++) {
        layout->removeItem(0);
    }
}
