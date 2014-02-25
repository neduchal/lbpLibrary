#ifndef __lbp_cxx
#define __lbp_cxx

/* -------------------------------------------------------------------------

      Program:   LBP for C++
      Module:    $RCSfile: realtime.c $
      Language:  C++
      Version:   $Revision: 0.6.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include "lbpCxx.hpp"
#include "lbp2x8Cxx.hpp"
#include "lbp3x10Cxx.hpp"
#include "lbp4x12Cxx.hpp"
#include "specialCxx.hpp"
#include "lbp.hpp"

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* lbp(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = lbpCxx(rows, columns, data, result);
  return dataOut;
}


/* ------------------------------------------------------------------------- */

WINDLLMSG  int* lbp2x8(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = lbp2x8Cxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* lbp3x10(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = lbp3x10Cxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* lbp4x12(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = lbp4x12Cxx(rows, columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* uniformLbp(int columns, const int* data,
  int* result)
{
  int* dataOut = uniformLbpCxx(columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* rotationMinLbp(int columns, const int* data,
  int* result)
{
  int* dataOut = rotationMinLbpCxx(columns, data, result);
  return dataOut;
}

/* ------------------------------------------------------------------------- */

WINDLLMSG  int* lbpIm(int rows, int columns, const int* data,
  int* result)
{
  int* dataOut = lbpImCxx(rows, columns, data, result);
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

