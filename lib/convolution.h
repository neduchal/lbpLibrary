#ifndef __convolution_h
#define __convolution_h

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: convolution.h $
      Language:  C++
      Date:      $Date: 2012-07-02 19:03:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */ 
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
  Funkce ConvolutionFFT vypocita konvoluci zdrojoveho obrazu a predanych filtru
      
  Vstupni parametry : 
    TInputImage *image - pointer na nacteny obrazek
    TFilterType - struktura s filtry pro konvoluci
  Vystup funkce : 
    Funkce ulozi vysledek konvoluce do struktury s filtry. (Prepise filtry)
*/
template <class TInputImage, class  TFilterType >
  void convolutionFFT(const TInputImage *image, TFilterType *filters);

 /* ------------------------------------------------------------------------- */

#endif
