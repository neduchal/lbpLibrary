#ifndef __lbp_hpp
#define __lbp_hpp

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
WINDLLMSG  int* lbp(int rows, int columns, const int* data,
  int* result);

WINDLLMSG  int* lbp2x8(int rows, int columns, const int* data,
  int* result);

WINDLLMSG  int* lbp3x10(int rows, int columns, const int* data,
  int* result);

WINDLLMSG  int* lbp4x12(int rows, int columns, const int* data,
  int* result);

WINDLLMSG  int* uniformLbp(int columns, const int* data, int* result);

WINDLLMSG  int* rotationMinLbp(int columns, const int* data, int* result);

WINDLLMSG  int* lbpIm(int rows, int columns, const int* data,
  int* result);

WINDLLMSG int * lbp2Hists (int rows, int columns, const int* data, int partRows, int partColumns, int* result);

/* ------------------------------------------------------------------------- */

#endif
