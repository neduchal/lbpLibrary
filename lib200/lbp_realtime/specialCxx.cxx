#ifndef __specialCxx_cxx
#define __specialCxx_cxx

/* -------------------------------------------------------------------------

      Program:   Realtime module fort LbpLibrary
      Module:    $RCSfile: specialCxx.cxx $
      Language:  C++
      Date:      $Date: 2013-12-20 9:12:00 $
      Version:   $Revision: 0.9.0$

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "realtimeCxx.hpp"

using namespace std;

/* ------------------------------------------------------------------------- */

int* uniformLbpCxx(int columns, const int* data, int* result)
{
  const int *p0 = data;

  memset(result, 0, columns*sizeof(int));

  // Cyklus pocitajici uniform patterns vzory          
  for(int i = 0; i < columns; i++)
  {
    value = *p0;	
    unsigned int unif = 0;
    char change = 0;
    char help = value % 2;

    while(i>1)
    {
      value /= 2;
      char value2 = i%2 ;
      if(help != value2) 
      {
        help = value2; 
        change++;
        if(change > 2) 
        {
          unif = 0;        
          break;
        }
      }
    }
		result[unif] += *p0;
		p0++;
  }         
}

/* ------------------------------------------------------------------------- */

int* rotationMinLbpCxx(int columns, const int* data, int* result)
{
  const int *p0 = data,
	unsigned int value;

  memset(result, 0, columns*sizeof(int));
	for(int i = 0; i < columns; i++)
  {
		value = *p0;	
		unsigned int minimum = pow(2.0,32)-1;

    for(int j = 0; j < 32; j++)
    {
      unsigned int help = (value<<j | value>>(32-j));
      if(help < minimum) minimum = help;          
    }
    
		result[minimum] += value;
		p0++;
  }     
}
/* ------------------------------------------------------------------------- */
#endif
