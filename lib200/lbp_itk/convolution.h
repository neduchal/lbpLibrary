#ifndef __convolution_h
#define __convolution_h

/**
 \file convolution.h
 \details File contains convolution method.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */

/* Necessary headers */ 
#include <vector>
#include <iostream>
#include <math.h>
#include "itkImageToImageFilter.h"
#include "itkImage.h"
#include "itkVnlFFTRealToComplexConjugateImageFilter.h"
#include "itkVnlFFTComplexConjugateToRealImageFilter.h"
#include "itkMultiplyImageFilter.h"
#include "itkImageRegionIterator.h" 

/* ------------------------------------------------------------------------- */

/**
 * \fn template <class TInputImage, class  TFilterType > void convolutionFFT(const TInputImage *image, TFilterType *filters);
 *
 * \brief Function does the convolution of input image data and set of input filters.
 *
 * It's necessary to determine correct template parameters. Function returns the results of convolution in *filters parameter.
 * \tparam TInputImage Type of input image data.
 * \tparam TFilterType Type of input filters data.
 * \param  *image  Pointer on input image data.
 * \param  *filters Pointer on structure with input filters data. 
 * \return Convolution responce on input filters.
 */
template <class TInputImage, class  TFilterType >
  void convolutionFFT(const TInputImage *image, TFilterType *filters);

 /* ------------------------------------------------------------------------- */

#endif
