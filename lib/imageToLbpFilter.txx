
/*=========================================================================

  Program:   LBP filter for C++
  Module:    $RCSfile: imageToLbpFilter.txx,v $
  Language:  C++
  Date:      $Date: 2011-01-30 15:28:00 $
  Version:   $Revision: 0.1.0 $

=========================================================================*/
/**
 * \file imageToLbpFilter.txx
 * \brief Implementace funkcí filtru imageToLbpFilter 
 * */
#ifndef __imageToLbpFilter_txx
#define __imageToLbpFilter_txx

/* Připojení hlavičkových souborů */
#include <vector>
#include <math.h>
#include <iostream>
#include "itkImageToImageFilter.h"

/* ------------------------------------------------------------------------- */

namespace itk 
{

  /**
   * Konstructor tridy
   */
  template <class TInputImage, class TOutputImage >
    ImageToLbpFilter<TInputImage,TOutputImage >
    ::ImageToLbpFilter()
	  { 
      this->m_mapping = LBP_BASIC;
      this->m_samples = 8;
      this->m_radius  = 1;
    }
    
/* ------------------------------------------------------------------------- */    

  /**
   *  GenerateData 
   *
   *  Hlavní metoda filtru, vygeneruje potřebná data a vrátí je zpět do programu.
   */
  template <class TInputImage, class TOutputImage >
    void
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::GenerateData( void )
    {

      // Vytvoření prázdného výstupního obrazu o velikosti vstupního souboru 
      OutputImagePointer LbpImage = OutputImageType::New();
      OutputImageRegion region;
      region = this->GetInput()->GetLargestPossibleRegion();
      LbpImage->SetRegions(region);
      LbpImage->Allocate();    
      // Vytvoreni masek dle nastaveni clenskych promennych
      generate2D(&(this->m_filters), m_radius, m_samples, region.GetSize()[0]);
      // Provedeni konvoluce obrazovych dat a jednotlivych masek
      convolutionFFT<InputImageType, ImageFilters>(this->GetInput(),&(this->m_filters));
      // Vypocet LBP dle nastaveni promenne m_mapping
      if(this->m_mapping == LBP_BASIC)
      {
        basic<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      }
      else if(this->m_mapping == LBP_ROT_MIN8)
      {
        rotmin8<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      }
      else if(this->m_mapping == LBP_ROT_MIN16)
      {
        rotmin16<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      }
      else if(this->m_mapping == LBP_ROT_MIN32)
      {
        rotmin32<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      }
      else if(this->m_mapping == LBP_UNIFORM)
      {
        uniform<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      }
      else {
        basic<OutputImageType,ImageFilters>(&LbpImage, &(this->m_filters));
      }
      // Vrácení výsledku do programu 
  	  this->GraftOutput(LbpImage);     
    }
    
/* ------------------------------------------------------------------------- */    

  /**
   *  PrintSelf
   *
   *  Metoda vypíše název filtru
   */
  template <class TInputImage, class TOutputImage >
    void
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::PrintSelf(std::ostream& os, Indent indent) const
    {
      Superclass::PrintSelf(os,indent);
      os << indent << "ImageToLbpFilter "<< std::endl;
    }
    
/* ------------------------------------------------------------------------- */    

  /*
    Metoda nastavuje vlastnosti LBP filtru 

    radius = polomer kruznice na ktere lezi body
    samples = pocet bodu na kruznici
  */
  template <class TInputImage, class TOutputImage >
    void
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::SetMaskProperties(unsigned int radius, unsigned int samples)
    {
      this->m_radius = radius;
      this->m_samples = samples;  
    }
    
/* ------------------------------------------------------------------------- */    

  /*
    funkce SetMappingType nastavuje typ mapovani pri vypoctu LBP 
  
    vstupni parametr viz konstanty filtru zacinajici na LBP
  */
  template <class TInputImage, class TOutputImage >
    void
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::SetMappingType(unsigned int type)
    {
      this->m_mapping = type; 
    }
    
/* ------------------------------------------------------------------------- */    

  /* 
    Funkce vrati typ mapovani
  */
  template <class TInputImage, class TOutputImage >
    unsigned int 
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::GetMappingType()
    {
      return this->m_mapping; 
    }
    
/* ------------------------------------------------------------------------- */    

  /*
    Funkce vrati pocet bodu ktere vypocet LBP bere v uvahu
  */
  template <class TInputImage, class TOutputImage >
    unsigned int 
    ImageToLbpFilter<TInputImage,TOutputImage>
    ::GetSamples()
    {
      return this->m_samples;
    }
    
/* ------------------------------------------------------------------------- */    

  /*
    Funkce vrati polomer kruznice na ktere se nachazeji body pro vypocet LBP
  */
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
