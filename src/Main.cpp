#include "Main.h"
#include "ConfigReader.h"

const DWORD hModFL = 0x400000;
DWORD dwOld;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WriteProcMem(void *pAddress, void *pMem, int iSize)
{
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
    VirtualProtectEx(hProc, pAddress, iSize, PAGE_EXECUTE_READWRITE, &dwOld);
    WriteProcessMemory(hProc, pAddress, pMem, iSize, 0);
    CloseHandle(hProc);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReadProcMem(void *pAddress, void *pMem, int iSize)
{
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
    VirtualProtectEx(hProc, pAddress, iSize, PAGE_EXECUTE_READWRITE, &dwOld);
    ReadProcessMemory(hProc, pAddress, pMem, iSize, 0);
    CloseHandle(hProc);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<UINT> vIntroBaseIDs;
UINT GetIntroBaseID()
{
    double fRand = (double)rand()/(RAND_MAX+1);
    fRand = fRand * vIntroBaseIDs.size();
    UINT i = (UINT)fRand;
    return vIntroBaseIDs[i];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

_DataStartup DataStartupOld;
int __cdecl DataStartup(const char *sz, void *thing, void *thing2)
{
    int iRet = DataStartupOld(sz, thing, thing2);
    FindIntroBases();
    WriteHooks();
    return iRet;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FindIntroBases()
{
    char szBuf[32];
    for(UINT i=1;;i++)
    {
        sprintf(szBuf, "Intro%u_Base", i);
        UINT iBaseID = Universe::get_base_id(szBuf);
        if(iBaseID)
        {
            vIntroBaseIDs.push_back(iBaseID);
        }
        else
        {
            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WriteHooks()
{
    char szOver[9];
    szOver[0] = '\xB8'; //MOV EAX
    szOver[5] = '\xFF'; //CALL
    szOver[6] = '\xD0'; //EAX
    szOver[7] = '\xEB'; //JMP
    szOver[8] = '\x15';
    UINT *iAddr = (UINT*)((char*)&szOver + 1);
    *iAddr = reinterpret_cast<UINT>((void*)GetIntroBaseID); //This simply writes the address of GetIntroBaseID to szOver[1 through 4]
    void *callAddr = (void*)((char*)hModFL + 0x173920);
    WriteProcMem(callAddr, (void*)&szOver, 9);
    void *freeAddr = (void*)((char*)hModFL + 0x17397e);
    char iFree = 16;
    WriteProcMem(freeAddr, (void*)&iFree, 1);
}

void Setup()
{
    const std::string configPath = "MultiIntro.ini";

    // Config reading
    IntroConfig config;
    ConfigReader cr;

    // Get the config
    cr.GetConfig(configPath, config);

    // Write pre-hooks
    FARPROC fpDataStartup = (FARPROC)DataStartup;
    FARPROC fpOldDataStartup;
    void *pAddress = (void*)((char*)hModFL + 0x1C6CB8);
    ReadProcMem(pAddress, &fpOldDataStartup, 4);
    WriteProcMem(pAddress, &fpDataStartup, 4);
    DataStartupOld = (_DataStartup)fpOldDataStartup;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if(fdwReason == DLL_PROCESS_ATTACH)
        Setup();

    return true;
}
