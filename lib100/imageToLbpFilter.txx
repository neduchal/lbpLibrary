
/*=========================================================================

  Program:   LBP filter for C++
  Module:    $RCSfile: imageToLbpFilter.txx,v $
  Language:  C++
  Date:      $Date: 2012-09-24 15:28:00 $
  Version:   $Revision: 1.0.0 $

=========================================================================*/
/**
 * \file imageToLbpFilter.txx
 * \brief Implementace funkcí filtru imageToLbpFilter 
 * */
#ifndef __imageToLbpFilter_txx
#define __imageToLbpFilter_txx

/* Necessary headers */ 
#include <vector>
#include <math.h>
#include <iostream>
#include "itkImageToImageFilter.h"

/* ------------------------------------------------------------------------- */

namespace itk 
{

  template <class TInputImage, class TOutputImage >
    ImageToLbpFilter<TInputImage,TOutputImage >
    ::ImageToLbpFilter()
	  { 
      this->m_mapping = LBP_BASIC;
      this->m_samples = 8;
      this->m_radius  = 1;
    }
    
/* ------------------------------------------------------------------------- */    

  template <class TInputImage, class TOutputImage >
    void
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::GenerateData( void )
    {
      OutputImagePointer LbpImage = OutputImageType::New();
      OutputImageRegion region;
      region = this->GetInput()->GetLargestPossibleRegion();
      LbpImage->SetRegions(region);
      LbpImage->Allocate();    

      generate2D(&(this->m_filters), m_radius, m_samples, region.GetSize()[0]);

      convolutionFFT<InputImageType, ImageFilters>(this->GetInput(),&(this->m_filters));

      if(this->m_mapping == LBP_BASIC)
      {
        basic<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      }
      else if(this->m_mapping == LBP_ROTMIN)
      {
        rotmin<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      }
      else {
        basic<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      } 
  	  this->GraftOutput(LbpImage);     
    }
    
/* ------------------------------------------------------------------------- */    

  template <class TInputImage, class TOutputImage >
    void
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::PrintSelf(std::ostream& os, Indent indent) const
    {
      Superclass::PrintSelf(os,indent);
      os << indent << "ImageToLbpFilter "<< std::endl;
    }
    
/* ------------------------------------------------------------------------- */    

  template <class TInputImage, class TOutputImage >
    void
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::SetMaskProperties(unsigned int radius, unsigned int samples)
    {
      this->m_radius = radius;
      this->m_samples = samples;  
    }
    
/* ------------------------------------------------------------------------- */    

  template <class TInputImage, class TOutputImage >
    void
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::SetAlgorithmType(unsigned int type)
    {
      this->m_mapping = type; 
    }
    
/* ------------------------------------------------------------------------- */    

  template <class TInputImage, class TOutputImage >
    unsigned int 
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::GetAlgorithmType()
    {
      return this->m_mapping; 
    }
    
/* ------------------------------------------------------------------------- */    

  template <class TInputImage, class TOutputImage >
    unsigned int 
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::GetSamples()
    {
      return this->m_samples;
    }
    
/* ------------------------------------------------------------------------- */    

  template <class TInputImage, class TOutputImage >
    unsigned int 
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::GetRadius()
    {
      return this->m_radius;
    }

} // end namespace itk

/* ------------------------------------------------------------------------- */

#endif
