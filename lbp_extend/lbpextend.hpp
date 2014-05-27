#ifndef __lbpextend_hpp
#define __lbpextend_hpp

/**
 \file realtime.h
 \details Interface for realtime lbp dynamic library.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */


/** \def WINDLLMSG
 *  Definition of string for dll compilation. In unix system the definition is empty.
*/
#ifdef __WIN32__

    #include <windows.h>

    #define  WINDLLMSG _declspec(dllexport)

#else
    #define WINDLLMSG ;
#endif

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* uniformLbp(int columns, const int* data, int* result);

WINDLLMSG  int* rotationMinLbp(int columns, const int* data, int* result);

/* ------------------------------------------------------------------------- */

#endif
