#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    //new
    fileName01 = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{
    //open
    QString file02 = QFileDialog::getOpenFileName(this,"Open the selected file");
    if(!file02.isEmpty())
    {
        QFile openedFile01(file02);
        if(openedFile01.open(QFile::ReadOnly | QFile::Text))
        {

            fileName01 = file02;
            QTextStream in(&openedFile01);
            QString text01 = in.readAll();
            openedFile01.close();

            ui->textEdit->setPlainText(text01);
        }
    }

}

void MainWindow::on_actionSave_triggered()
{
    //save
    QFile openedFile01(fileName01);
    if (openedFile01.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&openedFile01);

        out << ui->textEdit->toPlainText();


        openedFile01.close();
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    //save as
}

void MainWindow::on_actionCopy_triggered()
{
    //copy
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    //cut
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    //paste
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    //undo
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    //redo
    ui->textEdit->redo();
}
