#ifndef __realtimeLbp3x10Cxx_cxx
#define __realtimeLbp3x10Cxx_cxx

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
#include "realtimeLbp3x10Cxx.hpp"

// Helping macro for real-time algorithm
#define compab_mask_inc(ptr,shift) \
{ value |= ((unsigned int)(cntr - *ptr) & 0x80000000) \
>> (31-shift); ptr++; }

#define compab_mask_inc_diag(A, B, C, D,shift) \
{ value |= ((unsigned int)(cntr - ((0.1012*(*A))+(0.1358*(*B))+ (0.4372*(*C))+ (0.3258*(*D)))) & 0x80000000) \
>> (31-shift); A++; B++; C++; D++; 

#define compab_mask_inc_diag2(A, B, C, D,shift) \
{ value |= ((unsigned int)(cntr - ((0.0107*(*A))+(0.1363*(*B))+ (0.7907*(*C))+ (0.0623*(*D)))) & 0x80000000) \
>> (31-shift); A++; B++; C++; D++; }


using namespace std;

/* ------------------------------------------------------------------------- */

int * realTimeLbp3x10Cxx(int rows, int columns, const int* data, int* result)
{
  // MASK (group of pointers 
  const int *p01 = data + 2,
     *p02 = p01 + 1,
     *p03 = p02 + columns,
     *p04 = p03 - 1,
     *p11 = p02,
     *p12 = p11 + 1,
     *p13 = p12 + columns,
     *p14 = p13 - 1,
		 *p21 = p13 + 1, 
     *p22 = p21 + 1,
     *p23 = p22 + columns,
     *p24 = p23 - 1,		
     *p3 = p23 + columns,
		 *p41 = p3 + columns,
     *p42 = p41 + columns,
     *p43 = p42 - 1, 
     *p44 = p43 - columns,
     *p51 = p43 - 1 ,
     *p52 = p51 + columns,
     *p53 = p52 - 1, 
     *p54 = p53 - columns,
		 *p61 = p54 - 1,
     *p62 = p61 + columns,
     *p63 = p62 - 1, 
     *p64 = p63 - columns,
     *p71 = p64 - 1,
		 *p72 = p71 - 1, 
		 *p73 = p72 - columns,
		 *p74 = p73 + 1,
		 *p8 = p73 - columns,
     *p91 =  p8 - columns,
     *p92 = p91 - columns,
		 *p93 = p92 + 1
     *p94 = p93 + columns,		
		*center = p94 + 2 + columns;


  // Help variables for rows,cols and center
	int r,c,cntr;
	unsigned int value;
  // Memory allocation
  memset(result, 0, 1024*sizeof(int));
  // Main cycle
  for (r=0;r<rows-6;r++)
  {
    for (c=0;c<columns-6;c++)
    {
      value = 0;

			// TODO : zkontrolovat na zaklade nakresu
      cntr = *center - 1;
      compab_mask_inc_diag2(p04, p03, p02, p01, 1)
      compab_mask_inc_diag2(p13, p14, p11, p12, 2)
      compab_mask_inc_diag(p23, p24, p21, p22, 3)
      compab_mask_inc(p3,4);
      compab_mask_inc_diag(p42, p43, p44, p41, 5)
      compab_mask_inc_diag2(p52, p53, p54, p51, 6)
      compab_mask_inc_diag2(p63, p62, p61, p64, 7)
      compab_mask_inc_diag(p73, p72, p71, p74, 8)
      compab_mask_inc(p8,9);
      compab_mask_inc_diag(p91, p94, p93, p92, 10)
      center++;
      result[value]++;
    }
		 p01 += 6;
     p02 += 6;
     p03 += 6;
     p04 += 6;
     p11 += 6;
     p12 += 6;
     p13 += 6;
     p14 += 6;
		 p21 += 6;
     p22 += 6;
     p23 += 6;
     p24 += 6;		
     p3  += 6;
		 p41 += 6;
     p42 += 6;
     p43 += 6; 
     p44 += 6;
     p51 += 6;
     p52 += 6;
     p53 += 6;
     p54 += 6;
		 p61 += 6;
     p62 += 6;
     p63 += 6;
     p64 += 6;
     p71 += 6;
		 p72 += 6;
		 p73 += 6;
		 p74 += 6;
		 p8  += 6;
     p91 += 6;
     p92 += 6;
		 p93 += 6;
     p94 += 6;		
		center += 6;
  }
  
  return result;
}

/* ------------------------------------------------------------------------- */
#endif
