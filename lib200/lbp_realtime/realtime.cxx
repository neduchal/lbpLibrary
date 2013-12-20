#ifndef __realtime_cxx
#define __realtime_cxx

/* -------------------------------------------------------------------------

      Program:   Realtime LBP for C++
      Module:    $RCSfile: realtime.c $
      Language:  C++
      Date:      2013-10-18 $
      Version:   $Revision: 0.5.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include "realtimeCxx.hpp"
#include "realtimeLbp2x8Cxx.hpp"
#include "realtimeLbp3x10Cxx.hpp"
#include "realtimeLbp4x12Cxx.hpp"
#include "specialCxx.hpp"
#include "realtime.hpp"

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* realTimeLbp(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = realTimeLbpCxx(rows, columns, data, result);
  return dataOut;
}


/* ------------------------------------------------------------------------- */

WINDLLMSG  int* realTimeLbp2x8(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = realTimeLbp2x8Cxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* realTimeLbp3x10(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = realTimeLbp3x10Cxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* realTimeLbp4x12(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = realTimeLbp3x12Cxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* uniformLbp(int columns, const int* data,
  int* result)
{
  int* dataOut = unifomrLbpCxx(columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* rotationMinLbp(int columns, const int* data,
  int* result)
{
  int* dataOut = rotationMinCxx(columns, data, result);
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

