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
#include "specialCxx.hpp"


using namespace std;

/* ------------------------------------------------------------------------- */

int* uniformLbpCxx(int columns, const int* data, int* result)
{
  const int *p0 = data;

  memset(result, 0, columns*sizeof(int));

  // Cyklus pocitajici uniform patterns vzory          
  for(int i = 0; i < columns; i++)
  {
  	int value = i;	
    unsigned int unif = i;
    int change = 0;
    int help = ((value ) & 1);
    
		int help2 = 0;
    
    for(int j = 1; j < 32; j++)   
    {
      if(*p0 == 0) {break;}
    	int help2 = ((value) & (unsigned int)pow(2,j)) >> j;   
    	if(help != help2)
    	{    	
    		help = help2;
    		change++;
    	} 
    	   	
    }
    
    help = ((value ) & 1);
   	if(help != help2)
   	{    	
   		help = help2;
   		change++;
   	}     
    
    if(change != 2)
    {
   			result[0] += *p0;   			
				p0++; 
    		continue;	
    }
    
		result[unif] += *p0;
		p0++;  
	}  
    
  return result;
}

/* ------------------------------------------------------------------------- */

int* rotationMinLbpCxx(int columns, const int* data, int* result)
{
  const int *p0 = data;

  memset(result, 0, columns*sizeof(int));
	for(int i = 0; i < columns; i++)
  {
		int value = *p0;	
		if(value == 0) 
		{
			p0++;
			continue;
		
		}
		unsigned int minimum = (unsigned int)(pow(2.0,32)-1);

    for(int j = 0; j < 32; j++)
    {
      unsigned int help = (i<<j | i>>(32-j));
      if(help < minimum) minimum = help;          
    }
    
		result[minimum] += value;
		p0++;
  }     

  return result;
}
/* ------------------------------------------------------------------------- */

#endif
