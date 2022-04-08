#include "mainwindow.h"
#include "ui_mainwindow.h"

template <typename T>
void addItem(vector<T> v, T t)
{
    v.push_back(t);
}

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

void MainWindow::on_pushButton_3_clicked() //tp
{
    goRoom("teleport");
}

void MainWindow::on_pushButton_5_clicked() //east
{
    goRoom("east");
}

void MainWindow::on_pushButton_2_clicked() //south
{
    goRoom("south");
}

void MainWindow::goRoom(string direction)
{
    if (direction == "teleport")
        {
            ui->textEdit->append(QString::fromStdString(zork->teleport() + "\n"));
            if (zork->getCurrentRoom().description == "outside")
            {
                endGameState();
            }
        }
        else
        {
            ui->textEdit->append(QString::fromStdString(zork->go(direction) + "\n"));

            if (zork->getCurrentRoom().description == "outside")
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
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);


    ui->textEdit->setText(QString::fromStdString("Congratulations you are outside!! \nEnjoy the fresh air!"));


}

void MainWindow::on_pushButton_6_clicked() //map
{
    ui->textEdit->append(QString::fromStdString(zork->printMap()));
}

void MainWindow::on_pushButton_7_clicked() // help
{
    ui->textEdit->append(QString::fromStdString(zork->printHelp()));
}

void MainWindow::on_pushButton_8_clicked() // play wordle
{
    ui->textEdit->append(QString::fromStdString(zork->printWordle()));
}

void MainWindow::on_pushButton_9_clicked() //inventory
{
     ui->textEdit->append(QString::fromStdString(character.longDescription()));
}


void MainWindow::on_pushButton_10_clicked() // add item to inventory
{
   /*

    Room r = zork->getCurrentRoom();    // get room
    Item m = r.??;                      // see what item is in room
    character.additem(m);               // add to inventory
    r.removeItem(m):                    // remove from room

    ui->textEdit->append("You took the " + m);

    */
}

