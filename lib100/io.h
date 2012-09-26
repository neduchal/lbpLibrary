#ifndef __io_h
#define __io_h

/**
 \file io.h
 \details File contains I/O methods.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */

/* Necessary headers */  
#include <iostream>
#include "itkImage.h"
#include "itkImageRegionIterator.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRescaleIntensityImageFilter.h"

/* ------------------------------------------------------------------------- */

/**
 * \fn template <class TInputImage> int loadImage(typename TInputImage::Pointer *image, std::string filename);
 *
 * \brief Function loads the image from file.
 *
 * It's necessary to determine correct template parameter. Function returns the image in image parameter and function status as return value.
 * \tparam TInputImage Type of input image data.
 * \param  *image  Pointer on input image data.
 * \param filename String with path to the file.
 * \return Function status. If function passed the status will be number 0.
 */
template <class TInputImage>
int loadImage(typename TInputImage::Pointer *image, std::string filename);

/* ------------------------------------------------------------------------- */
	
/**
 * \fn template <class TInputImage, class TOutputImage> void rescaleImageIntensity(typename TInputImage::Pointer *imageIn,  typename TOutputImage::Pointer *imageOut, unsigned int min, unsigned int max);
 *
 * \brief Function rescales intensities in image to new range.
 *
 * It's necessary to determine correct template parameter. Function returns rescaled imageOut.
 * \tparam TInputImage Type of input image data.
 * \tparam TOutputImage Type of input image data.
 * \param  *imageIn  Pointer on input image data.
 * \param  *imageOut Pointer on output image data.
 * \param  min Minimum intensity value in new image data.
 * \param  max Maximum intensity value in new image data.
 * \return New image data in imageOut parram.
 */
template <class TInputImage, class TOutputImage>
void rescaleImageIntensity(typename TInputImage::Pointer *imageIn,
  typename TOutputImage::Pointer *imageOut, unsigned int min, unsigned int max);
	
/* ------------------------------------------------------------------------- */

/**
 * \fn template <class TInputImage> int saveImage(typename TInputImage::Pointer image, std::string filename);
 *
 * \brief Function saves the image to specific file.
 *
 * It's necessary to determine correct template parameter. Function returns status value.
 * \tparam TInputImage Type of input image data.
 * \param  *image  Pointer on input image data.
 * \param filename String with path to the file.
 * \return Function status. If function passed the status will be number 0.
 */	
template <class TInputImage>
int saveImage(typename TInputImage::Pointer image, std::string filename);

/* ------------------------------------------------------------------------- */
	

#endif
