#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include "ellipse.h"
#include "pointline.h"
#include "Circle.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Adjusts the MainWindow
    setFixedSize(820,870);
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
    selector->addItem("Circle of Lines");
    //Sets allignment of text to the middle
    for (int i = 0; i < selector->count(); i++) {
        selector->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    //Calls function to adjust the widget layout
    connect(selector, SIGNAL(activated(int)), this, SLOT(selectorBoxChanged()));


    //Create erase button
    erase->setGeometry(730, 0, 80, 40);
    erase->setCheckable(true);
    //Calls erase slots
    connect(erase, &QPushButton::clicked, scene, &QGraphicsScene::clear);
    connect(erase, SIGNAL(clicked()), this, SLOT(eraseClicked()));



    //Creating Draw Button
    draw->setCheckable(true);
    //Calls draw slot
    connect(draw, SIGNAL(clicked()), this, SLOT(drawButtonClicked()));

    

    //Add widgets to layout
    createLayout();
    this->centralWidget()->setLayout(layout);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function that is called whenever draw is clicked
void MainWindow::drawButtonClicked()
{
    //Grab user inputs
    int rx = x->displayText().toInt();
    int ry = y->displayText().toInt(); 
    int rwidth = width->displayText().toInt(); 
    int rheight = height->displayText().toInt();
    int rradius = radius->displayText().toInt();
    string rselect = selector->currentText().toStdString();

    //Clears scene everytime draw is clicked
    scene->clear();

    
    //Create Rectangle Item
    if (rselect == "Rectangle") {
        Rectangle* rect = new Rectangle();
        rect->setRect(0, 0, rwidth, rheight);
        scene->addItem(rect);
        rect->setPos(rx, ry);
        rect->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        rect->setFlag(QGraphicsItem::ItemIsFocusable);
        rect->setFocus();
    }
    //Create Ellipse Item
    else if (rselect == "Ellipse") {
        Ellipse* ellipse = new Ellipse();
        ellipse->setRect(0, 0, rwidth, rheight);
        scene->addItem(ellipse);
        ellipse->setPos(rx, ry);
        ellipse->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        ellipse->setFlag(QGraphicsItem::ItemIsFocusable);
        ellipse->setFocus();

        

    }
    //Create Line Item
    else if (rselect == "Line") {   
        QPoint pos(rx, ry);
        pointLine->setPos(pos);
        pointLine->setWidth(rwidth);
        layout->replaceWidget(view, pointLine);
        pointLine->show();
    }
    //Create a circle of lines
    else if (rselect == "Circle of Lines") {
        //rx = points
        //ry = red
        //rwidth = green
        //rheight = blue
        //rradius = radius
        QPen pen;
        QColor color;
        color.setRgb(ry, rwidth, rheight);
        pen.setColor(color);
        QPoint xy;
        xy.setX(scene->width() / 2);
        xy.setY(scene->height() / 2);
        Circle *circle = new Circle(color, rradius, rx, xy);
       // scene->addItem(circle);
        circle->show();
        
    }
}

//Function to change layout for Rectangle and Ellipse
void MainWindow::createLayout() {
    for (int i = 0; i < layout->count(); i++) {
        layout->removeItem(layout->itemAt(i));
    }
    pointLine->hide();
    x->clear();
    y->clear();
    width->clear();
    height->clear();
    radius->hide();
    //Adjusts QLineEdit Widgets
    x->setPlaceholderText("x position");
    y->setPlaceholderText("y position");
    width->setPlaceholderText("width");
    height->setPlaceholderText("height");
    
    layout->addWidget(view);
    layout->addWidget(x);
    layout->addWidget(y);
    layout->addWidget(width);
    layout->addWidget(height);
    layout->addWidget(draw);
    layout->addWidget(erase);
    layout->addWidget(selector);
    height->show();
    
}
//Layout for the Line option
void MainWindow::createLineLayout() {
    for (int i = 0; i < layout->count(); i++) {
        layout->removeItem(layout->itemAt(i));
    }
    x->setPlaceholderText("x position");
    y->setPlaceholderText("y position");
    width->setPlaceholderText("width");
    pointLine->hide();
    x->clear();
    y->clear();
    width->clear();
    height->clear();
    height->hide();
    radius->hide();
    layout->addWidget(view);
    layout->addWidget(x);
    layout->addWidget(y);
    layout->addWidget(width);
    layout->addWidget(draw);
    layout->addWidget(erase);
    layout->addWidget(selector);
    pointLine->setFixedSize(800, 600);
    layout->removeWidget(height);
    
    
}
void MainWindow::createCircleofLinesLayout() {
    for (int i = 0; i < layout->count(); i++) {
        layout->removeItem(layout->itemAt(i));
    }
    pointLine->hide();
    radius->show();
    x->clear();
    y->clear();
    width->clear();
    height->clear();
    x->setPlaceholderText("Number of Points");
    radius->setPlaceholderText("Radius");
    y->setPlaceholderText("Red Value: 0-255");
    width->setPlaceholderText("Green Value: 0-255");
    height->setPlaceholderText("Blue Value: 0-255");

    layout->addWidget(view);
    layout->addWidget(x);
    layout->addWidget(radius);
    layout->addWidget(y);
 
    layout->addWidget(width);
    layout->addWidget(height);
    
    layout->addWidget(draw);
    layout->addWidget(erase);
    layout->addWidget(selector);
    height->show();

}

//Function that is called whenever the combobox is called
void MainWindow::selectorBoxChanged()
{
    if (selector->currentText().toStdString() == "Rectangle") {
        scene->clear();

        createLayout();
    }
    else if (selector->currentText().toStdString() == "Ellipse") {
        scene->clear();
        createLayout();
    }
    else if (selector->currentText().toStdString() == "Line") {
        scene->clear();
        createLineLayout();
    }
    else if (selector->currentText().toStdString() == "Circle of Lines") {
        scene->clear();
        createCircleofLinesLayout();
    }
}
//Called whenever erase is clicked
void MainWindow::eraseClicked()
{
    if (selector->currentText() == "Line") {
        createLineLayout();
    }
    
}
