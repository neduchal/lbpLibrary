#ifndef __mask_h
#define __mask_h

/**
 \file mask.h
 \details File contains methods for creation the set of LBP masks (called filters).
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */

/* Necessary headers */  
#include <vector>
#include <math.h>
#include <iostream>
#include "itkImage.h"
#include "itkImageRegionIterator.h"
#include "const.h"

/* Useful constants */

/** \def RADIAN 
 *  One radian in degrees.
*/
#define RADIAN 57.29 
/** \def FOUR
 *  Constant wich can be used as parameter in functions below.
*/
#define FOUR   4
/** \def EIGHT
 *  Constant wich can be used as parameter in functions below.
*/
#define EIGHT  8

/* ------------------------------------------------------------------------- */

/**
 * \fn void generate2D(Image2DFilterPointers filters, unsigned int radius, unsigned int samples, unsigned int length);
 *
 * \brief Function generates the set of LBP masks.
 *
 * Function returns the set of LBP masks in filters parameter.
 * \param filters  Pointer on vector which is the destatination of generated masks.
 * \param radius Radius of sample points around the center of mask.
 * \param samples Number of points around the center of mask.
 * \param length Length of image side (width or height)
 * \return Convolution responce on input filters.
 */
void generate2D(Image2DFilterPointers filters, unsigned int radius,
  unsigned int samples, unsigned int length);

/* ------------------------------------------------------------------------- */

/**
 * \fn void generateEight2D( Image2DFilterPointers filters,unsigned int length);
 *
 * \brief Function generates the set of LBP masks (radius = 1; samples = 8). 
 *
 * Function returns the set of LBP masks in filters parameter.
 * \param filters  Pointer on vector which is the destatination of generated masks.
 * \param length Length of image side (width or height)
 * \return Convolution responce on input filters.
 */
void generateEight2D( Image2DFilterPointers filters,unsigned int length);

/* ------------------------------------------------------------------------- */

/**
 * \fn void generateFour2D( Image2DFilterPointers filters,unsigned int length);
 *
 * \brief Function generates the set of LBP masks (radius = 1; samples = 4). 
 *
 * Function returns the set of LBP masks in filters parameter.
 * \param filters  Pointer on vector which is the destatination of generated masks.
 * \param length Length of image side (width or height)
 * \return Convolution responce on input filters.
 */
void generateFour2D( Image2DFilterPointers filters,unsigned int length);
		
/* ------------------------------------------------------------------------- */

#endif
