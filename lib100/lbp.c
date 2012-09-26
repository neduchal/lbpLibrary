#ifndef __lbp_c
#define __lbp_c

/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: lbp.c $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 1.0.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include "lbpCxx.h"
#include "lbp.h"

/* ------------------------------------------------------------------------- */

WINDLLMSG  double* imageToLbp(int sizeX, int sizeY,
  double * data,unsigned int type,unsigned int radius,unsigned int samples)
{
  data = imageToLbpCxx(sizeX, sizeY,  data, type, radius, samples);
  return data;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* realTimeLbp(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = realTimeLbpCxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

#endif

