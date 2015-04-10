#include "mainwindow.h"
#include <QToolBar>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent){
setMinimumSize(640,480);

QToolBar * tbar = new QToolBar;
tbar = new QToolBar(this);
tbar->addAction(tr("Открыть"),this,SLOT(okClicked()));
tbar->addSeparator();
tbar->addAction(tr("Редактировать"),this,SLOT(on_btnOk_clicked()));
tbar->addSeparator();
tbar->addAction(tr("Удалить"),this,SLOT(on_btnOk_clicked()));

    this->addToolBar(tbar); // vot zdes nado skazat QMainWindow, chto u nego est toolbar!!!


QTextEdit *text = new QTextEdit;
text= new QTextEdit(this);
text->setGeometry(110,30,200,420);


QTextEdit *text1 = new QTextEdit;
text1= new QTextEdit(this);
text1->setGeometry(330,30,200,420);

//QVBoxLayout *Layout = new QVBoxLayout;  //здесь я хотел добавить на форму Layout и на нем попытаться распложить текстовые поля
 // Layout->addWidget(textedit);


QVBoxLayout *lay = new QVBoxLayout(this);
lay->addWidget(text);

QVBoxLayout *lay1 = new QVBoxLayout(this);
lay1->addWidget(text1);



QVBoxLayout *layout = new QVBoxLayout;
   layout->addWidget(text);
   layout->addWidget(text1);

   this->setLayout(layout);

}

void MainWindow::okClicked(){
// a zdes realizuem kazdjy slot
    qDebug()<<"ok clicked";




    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
             tr("Text Files (*.txt)"));

         if (fileName != "") {
             QFile file(fileName);
             if (!file.open(QIODevice::ReadOnly |  QIODevice::Text))
             {

                 QMessageBox::critical(this, tr("Error"), tr("Not open file"));
                 return;
             }


             QTextStream in(&file);
            //text1->setText(in.readAll());

            text1->setReadOnly(true);
             in<<text1;
    text1->insertPlainText(in.readAll());
         file.close();


         }

 }

/*
 void MainWindow::okClicked(){
     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
              tr("Text Files (*.txt)"));

     if (fileName != "") {
         QFile file(fileName);
         if (!file.open(QIODevice::ReadWrite |  QIODevice::Text))
         return;

    // if (sender() == okClicked)
         text->setText(fileName);
    // else if (sender() == okClicked)
      //   text1->setText(fileName);


    }

}
*/
