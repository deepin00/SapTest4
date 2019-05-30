#pragma once
#define TOTALMASK 576
class centercal
{
public:
	centercal();
	~centercal();
	float getThresh();
	void setvalidSubNum(int validNum);
	void setThresh(float thresh);
	void setImSize(int width, int height);
	void setSubSize(int subwidth, int subheight);
	void calCenter(short *image, float *datacenter, int *mask);
	int *defaultMask;
	int validSubNum;
	bool readMask();
private:
	float threshhold;
	int imageWidth;
	int imageHeight;
	int subWidth;
	int subHeight;
	int iSubNum;
	int jSubNum;
	
	void calSubCenterThresh(short *image, int iSubIndx, int jSubIndex,float *xcenter, float *ycenter);
};

