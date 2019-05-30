#pragma once
#ifdef _OPENCV
#inlcude <opencv2/core.hpp>
#endif
class CZernikeCal
{
public:
	CZernikeCal();
	~CZernikeCal();
	float* calZernikeCoef(float *datacenter);
	float* calPhase(float *zernikeCoef);
	float *phase;
	float getRmsValue();
	float getPvValue();

	float *zernikeCoef;
private:
	float **zerInvMatrix;
	float **zernikeMat;
	int nbItem;

	float phaseRms;
	float phasePV;

	bool initMatrix();

#ifdef _OPENCV
	cv::Mat zerInvMat;
#endif
};

