#ifndef __lbpCxx_h
#define __lbpCxx_h

/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: lbpCxx.h $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $

   ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */

/**
  Funkce imageToLbpCxx vypocita zakladni LBP reprezentaci ze zdrojovych dat.

  Vstupni parametry :
    int sizeX - Pocet radek pixelu obrazku
    int sizeY - Pocet sloupcu pixelu obrazku
	  double * data - Obrazova data
	  unsigned int type - Typ LBP - 1,2,3,4 viz dokumentace LBP filtru
    unsigned int radiu - Vzdalenost bodu od stredu masky (polomer masky)
    unsigned int samples - Pocet bodu v okoli stredu
*/
#ifdef __cplusplus
  extern "C"
#endif
double * imageToLbpCxx(int sizeX, int sizeY, double * data, unsigned int type,
  unsigned int radius, unsigned int samples);

/* ------------------------------------------------------------------------- */

/**
  Funkce realTimeLbpCxx vypocita zakladni LBP reprezentaci ze zdrojovych dat.

  Vstupni parametry :
    int rows - Pocet radek pixelu obrazku
    int columns - Pocet sloupcu pixelu obrazku
	  const int* data - Obrazova data
	  int* result - Vystupni parametr do ktereho se zpetne ulozi data
*/
#ifdef __cplusplus
  extern "C"
#endif
int* realTimeLbpCxx(int rows, int columns, const int* data, int* result);

/* ------------------------------------------------------------------------- */

#endif