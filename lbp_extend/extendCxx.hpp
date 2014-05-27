#ifndef __extendCxx_hpp
#define __extendCxx_hpp

/**
 \file specialsCxx.h
 \details Special LBP functions like uniform Patterns and rotation minimum LBP.
 \author Petr Neduchal
 \version 0.9.0
 \date 2013
 */

/* ------------------------------------------------------------------------- */

#ifdef __cplusplus
  extern "C"
#endif
int* uniformLbpCxx(int columns, const int* data, int* result);

#ifdef __cplusplus
  extern "C"
#endif
int* rotationMinLbpCxx(int columns, const int* data, int* result);

#endif
