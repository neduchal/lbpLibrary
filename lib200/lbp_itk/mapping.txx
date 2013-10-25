#ifndef __mapping_txx
#define __mapping_txx

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: mapping.txx $
      Language:  C++
      Date:      $Date: 2012-07-18 13:08:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */  
#include "mapping.h"

/* ------------------------------------------------------------------------- */
 
/** Funkce basic(*LbpImage, *filters) */
template <class TLbpImageType, class TFilterType >
void basic(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters)
{ 
  // Vytvoreni iteratoru pro LBP data a jejich vynulovani
  itk::ImageRegionIterator<TLbpImageType>  
  iterator((*LbpImage), (*LbpImage)->GetRequestedRegion()); 
  for( iterator.GoToBegin() ; !iterator.IsAtEnd() ; ++iterator)
  {
    iterator.Set(0);
  }
  // Vytvoreni iteratoru pro vektor s filtry 
  typename TFilterType::iterator  it;
  int i;
  // Cyklus vypocitavajici LBP z jednotlivych filtru 
  for (it = filters->begin(), i = 0; it != filters->end() ; ++it, i++)
  {
    Image2DIterator  
    filterIterator(*it, (*LbpImage)->GetRequestedRegion()); 
    for( iterator.GoToBegin(), filterIterator.GoToBegin(); 
      !iterator.IsAtEnd(); ++iterator , ++filterIterator)
    {
      if(floor(filterIterator.Get() + 0.5) >= 0) 
      {  
        iterator.Set(iterator.Get() + pow(2.0, i));
      }
    }       
  }
}

/* ------------------------------------------------------------------------- */


template <class TLbpImageType, class TFilterType >
void rotmin(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters)
{ 
  typedef typename TLbpImageType::PixelType PIXEL;
  char bits = sizeof(PIXEL)*8;
  
  // Zavolani funkce basic a vytvoreni iteratoru pro LBP data
  basic<TLbpImageType,TFilterType>(LbpImage, filters);
  itk::ImageRegionIterator<TLbpImageType>  
  iterator((*LbpImage), (*LbpImage)->GetRequestedRegion());   
  // Cyklus pocitajici miminalni rotaci pro 8 bit data   
  for( iterator.GoToBegin(); !iterator.IsAtEnd(); ++iterator)
  {

    PIXEL cell = iterator.Get();  
    PIXEL result = (PIXEL)(pow(2.0,bits)-1);
    for(int i = 0; i < bits; i++)
    {
      PIXEL help = (cell<<i | cell>>(bits-i));
      if(help < result) result = help;          
    }
    iterator.Set(result);
  }       
}

/* ------------------------------------------------------------------------- */

/** Funkce uniform(*LbpImage, *filters) */
template <class TLbpImageType, class TFilterType >
void uniform(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters)
{ 
  // Zavolani funkce basic a vytvoreni iteratoru pro LBP data
  basic<TLbpImageType,TFilterType>(LbpImage, filters);
  itk::ImageRegionIterator<TLbpImageType>  
  iterator((*LbpImage), (*LbpImage)->GetRequestedRegion()); 
  // Cyklus pocitajici uniform patterns vzory          
  for( iterator.GoToBegin(); !iterator.IsAtEnd(); ++iterator)
  {
    unsigned int cell = iterator.Get();  
    unsigned int result = 0;
    char change = 0;
    char value = cell % 2;
    while(cell>1)
    {
      cell /= 2;
      char value2 = cell%2 ;
      if(value != value2) 
      {
        value = value2; 
        change++;
        if(change > 2) 
        {
          result = 5;
          iterator.Set(result);
          break;
        }
      }
    }
  }         
}

/* ------------------------------------------------------------------------- */

#endif
