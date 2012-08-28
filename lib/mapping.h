#ifndef __mapping_h
#define __mapping_h

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: mapping.h $
      Language:  C++
      Date:      $Date: 2012-07-18 13:08:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */    
#include <vector>
#include <iostream>
#include <cmath>
#include "itkImage.h"
#include "itkImageRegionIterator.h"
#include "const.h"

/* ------------------------------------------------------------------------- */
  
/**
  Funkce basic vypocita zakladni LBP reprezentaci ze zdrojovych dat a 
  filtru predanych v parametrech

  Vstupni parametry :
    TLbpImageType::Pointer *LbpImage - Zdrojovy obrazek
    TFilterType *filters - filtry aplikovane na zdrojovy obrazek 
*/
template <class TLbpImageType, class TFilterType >
void basic(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);

/* ------------------------------------------------------------------------- */
       
/** 
  Funkce rotmin8 funguje podobne jako basic, jen s tim rozdilem, ze 
  hleda vzdy minimalni reprezentaci pomoci rotace bitu zakladniho LBP
  (rotace funguje maximalne pro 8 bitu)

  Vstupni parametry :
    jako funkce basic
*/   
template <class TLbpImageType, class TFilterType >
void rotmin8(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);

/* ------------------------------------------------------------------------- */

/** 
  Funkce rotmin16 funguje podobne jako basic, jen s tim rozdilem, ze 
  hleda vzdy minimalni reprezentaci pomoci rotace bitu zakladniho LBP
  (rotace funguje maximalne pro 16 bitu)

  Vstupni parametry :
    jako funkce basic
*/    
template <class TLbpImageType, class TFilterType >
void rotmin16(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);

/* ------------------------------------------------------------------------- */

/** 
  Funkce rotmin32 funguje podobne jako basic, jen s tim rozdilem, ze 
  hleda vzdy minimalni reprezentaci pomoci rotace bitu zakladniho LBP
  (rotace funguje maximalne pro 32 bitu)

  Vstupni parametry :
    jako funkce basic
*/   
template <class TLbpImageType, class TFilterType >
void rotmin32(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);

/* ------------------------------------------------------------------------- */

/**
  Funkce uniform vypocita uniform lbp reprezentaci ze zdrojovych dat

  Vystupni parametry
  jako u funkce basic
*/ 
template <class TLbpImageType, class TFilterType >
void uniform(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);

/* ------------------------------------------------------------------------- */

#endif
