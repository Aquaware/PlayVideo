#ifndef PLAYVIDEO_H
#define PLAYVIDEO_H

#include <QtWidgets/QMainWindow>
#include "ui_playvideo.h"
#include <opencv2/opencv.hpp>
#include <QWidget>
#include <QImage>
#include <QtGui>

class playVideo : public QMainWindow
{
	Q_OBJECT

public:
	playVideo(QWidget *parent = 0);
	~playVideo();
	void play(QString videoPath);

public slots:
	void selectVideo();


private:
	Ui::playVideoClass ui;
};

#endif // PLAYVIDEO_H
