#include "LoadDll.h"


CLoadDll::CLoadDll(char* path)
{
	Func = nullptr;
	CallBack = nullptr;
	cameraDll = nullptr;
	m_IsLoad = false;

	if (LoadDll(path)) 
	{
		m_IsLoad = true;
	}
}

CLoadDll::~CLoadDll()
{
	if (m_IsLoad) 
	{
		SetCallBack(nullptr);
		FreeDll();
	}
}

int CLoadDll::LoadDll(char *path)
{
	cameraDll = new QLibrary(path);
	if (!cameraDll) return 0;

	Func = (pfFunc)cameraDll->resolve("Func");
	CallBack = (pfCallBack)cameraDll->resolve("_SetCallBack");

	if (!Func)
	{
		FreeDll();
		return 0;
	}
	return 1;
}

void CLoadDll::FreeDll()
{
	if (!cameraDll) return;
	if (!m_IsLoad) return;

	cameraDll->unload();
	cameraDll = nullptr;
	m_IsLoad = false;
	Func = nullptr;
	CallBack = nullptr;
}

int CLoadDll::GetParam(int key, void *value)
{
	if (!cameraDll) return -2;
	if (!m_IsLoad) return -2;
	
	return ProcessFunc(2,&key, value);
}

int CLoadDll::SetParam(int key, void *value)
{
	if (!cameraDll) return -2;
	if (!m_IsLoad) return -2;
	return ProcessFunc(1,&key, value);
}

int CLoadDll::ProcessFunc(int key, void *value1, void *value2, void *value3)
{
	if (!cameraDll) return -2;
	if (!m_IsLoad) return -2;
	if (!Func) return -2;

	return (*Func)(key, value1, value2, value3);
}

int CLoadDll::SetCallBack(CallBackFunc pfcb)
{
	if (!cameraDll) return -2;
	if (!m_IsLoad) return -2;
	
	if (!CallBack) return -5;


	return (*CallBack)(pfcb);
}
