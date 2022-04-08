#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "ZorkUL.h"
#include "Character.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class Character;
    friend class Room;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void endGameState();
    void addItemsToListWidget(vector<Item> item);

private:
    Ui::MainWindow *ui;
    ZorkUL *zork = new ZorkUL();
    void goRoom(string direction);
    Character character = *new Character("Joe");
    bool putInInventory;
    void listItems(vector<Item> items, QString description);










private slots:
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
};
#endif // MAINWINDOW_H
