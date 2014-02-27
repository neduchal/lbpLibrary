#ifndef __lbp4x12Cxx_cxx
#define __lbp4x12Cxx_cxx

/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: lbpCxx.cxx $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 1.0.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "lbp4x12Cxx.hpp"

// Helping macro for real-time algorithm
#define compab_mask_inc(ptr,shift) \
{ value |= ((unsigned int)(cntr - *ptr) & 0x80000000) \
>> (31-shift); ptr++; }

#define compab_mask_inc_diag(A, B, shift) \
{ value |= ((unsigned int)(cntr - ((0.4641*(*A))+(0.5359*(*B)))) & 0x80000000) \
	>> (31-shift); A++; B++; }

using namespace std;

/* ------------------------------------------------------------------------- */

int * lbp4x12Cxx(int rows, int columns, const int* data, int* result)
{
  // MASK (group of pointers 
  const int *p01 = data + 2,
     *p02 = p01 + columns,
     *p1 = p01 + 2,
     *p21 = p1 + 2, 
     *p22 = p21 + columns,
     *p31 = p22 + 1 + columns, 
     *p32 = p31 + 1,
		 *p4 = p32 + columns + columns, 
     *p51 = p4 + columns + columns, 
     *p52 = p51 - 1,		
     *p61 = p52 - 1 + columns, 
     *p62 = p61 + columns,
     *p7 = p62 - 2,
     *p81 = p7 - 2, 
     *p82 = p81 - columns,
     *p91 = p82 - 1 - columns, 
     *p92 = p91 - 1,
		 *p10 = p92 - columns - columns, 
     *p111 = p10 - columns - columns, 
		 *p112 = p111 + 1,
		*center = p112 + 3 + columns + columns;


  // Help variables for rows,cols and center
	int r,c,cntr;
	unsigned int value;
  // Memory allocation
  memset(result, 0, 4096*sizeof(int));
  // Main cycle
  for (r=0;r<rows-8;r++)
  {
    for (c=0;c<columns-8;c++)
    {
      value = 0;

      cntr = *center - 1;
      compab_mask_inc_diag(p01, p02, 0)
      compab_mask_inc(p1,1);
      compab_mask_inc_diag(p21, p22, 2)
      compab_mask_inc_diag(p31, p32, 3)
      compab_mask_inc(p4,4);
      compab_mask_inc_diag(p51, p52, 5)
      compab_mask_inc_diag(p62, p61, 6)
      compab_mask_inc(p7,7);
      compab_mask_inc_diag(p81, p82, 8)
      compab_mask_inc_diag(p92, p91, 9)
      compab_mask_inc(p10,10);
      compab_mask_inc_diag(p111, p112, 11)
      center++;
      result[value]++;
      std::cout << value;
    }
		 p01 += 8;
     p02 += 8;
     p1 += 8;
     p21 += 8;
     p22 += 8;
     p31 += 8;
     p32 += 8;
		 p4 += 8;
     p51 += 8;
     p52 += 8;	
     p61 += 8;
     p62 += 8;
     p7 += 8;
     p81 += 8;
     p82 += 8;
     p91 += 8; 
     p92 += 8;
		 p10 += 8;
     p111 += 8;
		 p112 += 8;
		 center += 8;
  }
  
  return result;
}
/* ------------------------------------------------------------------------- */

#endif
