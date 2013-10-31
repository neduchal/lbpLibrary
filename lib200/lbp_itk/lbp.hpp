#ifndef __lbp_hpp
#define __lbp_hpp

/**
 \file lbp.h
 \details Interface for dynamic library lbp.dll/liblbp.so .
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
 * \fn double * imageToLbp(int sizeX, int sizeY, double * data, unsigned int type, unsigned int radius, unsigned int samples);
 *
 * \brief Implementation of Lbp algorithm
 *
 * Function returns LBP image data in data parameter.
 * \param sizeX  Width of image data
 * \param sizeY  Height of image data.
 * \param data  Image data in 1D array.
 * \param type Type of LBP algorithm 
 * \param radius Radius of sample points around the center of mask.
 * \param samples Number of points around the center of mask.
 * \see imageToLbpFilter.h
 * \return LBP image data.
 */
WINDLLMSG double * imageToLbp(int sizeX, int sizeY, double * data,
  unsigned int type,unsigned int radius,unsigned int samples);

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
