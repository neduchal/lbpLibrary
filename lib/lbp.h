#ifndef __lbp_h
#define __lbp_h

/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: lbp.h $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $

   ------------------------------------------------------------------------- */
#ifdef __WIN32__

    /* Pripojeni knihoven a hlavickovych souboru */
    #include <windows.h>

    #define  WINDLLMSG _declspec(dllexport)

#else
    #define WINDLLMSG ;
#endif

/* ------------------------------------------------------------------------- */

/**
  Funkce imageToLbp vypocita zakladni LBP reprezentaci ze zdrojovych dat.

  Vstupni parametry :
    int sizeX - Pocet radek pixelu obrazku
    int sizeY - Pocet sloupcu pixelu obrazku
	  double * data - Obrazova data
	  unsigned int type - Typ LBP - 1,2,3,4 viz dokumentace LBP filtru
    unsigned int radiu - Vzdalenost bodu od stredu masky (polomer masky)
    unsigned int samples - Pocet bodu v okoli stredu
*/
WINDLLMSG double * imageToLbp(int sizeX, int sizeY, double * data,
  unsigned int type,unsigned int radius,unsigned int samples);

/* ------------------------------------------------------------------------- */

/**
  Funkce realTimeLbp vypocita zakladni LBP reprezentaci ze zdrojovych dat.

  Vstupni parametry :
    int rows - Pocet radek pixelu obrazku
    int columns - Pocet sloupcu pixelu obrazku
	  const int* data - Obrazova data
	  int* result - Vystupni parametr do ktereho se zpetne ulozi data
*/
WINDLLMSG  int* realTimeLbp(int rows, int columns, const int* data,
  int* result);

/* ------------------------------------------------------------------------- */

#endif
