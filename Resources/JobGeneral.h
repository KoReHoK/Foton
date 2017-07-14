#pragma once

#include "LoadDll.h"
#include "JobStuct.h"

class CJobGeneral : public CLoadDll
{
public:
	CJobGeneral(char* path);
	virtual ~CJobGeneral(void);
	virtual int Init(int idx = 0);
	

	int SetStatusGeneral(void* in);
	int GetStatus();

	int DevicesRun(bool flag);
	int GetFocus(IN void* params);

	int CameraPreviewStart(HWND wnd, int camera = 0);
	int CameraDrawHistoStart(HWND wnd);
	int CameraPreviewStop(int camera = 0);
	int CameraFrameSave(char* path, int camera = 0);
	int CameraSettingsSet(quint8 inData=0, int camera = 0);
	int CameraFlippingSet(bool flipX, bool flipY);
	int CameraSetMask(int id, int camera = 0);
	int CameraSetMode(int mode, HWND wnd);
	int CameraSetMeasure( CameraMeasure* measure );
	int CameraAutoExposure();

	int DeskJoyWork(bool x, bool y, bool z);
	int DeskJoySpeed(char x, char y, char z);
	int DeskSpeedMove(float x, float y, float z);
	int DeskCurrentMove(quint8 x, quint8 y, quint8 z);
	int DeskMoveAbs(float x_mm, float y_mm, float z_mm);
	int DeskMoveRel(float x_mm, float y_mm, float z_mm);
	int DeskMoveStep(int x, int y, int z);


	int DeskStop();

	int SwitchLight(bool flag);
	int GetLastMesage(char* mess, int maxSizeInBuff);
	int SaveOneFramePosition(float x, float y);
	int ObjectiveSwitch(int id);

	int FindBestFocusPosition(bool param);

	int SeMaxZPos(float pos_mm);
	virtual CStatusCameraAndDesk* pStatus()
	{
		return (CStatusCameraAndDesk*)  pStructStatus;
	}
	
protected:
	void *pStructStatus;
	char m_LastMessage[256];
};
