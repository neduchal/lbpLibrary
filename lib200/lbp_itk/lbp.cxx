#ifndef __lbp_cxx
#define __lbp_cxx

/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: lbp.c $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 1.0.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include "lbpCxx.hpp"
#include "lbp.hpp"

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

WINDLLMSG  int* realTimeLbpIm(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = realTimeLbpImCxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG int * lbp2Hists(int rows, int columns, const int* data, 
                                    int partRows, int partColumns, int* result)
{
    int *dataOut = lbp2HistsCxx(rows, columns, data, partRows, partColumns, result);
  return dataOut;
}


#endif

