#ifndef __lbp3dCxx_cxx
#define __lbp3dCxx_cxx

/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: lbp3dCxx.cxx $
      Language:  C++
      Date:      2014 
      Version:   $Revision: 0.1.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "lbp3dCxx.hpp"


// Helping macro for real-time algorithm
#define compab_mask_inc(ptr,shift) \
{ value |= ((unsigned int)(cntr - *ptr) & 0x80000000) \
>> (31-shift); ptr++; }


using namespace std;

/* ------------------------------------------------------------------------- */

int * lbp3dCxx(int rows, int columns, int slides, const double* centerX, const double* centerY, int radius, int pointsNum, const int* data, int* result)
{

	// TODO : AUTOMATIC CREATION OF THE MASK
  // MASK (group of pointers 
  /*const int *p0 = data,
     *p1 = p0 + 1,
     *p2 = p1 + 1,
     *p3 = p2 + columns,
     *p4 = p3 + columns,
     *p5 = p4 - 1,
     *p6 = p5 - 1,
     *p7 = p6 - columns,
		*center = p7 + 1;*/
  // Help variables for rows,cols and center
	int r,c,s,cntr;
	unsigned int value;
  // Memory allocation
  memset(result, 0, pow(2,pointsNum)*sizeof(int));
  // Main cycle
  for (r=0;r < rows - (radius*2); r++)
  {
    for (c=0;c < columns - (radius*2); c++)
    {
			for (s=0;s < slides - (radius*2); s++)
			{

			// TODO : main loop with created mask

/*
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
      result[value]++;
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

*/
    }
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
