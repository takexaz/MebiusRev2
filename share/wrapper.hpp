#pragma once
#include <Windows.h>

#ifdef MEBIUS_EXPORT
#define MEBIUSAPI __declspec(dllexport)
#else
#define MEBIUSAPI __declspec(dllimport)
#endif

namespace mebius::wrapper {
    class MEBIUSAPI WrapLibrary
    {
    private:
        HMODULE _handle;
    public:
        WrapLibrary(LPCSTR lpLibFileName) {
            char path[MAX_PATH];
            GetSystemDirectoryA(path, MAX_PATH);
            strcat_s(path, "\\");
            strcat_s(path, lpLibFileName);

            this->_handle = LoadLibraryA(path);
        }
        ~WrapLibrary() {
            if (this->_handle)
            {
                FreeLibrary(this->_handle);
            }
        }
        HMODULE get_handle() const {
            return this->_handle;
        }
    };
}