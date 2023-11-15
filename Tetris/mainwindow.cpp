#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QTimer>
#include <QEventLoop>


std::pair<QLabel*,Node> fieldArray[22][10];
Piece current;
bool Gamestarted = false;
int piecesUsed = 0;
int currentSpeed = 0;
int speed[10] = {1000,900,800,700,600,500,400,300,200,100};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createFieldArray(){

    int width = 100;
    int height = 0;

    for(int rad = 0; rad < 22; rad++){

        for(int kolumn = 0; kolumn <10; kolumn++){

            std::pair<QLabel*,Node> temp;
            QLabel *label = new QLabel(this);
            label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
            label->setStyleSheet("background-color:black;");
            label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
            label->setGeometry(width,height,25,25);
            if(rad >1)
                label->show();
            temp.first = label;
            temp.second.y = rad;
            temp.second.x = kolumn;
            temp.second.colour = ("background-color:black;");
            fieldArray[rad][kolumn] = temp;
            width += 26;
        }
        height += 26;
        width = 100;
    }
}

int MainWindow::getSpeed()
{
    if(piecesUsed > 7 && piecesUsed <= 14)
        return 1;
    if(piecesUsed > 14 && piecesUsed <= 21)
        return 2;
    if(piecesUsed > 21 && piecesUsed <= 28)
        return 3;
    if(piecesUsed > 28 && piecesUsed <= 35)
        return 4;
    if(piecesUsed > 35 && piecesUsed <= 42)
        return 5;
    if(piecesUsed > 42 && piecesUsed <= 49)
        return 6;
    if(piecesUsed > 49 && piecesUsed <= 56)
        return 7;
    if(piecesUsed > 56 && piecesUsed <= 63)
        return 8;
    if(piecesUsed > 63)
        return 9;

    return 0;
}

void MainWindow::dropNewPiece()
{
    piecesUsed += 1;
    if(currentSpeed < 9)
    currentSpeed = getSpeed();

    QEventLoop loop;
    QTimer::singleShot(500,&loop,SLOT(quit()));
    loop.exec();
    int i = rand() % 7;

    if(i == 0)
        pieceCube();
    if(i == 1)
        pieceLine();
    if(i == 2)
        pieceRightL();
    if(i == 3)
        pieceLeftL();
    if(i == 4)
        pieceShortT();
    if(i == 5)
        pieceRightZ();
    if(i == 6)
        pieceLeftZ();
    current.anchor.first = 1;
    current.anchor.second = 5;
}

void MainWindow::drawField()
{
    for (int rad = 2; rad < 22; rad ++){

        for(int kolumn = 0; kolumn < 10; kolumn++){
            if (fieldArray[rad][kolumn].second.isTaken){
                continue;
            }
            if(current.anchor.first == rad && current.anchor.second == kolumn){
                fieldArray[rad][kolumn].first->setStyleSheet(current.colour);
                continue;
            }

            if(current.node2.first == rad && current.node2.second == kolumn){
                fieldArray[rad][kolumn].first->setStyleSheet(current.colour);
                continue;
            }

            if(current.node3.first == rad && current.node3.second == kolumn){
                fieldArray[rad][kolumn].first->setStyleSheet(current.colour);
                continue;
            }

            if(current.node4.first == rad && current.node4.second == kolumn){
                fieldArray[rad][kolumn].first->setStyleSheet(current.colour);
                continue;
            }
            else{
                fieldArray[rad][kolumn].first->setStyleSheet(fieldArray[rad][kolumn].second.colour);
            }
        }
    }
}

void MainWindow::convertValuesXY() // returnerar koordinater till var det ska ritas
{

    current.node2.first = current.anchor.first + current.node2.first;
    current.node2.second = current.anchor.second + current.node2.second;
    current.node3.first = current.anchor.first + current.node3.first;
    current.node3.second = current.anchor.second + current.node3.second;
    current.node4.first = current.anchor.first + current.node4.first;
    current.node4.second = current.anchor.second + current.node4.second;

}

void MainWindow::pieceCube() // returnerar förberedande värden till convertValuesXY
{

    current.colour = ("background-color:yellow;");
    current.pieceID = 0;

    if(current.rotation == 0){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 1;
        current.node3.second =-1;
        current.node4.first = 1;
        current.node4.second =0;
    }
    if(current.rotation == 1){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 1;
        current.node3.second =-1;
        current.node4.first = 1;
        current.node4.second =0;
    }
    if(current.rotation == 2){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 1;
        current.node3.second =-1;
        current.node4.first = 1;
        current.node4.second =0;
    }
    if(current.rotation == 3){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 1;
        current.node3.second =-1;
        current.node4.first = 1;
        current.node4.second =0;
    }
}

void MainWindow::pieceLine()
{
    current.colour = ("background-color:blue;");
    current.pieceID = 1;

    if(current.rotation == 0){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = 2;
        current.node4.second = 0;
    }
    if(current.rotation == 1){
        current.node2.first = 0;
        current.node2.second = -2;
        current.node3.first = 0;
        current.node3.second = -1;
        current.node4.first = 0;
        current.node4.second = 1;
    }
    if(current.rotation == 2){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = 2;
        current.node4.second = 0;
    }
    if(current.rotation == 3){
        current.node2.first = 0;
        current.node2.second = -2;
        current.node3.first = 0;
        current.node3.second = -1;
        current.node4.first = 0;
        current.node4.second = 1;
    }

}

void MainWindow::pieceRightL()
{
    current.colour = ("background-color:orange;");
    current.pieceID = 2;

    if(current.rotation == 0){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = 1;
        current.node4.second = 1;
    }
    if(current.rotation == 1){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 0;
        current.node3.second = 1;
        current.node4.first = 1;
        current.node4.second = -1;
    }
    if(current.rotation == 2){
        current.node2.first = 1;
        current.node2.second = 0;
        current.node3.first = -1;
        current.node3.second = 0;
        current.node4.first = -1;
        current.node4.second = -1;
    }
    if(current.rotation == 3){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 0;
        current.node3.second = 1;
        current.node4.first = -1;
        current.node4.second = 1;
    }
}

void MainWindow::pieceLeftL()
{
    current.colour = ("background-color:green;");
    current.pieceID = 3;

    if(current.rotation == 0){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = 1;
        current.node4.second = -1;
    }
    if(current.rotation == 1){
        current.node2.first = 0;
        current.node2.second = 1;
        current.node3.first = 0;
        current.node3.second = -1;
        current.node4.first = -1;
        current.node4.second = -1;
    }
    if(current.rotation == 2){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = -1;
        current.node4.second = 1;
    }
    if(current.rotation == 3){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 0;
        current.node3.second = 1;
        current.node4.first = 1;
        current.node4.second = 1;
    }
}

void MainWindow::pieceShortT()
{
    current.colour = ("background-color:purple;");
    current.pieceID = 4;

    if(current.rotation == 0){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 0;
        current.node3.second = 1;
        current.node4.first = 1;
        current.node4.second = 0;
    }
    if(current.rotation == 1){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = 0;
        current.node4.second = -1;
    }
    if(current.rotation == 2){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 0;
        current.node3.second = 1;
        current.node4.first = -1;
        current.node4.second = 0;
    }
    if(current.rotation == 3){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = 0;
        current.node4.second = 1;
    }
}

void MainWindow::pieceRightZ()
{
    current.colour = ("background-color:red;");
    current.pieceID = 5;

    if(current.rotation == 0){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = -1;
        current.node3.second = 0;
        current.node4.first = -1;
        current.node4.second = 1;
    }
    if(current.rotation == 1){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 0;
        current.node3.second = 1;
        current.node4.first = 1;
        current.node4.second = 1;
    }
    if(current.rotation == 2){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = -1;
        current.node3.second = 0;
        current.node4.first = -1;
        current.node4.second = 1;
    }
    if(current.rotation == 3){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 0;
        current.node3.second = 1;
        current.node4.first = 1;
        current.node4.second = 1;
    }
}

void MainWindow::pieceLeftZ()
{
    current.colour = ("background-color:pink;");
    current.pieceID = 6;

    if(current.rotation == 0){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = 1;
        current.node4.second = 1;
    }
    if(current.rotation == 1){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 0;
        current.node3.second = -1;
        current.node4.first = 1;
        current.node4.second = -1;
    }
    if(current.rotation == 2){
        current.node2.first = 0;
        current.node2.second = -1;
        current.node3.first = 1;
        current.node3.second = 0;
        current.node4.first = 1;
        current.node4.second = 1;
    }
    if(current.rotation == 3){
        current.node2.first = -1;
        current.node2.second = 0;
        current.node3.first = 0;
        current.node3.second = -1;
        current.node4.first = 1;
        current.node4.second = -1;
    }
}

void MainWindow::clearLines(int lines[])
{
    int i = 0;

    for (int rad = 2; rad < 22; rad ++){ // för att radera rader som är fullständiga

        for(int kolumn = 0; kolumn < 10; kolumn++){

            if (lines[i] == rad){
                fieldArray[rad][kolumn].second.isTaken = false;
                fieldArray[rad][kolumn].second.colour =("background-color:black;");
                fieldArray[rad][kolumn].first->setStyleSheet("background-color:black;");
                if(kolumn == 9 && rad == lines[i]){
                    i++;
                }
            }
        }
    }
    for(int iterations = 0; iterations < 4; iterations++){ // För att flytta ner spelfältet

        for (int rad = 20; rad > 2; rad --){

            for(int kolumn = 0; kolumn < 10; kolumn++){

                if(rad < lines[iterations]){

                    QString tempColour = fieldArray[rad][kolumn].second.colour;
                    fieldArray[rad][kolumn].second.colour = fieldArray[rad+1][kolumn].second.colour;
                    fieldArray[rad+1][kolumn].second.colour = tempColour;

                    bool tempBool = fieldArray[rad][kolumn].second.isTaken;
                    fieldArray[rad][kolumn].second.isTaken = fieldArray[rad+1][kolumn].second.isTaken;
                    fieldArray[rad+1][kolumn].second.isTaken = tempBool;

                    fieldArray[rad+1][kolumn].first->setStyleSheet(fieldArray[rad+1][kolumn].second.colour);
                }
            }
        }
    }
}


void MainWindow::checkForFulllines()
{
    int clearedLines[4]{0,0,0,0};
    int i = 0;
    bool linesFound = false;

    for (int rad = 2; rad < 22; rad ++){

        for(int kolumn = 0; kolumn < 10; kolumn++){
            if(!fieldArray[rad][kolumn].second.isTaken){
                break;
            }
            if(kolumn == 9){
                clearedLines[i] = rad;
                linesFound = true;
                i++;
                break;
            }

        }
    }

    if(linesFound)
        clearLines(clearedLines);
}


bool MainWindow::checkCollision_Horisontal_Left()
{
    if(fieldArray[current.anchor.first][current.anchor.second-1].second.isTaken || current.anchor.second < 1)
        return true;
    if(fieldArray[current.node2.first][current.node2.second-1].second.isTaken || current.anchor.second < 1)
        return true;
    if(fieldArray[current.node3.first][current.node3.second-1].second.isTaken || current.anchor.second < 1)
        return true;
    if(fieldArray[current.node4.first][current.node4.second-1].second.isTaken || current.anchor.second < 1)
        return true;
    else
        return false;
}

bool MainWindow::checkCollision_Horisontal_Right()
{
    if(fieldArray[current.anchor.first][current.anchor.second+1].second.isTaken)
        return true;
    if(fieldArray[current.node2.first][current.node2.second+1].second.isTaken)
        return true;
    if(fieldArray[current.node3.first][current.node3.second+1].second.isTaken)
        return true;
    if(fieldArray[current.node4.first][current.node4.second+1].second.isTaken)
        return true;
    else
        return false;

}

bool MainWindow::checkCollision_Vertical()
{
    if(current.anchor.first == 21 || current.node2.first == 21 || current.node3.first == 21 || current.node4.first == 21) // kolla denna
        return true;
    if(fieldArray[current.anchor.first+1][current.anchor.second].second.isTaken)
        return true;
    if(fieldArray[current.node2.first+1][current.node2.second].second.isTaken)
        return true;
    if(fieldArray[current.node3.first+1][current.node3.second].second.isTaken)
        return true;
    if(fieldArray[current.node4.first+1][current.node4.second].second.isTaken)
        return true;
    else
        return false;
}

void MainWindow::checkGameOver()
{
    for (int i = 0; i <10; i++){
        if(fieldArray[2][i].second.isTaken){
            Gamestarted = false;
        }
    }
}

void MainWindow::lockPieceOnField()
{
    for (int rad = 2; rad < 22; rad ++){

        for(int kolumn = 0; kolumn < 10; kolumn++){

            if(current.anchor.first == rad && current.anchor.second == kolumn){
                fieldArray[rad][kolumn].second.colour = current.colour;
                fieldArray[rad][kolumn].first->setStyleSheet(fieldArray[rad][kolumn].second.colour);
                fieldArray[rad][kolumn].second.isTaken = true;
            }
            if(current.node2.first == rad && current.node2.second == kolumn){
                fieldArray[rad][kolumn].second.colour = current.colour;
                fieldArray[rad][kolumn].first->setStyleSheet(fieldArray[rad][kolumn].second.colour);
                fieldArray[rad][kolumn].second.isTaken = true;
            }
            if(current.node3.first == rad && current.node3.second == kolumn){
                fieldArray[rad][kolumn].second.colour = current.colour;
                fieldArray[rad][kolumn].first->setStyleSheet(fieldArray[rad][kolumn].second.colour);
                fieldArray[rad][kolumn].second.isTaken = true;
            }
            if(current.node4.first == rad && current.node4.second == kolumn){
                fieldArray[rad][kolumn].second.colour = current.colour;
                fieldArray[rad][kolumn].first->setStyleSheet(fieldArray[rad][kolumn].second.colour);
                fieldArray[rad][kolumn].second.isTaken = true;
            }

        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

    if((e->key() == Qt::Key_Left))
    {
        if(current.anchor.second >0 && current.node2.second >0 && current.node3.second >0 && current.node4.second >0 && !checkCollision_Horisontal_Left())
            current.anchor.second -= 1;
        onClick();
        return;
    }
    if((e->key() == Qt::Key_Right))
    {
        if(current.anchor.second <9 && current.node2.second <9 && current.node3.second <9 && current.node4.second <9 && !checkCollision_Horisontal_Right())
            current.anchor.second += 1;
        onClick();
        return;
    }
    if(e->key() == Qt::Key_Down)
    {
        if(current.anchor.first <21 && current.node2.first <21 && current.node3.first <21 && current.node4.first <21 && !checkCollision_Vertical())
            current.anchor.first += 1;
        onClick();
        return;
    }
    if(e->key() == Qt::Key_Up)
    {
        if(!checkCollision_Horisontal_Left() && !checkCollision_Horisontal_Right()){
            if((current.pieceID == 1 && current.anchor.second < 2) || (current.pieceID == 1 && current.anchor.second >8) || (current.pieceID == 4 && current.anchor.second >8)
                    ||(current.pieceID == 6 && current.anchor.second >8) || (current.pieceID == 5 && current.anchor.second <1) || (current.pieceID == 3 && current.anchor.second >8)
                    ||(current.pieceID == 2 && current.anchor.second >8))
                return;

            current.rotationBeforeModulo += 1;
            current.rotation = current.rotationBeforeModulo % 4;
            onClick();
            return;
        }
        else return;
    }

}

void MainWindow::onClick()
{
    if(current.pieceID == 0)
        pieceCube();
    if(current.pieceID == 1)
        pieceLine();
    if(current.pieceID == 2)
        pieceRightL();
    if(current.pieceID == 3)
        pieceLeftL();
    if(current.pieceID == 4)
        pieceShortT();
    if(current.pieceID == 5)
        pieceRightZ();
    if(current.pieceID == 6)
        pieceLeftZ();

    convertValuesXY();
    drawField();
}

void MainWindow::on_New_Game_clicked(){

    if(!Gamestarted){
        createFieldArray();
        dropNewPiece();
        convertValuesXY();
        drawField();
        Gamestarted = true;
        gameLoop();
    }
    else
        return;
}

void MainWindow::gameLoop()
{
    while(Gamestarted){

        QEventLoop loop;
        QTimer::singleShot(speed[currentSpeed],&loop,SLOT(quit()));
        loop.exec();
        onClick();
        checkGameOver();
        if(checkCollision_Vertical()){
            lockPieceOnField();
            dropNewPiece();
        }
        checkForFulllines();
        if(!checkCollision_Vertical())
        current.anchor.first +=1;
    }
    if(!Gamestarted){
        currentSpeed = 0;
        QWidget *wdg = new QWidget;
        QLabel *label = new QLabel(wdg);
        wdg->setGeometry(810,400,220,220);
        label->setText("Game Over");
        label->setGeometry(0,0,220,200);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size: 20px;");
        label->show();
        wdg->show();
    }
}


void MainWindow::on_Exit_clicked()
{
    Gamestarted = false;
    QApplication::quit();
}

