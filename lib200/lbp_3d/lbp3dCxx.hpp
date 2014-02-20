#ifndef __lbp3dCxx_hpp
#define __lbp3dCxx_hpp

/**
 \file lib3dCxx.h
 \details Source for 3d lbp dynamic library .
 \author Petr Neduchal
 \version 0.1.0
 \date 2014
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
int* lbp3dCxx(int rows, int columns, int slides, int* mask, const double* maskCoef, const int pointsNum, const int centerPos, const int radius, const int* data, int* result);

#endif
