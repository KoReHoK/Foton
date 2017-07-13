// CamStructures.h
#pragma once
#include <QPoint>
#include <QColor>
#include <QRect>

#define FieldViewEsExp3Mpxl_5X_mkm 3520
#define FieldViewEsExp3Mpxl_10X_mkm 1515
#define FieldViewEsExp3Mpxl_20X_mkm 877
#define FieldViewEsExp3Mpxl_50X_mkm 353
#define FieldViewEsExp3Mpxl_100X_mkm 170

struct  CameraFields
{
	int x5;
	int x10;
	int x20;
	int x50;
	int x100;
	int x50L;	//Для АФМ
	QRect afmScanArea;	// В %. Для отрисовки сканируемой области АФМ на камере. В других модулях не используется
	QPointF ptCantilever;
	QPoint  afmMaxScanSize;	// В мкм. Макс. поле сканирования. Для отрисовки сканируемой области АФМ на камере. В других модулях не используется
};

struct  MeasureLine
{
	QPointF p1;
	QPointF p2;
	QColor	color;
};

struct  CameraMeasure
{
	int count;
	bool show;
	float koeff_mkm;
	MeasureLine line[8];
} ;


struct  CAMERACONTRAST
{
	bool IsWork;
	void* pData;
	float aver;
	float std;
	int numFrame;
	quint8 histo[3][256];
	long fLevel;
	float fps;
} ;
typedef struct FormatName 
{	
	char buff[128];
}FORMATNAME;

typedef struct CameraFormat 
{
	FORMATNAME name[16];
	int count;
}CAMERAFORMAT;

typedef struct Property 
{	
	float value;
	float min;
	float max;
	float default;
	long flags;
}PROPERTY;

typedef struct Camera_Settings
{
	char modeName[128];
	int numCamera;
	int lastModeCamera;
	bool flipX;
	bool flipY;
	QPoint frameSize;
	QPoint frameShift;
	quint16 frameDepth;
	quint16 frameChannels;
	PROPERTY expasure;
	PROPERTY expasureFrames;
	PROPERTY brightness;
	PROPERTY gainAnalog;
	PROPERTY gainDigital;
	PROPERTY countFrames;
	PROPERTY gamma;
	PROPERTY hue;
	PROPERTY saturation;
	PROPERTY gainR;
	PROPERTY gainG;
	PROPERTY gainB;
} CAMERA_SETTINGS;

//----------- Pixel Format IDs ------------------

#define CAM_PF_8                          0
#define CAM_PF_16                         1
#define CAM_PF_24                         2
#define CAM_PF_YUV422                     3
#define CAM_PF_COUNT                      4
#define CAM_PF_FILTER                     5
#define CAM_PF_32                         6
#define CAM_PF_48                         7


//----------- Properties ------------------------

#define CAM_PROP_BRIGHTNESS               0
#define CAM_PROP_CONTRAST            	  1
#define CAM_PROP_HUE                      2
#define CAM_PROP_SATURATION               3
#define CAM_PROP_SHARPNESS                4
#define CAM_PROP_GAMMA                    5

#define CAM_PROP_PAN                      16
#define CAM_PROP_TILT                     17
#define CAM_PROP_ROLL                     18
#define CAM_PROP_ZOOM                     19
#define CAM_PROP_EXPOSURE                 20
#define CAM_PROP_IRIS                     21
#define CAM_PROP_FOCUS                    22



#define CAM_PROP_GAIN                     40
#define CAM_PROP_GAIN_RED                 41
#define CAM_PROP_GAIN_BLUE                42
#define CAM_PROP_GAIN_GREEN1              43
#define CAM_PROP_GAIN_GREEN2              44
#define CAM_PROP_GAIN_MAGENTA             41
#define CAM_PROP_GAIN_CYAN                42
#define CAM_PROP_GAIN_YELLOW1             43
#define CAM_PROP_GAIN_YELLOW2             44


#define CAM_PROP_DEMOSAICING_METHOD       64
#define CAM_PROP_CORRECTION_MATRIX        65
#define CAM_PROP_FLIPPING                 66

#define CAM_PROP_DIGITAL_WHITEBALANCE_U   69 // from -100 to 100
#define CAM_PROP_DIGITAL_WHITEBALANCE_V   70 // from -100 to 100
#define CAM_PROP_DIGITAL_GAIN             71 // from 0 to 2, 1 means a gain of 1.0
#define CAM_PROP_DIGITAL_GAIN_RED         72 // from 0 to 2.5, 1 means a gain of 1.0. Relates to GAIN_Y and WHITEBALANCE
#define CAM_PROP_DIGITAL_GAIN_GREEN       73 // from 0 to 2.5, 1 means a gain of 1.0. Relates to GAIN_Y and WHITEBALANCE
#define CAM_PROP_DIGITAL_GAIN_BLUE        74 // from 0 to 2.5, 1 means a gain of 1.0. Relates to GAIN_Y and WHITEBALANCE

#define CAM_PROP_COLOR_FORMAT             80 // (read only)
#define CAM_PROP_MAX_WIDTH                81 // (read only)
#define CAM_PROP_MAX_HEIGHT               82 // (read only)

#define CAM_PROP_ABS_FOCUS                85 // requires the auto lens to be initialized
#define CAM_PROP_BLACK_LEVEL              86

#define CAM_PROP_KNEE1_EXPOSURE           96
#define CAM_PROP_STILL_KNEE1_EXPOSURE     96
#define CAM_PROP_KNEE2_EXPOSURE           97
#define CAM_PROP_STILL_KNEE2_EXPOSURE     97
#define CAM_PROP_STILL_KNEE3_EXPOSURE     98
#define CAM_PROP_VIDEO_KNEE               99
#define CAM_PROP_KNEE1_LEVEL              99
#define CAM_PROP_THRESHOLD                101
#define CAM_PROP_AUTO_EXP_TARGET          103
#define CAM_PROP_TIMESTAMPS               105
#define CAM_PROP_SNAPSHOT_CLOCK_SPEED     106 // 0 is the fastest
#define CAM_PROP_AUTO_EXP_MAXIMUM         107
#define CAM_PROP_TEMPERATURE              108
#define CAM_PROP_TRIGGER                  110
#define CAM_PROP_FRAME_GATE               112
#define CAM_PROP_EXPOSURE_INTERVAL        113
#define CAM_PROP_PWM                      114
#define CAM_PROP_MEMORY                   115 // value is RO and represent # of frames in memory
#define CAM_PROP_STILL_STROBE_DURATION    116
#define CAM_PROP_FAN                      118
#define CAM_PROP_SYNC_MODE                119
#define CAM_PROP_SNAPSHOT_COUNT           120
#define CAM_PROP_LSC_X                    121
#define CAM_PROP_LSC_Y                    122
#define CAM_PROP_AUTO_IRIS_MAX            123
#define CAM_PROP_LENS_STABILIZATION       124
#define CAM_PROP_VIDEO_TRIGGER            125
#define CAM_PROP_KNEE2_LEVEL              163
#define CAM_PROP_THRESHOLD_LOW            165
#define CAM_PROP_THRESHOLD_HIGH           166

#define CAM_PROP_JPEG_QUALITY             256


#define CAM_PROP_FLAG_USE                 0x80000000
#define CAM_PROP_FLAG_AUTO                0x40000000
#define CAM_PROP_FLAG_MASTER              0x40000000 // for CAM_PROP_SYNC_MODE
#define CAM_PROP_FLAG_STROBE_FROM_START_OF_EXPOSURE   0x20000000
#define CAM_PROP_FLAG_BACKLASH_COMPENSATION           0x20000000 // LUCAM_PROP_IRIS and LUCAM_PROP_FOCUS
#define CAM_PROP_FLAG_USE_FOR_SNAPSHOTS   0x04000000 // For CAM_PROP_IRIS
#define CAM_PROP_FLAG_POLARITY            0x10000000
#define CAM_PROP_FLAG_MEMORY_READBACK     0x08000000 // for CAM_PROP_MEMORY
#define CAM_PROP_FLAG_UNKNOWN_MAXIMUM     0x00020000
#define CAM_PROP_FLAG_UNKNOWN_MINIMUM     0x00010000
#define CAM_PROP_FLAG_LITTLE_ENDIAN       0x80000000 // for CAM_PROP_COLOR_FORMAT
#define CAM_PROP_FLAG_ALTERNATE           0x00080000 
#define CAM_PROP_FLAG_READONLY            0x00010000 // in caps param of GetPropertyRange

// Prop flags for VIDEO_TRIGGER (also uses CAM_PROP_FLAG_USE)
#define CAM_PROP_FLAG_HW_ENABLE            0x40000000
#define CAM_PROP_FLAG_SW_TRIGGER           0x00200000 // self cleared


// Those flags can be used with the CAM_PROP_GAMMA / CAM_PROP_BRIGHTNESS / LUCAM_PROP_CONTRAST
// properties. They are available on specifica cameras only.
#define CAM_PROP_FLAG_RED                  0x00000001
#define CAM_PROP_FLAG_GREEN1               0x00000002
#define CAM_PROP_FLAG_GREEN2               0x00000004
#define CAM_PROP_FLAG_BLUE                 0x00000008


// Do not access these properties unless you know what you are doing.

#define CAM_PROP_STILL_EXPOSURE           50
#define CAM_PROP_STILL_GAIN               51
#define CAM_PROP_STILL_GAIN_RED           52
#define CAM_PROP_STILL_GAIN_GREEN1        53
#define CAM_PROP_STILL_GAIN_GREEN2        54
#define CAM_PROP_STILL_GAIN_BLUE          55
#define CAM_PROP_STILL_GAIN_MAGENTA       52
#define CAM_PROP_STILL_GAIN_YELLOW1       53
#define CAM_PROP_STILL_GAIN_YELLOW2       54
#define CAM_PROP_STILL_GAIN_CYAN          55


// color pattern for the CAM_PROP_COLOR_FORMAT property
#define CAM_CF_MONO                       0
#define CAM_CF_BAYER_RGGB                 8
#define CAM_CF_BAYER_GRBG                 9
#define CAM_CF_BAYER_GBRG                 10
#define CAM_CF_BAYER_BGGR                 11
#define CAM_CF_BAYER_CYYM                 16
#define CAM_CF_BAYER_YCMY                 17
#define CAM_CF_BAYER_YMCY                 18
#define CAM_CF_BAYER_MYYC                 19

// parameter for the CAM_PROP_FLIPPING property
#define CAM_PROP_FLIPPING_NONE            0
#define CAM_PROP_FLIPPING_X               1
#define CAM_PROP_FLIPPING_Y               2
#define CAM_PROP_FLIPPING_XY              3



//----------- Version Structure ------------------

typedef struct {
	ulong firmware; 	// Firmware version
	ulong fpga; 		// FPGA version
	ulong api;			// API version
	ulong driver; 		// Device driver version
	ulong serialnumber; // of the camera
	ulong reserved;   // do not use
} CAM_VERSION;


//------------- Frame format --------------------

typedef struct {
	ulong xOffset; 	// x coordinate on imager of top left corner of subwindow in pixels
	ulong yOffset; 	// y coordinate on imager of top left corner of subwindow in pixels
	ulong width; 	// width in pixels of subwindow
	ulong height; 	// height in pixels of subwindow
	ulong pixelFormat; // pixel format for data
	union
	{
		ushort subSampleX;	// sub-sample ratio in x direction in pixels (x:1)
		ushort binningX;	// binning ratio in x direction in pixels (x:1)
	};
	ushort flagsX; // CAM_FRAME_FORMAT_FLAGS_*
	union
	{
		ushort subSampleY;  // sub-sample ratio in y direction in pixels (y:1)
		ushort binningY;	// binning ratio in y direction in pixels (y:1)
	};
	ushort flagsY; // CAM_FRAME_FORMAT_FLAGS_*
} CAM_FRAME_FORMAT;

#define CAM_FRAME_FORMAT_FLAGS_BINNING     0x0001


//------------ Snapshot Settings Structure -------


typedef struct {
	float exposure;		// Exposure in milliseconds
	float gain;			// Overall gain as a multiplicative factor
	union {
		struct {
			float gainRed; 	// Gain for Red pixels as multiplicative factor
			float gainBlue; 	// Gain for Blue pixels as multiplicative factor
			float gainGrn1; 	// Gain for Green pixels on Red rows as multiplicative factor
			float gainGrn2; 	// Gain for Green pixels on Blue rows as multiplicative factor
		};
		struct {  
			float gainMag; 	// Gain for Magenta pixels as multiplicative factor
			float gainCyan; 	// Gain for Cyan pixels as multiplicative factor
			float gainYel1; 	// Gain for Yellow pixels on Magenta rows as multiplicative factor
			float gainYel2; 	// Gain for Yellow pixels on Cyan rows as multiplicative factor
		};
	};
	union
	{
		bool useStrobe;		// for backward compatibility
		ulong strobeFlags;   // use CAM_PROP_FLAG_USE and/or CAM_PROP_FLAG_STROBE_FROM_START_OF_EXPOSURE
	};
	float strobeDelay;	// time interval from when exposure starts to time the flash is fired in milliseconds
	bool useHwTrigger;	// wait for hardware trigger
	float timeout;		// maximum time to wait for hardware trigger prior to returning from function in milliseconds
	CAM_FRAME_FORMAT format;   // frame format for data
	ulong shutterType;
	float exposureDelay;
	union
	{
		bool bufferlastframe;   // set to TRUE if you want TakeFastFrame to return an already received frame.
		ulong ulReserved1;
	};
	ulong ulReserved2;   // must be set to 0
	float flReserved1;   // must be set to 0
	float flReserved2;   // must be set to 0
} CAM_SNAPSHOT;


//------------ Streaming Video Modes --------------

#define STOP_STREAMING	0
#define START_STREAMING 1
#define START_DISPLAY	2
#define PAUSE_STREAM    3
#define START_RGBSTREAM 6

//------------ Streaming AVI Modes --------------
#define STOP_AVI 0
#define START_AVI 1
#define PAUSE_AVI 2

//------------ Parameters for AVI types --------------
#define AVI_RAW_LUMENERA	0
#define AVI_STANDARD_24		1
#define AVI_STANDARD_32		2
#define AVI_XVID_24			3
#define AVI_STANDARD_8     4 // for monochrome only


//---------- Parameters for CamConvertFrameToRgb24 --------------

typedef struct
{
	ulong DemosaicMethod;
	ulong CorrectionMatrix;

}CAM_CONVERSION;

// to use with LUCAM_CONVERSION.DemosaicMethod
#define CAM_DM_NONE                   0
#define CAM_DM_FAST                   1
#define CAM_DM_HIGH_QUALITY           2
#define CAM_DM_HIGHER_QUALITY         3
#define CAM_DM_SIMPLE                 8


// to use with CAM_CONVERSION.CorrectionMatrix
#define CAM_CM_NONE                   0
#define CAM_CM_FLUORESCENT            1
#define CAM_CM_DAYLIGHT               2
#define CAM_CM_INCANDESCENT           3
#define CAM_CM_XENON_FLASH            4
#define CAM_CM_HALOGEN                5

#define CAM_CM_IDENTITY               14
#define CAM_CM_CUSTOM                 15


//----------- Shutter types ------------

#define CAM_SHUTTER_TYPE_GLOBAL         0
#define CAM_SHUTTER_TYPE_ROLLING        1


//----------- Extern interfaces -------

#define CAM_EXTERN_INTERFACE_USB1       1
#define CAM_EXTERN_INTERFACE_USB2       2


// New Structure used for the new conversion functions

typedef struct _CAM_CONVERSION_PARAMS
{
	ulong Size;  // of this structure
	ulong DemosaicMethod;
	ulong CorrectionMatrix;
	bool FlipX;
	bool FlipY;
	float Hue;
	float Saturation;
	bool UseColorGainsOverWb;
	union
	{
		struct
		{
			float DigitalGain;
			float DigitalWhiteBalanceU;
			float DigitalWhiteBalanceV;
		};
		struct
		{
			float DigitalGainRed;
			float DigitalGainGreen;
			float DigitalGainBlue;
		};
	};
}CAM_CONVERSION_PARAMS, *PCAM_CONVERSION_PARAMS;


typedef struct _CAM_IMAGE_FORMAT
{
	ulong Size; // of this structure
	ulong Width;
	ulong Height;
	ulong PixelFormat;
	ulong ImageSize;

	ulong LucamReserved[8];

}CAM_IMAGE_FORMAT, *PCAM_IMAGE_FORMAT;

// For use with CamRegisterEventNotification
#define CAM_EVENT_START_OF_READOUT         2
#define CAM_EVENT_GPI1_CHANGED             4
#define CAM_EVENT_GPI2_CHANGED             5
#define CAM_EVENT_GPI3_CHANGED             6
#define CAM_EVENT_GPI4_CHANGED             7
#define CAM_EVENT_DEVICE_SURPRISE_REMOVAL  32