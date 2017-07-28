#ifndef MAPSVIEWER_H
#define MAPSVIEWER_H

#include <QWidget>
#include <QToolBar>
#include <QPen>
#include <QDebug>

#include "cyberglobal.h"


/* RSSI,Received signal strength indication */
struct vRSSI{
    QString SSID;                   //Source device ID
    unsigned SSID_index;            //Source device tag
    float dBm;                      //Received signal strength
    float distance;
};

struct vLaunch{
    float dBm;                      //wifi signal strength
    float distance;
};

struct vAntenna{
    unsigned rssis_size;
    QVector<vRSSI> rssis;
    QPoint antXY;
    vLaunch lau;
};

/* WAP,Wireless Access Point */
struct vWAP{
    QString SSID;                  //ID
    unsigned index;                //tag
    unsigned antenna_size;
    QVector<vAntenna> ant;
    QPoint wapXY;
};

struct vStyle{
    int R;
    int G;
    int B;
    Qt::BrushStyle bStyle;
};

namespace Ui {
class MapsViewer;
}

class MapsViewer : public QWidget
{
    Q_OBJECT

public:
    explicit MapsViewer(QWidget *parent = 0);
    ~MapsViewer();
    void drawWAPs(WAP *waps, const unsigned waps_size);

protected:
    void paintEvent(QPaintEvent *event);

private:
    //ui
    Ui::MapsViewer *ui;

    //螢幕
    float rate;
    float Woutset;
    float Houtset;
    QPen pen;
    volatile bool isSetting;
    volatile bool isVDist;  //is view Distance

    //Style
    vStyle *style;

    //value
    QVector<vWAP> waps;

private slots:
    void btn_sw_dD_Click();
};

#endif // MAPSVIEWER_H
