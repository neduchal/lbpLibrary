#ifndef __lbpextend_cxx
#define __lbpextend_cxx

/* -------------------------------------------------------------------------

      Program:   LBP for C++
      Module:    $RCSfile: realtime.c $
      Language:  C++
      Version:   $Revision: 0.6.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include "specialCxx.hpp"
#include "lbp.hpp"

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

#endif

