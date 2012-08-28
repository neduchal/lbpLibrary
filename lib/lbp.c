#ifndef __lbp_c
#define __lbp_c

/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: lbp.c $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */
#include "lbpCxx.h"
#include "lbp.h"

/* ------------------------------------------------------------------------- */

 /** imageToLbpCxx(sizeX, sizeY, data, type, radius, samples) */
__declspec(dllexport) double* imageToLbp(int sizeX, int sizeY,
  double * data,unsigned int type,unsigned int radius,unsigned int samples)
{
  // Zavolani funkce pro prevod do LBP
  data = imageToLbpCxx(sizeX, sizeY,  data, type, radius, samples);
  return data;
}

/* ------------------------------------------------------------------------- */

/** RealTimeLbp(rows, columns, data, result) */
__declspec(dllexport) int* realTimeLbp(int rows, int columns, const int* data,
  int* result)
{
  // Zavolani funkce pro prevod do (realtime) LBP
  int* dataOut = realTimeLbpCxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

#endif

