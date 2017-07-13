//#include "StdAfx.h"
#include "JobGeneral.h"

CJobGeneral::CJobGeneral(char* path) 
						: CLoadDll(path)
{
	pStructStatus = 0;
	pStructStatus = new CStatusCameraAndDesk();
	memset(pStructStatus, 0, sizeof(CStatusCameraAndDesk));
}

CJobGeneral::~CJobGeneral(void)
{
	SetStatusGeneral(0);
	
	if (pStructStatus) delete pStructStatus;
	pStructStatus = 0;

	ProcessFunc(20);
}

int CJobGeneral::Init(int idx)
{
	if (!m_IsLoad) return -1;

	int error =0;

	error = ProcessFunc(0);
	if (error)  return error;

	error = ProcessFunc(10, (void*)&idx);
	if (error)  return error;
	
	error = SetStatusGeneral(pStructStatus);
	if (error)  return error;

	return 0;
}

int CJobGeneral::CameraPreviewStart(HWND wnd, int camera)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(startCameraPreview, (void*) wnd, &camera);
	if (error)  return error;

	return 0;
}

int CJobGeneral::CameraDrawHistoStart(HWND wnd)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(startDrawHisto, (void*) wnd);
	if (error)  return error;

	return 0;

}

int CJobGeneral::CameraPreviewStop(int camera)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(stopCameraPreview, &camera);
	if (error)  return error;

	return 0;
}

int CJobGeneral::CameraFrameSave(char* path, int camera)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(saveCameraFrame, path, &camera);
	if (error)  return error;

	return 0;
}

int CJobGeneral::CameraSettingsSet(quint8 inData, int camera)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setCameraSettings, &inData, &camera);
	if (error)  return error;

	return 0;
}

int CJobGeneral::CameraFlippingSet(bool flipX, bool flipY)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setFlipping, &flipX, &flipY);
	if (error)  return error;

	return 0;
}

int CJobGeneral::CameraSetMask(int id, int camera)
{
	if (!m_IsLoad) return -1;

	return ProcessFunc(setCameraMask, &id, &camera);
}

int CJobGeneral::CameraSetMode( int mode, HWND wnd )
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setVideoMode, &mode, &wnd);
	return error;
}

int CJobGeneral::CameraSetMeasure( CameraMeasure* measure )
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setCameraMeasure,measure);
	return error;
}

int CJobGeneral::CameraAutoExposure()
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setCameraAutoexposure);
	return error;
}

int CJobGeneral::DeskJoyWork(bool x, bool y, bool z)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setDeskJoystickEnable, &x, &y, &z);
	if (error)  return error;

	return 0;
}

int CJobGeneral::DeskJoySpeed(char x, char y, char z)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setDeskJoystickSpeed, &x, &y, &z);
	if (error)  return error;

	return 0;
}

int CJobGeneral::DeskSpeedMove(float x, float y, float z)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setDeskSpeed, &x, &y, &z);
	if (error)  return error;

	return 0;
}

int CJobGeneral::DeskCurrentMove(quint8 x, quint8 y, quint8 z)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setDeskCurrent, &x, &y, &z);
	if (error)  return error;

	return 0;
}

int CJobGeneral::SetStatusGeneral(void* in)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setStatusGeneral, in);
	if (error)  return error;

	return 0;
}

int CJobGeneral::DeskMoveAbs(float x_mm, float y_mm, float z_mm)
{
	if (!m_IsLoad) return -1;

	int error = 0;

//	MessageBox(0,"Требуется корректное указания кода функции.","",0);
	error = ProcessFunc(deskMoveAbs, &x_mm, &y_mm, &z_mm);
	if (error)  return error;

	return 0;
}

int CJobGeneral::DeskMoveRel(float x_mm, float y_mm, float z_mm)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(deskMoveRel, &x_mm, &y_mm, &z_mm);
	if (error)  return error;

	return 0;
}

int CJobGeneral::DeskMoveStep(int x, int y, int z)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(deskMoveStep, &x, &y, &z);
	if (error)  return error;

	return 0;
}

int CJobGeneral::DeskStop()
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(deskStop);
	if (error)  return error;

	return 0;
}

int CJobGeneral::DevicesRun(bool flag)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	if (flag)	error = ProcessFunc(setConnectDevices);
	else error = ProcessFunc(setDisconnectDevices);
	if (error)  return error;

	return 0;
}

int CJobGeneral::SwitchLight(bool flag)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(switchLight, &flag);
	if (error)  return error;

	return 0;
}

int CJobGeneral::ObjectiveSwitch( int id)   
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(switchObjective, &id);
	return error;
}

int CJobGeneral::GetLastMesage(char* mess, int maxSizeInBuff)
{
	if (!m_IsLoad) return -1;

	int error = 0;


	error = GetParam(getLastMesage, m_LastMessage);
	if (error)  
	{
		if (mess) mess[0] = 0;
		return error;
	}

	if (strlen(m_LastMessage)>maxSizeInBuff-1)
	{
		memcpy(mess, m_LastMessage,maxSizeInBuff);
		mess[maxSizeInBuff-1] = 0;
	}
	else
	{
		strcpy(mess, m_LastMessage);
	}

	return 0;
}

int CJobGeneral::SaveOneFramePosition(float x, float y)
{
	if (!m_IsLoad) return -1;

	int error = 0;
	QPointF data = {x,y};

	error = ProcessFunc(saveOneFramePosition, &data);
	if (error)  return error;

}

int CJobGeneral::GetFocus( IN void* params)
{
	if (!m_IsLoad) return -1;

	return ProcessFunc(findFocus, params);

}

int CJobGeneral::FindBestFocusPosition(bool param) {
	if (!m_IsLoad) return -1;

	return ProcessFunc(findBestFocus, &param);
}

int CJobGeneral::SeMaxZPos(float pos_mm) {
	if (!m_IsLoad) return -1;

	return ProcessFunc(setMaxZ, &pos_mm);
}
