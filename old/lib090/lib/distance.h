#ifndef __distance_h
#define __distance_h

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: distance.h $
      Language:  C++
      Date:      $Date: 2012-07-04 16:53:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */ 
#include <math.h>

/* ------------------------------------------------------------------------- */

/**
  Funkce euclideanDistance vypocita euklidovskou vzdalenost mezi dvema 
	histogramy
      
  Vstupni parametry : 
    THistogramType::ConstPointer histogram1 - prvni histogram k porovnani
    THistogramType::ConstPointer histogram2 - druhy histogram k porovnani
  Vystup funkce : 
    Vysledek je vracen jako hodnota typu double
*/
template <class THistogramType >
double euclideanDistance(typename THistogramType::ConstPointer histogram1,
							typename THistogramType::ConstPointer histogram2);

/* ------------------------------------------------------------------------- */

/**
  Funkce minMaxDistance vypocita min/max podobnost dvou histogramu
      
  Vstupni parametry : 
    THistogramType::ConstPointer histogram1 - prvni histogram k porovnani
    THistogramType::ConstPointer histogram2 - druhy histogram k porovnani
  Vystup funkce : 
    Vysledek je vracen jako hodnota typu double v procentech
*/
template <class THistogramType >
double minMaxDistance(typename THistogramType::ConstPointer histogram1,
							typename THistogramType::ConstPointer histogram2);

/* ------------------------------------------------------------------------- */

#endif
