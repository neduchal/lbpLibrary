#ifndef __realtime_hpp
#define __realtime_hpp

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

WINDLLMSG  int* lbp3d(int rows, int columns, int slides, int* mask, const double* maskCoef, const int pointsNum, const int centerPos, const int radius, const int* data, int* result);

/* ------------------------------------------------------------------------- */

#endif
