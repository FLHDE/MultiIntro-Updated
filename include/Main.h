#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <vector>

#define foreach(lst, type, var) for(list<type>::iterator var = lst.begin(); (var != lst.end()); var++)
typedef int (__cdecl *_DataStartup)(const char *sz, void *thing, void *thing2);

#include "Common.h"

struct PATCH_INFO_ENTRY
{
	UINT pAddress;
	void *pNewValue;
	UINT iSize;
	void *pOldValue;
	bool bAlloced;
};

struct PATCH_INFO
{
	char	*szBinName;
	UINT	pBaseAddress;

	PATCH_INFO_ENTRY piEntries[128];
};

void WriteHooks();
void FindIntroBases();
