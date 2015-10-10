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
	cv::VideoWriter writer;

	int fourccDib = CV_FOURCC('D', 'I', 'B', ' ');// = –³ˆ³k
	int fourccMpeg1 = CV_FOURCC('P', 'I', 'M', '1');// = MPEG - 1 codec
	int fourccMjpg = CV_FOURCC('M', 'J', 'P', 'G');// = motion - jpeg codec(does not work well)
	int fourccMpeg4_2 = CV_FOURCC('M', 'P', '4', '2');// = MPEG - 4.2 codec
	int fourccMpeg4_3 = CV_FOURCC('D', 'I', 'V', '3');// = MPEG - 4.3 codec
	int fourccDivx = CV_FOURCC('D', 'I', 'V', 'X'); // = MPEG - 4 codec
	int fourccH263 = CV_FOURCC('U', '2', '6', '3');// = H263 codec
	int fourccH263i = CV_FOURCC('I', '2', '6', '3'); //= H263I codec
	int fourccFlv1 = CV_FOURCC('F', 'L', 'V', '1');// = FLV1 codec
	int fourccAvi = CV_FOURCC('I', '4', '2', '0');
	int fourccH264 = CV_FOURCC('X', '2', '6', '4');// mp4 
	int fourccMp4 = CV_FOURCC('M', 'P', '4', 'V');// mp4 

	if (video.exists()){
		const std::string path = videoPath.toUtf8().constData();
		cv::VideoCapture capture(path);
		cv::Mat frame;

		if (!capture.isOpened()){
			qDebug() << "Error, video not loaded";
		}
		bool success = capture.read(frame);
		if (success == false){
			return;
		}
		int width = frame.cols;
		int height = frame.rows;
		cv::Size size = cv::Size(width, height);
		cv::Mat outImage = cv::Mat(size, frame.type());
		
		writer = cv::VideoWriter("c:/tmp/movie.avi", fourccH264, 30, size);
		int count = 0;
		while (true){
			if (count > 0) {
				bool success = capture.read(frame);
				if (success == false){
					break;
				}
			}

			cv::resize(frame, outImage, size);
			writer.write(outImage);
			//cv::imshow("window", frame);
			QImage image(outImage.data, outImage.cols, outImage.rows, QImage::Format_RGB888);
			image = image.rgbSwapped();
			ui.outLabel->setPixmap(QPixmap::fromImage(image));
			ui.outLabel->repaint();
			//cv::String path = cv::format( "c:/tmp/image/frame%d.png", count);
			//cv::imwrite(path, frame);
			count++;
			cv::waitKey(20);
		}
		cv::waitKey(0);
	}
	else{
		qDebug() << "Error, File doesn't exist";
	}

	writer.release();
}
