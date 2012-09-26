#ifndef __histogram_h
#define __histogram_h

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: histogram.h $
      Language:  C++
      Date:      $Date: 2012-07-04 19:51:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */ 
#include "itkScalarImageToListAdaptor.h"
#include "itkListSampleToHistogramGenerator.h"

/* ------------------------------------------------------------------------- */

/**
  Funkce createSimpleHistogram vytvori histogram zdrojovych dat

  Vstupni parametry :
	TInputImage::Pointer image - Zdrojova obrazova data
    THistogramType::ConstPointer *histogram - Promenna do ktere se histogram 
											  ulozi
	int hSize - Sirka histogramu
*/
    template <class TInputImage, class THistogramType>
    void
    createSimpleHistogram(typename TInputImage::Pointer image,
      typename THistogramType::ConstPointer *histogram, int hSize);

/* ------------------------------------------------------------------------- */
	
#endif
