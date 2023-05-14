#include <string>
#include <vector>
#include <windows.h>
using namespace std;

#define IMPORT __declspec(dllimport)
#define EXPORT __declspec(dllexport)
#define foreach(lst, type, var) for(list<type>::iterator var = lst.begin(); (var != lst.end()); var++)
typedef unsigned int uint;
typedef int (__cdecl *_DataStartup)(const char *sz, void *thing, void *thing2);

#include "Common.h"

struct PATCH_INFO_ENTRY
{
	uint pAddress;
	void *pNewValue;
	uint iSize;
	void *pOldValue;
	bool bAlloced;
};

struct PATCH_INFO
{
	char	*szBinName;
	uint	pBaseAddress;

	PATCH_INFO_ENTRY piEntries[128];
};
