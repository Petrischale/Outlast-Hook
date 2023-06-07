#pragma once
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>

bool GetPid(const wchar_t* targetProcess, DWORD* procID)
{
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap && snap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(pe);
        if (Process32First(snap, &pe))
        {
            do
            {
                if (!wcscmp(pe.szExeFile, targetProcess))
                {
                    CloseHandle(snap);
                    *procID = pe.th32ProcessID;
                    return true;
                }
            } while (Process32Next(snap, &pe));
        }
    }
    return false;
}

char* GetModuleBase(const wchar_t* ModuleName, DWORD procID)
{
    MODULEENTRY32 ModuleEntry = { 0 };
    HANDLE SnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procID);

    if (!SnapShot) return NULL;

    ModuleEntry.dwSize = sizeof(ModuleEntry);

    if (!Module32First(SnapShot, &ModuleEntry)) return NULL;

    do
    {
        if (!wcscmp(ModuleEntry.szModule, ModuleName))
        {
            CloseHandle(SnapShot);
            return (char*)ModuleEntry.modBaseAddr;
        }
    } while (Module32Next(SnapShot, &ModuleEntry));

    CloseHandle(SnapShot);
    return NULL;
}