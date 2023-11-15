#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

struct Node{

    bool isTaken = false;
    int x = 0;
    int y = 0;
    QString colour;
};

struct Piece{
    std::pair<int,int> anchor= {0,0};
    std::pair<int,int> node2 = {0,0};
    std::pair<int,int> node3 = {0,0};
    std::pair<int,int> node4 = {0,0};
    int rotationBeforeModulo;
    int rotation = 0;
    int pieceID = 0;
    QString colour;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_New_Game_clicked();
    void createFieldArray();
    void drawField();
    void pieceCube();
    void pieceLine();
    void pieceRightL();
    void pieceLeftL();
    void pieceShortT();
    void pieceRightZ();
    void pieceLeftZ();
    void checkForFulllines();
    void clearLines(int lines[4]);
    void convertValuesXY();
    bool checkCollision_Horisontal_Left();
    bool checkCollision_Horisontal_Right();
    bool checkCollision_Vertical();
    void checkGameOver();
    int getSpeed();
    void lockPieceOnField();
    void dropNewPiece();
    void onClick();
    void gameLoop();
    void keyPressEvent(QKeyEvent *e) override;


    void on_Exit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
