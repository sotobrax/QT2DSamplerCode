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
    //Setting up color selector for Rectangle and Ellipse
    color->addItem("Red");
    color->addItem("Black");
    color->addItem("Blue");
    color->addItem("Orange");
    color->addItem("Purple");
    color->addItem("Yellow");
    color->addItem("White");
    color->addItem("Brown");

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
    QString rcolor = color->currentText();

    //Clears scene everytime draw is clicked
    scene->clear();

    
    //Create Rectangle Item
    if (rselect == "Rectangle") {
        Rectangle* rect = new Rectangle();
        rect->setRect(0, 0, rwidth, rheight);
        scene->addItem(rect);
        rect->setPos(rx, ry);
        QColor col;
        col.setNamedColor(rcolor);
        rect->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        QBrush brush;
        brush.setColor(col);
        brush.setStyle(Qt::SolidPattern);
        rect->setBrush(brush);

        rect->setFlag(QGraphicsItem::ItemIsFocusable);
        rect->setFocus();
    }
    //Create Ellipse Item
    else if (rselect == "Ellipse") {
        Ellipse* ellipse = new Ellipse();
        ellipse->setRect(0, 0, rwidth, rheight);
        QColor col;
        col.setNamedColor(rcolor);

        QBrush brush;
        brush.setColor(col);
        brush.setStyle(Qt::SolidPattern);
        ellipse->setBrush(brush);

        scene->addItem(ellipse);
        ellipse->setPos(rx, ry);
        ellipse->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        ellipse->setFlag(QGraphicsItem::ItemIsFocusable);
        ellipse->setFocus();

        

    }
    //Create Line Item
    else if (rselect == "Line") {   
        QColor col;
        col.setNamedColor(rcolor);
        QPoint pos(rx, ry);
        pointLine->setPos(pos);
        pointLine->setWidth(rwidth);
        pointLine->setColor(col);
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
        circle->setColor(color);
        circle->setPoints(rx);
        circle->setOrigin(xy);
        circle->setRadius(rradius);
        layout->replaceWidget(view, circle);

        circle->show();
        
    }
}

//Function to change layout for Rectangle and Ellipse
void MainWindow::createLayout() {
    for (int i = 0; i < layout->count(); i++) {
        layout->removeItem(layout->itemAt(i));
    }
    pointLine->hide();
    circle->hide();
    x->clear();
    y->clear();
    width->clear();
    height->clear();
    radius->hide();
    color->show();
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
    layout->addWidget(color);
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
    circle->hide();
    color->show();
    
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
    layout->addWidget(color);
    layout->addWidget(draw);
    layout->addWidget(erase);
    layout->addWidget(selector);
    pointLine->setFixedSize(800, 600);
    layout->removeWidget(height);
    
    
}
//Creating UI Layout for circle of lines
void MainWindow::createCircleofLinesLayout() {
    for (int i = 0; i < layout->count(); i++) {
        layout->removeItem(layout->itemAt(i));
    }
    pointLine->hide();
    circle->hide();
    color->hide();
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
    if (selector->currentText() == "Circle of Lines") {
        createCircleofLinesLayout();
    }
    
}
