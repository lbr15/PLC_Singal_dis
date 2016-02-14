#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "def.h"
//=========================================================================//
//DB_W 将8进制转化为2进制数字显示
QString Byte_to_Bit (unsigned char indata)
{
    QString str="0";
    S8 st;
    for(char i=0;i<8;i++)
    {
        if(indata&(1<<i))
            st='1';
        else
            st='0';
        str[14-2*i]=st;
    }
    return str;
}
//=========================================================================//
//DB_W 刷新显示数据
QString Refesh_dis()
{
    QString dis="0";
    dis = "SIG 寄存器数值 : ";
    dis += Byte_to_Bit(123)+" || ";
    dis += Byte_to_Bit(456)+" || ";
    return dis;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(Refesh_dis());
}

MainWindow::~MainWindow()
{
    delete ui;
}
