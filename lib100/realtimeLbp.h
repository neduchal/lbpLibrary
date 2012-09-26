#ifndef __realtimeLbp_h
#define __realtimeLbp_h

/**
 \file realtimeLbp.h
 \details File contains implementation of realtime LBP algorithm.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */


/* Necessary headers */   
#include <string.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------- */

/**
 * \fn int* RealTimeLbp(int rows, int columns, const int* data, int* result);
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
int* RealTimeLbp(int rows, int columns, const int* data, int* result);

/* ------------------------------------------------------------------------- */

#endif
