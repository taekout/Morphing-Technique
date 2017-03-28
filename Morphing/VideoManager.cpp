#include "VideoManager.h"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

using namespace std;

VideoManager::VideoManager(void)
{
	writer = NULL;
}

VideoManager::~VideoManager(void)
{
}

void VideoManager::Initialize(string filename, int fourcc, double fps, CvSize framesize, int isColor)
{
	writer=cvCreateVideoWriter(filename.c_str() , fourcc, //example >  CV_FOURCC('P','I','M','1'),
		fps, framesize, isColor);
}

void VideoManager::AddFrame(IplImage * img)
{
	cvWriteFrame(writer, img);      // add the frame to the file
}

void VideoManager::ReleaseVideoWrite(void)
{
	cvReleaseVideoWriter(&writer);
}
