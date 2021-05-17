#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "module_bluetoth/device.h"
//#include <QBluetoothDeviceDiscoveryAgent>
//#include <QBluetoothDeviceInfo>
//#include <QLowEnergyController>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Device *NixBlDev;
  //  QVariant *ListDev;


private slots:
    void on_pushButton_clicked();
    //void deviceDiscovered(const QBluetoothDeviceInfo &device);
     void deviceDiscovered();
     void servicesUpd();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_led_button_clicked();

private:
    Ui::MainWindow *ui;
  //  void startDeviceDiscovery();
  // QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
  // QLowEnergyController *m_control;
};
#endif // MAINWINDOW_H
