//#include "StdAfx.h"
#include "JobMicro.h"

CJobMicro::CJobMicro(char* path) 
						: CJobGeneral(path)
{
//	SetStatusGeneral(0);

	delete []pStructStatus;
	pStructStatus = new CStatusMicro();

	memset(pStructStatus, 0, sizeof(CStatusMicro));
}

CJobMicro::~CJobMicro(void)	
{

}

int CJobMicro::Init(int idx)   
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = CJobGeneral::Init();
	if (error)  return error;

	return 0;
}

CStatusMicro* CJobMicro::pStatus()
{
	return (CStatusMicro*)  pStructStatus; 
}

int CJobMicro::SetScanWork(bool flag)
{
	if (!m_IsLoad) return -1;

	int error = 0;
	error = ProcessFunc(setScanningRun, &flag);
	return error;
}

int CJobMicro::CameraSetMode(int mode, int camera)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setCameraMode, &mode, &camera);
	return error;
}

int CJobMicro::CameraSetMode( int mode, HWND wnd )
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(setVideoMode, &mode, &wnd);
	return error;
}
int CJobMicro::CameraGetModes(void* inData, int camera)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(getCameraModes, inData, &camera);
	return error;
}

int CJobMicro::ObjectiveSwitch( int id)   
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(switchObjective, &id);
	return error;
}

int CJobMicro::PowerLed( bool id )
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(powerLed, &id);
	return error;
}

int CJobMicro::WaferGotoCristall( int  id, bool toAngle )
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(gotoCristall, &id, (void*)toAngle);
	return error;
}

int CJobMicro::WaferLoad(CString path)
{
	if (!m_IsLoad) return -1;

	int error = 0;

	error = ProcessFunc(waferload,&path);
	return error;

}

int CJobMicro::WaferCalcMap()
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

//	 error = ProcessFunc(calcWaferMap);
	 return error;
 }

 int CJobMicro::WaferIsInvalid()
 {
	 if (!m_IsLoad) return -2;

	 return ProcessFunc(waferIsInvalid);
 }



 int CJobMicro::WaferSetCristallState( int state )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(setCristallState, &state);
	 return error;
 }

 int CJobMicro::WaferGetCristallState(int id, int* state )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(getCristallState, &id,state);
	 return error;
 }

 int CJobMicro::WaferGetCristallSize( int* width, int* height )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(getCristallSize, width,height);
	 return error;
 }

 int CJobMicro::WaferStartScan( int scanType )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

//	 error = ProcessFunc(scanCristallStart, &scanType);
	 return error;
 }

 int CJobMicro::WaferStopScan()
 {
	 return DeskStop();
 }

 int CJobMicro::WaferGetDeskPos( int* coords )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(waferdeskpos,coords);
	 return error;
 }

 int CJobMicro::WaferSetScanSpeed( float speed )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(setScanSpeed,&speed);
	 return error;
 }


 int CJobMicro::DeskGetKey( char* key )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(getKbrdKey,key);
	 return error;
 }

 int CJobMicro::WaferGotoNextGood()
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(gotoNextGood);
	 return error;
 }

 int CJobMicro::WaferGotoPrevGood()
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(gotoPrevGood);
	 return error;
 }

 int CJobMicro::CameraSetMeasure( CameraMeasure* measure )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(setCameraMeasure,measure);
	 return error;
 }

 int CJobMicro::PauseScan()
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(setScanPause);
	 return error;
 }

 int CJobMicro::WaferGetCurFileName( CString &fname )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(getfileName,&fname);
	 return error;
 }

 int CJobMicro::WaferIsPosCorrected( bool &isCorrected )
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(checkCorrectPos,&isCorrected);
	 return error;
 }

 int CJobMicro::WaferGetAngle(float &angle)
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(getAngle,&angle);
	 return error;
 }

 int CJobMicro::WaferGetCurCristall(int id, QPoint &curCrist)
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(getCurCristall,&id, &curCrist);
	 return error;
 }

 int CJobMicro::WaferGetBaseData( int * outData )
 {
	 if (!m_IsLoad) return -1;
																															 
	 int error = 0;

	 error = ProcessFunc(getBaseData,outData);
	 return error;
 }

 int CJobMicro::WaferResetBase(bool resetMap)
 {
	 if (!m_IsLoad) return -1;

	 int error = 0;

	 error = ProcessFunc(resetBase, &resetMap);
	 return error;
 }

 int CJobMicro::LoadPlate()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(loadPlate);
 }

 int CJobMicro::UnloadPlate()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(unloadPlate);
 }

 int CJobMicro::StartAnalyse()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(startAnalyse);
 }		  
 
 int CJobMicro::ReperPoint()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(reperPoint);
 }

 int CJobMicro::UgolPoint()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(ugolPoint);
 }

 int CJobMicro::KeyPressed(quint8 key )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(keyPressed,&key);

 }

 int CJobMicro::WaferGetCristallStates( void* states )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(getCrStates,states);

 }

 int CJobMicro::WaferCopyMap()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(copymap);
 }

 int CJobMicro::WaferGetStatistic( void* outData )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(getStat,outData);
 }

 int CJobMicro::WaferSetNames( CString operatorname, CString diffusianame,CString platename)
 {
	 if (!m_IsLoad) return -1;
	 ProcessFunc(setOperatorStr,&operatorname);
	 ProcessFunc(setDiffusiaStr,&diffusianame);
	 ProcessFunc(setPlateNumberStr,&platename);

	return 0;
 }

 int CJobMicro::WaferSetJoyMode( quint8 mode )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(joyMode,(void*) mode);
 }

 int CJobMicro::WaferGetZoom( QPointF * inData )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(getzoom,inData);
 }

 int CJobMicro::UnloadPosition()
 {																																									 
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(unloadPosition);
 }

 int CJobMicro::MoveToCristal(float x, float y)
 {
	 if (!m_IsLoad) return -1;

	 QPoint pos = {x*1000, y*1000};

	 return ProcessFunc(moveToCristal_mkm,&pos);

 }

 int CJobMicro::GenerateReport( int type )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(report,&type);
 }

 CDefects* CJobMicro::pDefects()
 {
	 if (!m_IsLoad) return NULL;
	 int adrDefects = NULL;
	 ProcessFunc(ptrDefects,&adrDefects);
	 return (CDefects*)adrDefects;
 }

 WaferStructure* CJobMicro::pWafer()
 {
	 if (!m_IsLoad) return NULL;
	 int adrWafer = NULL;
	 ProcessFunc(ptrWafer,&adrWafer);
	 return (WaferStructure*)adrWafer;
 }

 int CJobMicro::WaferGetCristallCount(int* cnt)
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(cristCnt,cnt);
 }

 int CJobMicro::WaferGetSelectedCristall( int &selCristID )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(selectedCrist,&selCristID);
 }

 int CJobMicro::WaferGetMinID( QPoint &minID )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(minid,&minID);
 }

 int CJobMicro::WaferGetRefPoint( QPoint &refPt )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(refpoint,&refPt);
 }

 int CJobMicro::WaferGetInfoString( CString &info )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(infostring,&info);	
 }

 int CJobMicro::SwitchCamera()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(switchCamera);	
 }

 int CJobMicro::SetKeyAssociation( std::string funkName, int keyCode )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(setkeyAssociation,&funkName,&keyCode);	
 }

 int CJobMicro::SaveKeyAssociation()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(savekeyAssociation);	
 }

 int CJobMicro::GetKeyAssociation( std::string funkName, int &key )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(getkeyAssociation,&funkName,&key);	
 }

 bool CJobMicro::IsKeyUsed( int key )
 {
	 if (!m_IsLoad) return true;
	 bool isUsed=false;
	 ProcessFunc(checkkeyused,&key,&isUsed);	
	 return isUsed;
 }

 bool CJobMicro::IsFocusPlaneGood()
 {
	 if (!m_IsLoad) return true;
	 bool isGood=false;
	 ProcessFunc(focusplanegood,&isGood);	
	 return isGood;
 }

 int CJobMicro::GetKeyCount()
 {
	 if (!m_IsLoad) return -1;
	 int count=0;
	 ProcessFunc(keycount,&count);
	 return count;		 
 }

 int CJobMicro::GetKeyboardKey(IN int id, OUT int &key  )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(getkeyboardkey,&id,&key);
 }

 int CJobMicro::SendHotKey(IN int key  )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(exechotkey,&key);
 }

 int CJobMicro::WaferSetOperator( CString operatorname)
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(setOperatorStr,&operatorname);
 }

 int CJobMicro::SetAutofocusType(quint8 type)
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(afocustype,&type);
 }

 int CJobMicro::AddDefect()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(adddefect);
 }

 int CJobMicro::ReadKeyAssociation()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(readkeyAssociation);
 }

 int CJobMicro::ToReper()
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(toreper);   
 }



 int CJobMicro::SetMeasureData( CString pathToImage )
 {
	 if (!m_IsLoad) return -1;

	 return ProcessFunc(setMeasureData, &pathToImage);
 }

 int CJobMicro::DoMeasure( )
 {
	 if (!m_IsLoad) return -1;

	 return ProcessFunc(doMeasure);
 }

 int CJobMicro::DeleteMeasure( int  id)
 {
	 if (!m_IsLoad) return -1;

	 return ProcessFunc(deleteMeasure, &id);
 }

 MEASURE* CJobMicro::GetMeasure(int  id)
 {
	 if (!m_IsLoad) return 0;

	 int adrMeasure = NULL;
	 ProcessFunc(getMeasure,&adrMeasure,&id);
	 return (MEASURE*)adrMeasure;

 }

 int CJobMicro::ReMeasure( int whatUpdate, void* param )
 {
	 if (!m_IsLoad) return 0;

	 return ProcessFunc(reMeasure,&whatUpdate,param);
 }

 int CJobMicro::GetImageCamera( void* outImg )
 {
	 if (!m_IsLoad) return 0;

	 return ProcessFunc(getCamImg,outImg);
 } 

 int CJobMicro::SetMeasureParam( int param, void* value)
 {
	 if (!m_IsLoad) return 0;

	 return ProcessFunc(setMeasParam,&param,value);
 }

 int CJobMicro::SetMeasureZoom( int zoom, float* outKoeff )
 {
	 if (!m_IsLoad) return 0;

	 return ProcessFunc(setMeasZoom,&zoom, outKoeff);
 }

 int CJobMicro::AddMeasureZoom( int zoom, float koeff )
 {
	 if (!m_IsLoad) return 0;

	 return ProcessFunc(addMeasZoom,&zoom,&koeff);
 }

 int CJobMicro::AVIRecordStart()
 {
	 if (!m_IsLoad) return 0;

	 quint8 status=1;
	 return ProcessFunc(aviRecord,&status);
 }

 int CJobMicro::AVIRecordPause()
 {
	 if (!m_IsLoad) return 0;

	 quint8 status=2;
	 return ProcessFunc(aviRecord,&status);
 }

 int CJobMicro::AVIRecordStop()
 {
	 if (!m_IsLoad) return 0;

	 quint8 status=0;
	 return ProcessFunc(aviRecord,&status);
 }

 int CJobMicro::AVIUpdateParams()
 {
	 if (!m_IsLoad) return 0;

	 quint8 status=0;
	 return ProcessFunc(aviParamsUpd);
 }

 int CJobMicro::CameraPrintFrame()
 {
	 if (!m_IsLoad) return 0;

	 quint8 status=0;
	 return ProcessFunc(printFrame);
 }

 int CJobMicro::SelectCamera(int id)
 {
	  if (!m_IsLoad) return 0;
	  return ProcessFunc(selectCamera, &id);
 }

 int CJobMicro::SetVacuum(bool enable)
 {
	 if (!m_IsLoad) return 0;
	 return ProcessFunc(vacuum, &enable);
 }

 int CJobMicro::ReloadKeyboard()
 {
	 if (!m_IsLoad) return 0;
	 return ProcessFunc(reloadKeyboard);
 }

 int CJobMicro::SetJoyMode( quint8 mode )
 {
	 if (!m_IsLoad) return -1;
	 return ProcessFunc(joyMode, &mode);
 }