#include "ChromaAnimationAPI.h"

#include <string>

namespace razerInit
{
    // Returns the application information for the Enigma Keyboard application
    ChromaSDK::APPINFOTYPE GetAppInfo();

    //Initializes the Chroma Libarary based on the Enigma Keyboard application information
    int InitializeKeyboard();

    // Initializes the Chroma Library based on a passed appInfo object
    int Init(ChromaSDK::APPINFOTYPE appInfo);
}