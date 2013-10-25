#ifndef __histogram_txx
#define __histogram_txx

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: histogram.txx $
      Language:  C++
      Date:      $Date: 2012-07-04 19:56:00 $
      Version:   $Revision: 1.0.0 $ 

   ------------------------------------------------------------------------- */

/* Necessary headers */ 
#include "histogram.h"

/* ------------------------------------------------------------------------- */

template <class TInputImage, class THistogramType>
  void createSimpleHistogram(typename TInputImage::Pointer image,
    typename THistogramType::ConstPointer *histogram, int hSize)
{
  typename itk::Statistics::ScalarImageToListAdaptor< TInputImage >::Pointer 
  adaptor =  itk::Statistics::ScalarImageToListAdaptor< TInputImage >::New();
  adaptor->SetImage( image );

  typename itk::Statistics::ListSampleToHistogramGenerator< typename 
  itk::Statistics::ScalarImageToListAdaptor< TInputImage >, 
  typename TInputImage::PixelType >::Pointer
  generator = itk::Statistics::ListSampleToHistogramGenerator< 
  typename itk::Statistics::ScalarImageToListAdaptor< TInputImage >, 
  typename TInputImage::PixelType >::New();

  typename itk::Statistics::ListSampleToHistogramGenerator< 
  typename itk::Statistics::ScalarImageToListAdaptor< TInputImage >, 
  typename TInputImage::PixelType >::HistogramType::SizeType size;

  size.Fill( hSize ); 

  generator->SetListSample( adaptor );
  generator->SetNumberOfBins( size );
  generator->SetMarginalScale( 1.0 );
  generator->Update();
  *histogram = generator->GetOutput();
}

/* ------------------------------------------------------------------------- */

#endif
