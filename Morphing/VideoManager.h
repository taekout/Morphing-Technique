#pragma once

#include <cv.h>
#include <highgui.h>
#include <cxcore.h>

using namespace std;

class VideoManager
{
public:
	CvVideoWriter *writer;

	VideoManager(void);
	void Initialize(string filename, int fourcc, double fps, CvSize framesize, int iscolor = 1);
	void AddFrame(IplImage * img);
	void ReleaseVideoWrite(void);

public:
	~VideoManager(void);
};
