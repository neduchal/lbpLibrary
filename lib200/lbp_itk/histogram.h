#ifndef __histogram_h
#define __histogram_h

/**
 \file histogram.h
 \details File contains method called createSimpleHistogram, which creates histogram from input data.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */

/* Necessary headers */ 
#include "itkScalarImageToListAdaptor.h"
#include "itkListSampleToHistogramGenerator.h"

/* ------------------------------------------------------------------------- */

/**
 * \fn template <class TInputImage, class THistogramType> void createSimpleHistogram(typename TInputImage::Pointer image, typename THistogramType::ConstPointer *histogram, int hSize);
 *
 * \brief Function creates histogram from input image data.
 *
 * It's necessary to determine correct template parameters. Function returns the histogram of input image data in *histogram parameter.
 * \tparam TInputImage Type of input image data.
 * \tparam TFilterType Type of input filters data.
 * \param image - Input image data.
 * \param *histogram - Pointer on object of histogram class. 
 * \param hSize Width of the histogram. 
 * \return Histogram of input image data.
 */
template <class TInputImage, class THistogramType>
void
createSimpleHistogram(typename TInputImage::Pointer image,
      typename THistogramType::ConstPointer *histogram, int hSize);

/* ------------------------------------------------------------------------- */
	
#endif
