#ifndef __realtimeLbp_h
#define __realtimeLbp_h

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: realtimeLbp.h $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */
 
/* Pripojeni knihoven a hlavickovych souboru */    
#include <string.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------- */

/**
  Funkce RealTimeLbp vypocita zakladni LBP reprezentaci ze zdrojovych dat. 

  Vstupni parametry :
    int rows - Pocet radek pixelu obrazku
    int columns - Pocet sloupcu pixelu obrazku
	  const int* data - Obrazova data
	  int* result - Vystupni parametr do ktereho se zpetne ulozi data
*/
int* RealTimeLbp(int rows, int columns, const int* data, int* result);

/* ------------------------------------------------------------------------- */

#endif
