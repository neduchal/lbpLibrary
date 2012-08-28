#ifndef __mask_h
#define __mask_h

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: mask.h $
      Language:  C++
      Date:      $Date: 2012-07-18 13:08:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */    
#include <vector>
#include <math.h>
#include <iostream>
#include "itkImage.h"
#include "itkImageRegionIterator.h"
#include "const.h"

/* Uzitecne konstanty */
#define RADIAN 57.29 // pro prevod na  radiany
#define FOUR   4
#define EIGHT  8

/* ------------------------------------------------------------------------- */

/**
  Funkce generate2D vygeneruje sadu masek dle vstupnich parametru.

  Vstupni parametry :
    itk::queetech::Image2DFilterPointers filters - pointer na vektor filtru
    unsigned int radius - polomer masky (vzdalenost od stredoveho pixelu)
    unsigned int samples - pocet bodu v masce (okolo stredoveho pixelu)
    unsigned int length - delka strany masky

  Vystup funkce : 
    Filtry ulozene zpet do parametru filters.
*/
void generate2D(Image2DFilterPointers filters, unsigned int radius,
  unsigned int samples, unsigned int length);

/* ------------------------------------------------------------------------- */

/**
  Zkratka k funkci generate2D, ktera vytvari LBP filtry 
           radius = 1 , samples = 8
*/
void generateEight2D( Image2DFilterPointers filters,unsigned int length);

/* ------------------------------------------------------------------------- */

/**
  Zkratka k funkci generate2D, ktera vytvari LBP filtry 
           radius = 1 , samples = 4
*/
void generateFour2D( Image2DFilterPointers filters,unsigned int length);
		
/* ------------------------------------------------------------------------- */

#endif
