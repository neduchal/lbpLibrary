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

/**
 * \fn int* realTimeLbp(int rows, int columns, const int* data, int* result);
 *
 * \brief Realtime implementation of Lbp algorithm
 *
 * Function returns histogram of the LBP image in result parameter.
 * \param rows  Number of rows in image.
 * \param columns  Number of cols in image.
 * \param data  Image data in 1D array.
 * \param result Output parameter.
 * \return Histogram of LBP image data.
 */
WINDLLMSG  int* realTimeLbp(int rows, int columns, const int* data,
  int* result);


WINDLLMSG  int* realTimeLbpIm(int rows, int columns, const int* data,
  int* result);

WINDLLMSG int * lbp2Hists (int rows, int columns, const int* data, int partRows, int partColumns, int* result);

/* ------------------------------------------------------------------------- */

#endif
