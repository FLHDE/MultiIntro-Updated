#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

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

void WriteHooks();
void FindIntroBases();
