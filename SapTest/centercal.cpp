#include "centercal.h"
#include <stdio.h>
#define MAXTHRESH 8000

centercal::centercal()
{
	defaultMask = new int[TOTALMASK];
	for (int i = 0; i < TOTALMASK; i++)
	{
		defaultMask[i] = 0;
	}
	readMask();
	imageHeight = 240;
	imageWidth = 240;
	subHeight = 10;
	subWidth = 10;
	iSubNum = 24;
	jSubNum = 24;
}


centercal::~centercal()
{
}
void centercal::setThresh(float thresh)
{
	if (thresh > 1 && thresh < MAXTHRESH)
	threshhold = thresh;
}
float centercal::getThresh()
{
	return threshhold;
}
void centercal::setImSize(int width, int height)
{
	imageWidth = width;
	imageHeight = height;
}
void centercal::setSubSize(int subwidth, int subheight)
{
	subWidth = subwidth;
	subHeight = subheight;
	iSubNum = imageHeight / subHeight;
	jSubNum = imageWidth / subWidth;
}
void centercal::setvalidSubNum(int validNum)
{
	validSubNum = validNum;
}
void centercal::calCenter(short *image, float *datacenter, int *mask = 0)
{
	if (mask == NULL)
		mask = defaultMask;
	int validIndex = 0;
	for (int i = 0; i < iSubNum; i++)
	{
		for (int j = 0; j < jSubNum; j++)
		{
			if (mask[i*jSubNum + j] == 1)
			{
				calSubCenterThresh(image, i, j, &(datacenter[validIndex]), &(datacenter[validIndex + validSubNum]));
				validIndex++;
			}			    
		}
	}
}

void centercal::calSubCenterThresh(short *image, int iSubIndx,int jSubIndex,float *xcenter, float *ycenter)
{
	float iSum = 0, jSum = 0, pixelSum = 0;
	int iOffset = iSubIndx * subHeight;
	int jOffset = jSubIndex * subWidth;
	for (int i = 0; i < subHeight; i++)
	{
		for (int j = 0; j < subWidth; j++)
		{
			short pixelValue = image[(iOffset + i)*imageWidth + (jOffset + j)];
			if (pixelValue > threshhold)
			{
				iSum += i * pixelValue;
				jSum += j * pixelValue;
				pixelSum += pixelValue;
			}
		}// end second for
	}//end first for
	*xcenter = iSum / pixelSum;
	*ycenter = jSum / pixelSum;
}

bool centercal::readMask()
{
	FILE *maskFile = fopen("mask349.txt", "r");
	if (maskFile == NULL)
		return false;
	for (int i = 0; i < TOTALMASK; i++)
	{
		fscanf(maskFile, "%d", defaultMask[i]);
	}
	fclose(maskFile);
	validSubNum = 0;
	for (int i = 0; i < TOTALMASK; i++)
	{
		if (defaultMask[i] == 1)
			validSubNum++;
	}
	return true;
}