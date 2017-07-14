#pragma once

#include "JobGeneral.h"
#include "Defects.h"
#include "WaferStruct.h"
#include "MeasureData.h"

class CJobMicro : public CJobGeneral
{
public:
	CJobMicro(char* path);
	~CJobMicro();
	virtual int Init(int idx = 0);

	int SetScanWork(bool flag);
	int CameraSetMode(int mode, int camera=0);
	int CameraSetMeasure( CameraMeasure* measure );
	int CameraSetMode(int mode, HWND wnd);
	int CameraGetModes(void* inData, int camera=0);
	int ObjectiveSwitch(int id);
	CStatusMicro* pStatus();
	int PowerLed( bool id );
	int WaferCalcMap();
	int WaferGotoCristall(int id, bool toAngle=true);//toAngle - в левый верхний край(для привязки). Иначе в центр со смещением
	int WaferGotoNextGood();
	int WaferGotoPrevGood();
	int WaferLoad(CString path);
	int WaferIsInvalid();
	int WaferSetCristallState(int state);
	int WaferGetCristallSize(int* width, int* height);
	int WaferStartScan(int scanType);
	int WaferStopScan();
	int WaferGetDeskPos(int* coords);
	int WaferSetScanSpeed(float speed);
	int WaferGetCurFileName(CString &fname);
	int WaferIsPosCorrected(bool &isCorrected);
	int WaferGetAngle(float &angle);
	int WaferGetCristallStates(void* states);
	int WaferGetBaseData(int * outData);
	int WaferResetBase(bool resetMap=false);
	int WaferCopyMap();
	int WaferSetNames( CString operatorname, CString diffusianame,CString platename);
	int WaferGetStatistic(void* outData);
	int WaferSetJoyMode(quint8 mode);
	int WaferGetZoom(QPointF * inData);

	int WaferGetCristallCount(int* cnt);
	int WaferGetCristallState(int id,int* state);
	int WaferGetCurCristall(int id,QPoint &curCrist);
	int WaferGetSelectedCristall(int &selCristID);
	int WaferGetMinID(QPoint &minID);
	int WaferGetRefPoint(QPoint &refPt);
	int WaferGetInfoString(CString &info);

	int SwitchCamera();
	int DeskGetKey(char* key);
	int PauseScan();
	int LoadPlate();
	int UnloadPlate();
	int StartAnalyse();
	int	 UgolPoint();
	int ReperPoint();
	int ToReper();
	int KeyPressed(quint8 key);
	int MoveToCristal(float x, float y);
	int UnloadPosition();
	CDefects* pDefects();
	WaferStructure* pWafer();

	int GenerateReport(int type);
	int SetKeyAssociation( std::string funkName, int keyCode );
	int SaveKeyAssociation();
	int ReadKeyAssociation();
	int GetKeyAssociation( std::string funkName, int &key );
	int GetKeyboardKey(IN int id, OUT int &key );
	bool IsKeyUsed( int key );
	int GetKeyCount();
	int SendHotKey(IN int key );
	int WaferSetOperator( CString operatorname);
	int SetAutofocusType(quint8 type);
	bool IsFocusPlaneGood();
	int AddDefect();

	int SetMeasureData(CString pathToImage);	
	int DoMeasure( );
	int DeleteMeasure( int id);
	MEASURE* GetMeasure(int id=-1);
	int ReMeasure( int whatUpdate, void* param );
	int GetImageCamera( void* outImg );
	int SetMeasureParam( int param, void* value);
	int SetMeasureZoom( int zoom, float* outKoeff);
	int AddMeasureZoom( int zoom, float koeff );
	int AVIRecordStart();
	int AVIRecordPause();
	int AVIRecordStop();
	int AVIUpdateParams();
	int CameraPrintFrame();
	int SelectCamera(int id);
	int SetVacuum(bool enable);
	int ReloadKeyboard();
	int SetJoyMode(quint8 mode);
private:
	
};
