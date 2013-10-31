#ifndef __lbpCxx_hpp
#define __lbpCxx_hpp

/**
 \file lbpCxx.h
 \details Source for dynamic library lbp.dll/liblbp.so .
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */

/* ------------------------------------------------------------------------- */

/**
 * \fn double * imageToLbpCxx(int sizeX, int sizeY, double * data, unsigned int type, unsigned int radius, unsigned int samples);
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
#ifdef __cplusplus
  extern "C"
#endif
double * imageToLbpCxx(int sizeX, int sizeY, double * data, unsigned int type,
  unsigned int radius, unsigned int samples);

/* ------------------------------------------------------------------------- */

/**
 * \fn int* realTimeLbpCxx(int rows, int columns, const int* data, int* result);
 *
 * \brief Realtime implementation of Lbp algorithm
 *
 * Function returns histogram of the LBP image in result parameter.
 * \param rows  Number of rows in image.
 * \param columns Number of cols in image.
 * \param data  Image data in 1D array.
 * \param result Output parameter.
 * \return Histogram of LBP image data.
 */
#ifdef __cplusplus
  extern "C"
#endif
int* realTimeLbpCxx(int rows, int columns, const int* data, int* result);

#ifdef __cplusplus
  extern "C"
#endif
int * realTimeLbpImCxx(int rows, int columns, const int* data, int* result);
/* ------------------------------------------------------------------------- */

#ifdef __cplusplus
  extern "C"
#endif
int * lbp2HistsCxx(int rows, int columns, const int* data, int partRows, int partColumns, int* result);


#endif
