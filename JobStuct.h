#pragma once

#include "CamStructures.h"
#include "LirStructures.h"

#include <list>
#include <vector>
#include <string>


using namespace std;

enum JobGeneralFunction{
	setStatusGeneral = 1000,
	getStatusGeneral,
	setDeskSpeed = 1020,
	setDeskCurrent,
	setDeskJoystickEnable,
	setDeskJoystickSpeed,
	deskStop,
	deskMoveAbs,
	deskMoveRel,
	deskMoveStep,
	switchObjective,
	startCameraPreview = 1100,
	stopCameraPreview,
	startDrawHisto,
	setCameraSettings,
	getCameraSettings,
	saveCameraFrame,
	captureCameraFrame,
	setCameraMask,
	setCameraMeasure,
	setCameraAutoexposure,
	setVideoMode,
	setCameraMode,
	getCameraModes,
	setFlipping,
	selectCamera,
	setDisconnectDevices = 1200,
	setConnectDevices,
	switchLight,
	getLastMesage,
	findBestFocus,
	focusLevel,
	vacuum,
	reloadKeyboard,
	switchCamera,
	setMaxZ,
	findFocus = 1300	
};
enum JobVoronegFunction{
	getWaferData = 3000,
	powerLed,
	gotoCristall,
	getRowColumn,
	waferIsInvalid,
	setCristallState,
	getCristallState,
	getCristallSize,
	gotoNextGood,
	gotoPrevGood,
	waferdeskpos,
	setScanSpeed,
	resetBase,
	getKbrdKey,
	setScanPause,
	getfileName,
	checkCorrectPos,
	getAngle,
	getCurCristall,
	saveDataStruct,
	getBaseData,
	unloadPlate,
	loadPlate,
	startAnalyse,
	reperPoint,
	ugolPoint,
	keyPressed,
	getCrStates,
	copymap,
	getStat,
	setOperatorStr,
	setDiffusiaStr,
	setPlateNumberStr,
	joyMode,
	getzoom,
	unloadPosition,
	moveToCristal_mkm,

	scanCristallStart,
	calcWaferMap,
	waferLoad

};

enum JobRostFunction{
	report = 3500,
	waferload,
	ptrDefects,
	ptrWafer,
	cristCnt,
	selectedCrist,
	minid,
	refpoint,
	infostring,
	getkeyAssociation,
	setkeyAssociation,
	savekeyAssociation,
	readkeyAssociation,
	checkkeyused,
	keycount,
	getkeyboardkey,
	exechotkey,
	afocustype,
	focusplanegood,
	adddefect,
	toreper,
	setMeasureData,
	doMeasure,
	getMeasureArray,
	deleteMeasure,
	getMeasure,
	reMeasure,
	getCamImg,
	setMeasParam,
	setMeasZoom,
	addMeasZoom,
	aviRecord,
	aviParamsUpd,
	printFrame,
	reloadFocusOffset,
	compensateFocusOffset
};

enum JobAFMFunction{
	mupstop = 4000,
	switchObj,
	mupmove,
	mupmovecant,
	mupjoywork,
	turret,
	resetcoord,
	exporttofile,
	setfocus,
	correctPhotodiode,
	contactCanteliver,
	setPosFocus,
	switchFeedback,
	switchLaser,
	startScan,
	setFeedback,
	resetNewScanData,
	getAfmProfile,
	setMupDevice,
	captureDebugDataAFM,
	getInfo,
	klinUpdate,
	postProcessing,
	setProcessWnd,
	setPosPiezostack,
	makePostProcessing,
	flipAfmData
};

enum JobCitomirFunction{
	createNewPoints = 2000,
	getPoints,
	resetPoints,
	addPoint,
	nextPoint,
	removePoint,
	destroyExperiment,


	playVideoPath = 2100,
	playVideoPos,
	pauseVideo,
	stopVideo,
	changeWindowVideo,
	getSlideShowPathFromIndex,
	
	createCompressVideo = 2200,
	choiceCodecVideo,

	setScanningRun = 2300,

	saveOneFramePosition = 2400
};

enum TypeJobDll{
	JobGeneral = 100,
	JobCitomir,
	JobMA,
	JobMicroUV,
	JobPolarization,
	JobVoroneg,
	JobMicro,
	JobRost
};

class MyCriticalSection
{
private:
	CRITICAL_SECTION CriticalSection;
	bool success;
public:
	MyCriticalSection ()
	{
		success = true;
		// Initialize the critical section.
		InitializeCriticalSection (&CriticalSection);
	};
	bool Lock ()
	{
		// Request ownership of the critical section.
		__try
		{
			EnterCriticalSection (&CriticalSection);
			return true;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			// Release ownership of the critical section.
			LeaveCriticalSection (&CriticalSection);
			// Release resources used by the critical section object.
			DeleteCriticalSection (&CriticalSection);
			success = false;
			return false;
		}
	};
	void Unlock ()
	{
		if (success)
		{
			// Release ownership of the critical section.
			LeaveCriticalSection (&CriticalSection);
		}
	};
	~MyCriticalSection ()
	{
		// Release resources used by the critical section object.
		if (success)
		{
			DeleteCriticalSection (&CriticalSection);
		}
	};
};


class CMyStringsList	: vector<string>, public MyCriticalSection
{
public:
	CMyStringsList ()   : vector<string>(), MyCriticalSection ()
	{
		lastread = false;
		clear();
	};

	bool    add_string (const string& str)
	{
		if (Lock ())
		{
			if (lastread)
			{
				clear();
				lastread = false;
			}
			lastread = false;
			push_back(str);
			Unlock ();
			return true;
		}
		return false;
	}
	int get_laststring(string& res)
	{		  
		if (size() && Lock ())
		{
			res.clear();
			res = at(0);
			erase(begin());
			Unlock();
			return 0;
		}

		return -1;
	}

	int get_laststrings (vector<string>& res)
	{	//	  
		if ( !lastread && Lock ())
		{
			res.clear();
			
			for (vector<string>::iterator a = begin(); a !=end (); ++a) 
			{
				res.push_back((*a).c_str()); 
			}
			lastread = true;

		//	AfxMessageBox((res[0]).c_str());
			Unlock();


			return 1;
		}
		else return NULL;
	}
	int count()
	{	
		int a = 0;
		if (Lock ())
		{
			a = size();
			Unlock();
			return a;
		}
		
		return 0;
	}
private:
	bool lastread;

};

class CGeneralInfo 
{
public:
	bool IsConnect;
	volatile bool IsWork;
	bool rezerv1;
	bool rezerv2;

	float progress;

	CGeneralInfo()
	{
		rezerv1 = 0;
		rezerv2 = 0;
		IsConnect = false;
		IsWork = false;
		progress = 0.0f;
	}
};


class CStatusBase : public CGeneralInfo
{
public:
	int countMessage;
	quint32 lastError;

	CStatusBase()
	{
		countMessage = 0;
		lastError = 0;
	}
};


class CDeskBase : public CGeneralInfo
{
public:
	bool IsHomePosGood;
	float coordinata[4];
	float maxMove_mm[4];
	quint8 objective;
	bool IsWorkJoy[4];
	bool IsFastXYZ;
	quint8 joyWorkMethod;
	bool compensateFocus;
	CDeskBase()
	{
		objective = 0;
		IsHomePosGood = 0;
		IsFastXYZ = true;
		joyWorkMethod=0;
		memset(&IsWorkJoy, 0, sizeof(bool) * 4);
		memset(&coordinata, 0, sizeof(float) * 4);
		memset(&maxMove_mm, 0, sizeof(float) * 4);
	}
};

class CCameraBase : public CGeneralInfo
{
public:
	quint8 current;
	quint8 count;
	quint32 width;
	quint32 height;
	quint8 bitsPixel;
	quint32 numFrame;
	float aver;
	float std;
	float fps;
	long fLevel;
	quint8 mode;
	quint8 submode;
	quint8 lightType;
	quint8 flipX;
	quint8 flipY;
	CAMERAFORMAT formats;
	
	CCameraBase()
	{
		current = 0;
		width = 0;
		height = 0;
		bitsPixel = 0;
		numFrame = 0;
		aver = 0.0f;
		std = 0.0f;
		fps = 0.0f;
		fLevel = 0;
		lightType=0;
		flipX = flipY = 0;
		memset(&formats, 0, sizeof(CAMERAFORMAT));
	}
};

struct focus_data{
	int time;
	int index;
	float std;
	float aver;
	float z;
};
class CFocusInfo : public CGeneralInfo
{
public:
	float zBest;
	float noise;
// 	std::vector<focus_data> lastScanData;
// 	std::vector<focus_data> lastScanDataBest;
	bool isScan;
	bool needStopScan;
	CFocusInfo()
	{
		isScan=false;
		zBest = 0;
		noise = 0;
		needStopScan=false;
// 		lastScanData.clear();
// 		lastScanDataBest.clear();
	}
	~CFocusInfo()
	{
// 		lastScanData.clear();
// 		lastScanDataBest.clear();
		return;
	}
};

class CLirBase : public CGeneralInfo
{
public:
	int numDevice;
	LIR_DATA data[16];
 
 	CLirBase()
 	{
		numDevice = 0;
		memset(data, 0, sizeof(LIR_DATA) * 16);
 	}
};


class CStatusCamera : public CStatusBase
{
public:
	CCameraBase camera;
	quint8 initProgress;
};


class CStatusCameraAndDesk : public CStatusCamera
{
public:
	//CCameraBase camera;
	CDeskBase desk;
	CFocusInfo focus;
	bool isVacuum;
};

class CCaptureFrameStatus : public CGeneralInfo
{
public:
	int indexFast;
	QPoint index;
	bool light;
	CCaptureFrameStatus()
	{
		indexFast = 0;
		light = false;
		memset(&index, 0, sizeof(QPoint));
	}
};

class CStatusCitomir  : public CStatusCameraAndDesk
{
public:
	CGeneralInfo videoShow;
	CGeneralInfo videoAppendFrame;
	CGeneralInfo videoCompress;
	CCaptureFrameStatus CaptureFrame;
};

class CStatusVoroneg : public CStatusCameraAndDesk
{
public:
	quint8 isMode;
	quint8 isSubMode;
	char isWork;
	CCaptureFrameStatus CaptureFrame;
};

struct STATUS_AVI
{
	quint8 status; // 0 - stop, 1 - record, 2 - pause
	quint8 modeImage; // Размер  выходной картинки
	quint8 modeWork; // 0 - Сохранять в видео файл, 1 - сохранять картинки в папку
	CString filePath;
	CString codec;
	int fps;
};

class CStatusRost : public CStatusCameraAndDesk
{
public:
	STATUS_AVI avi;

	CCaptureFrameStatus CaptureFrame;
	quint8 mode;
	quint8 subMode;
	char isWork;
	CStatusRost()
	{
		mode=0;
		subMode=0;
		isWork=0;
		avi.status=0;
		avi.modeImage=0;
		avi.fps=15;
	}
};

class CStatusMicro : public CStatusCameraAndDesk
{
public:
	STATUS_AVI avi;
	CCaptureFrameStatus CaptureFrame;
	quint8 mode;
	quint8 subMode;
	char isWork;
	bool isInitialising;
	CStatusMicro()
	{
		mode=0;
		subMode=0;
		isWork=0;
		avi.status=0;
		avi.modeImage=0;
		avi.filePath="";
		isVacuum=false;
		isInitialising=false;
	}
};

typedef struct 
{
	quint8 P;
	quint8 I;
	quint8 D;
	quint8 Average;
	quint8 AveragePointsCapture;
	quint8 PorogPID;
	quint8 PorogDefl;
	unsigned short TipVoltage;
	unsigned short PropCoeff;
	unsigned short Speed;
	unsigned short ReferenceLevel;
} FeedBackInfo;

struct STATUS_MOTOR
{
	bool isWork;
	bool isJoy;
	int speed;
	int coordinata;
	int stepCount;
	bool startSwitch;
	bool stopSwitch;
};

struct STATUS_MULTIPLEXOR  
{
	STATUS_MOTOR motors[10];	
	bool isConnected;
	int currentObjectiveID;
	int lastDrive;
	int sensors;
};

enum MUPv1Drivers
{
	FD_X = 1,
	FD_Y,
	DIAFRAGMA,
	ZERKALO,
	KAMERA,
	T_POLE,
	CANTILEVER = 9
};

struct SCAN_DATA_AFM
{
	QPoint size; //размер матриц raw_Data и normedForDraw
	__int16 global_min;	 //минимум по всему изображению
	__int16 global_max;//максимум по всему изображению
	__int16 local_min;  //минимум на последней линии(для графика)
	__int16 local_max; //максимум на последней линии(для графика)
	__int16* raw_Data; // Исходный массив, приведенный к нм
	quint8* normedForDraw;// массив для визуализации(2D/3D)
	float* normedForGraphLast; // Последняя отсканированная строчка
	float* normedForGraphPrev; // Предпоследняя отсканированная строчка
	float realSize[3];//Реальные размеры сканируемой области в нм
};

struct AFM_PROFILE
{
	QPoint projection_pt[2]; //Начальная и конечная точки профиля
	float profile[1024];//Массив с данными профиля
	int profileLength;//Длина массива profile
	int min;	//Минимальное значение в profile
	int max;//Максимальное значение в profile
};


struct SCAN_PARAMS
{
	bool single_line;
	QPointF start;
	QPointF end;
	QPoint countDiscret;
};



struct STATUS_SCANNER_AFM
{
	bool isConnect;
	bool isWork;
	bool isLaserOn;
	bool isFeedbackOn;
	float temperature;
	float preasure;
	float humidity;
	float sum;		  //100%
	float deflection;//+/-100%
	float torsion;	 //+/-100%																																													 
	float vibration_level; 
	float capacity_pos[4];//0-100%
	float position_scanner[4];//0-100% текущая позиция пьезосканеров
	float process_scan;//0-100%  , общий ход сканирования
	float process_scanLine;//0-100%  , процент скана текущей линии 
	unsigned __int16 last_process_line;
	QPoint countField;
	QRect area_scan;//0-100%
	unsigned __int16 time_scan_line_ms; //время одной линии
	unsigned __int16 time_scan_ms;//время от начала сканирования
};

enum ProcessingTypes{

};
class CStatusAFM : public CStatusCameraAndDesk   
{
public:
	CCaptureFrameStatus CaptureFrame;
	STATUS_MULTIPLEXOR multiplexor;
	STATUS_SCANNER_AFM scanner;
	SCAN_DATA_AFM scanResults[4];
	//SCAN_DATA_AFM postScanResults;
	AFM_PROFILE scanProfile;
	quint8 isMode;
	quint8 isSubMode;
	quint8 progressLongWork;
	quint8 currentStepper;
	bool IsFocusFindGood;
	bool isNewData;
	bool IsContactZ;
	CStatusAFM()
	{
		currentStepper=-1;
		isMode = 0;
		isSubMode = 0;
		progressLongWork = 0;
		IsFocusFindGood = 0;
		isNewData = 0;
		IsContactZ = 0;
		//ZeroMemory(&postScanResults,sizeof(SCAN_DATA_AFM)); 
		memset(&scanner, 0, sizeof(STATUS_SCANNER_AFM));
		memset(&scanResults, 0, sizeof(SCAN_DATA_AFM)*4);
		memset(&scanProfile, 0, sizeof(AFM_PROFILE));
		memset(&multiplexor, 0, sizeof(STATUS_MULTIPLEXOR));
	}
};

class CStatusPolarization : public CStatusCamera
{
public:
	CCameraBase camera;
	CLirBase lir;
};

class CStatusMKAM : public CStatusCameraAndDesk
{
public:
};

struct OBJECTIVE
{
	QPointF visionField;
	QPointF OverlapVisionField;
};

struct INFOFROMPOINT
{
	char name[32];
	int time_sec;
	QColor color;
};

struct SAVEIMAGEINFO
{
	float zoomImage;
	QPoint sizeVideo;
	quint32 fccHandler;
	quint8 fps;
	char extend[4];
};

struct WORKDATA
{
	quint8 id;
	float positionX;
	float positionY;
	float positionZ;
	QPoint index;
	QPointF lefttop;
	QPointF rightbotton;
	quint32 numFrame;
	CTime lastTimeStay; //being
	QPointF sdvigZona;
	char comment[32];
};


struct WORKDATA_OF_SOFTWARE
{
	int currentPosition;
	int countAllPosition;
	char nameWork[64];
	char pathSave[512];
	char additionName[128];
	int statusWork;
	int vesselType;
	int minTimeDelay;
	int AlgorithmMovement;
	float speedMototor[2];
	float leftTopZ;
	float rightBottonZ;
	QPointF offsetZonaScan;
	QPointF sizeZonaScan;
	QPoint countPosition;
	SAVEIMAGEINFO saveInfo;
	quint8 indexObj;
	OBJECTIVE objectiveSettings;
	CTime startTime;
	CTime videoTime;
	CTime compressTime;
	bool flagSaveDataToImage;
	bool flagSaveDataToVideo;
	int waitTimeAppendFrame;
	int waitTimeCompessAvi;

	WORKDATA* workData;
};	

