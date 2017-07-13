#pragma once
#include <QLibrary>

typedef void (__stdcall *CallBackFunc)( long code, long value );
typedef int ( *pfFunc)(int key, void* value1, void* value2, void* value3);
typedef int  (__stdcall *pfCallBack)(CallBackFunc callBack);



class CLoadDll
{
public:
	CLoadDll(char* path);
	virtual ~CLoadDll(void);
	int ProcessFunc(int key, void* value1 = nullptr, void* value2 = nullptr, void* value3 = nullptr);
	int SetParam(int key, void *value);
	int GetParam(int key, void* value);
	int SetCallBack(CallBackFunc pfcb);
	bool m_IsLoad;
private:
	void FreeDll();
	int LoadDll(char* path);
	QLibrary* cameraDll;
	pfFunc			Func;
	pfCallBack		CallBack;
 };
