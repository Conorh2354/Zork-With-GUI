#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->append(QString::fromStdString(zork->printWelcome() + "\n"));
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked() //north
{
    goRoom("north");
}

void MainWindow::on_pushButton_4_clicked() //west
{
    goRoom("west");
}

void MainWindow::on_pushButton_2_clicked() //south
{
    goRoom("south");
}

void MainWindow::on_pushButton_5_clicked() //east
{
    goRoom("east");
}

void MainWindow::on_pushButton_3_clicked() //teleport
{
    goRoom("teleport");
}

void MainWindow::on_pushButton_6_clicked() //print map
{
     ui->textEdit->append(QString::fromStdString(zork->map() + "\n"));
}

void MainWindow::on_pushButton_7_clicked() // print help
{
    ui->textEdit->append(QString::fromStdString(zork->printHelp()));
}

void MainWindow::on_pushButton_8_clicked() //play wordle
{
     ui->textEdit->append(QString::fromStdString(zork->playWordle() + "\n"));
}



void MainWindow::goRoom(string direction)
{

        if (direction == "teleport")
        {
            ui->textEdit->append(QString::fromStdString(zork->teleport() + "\n"));
        }
        else
        {
            ui->textEdit->append(QString::fromStdString(zork->go(direction) + "\n"));

            if (zork->getCurrentRoom().description == "j")
            {
                endGameState();
            }
        }
}

void MainWindow::endGameState()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);


    ui->textEdit->setText(QString::fromStdString("You have won the game, You reached room J!"));


}









