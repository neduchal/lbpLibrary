#ifndef __lbpCxx_cxx
#define __lbpCxx_cxx

/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: lbpCxx.cxx $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */
#include "const.h"
#include "imageToLbpFilter.h"
#include "realtimeLbp.h"
#include <iostream>
#include <stdlib.h>
#include "lbpCxx.h"

// Makro pocitajici jednu LBP hodnotu pomoci real time implementace
#define compab_mask_inc(ptr,shift) \
{ value |= ((unsigned int)(cntr - *ptr) & 0x80000000) \
>> (31-shift); ptr++; }

// Pouziti potrebnych namespace
using namespace std;
using namespace itk;

/* ------------------------------------------------------------------------- */

/** imageToLbpCxx(sizeX, sizeY, data, type, radius, samples) */
double * imageToLbpCxx(int sizeX, int sizeY, double * data,unsigned int type,
  unsigned int radius,unsigned int samples)
{
  // alokace pameti pro vstupni data.
  Image2D::IndexType start;
	Image2D::SizeType  size;
  size[0]  = sizeX;  // size along X
	size[1]  = sizeY;  // size along Y
	start[0] =   0;  // first index on X
	start[1] =   0;  // first index on Y
	Image2D::Pointer image = Image2D::New();
	Image2D::RegionType region;
	region.SetSize( size );
	region.SetIndex( start );
	image->SetRegions( region );
	image->Allocate();
  // Naplneni vstupnimi daty
	Image2D::IndexType pixelIndex;
  int i,j;
  for( i = 0; i < sizeX; i++)
  {
    for( j = 0; j < sizeY; j++)
    {
      // Nastaveni pozice v obrazu
      pixelIndex[0] = i;   // x position
      pixelIndex[1] = j;   // y position
      // Ziskani spravne hodnoty pixelu
      Image2DPixel pixelValue = data[i*sizeX + j];
      // Nastaveni pixelu v alokovane pameti
      image->SetPixel(pixelIndex, pixelValue);
    }
  }
  // Vytvoreni objektu LBP filtru
  ImageToLbpFilter<Image2D, LBP8bit2D>::Pointer LbpFilter =
    ImageToLbpFilter<Image2D, LBP8bit2D>::New();
  // Nastaveni LBP filtru
  LbpFilter->SetInput(image);
  LbpFilter->SetMappingType(type);
  LbpFilter->SetMaskProperties(radius, samples);
  // Prevod na lbp
  LbpFilter->Update();

  // Ziskani vystupnich dat
  for( i = 0; i < sizeX; i++) {
    for( j = 0; j < sizeY; j++) {
        pixelIndex[0] = i;   // x position
        pixelIndex[1] = j;   // y position
        data[i*sizeX + j] = LbpFilter->GetOutput()->GetPixel(   pixelIndex );
    }
  }
  // Vraceni vystupu
  return data;
}

/* ------------------------------------------------------------------------- */

/** RealTimeLbp(rows, columns, data, result) */
int * realTimeLbpCxx(int rows, int columns, const int* data, int* result)
{
  // Nastaveni masky na pocatek obrazovych dat
	const int *p0 = data,
		*p1 = p0 + 1,
		*p2 = p1 + 1,
		*p3 = p2 + columns,
		*p4 = p3 + columns,
		*p5 = p4 - 1,
		*p6 = p5 - 1,
		*p7 = p6 - columns,
		*center = p7 + 1;
  // Pomocne promenne (radky, sloupce, stred masky, hodnota)
	int r,c,cntr;
	unsigned int value;
  // Alokace pameti pro vystupni histogram
  memset(result, 0, 256*sizeof(int));
  // Cyklus prochazejici data a pocitajici jednotlive LBP hodnoty
	for (r=0;r<rows-2;r++)
	{
		for (c=0;c<columns-2;c++)
		{
			value = 0;
			cntr = *center - 1;
      // Vyuziti makra (viz vyse)
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
    // Inkrementace masky - pohyb v datech
		p0 += 2;
		p1 += 2;
		p2 += 2;
		p3 += 2;
		p4 += 2;
		p5 += 2;
		p6 += 2;
		p7 += 2;
		center += 2;
	}
  // Vraceni vysledku
	return result;
}
/* ------------------------------------------------------------------------- */

#endif