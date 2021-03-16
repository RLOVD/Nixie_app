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
    startDeviceDiscovery();
 //   m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Хуй");
}



void MainWindow::startDeviceDiscovery()
{
  // Create a discovery agent and connect to its signals
 // QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
 // connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
 //       this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

  // Start a discovery
// discoveryAgent->start();
//  discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

   QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
   // discoveryAgent->setLowEnergyDiscoveryTimeout(5000);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    discoveryAgent->start();//QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
}

// In your local slot, read information about the found devices
void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    //if (device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
  qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}
