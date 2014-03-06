#ifndef __lbp2x8Cxx_hpp
#define __lbp2x8Cxx_hpp

/**
 \file realtimeCxx.h
 \details Source for realtime lbp dynamic library .
 \author Petr Neduchal
 \version 0.5.0
 \date 2013
 */

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
int* lbp2x8Cxx(int rows, int columns, const int* data, int* result);

#endif
