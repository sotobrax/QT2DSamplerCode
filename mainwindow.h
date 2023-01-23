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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QLineEdit* x = new QLineEdit(this);
    QLineEdit* y = new QLineEdit(this);
    QLineEdit* width = new QLineEdit(this);
    QLineEdit* height = new QLineEdit(this);
    QGraphicsScene* scene = new QGraphicsScene(this);
public slots:
    void drawButtonClicked();
    //void checkInput(QLineEdit& text);
};

