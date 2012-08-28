#ifndef __distance_txx
#define __distance_txx

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: distance.txx $
      Language:  C++
      Date:      $Date: 2012-07-04 16:53:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */ 
#include "distance.h"

/* ------------------------------------------------------------------------- */

/** Funkce euclideanDistance(histogram1, histogram2) */
template <class THistogramType >
double euclideanDistance(typename THistogramType::ConstPointer histogram1,
  typename THistogramType::ConstPointer histogram2) 
{
  // Vytvoreni potrebnych promennych
  unsigned int i;
  double a, b ;
  double v = 0; 
  // Cyklus vypoctu euklidovske vzdalenosti jednotlivych indexu histogramu
  for(i = 0; i < histogram1->Size() ; i++) {
    a = histogram1->GetFrequency( i , 0);    
    b = histogram2->GetFrequency( i , 0);
    v += pow((a-b),2); // Pripocteni aktualni hodnoty do mezivysledku
  }
  // Odmocneni vysledku a ukonceni funkce
  v = sqrt(v);
  return v;
}

/* ------------------------------------------------------------------------- */

/** Funkce minMaxDistance(histogram1, histogram2) */
template <class THistogramType >
double minMaxDistance(typename THistogramType::ConstPointer histogram1,
  typename THistogramType::ConstPointer histogram2) 
{
  // Vytvoreni potrebnych promennych 
  unsigned int i;
  double a, b ;
  double v = 0;
  double v1 = 0;
  double v2 = 0;
  // Cyklus vypoctu min/max podobnosti jednotlivych indexu histogramu
  for(i = 0; i < histogram1->Size() ; i++) {
    a = histogram1->GetFrequency( i , 0); 
    b = histogram2->GetFrequency( i , 0);
	// Rozhodnuti o prirazeni minima a maxima na zaklade porovnani hodnot
	// na stejnych pozicich
    if(a < b) {
      v1 += a;
      v2 += b;
    }
    else {
      v1 += b;
      v2 += a;
    }  
  }
  // Vypocet celkoveho vysledku v procentech
  v = (v1/v2)*100;
  return v;
}

/* ------------------------------------------------------------------------- */

#endif
