//
// Created by ukhegg on 26.01.19.
//


#ifndef UFUZZER_LIB_H
#define UFUZZER_LIB_H

// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
#define UFUZZER_HELPER_DLL_IMPORT __declspec(dllimport)
#define UFUZZER_HELPER_DLL_EXPORT __declspec(dllexport)
#define UFUZZER_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define UFUZZER_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define UFUZZER_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define UFUZZER_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define UFUZZER_HELPER_DLL_IMPORT
    #define UFUZZER_HELPER_DLL_EXPORT
    #define UFUZZER_HELPER_DLL_LOCAL
#endif
#endif

// Now we use the generic helper definitions above to define UFUZZER_API and UFUZZER_LOCAL.
// UFUZZER_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// UFUZZER_LOCAL is used for non-api symbols.

#ifdef UFUZZER_DLL // defined if UFUZZER is compiled as a DLL
#ifdef UFUZZER_DLL_EXPORTS // defined if we are building the UFUZZER DLL (instead of using it)
    #define UFUZZER_API UFUZZER_HELPER_DLL_EXPORT
  #else
    #define UFUZZER_API UFUZZER_HELPER_DLL_IMPORT
  #endif // UFUZZER_DLL_EXPORTS
  #define UFUZZER_LOCAL UFUZZER_HELPER_DLL_LOCAL
#else // UFUZZER_DLL is not defined: this means UFUZZER is a static lib.
#define UFUZZER_API
#define UFUZZER_LOCAL
#endif // UFUZZER_DLL


#endif //UFUZZER_LIB_UFUZZER_HPP_H
