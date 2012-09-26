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

/** Funkce rotmin8(*LbpImage, *filters) */
template <class TLbpImageType, class TFilterType >
void rotmin8(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters)
{ 
  // Zavolani funkce basic a vytvoreni iteratoru pro LBP data
  basic<TLbpImageType,TFilterType>(LbpImage, filters);
  itk::ImageRegionIterator<TLbpImageType>  
  iterator((*LbpImage), (*LbpImage)->GetRequestedRegion());   
  // Cyklus pocitajici miminalni rotaci pro 8 bit data   
  for( iterator.GoToBegin(); !iterator.IsAtEnd(); ++iterator)
  {
    unsigned char cell = iterator.Get();  
    unsigned char result = (unsigned char)(pow(2.0,8)-1);
    for(int i = 0; i < 8; i++)
    {
      unsigned char help = (cell<<i | cell>>(8-i));
      if(help < result) result = help;          
    }
    iterator.Set(result);
  }       
}

/* ------------------------------------------------------------------------- */

/** Funkce rotmin16(*LbpImage, *filters) */
template <class TLbpImageType, class TFilterType >
void rotmin16(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters)
{ 
  // Zavolani funkce basic a vytvoreni iteratoru pro LBP data
  basic<TLbpImageType,TFilterType>(LbpImage, filters);
  itk::ImageRegionIterator<TLbpImageType>  
  iterator((*LbpImage), (*LbpImage)->GetRequestedRegion()); 
  // Cyklus pocitajici miminalni rotaci pro 16 bit data            
  for( iterator.GoToBegin(); !iterator.IsAtEnd(); ++iterator)
  {
    unsigned short cell = iterator.Get();  
    unsigned short result = (unsigned short)(pow(2.0,16)-1);
    for(int i = 0; i < 16; i++)
    {
      unsigned short help = (cell<<i | cell>>(16-i));
      if(help < result) result = help;          
    }
    iterator.Set(result);
  }               
}

/* ------------------------------------------------------------------------- */

/** Funkce rotmin32(*LbpImage, *filters) */ 
template <class TLbpImageType, class TFilterType >
void rotmin32(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters)
{ 
  // Zavolani funkce basic a vytvoreni iteratoru pro LBP data
  basic<TLbpImageType,TFilterType>(LbpImage, filters);
  itk::ImageRegionIterator<TLbpImageType>  
  iterator((*LbpImage), (*LbpImage)->GetRequestedRegion()); 
  // Cyklus pocitajici miminalni rotaci pro 32 bit data           
  for( iterator.GoToBegin(); !iterator.IsAtEnd(); ++iterator)
  {
    unsigned int cell = iterator.Get();  
    unsigned int result = (unsigned int)(pow(2.0,32)-1);
    for(int i = 0; i < 32; i++)
    {
      unsigned int help = (cell<<i | cell>>(32-i));
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
