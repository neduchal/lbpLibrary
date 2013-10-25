#ifndef __realtime_c
#define __realtime_c

/* -------------------------------------------------------------------------

      Program:   Realtime LBP for C++
      Module:    $RCSfile: realtime.c $
      Language:  C++
      Date:      2013-10-18 $
      Version:   $Revision: 0.5.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include "realtimeCxx.h"
#include "realtime.h"

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

