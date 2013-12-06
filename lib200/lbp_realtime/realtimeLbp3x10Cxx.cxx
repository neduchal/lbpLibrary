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
     *p91 =  p81 - columns,
     *p92 = p91 - columns,
		 *p93 = p92 + 1
     *p94 = p93 + columns,		
		*center = p94 + 2 + columns;


  // Help variables for rows,cols and center
	int r,c,cntr;
	unsigned int value;
  // Memory allocation
  memset(result, 0, 256*sizeof(int));
  // Main cycle
  for (r=0;r<rows-4;r++)
  {
    for (c=0;c<columns-4;c++)
    {
      value = 0;

			// TODO : DO IT
      cntr = *center - 1;
      compab_mask_inc_diag(p04, p03, p02, p01, 0)
      compab_mask_inc(p0,0);
      compab_mask_inc(p1,1);
      compab_mask_inc_diag(p23, p24, p21, p22, 2)
      compab_mask_inc(p3,3);
      compab_mask_inc_diag(p41, p42, p43, p44, 4)
      compab_mask_inc(p5,5);
      compab_mask_inc_diag(p63, p64, p61, p62, 6)
      compab_mask_inc(p7,7);
      center++;
      result[value]++;
    }
		 *p01 += 4,
     *p02 += 4,
     *p03 += 4,
     *p04 += 4,
     *p1  += 4,
		 *p21 += 4, 
     *p22 += 4,
     *p23 += 4,
     *p24 += 4,		
     *p3  += 4,
		 *p41 += 4,
     *p42 += 4,
     *p43 += 4,
     *p44 += 4,
     *p5  += 4,
		 *p61 += 4,
     *p62 += 4,
     *p63 += 4,
     *p64 += 4,
     *p7  += 4,
		 *center += 4;
  }
  
  return result;
}
/* ------------------------------------------------------------------------- */


int * realTimeLbpImCxx(int rows, int columns, const int* data, int* result)
{
  // MASK (group of pointers 
  const int *p0 = data,
     *p1 = p0 + 1,
     *p2 = p1 + 1,
     *p3 = p2 + columns,
     *p4 = p3 + columns,
     *p5 = p4 - 1,
     *p6 = p5 - 1,
     *p7 = p6 - columns,
     *center = p7 + 1;

   int *rp = result + columns + 1;
  // Help variables for rows,cols and center
	int r,c,cntr;
	unsigned int value;
  // Memory allocation
  memset(result, 0, rows*columns*sizeof(int));
  // Main cycle
  for (r=0;r<rows-2;r++)
  {
    for (c=0;c<columns-2;c++)
    {
      value = 0;
      cntr = *center - 1;
      
      compab_mask_inc(p0,0);
      compab_mask_inc(p1,1);
      compab_mask_inc(p2,2);
      compab_mask_inc(p3,3);
      compab_mask_inc(p4,4);
      compab_mask_inc(p5,5);
      compab_mask_inc(p6,6);
      compab_mask_inc(p7,7);
      center++;
      *rp = value;
      rp++;
    }
    p0 += 2;
    p1 += 2;
    p2 += 2;
    p3 += 2;
    p4 += 2;
    p5 += 2;
    p6 += 2;
    p7 += 2;
    center += 2;
    rp += 2;
  }
  
  return result;
}
/* ------------------------------------------------------------------------- */

int * lbp2HistsCxx(int rows, int columns, const int* data, int partRows, int partColumns, int* result)
{
  // pointer to center of 32x32 matrix
  const int *center = data;    
   
  // Help variables for rows,cols
  int r,c;
  // Memory allocation
  int cr = (rows)/partRows;
  int cc = (columns)/partColumns;
  memset(result, 0, cr*cc*256*sizeof(int));
  // Main cycle
  for (r=0;r<rows;r++)
  {
    int actualR = r/partRows;
    for (c=0;c<columns;c++)
    {
      int actualC = c/partColumns; 
      //cout << r << " " << c << " " << actualR << " " << actualC << " " << (((actualR*cc)+actualC)*256) + *center << " " << *center << endl;      
      result[(((actualR*cc)+actualC)*256) + *center]++;
      //cout << result[(((actualR*cc)+actualC)*256) + *center] << endl;
      center++;
    }
  }
  
  return result;
}
/* ------------------------------------------------------------------------- */
#endif
