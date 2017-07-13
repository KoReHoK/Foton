#pragma once
#include <QLibrary>

// Коды, возвращаемые функциями библиотеки.
#define		SI_SUCCESS					0x00
#define		SI_DEVICE_NOT_FOUND			0xFF
#define		SI_INVALID_HANDLE			0x01
#define		SI_READ_ERROR				0x02
#define		SI_RX_QUEUE_NOT_READY		0x03
#define		SI_WRITE_ERROR				0x04
#define		SI_RESET_ERROR				0x05
#define		SI_INVALID_PARAMETER		0x06
#define		SI_INVALID_REQUEST_LENGTH	0x07
#define		SI_DEVICE_IO_FAILED			0x08
#define		SI_INVALID_BAUDRATE			0x09
#define		SI_FUNCTION_NOT_SUPPORTED	0x0a
#define		SI_GLOBAL_DATA_ERROR		0x0b
#define		SI_SYSTEM_ERROR_CODE		0x0c
#define		SI_READ_TIMED_OUT			0x0d
#define		SI_WRITE_TIMED_OUT			0x0e
#define		SI_IO_PENDING				0x0f

// Флаги для функции GetProductString().
#define		SI_RETURN_SERIAL_NUMBER		0x00
#define		SI_RETURN_DESCRIPTION		0x01
#define		SI_RETURN_LINK_NAME			0x02
#define		SI_RETURN_VID				0x03
#define		SI_RETURN_PID				0x04

// Статусные флаги RX Queue
#define		SI_RX_NO_OVERRUN			0x00
#define		SI_RX_EMPTY					0x00
#define		SI_RX_OVERRUN				0x01
#define		SI_RX_READY					0x02

// Ограничения на размеры буфферов.
#define		SI_MAX_DEVICE_STRLEN		256
#define		SI_MAX_READ_SIZE			4096*16
#define		SI_MAX_WRITE_SIZE			4096

// Определения используемых типов
typedef		int		SI_STATUS;
typedef		char	SI_DEVICE_STRING[SI_MAX_DEVICE_STRLEN];

// Input and Output pin Characteristics
#define		SI_HELD_INACTIVE			0x00
#define		SI_HELD_ACTIVE				0x01
#define		SI_FIRMWARE_CONTROLLED		0x02		
#define		SI_RECEIVE_FLOW_CONTROL		0x02
#define		SI_TRANSMIT_ACTIVE_SIGNAL	0x03
#define		SI_STATUS_INPUT				0x00
#define		SI_HANDSHAKE_LINE			0x01


const quint32 IN_PACKAGE_SIZE = 13;		// размер считываемого пакета
const quint32 OUT_PACKAGE_SIZE = 1;		// размер передаваемого пакета

const uchar REF_MARK_FLAG = 1 << 7;		// флаг захвата референтной метки
const uchar VCC_FLAG	  = 1 << 6;		// флаг питания датчика

const uchar PACKAGE_REQUEST =	  0x33;	// команда запроса пакета
const uchar DROP_ABS_COORDINATE = 0x31;	// команда сброса абсолютной координаты
const uchar DROP_REL_COORDINATE = 0x30;	// команда сброса относительной координаты

const quint32 ABS_COORD_NUM = 0;			// номер абсолютной координаты в пакете
const quint32 REL_COORD_NUM = 1;			// номер относительной координаты в пакете
const quint32 REF_COORD_NUM = 2;			// номер координаты референтой метки в пакете

const quint32 STATUS_OFFSET = 0;			// смещение байта статуса в пакете


typedef struct  
{
	int AbsCoordinata;
	int RelCoordinata;
	int RefCoordinata;
	bool VCC;
	bool REF_MARK;
	quint8 rezerv1;
	quint8 rezerv2;
} LIR_DATA;


typedef struct  
{
	int numDevice;
	LIR_DATA data[16];
	int Error;
} LIR_STATUS;