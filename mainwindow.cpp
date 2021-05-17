#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"Тесст";
    quint8 t;
    for (t=0;t<8 ;t++)
    {
      qDebug()<<t;
    }
    NixBlDev = new Device;
   // NixBlDev->
  //  NixBlDev->startDeviceDiscovery();

   // NixBlDev->scanServices("00:80:E1:26:CB:1A");


    //startDeviceDiscovery();
 //   m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   // ui->label->setText("Поиск");
    NixBlDev->startDeviceDiscovery();
    connect(NixBlDev, &Device::devicesUpdated,
            this, &MainWindow::deviceDiscovered);

    //ListDev = new QVariant;
   // QVariant ListDev = NixBlDev->getDevices();

}

void MainWindow::deviceDiscovered()
{
  qDebug()<< NixBlDev->getDevices().toStringList();
  connect(NixBlDev, &Device::servicesUpdated, this,
          &MainWindow::servicesUpd);
  NixBlDev->scanServices("00:80:E1:26:CB:1A");

}

void MainWindow::servicesUpd()
{
 qDebug()<<"Servise Upd" ;
}


void MainWindow::on_pushButton_2_clicked()
{
 NixBlDev->connectToService("0000fe40-cc7a-482a-984a-7f2ed5b3e58f");

}

void MainWindow::on_led_button_clicked()
{
    QByteArray Led;
    Led.resize(2);
    //Led[0]=0x01;
    //Led[1]=0x01;

    static uint8_t fl=0;
    if (!fl)
    {
     Led=QByteArray::fromHex("0101");
     ui->led_button->setText("LED ON");
    }
    else
      {
       Led=QByteArray::fromHex("0000");
       ui->led_button->setText("LED OFF");
      }

     NixBlDev->SetCharacteristics(Led,"0000fe40-cc7a-482a-984a-7f2ed5b3e58f");
     fl=~fl;
}
