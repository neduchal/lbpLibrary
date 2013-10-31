#ifndef __distance_txx
#define __distance_txx

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: distance.txx $
      Language:  C++
      Date:      $Date: 2012-07-04 16:53:00 $
      Version:   $Revision: 1.0.0 $ 

   ------------------------------------------------------------------------- */

/* Necessary headers */ 
#include "distance.hpp"

/* ------------------------------------------------------------------------- */

template <class THistogramType >
double euclideanDistance(typename THistogramType::ConstPointer histogram1,
  typename THistogramType::ConstPointer histogram2) 
{
  unsigned int i;
  double a, b ;
  double v = 0; 

  for(i = 0; i < histogram1->Size() ; i++) {
    a = histogram1->GetFrequency( i , 0);    
    b = histogram2->GetFrequency( i , 0);
    v += pow((a-b),2); // Pripocteni aktualni hodnoty do mezivysledku
  }

  v = sqrt(v);
  return v;
}

/* ------------------------------------------------------------------------- */

template <class THistogramType >
double minMaxDistance(typename THistogramType::ConstPointer histogram1,
  typename THistogramType::ConstPointer histogram2) 
{

  unsigned int i;
  double a, b ;
  double v = 0;
  double v1 = 0;
  double v2 = 0;

  for(i = 0; i < histogram1->Size() ; i++) {
    a = histogram1->GetFrequency( i , 0); 
    b = histogram2->GetFrequency( i , 0);
    if(a < b) {
      v1 += a;
      v2 += b;
    }
    else {
      v1 += b;
      v2 += a;
    }  
  }

  v = (v1/v2)*100;
  return v;
}

/* ------------------------------------------------------------------------- */

#endif
