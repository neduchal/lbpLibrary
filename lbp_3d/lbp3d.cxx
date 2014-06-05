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
#include "lbp3d.hpp"
#include "lbp3dCxx.hpp"
#include <iostream>

/* ------------------------------------------------------------------------- */

WINDLLMSG  int * lbp3d(int rows, int columns, int slides, int* mask, const double* maskCoef, const int pointsNum, const int centerPos, const int radius, int* data, int* result)
{
  //int* dataOut = lbp3dCxx(rows, columns, slides, mask, maskCoef, pointsNum, centerPos, radius, data, result);

  //return dataOut;
}

#endif

