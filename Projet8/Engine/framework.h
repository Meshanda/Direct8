// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers

// Windows Header Files
#include <windows.h>
#include <windowsx.h>

// C RunTime Header Files
#include <cstdlib>
#include <map>
#include <functional>
#include <typeinfo>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <list>
#include <algorithm>
#include <timeapi.h>
#include <profileapi.h>
#include <cstring>
#include <sstream>
#include <chrono>
#include <thread>
#include <utility>

#include <d3d9.h>
#include <d3dx9.h>

// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

#pragma comment(lib, "secur32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dmoguids.lib")
#pragma comment(lib, "wmcodecdspuuid.lib")
#pragma comment(lib, "msdmo.lib")
#pragma comment(lib, "Strmiids.lib")
#pragma comment(lib, "Kernel32.lib")

#pragma comment(lib, "dxerr.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

#include <DxErr.h>

// declare global variables

#define RUNNER(func) [=] { func(); }
#define SUPPLIER(func) [=] { return func(); }
#define CONSUMER(arg, func) [=](arg* param) { func(param); }
// #define FUNCTION(Param, func) [=]((Param)* param) { return func(param); }

#define CLASSNAMEOF(T) string(typeid(T).name()).substr(6) // gives the pure name of a class
#define NAMEOF(T) string(typeid(T).name()) // gives the type name of a var / class

// declare global variables

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 600

extern LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
extern LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
extern LPDIRECT3DVERTEXBUFFER9 _VBuffer;    // the pointer to the vertex buffer
extern LPDIRECT3DINDEXBUFFER9 _IBuffer;    // the pointer to the index buffer

#define HR(x)										\
{													\
	HRESULT hr = x;									\
	if (FAILED(hr))									\
	{												\
		DXTraceA(__FILE__, __LINE__, hr, #x, FALSE);\
	}												\
}

//structure
struct CUSTOMVERTEX { FLOAT X, Y, Z; D3DVECTOR NORMAL; };
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_NORMAL)

using namespace std;
