#include "playvideo.h"
#include <QtGui>
#include <QFileDialog>

playVideo::playVideo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	cv::Mat src = cv::imread("c:/tmp/sample.png", 1);
	QImage image(src.data, src.cols, src.rows, QImage::Format_RGB888);
	image = image.rgbSwapped();
	ui.outLabel->setPixmap(QPixmap::fromImage(image));
	QPushButton* button = ui.selectButton;
	connect(button, SIGNAL(clicked()), this, SLOT(selectVideo()));
}

playVideo::~playVideo()
{

}

void playVideo::selectVideo()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Video"), "/home", tr("Video Files (*.avi *.mp4 *.mpeg *.mpg)"));
	qDebug() << "Path:" << fileName;
	play(fileName);
}

void playVideo::play(QString videoPath)
{
	QFileInfo video(videoPath);
	if (video.exists()){
		const std::string path = videoPath.toUtf8().constData();
		cv::VideoCapture capture(path);
		cv::Mat frame;

		if (!capture.isOpened()){
			qDebug() << "Error, video not loaded";
		}
		int count = 0;
		while (true){
			bool success = capture.read(frame);
			if (success == false){
				break;
			}
			count++;
			//cv::imshow("window", frame);
			QImage image(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);
			image = image.rgbSwapped();
			ui.outLabel->setPixmap(QPixmap::fromImage(image));
			ui.outLabel->repaint();
			cv::String path = cv::format( "c:/tmp/image/frame%d.png", count);
			cv::imwrite(path, frame);
			cv::waitKey(20);
		}
		cv::waitKey(0);
	}
	else{
		qDebug() << "Error, File doesn't exist";
	}
}
