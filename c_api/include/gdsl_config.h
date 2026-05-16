#ifndef GDSL_CONFIG_H
#define GDSL_CONFIG_H

#ifdef _WIN32
    #ifdef GDSL_BUILD_DLL
        #define GDSL_API __declspec(dllexport)
    #else
        #define GDSL_API __declspec(dllimport)
    #endif
#else
    #define GDSL_API
#endif

#endif