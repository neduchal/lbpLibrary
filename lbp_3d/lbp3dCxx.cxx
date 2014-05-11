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
#define compab_mask_inc(A, B, C, D, E, F, G, H, Ac, Bc, Cc, Dc, Ec, Fc, Gc, Hc, shift) \
{ value |= ((unsigned int)(cntr - (A*Ac + B*Bc + C*Cc + D*Dc + E*Ec + F*Fc + G*Gc + H*Hc)) & 0x80000000) \
>> (31-shift); A++; B++; C++; D++; E++; F++;G++; H++; } 


using namespace std;

/* ------------------------------------------------------------------------- */
/**
	Function lbp3dCxx

	- 3D Version of LBP texture analysis method.
  - Parameters :
			* rows - Nuber of rows in data
			* columns - Nuber of columns in data
			* slides - Number of slides in data
			* mask - Int numbers of voxel position in mask
			* maskCoef - Coefs for voxels in mask
			* pointsNum - Number of points in mask
			* center - Int position of center voxel in mask
			* radius - radius of mask
			* data - input data
			*result - output data 
*/
int * lbp3dCxx(int rows, int columns, int slides, int* mask, const double* maskCoef, const int pointsNum, const int centerPos, const int radius, int* data, int* result)
{

	int *p0 = data;
    int *pointers[240];

	/* Mask settings*/
	for(int i = 0; i < pointsNum * 8; i++)
	{
		pointers[i] = (p0 + *(mask+i));
	}
	const int *center = p0 + centerPos;

  // Help variables for rows,cols and center
	int r,c,s,cntr;
	unsigned int value;
  // Memory allocation
  memset(result, 0, (size_t)(pow(2,pointsNum)*sizeof(int)));
  // Main cycle
  for (s=0;s < slides - (radius*2); s++)
  {
    for (r=0; r < rows - (radius*2); r++)
    {
			for (c=0;c < columns - (radius*2); c++)
			{
      	value = 0;
      	cntr = *center - 1;
				for(int i = 0; i < pointsNum;i++)
				{
					compab_mask_inc(*pointers[(i)*8], *pointers[(i)*8+1], *pointers[(i)*8+2], *pointers[(i)*8+3], *pointers[(i)*8+4], *pointers[(i)*8+5], *pointers[(i)*8+6], *pointers[(i)*8+7], maskCoef[i*8], maskCoef[i*8+1], maskCoef[i*8+2], maskCoef[i*8+3], maskCoef[i*8+4], maskCoef[i*8+5], maskCoef[i*8+6], maskCoef[i*8+7], i);
				}
      	center++;
      	result[value]++;
			}

			for(int i = 0; i < pointsNum * 8; i++)
			{
				pointers[i] += (radius*2);
			}
	    center += (radius*2);
    }

		for(int i = 0; i < pointsNum * 8; i++)
		{
			pointers[i] += (radius*2)*columns;
		}
    center += (radius*2)*columns;
  }
  
  return result;
}
/* ------------------------------------------------------------------------- */
#endif
