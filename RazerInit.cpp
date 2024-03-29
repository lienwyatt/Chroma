#include "RazerInit.h"
#include "ChromaAnimationAPI.h"
#include <tchar.h>

int razerInit::InitializeKeyboard()
{
    //A struct with info about this application 
    ChromaSDK::APPINFOTYPE appInfo = razerInit::GetAppInfo();

    //Intialize the chroma Keyboard
    return razerInit::Init(appInfo);
}


ChromaSDK::APPINFOTYPE razerInit::GetAppInfo()
{

    ChromaSDK::APPINFOTYPE appInfo = {};
    _tcscpy_s(appInfo.Title, 256, _T("Enigma Keyboard"));
    _tcscpy_s(appInfo.Description, 1024, _T("An implementation of Enigma Encryption on an RGB Keyboard"));
    _tcscpy_s(appInfo.Author.Name, 256, _T("Wyatt Lien"));
    _tcscpy_s(appInfo.Author.Contact, 256, _T("lienwyatt@gmail.com"));
    //appInfo.SupportedDevice = 
    //    0x01 | // Keyboards
    //    0x02 | // Mice
    //    0x04 | // Headset
    //    0x08 | // Mousepads
    //    0x10 | // Keypads
    //    0x20   // ChromaLink devices
    appInfo.SupportedDevice = (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20);
    //    0x01 | // Utility. (To specifiy this is an utility application)
    //    0x02   // Game. (To specifiy this is a game);
    appInfo.Category = 1;
    return appInfo;
}

int razerInit::Init(ChromaSDK::APPINFOTYPE appInfo)
{
    if (ChromaSDK::ChromaAnimationAPI::InitAPI() != RZRESULT_SUCCESS)
    {
        return -1;
    }

    RZRESULT result = ChromaSDK::ChromaAnimationAPI::InitSDK(&appInfo);
    if (result == RZRESULT_SUCCESS)
    {
        //just continue
    }
    else if (result == RZRESULT_DLL_NOT_FOUND)
    {
        fprintf(stderr, "Chroma DLL is not found! %d", result);
    }
    else if (result == RZRESULT_DLL_INVALID_SIGNATURE)
    {
        fprintf(stderr, "Chroma DLL has an invalid signature! %d", result);
    }
    else
    {
        fprintf(stderr, "Failed to initialize Chroma! %d", result);
    }

    if (result != 0)
    {
        if (ChromaSDK::ChromaAnimationAPI::UninitAPI() != 0)
        {
            fprintf(stderr, "Failed to uninit Chroma API!\r\n");
        }
        return -1;
    }

    //wait for init
    Sleep(100);
    return 0;
}
