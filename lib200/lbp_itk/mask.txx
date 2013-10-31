#ifndef __mask_txx
#define __mask_txx

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: mask.txx $
      Language:  C++
      Date:      $Date: 2012-07-18 13:14:00 $
      Version:   $Revision: 1.0.0 $ 

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include "mask.hpp"

/* Constants */
#define RADIAN 57.29 // pro prevod na  radiany
#define FOUR   4
#define EIGHT  8

/* ------------------------------------------------------------------------- */

void generate2D(Image2DFilterPointers filters, unsigned int radius,
  unsigned int samples, unsigned int length)
{
  // Pomocne promenne pro spravne urcovani indexu a hodnot v masce
  float value = (1.0/(float)radius);
  double angle = 360.0/(double)samples;
  double shift = (25-((radius-2)*5));
  if (radius == 1)
  {
     shift = 0;
  }
  
  // Nastaveni pocatku masky na 0,0
  Image2DIndex index;
  index[0] = 0;
  index[1] = 0;

  // Nastaveni velikosti masky
  Image2DSize size;
  size[0] = length;
  size[1] = length;

  // Ulozeni hodnot do regionu a vytvoreni promenne pro pixel index
  Image2DRegion region;
  region.SetIndex(index);
  region.SetSize(size);
  Image2DIndex pixelIndex;
      
  // Tvorba masek
  for(unsigned int i = 0; i < samples; i++)
  {       
    // Vytvoreni promenne s maskou
    Image2DPointer sink = Image2D::New();
     
	// Nastaveni vlastnosti a alokovani pameti
	sink->SetRegions(region);
    sink->Allocate();

	// Nastaveni stredu masky
    pixelIndex[0] = radius; 
    pixelIndex[1] = radius;  
    sink->SetPixel( pixelIndex, -1 );
	
	// Nastaveni ostatnich bodu masky
    for(unsigned int j = 0; j < radius; j++)
	{
	  pixelIndex[0] = (radius - floor(((cos(((i*angle)+((shift)*j))/RADIAN))*radius)+0.5)); 
	  pixelIndex[1] = (radius - floor(((-sin(((i*angle)+((shift)*j))/RADIAN))*radius)+0.5));       
      sink->SetPixel( pixelIndex, value);
    }
	
	// Vraceni vysledku
    filters->push_back(sink);
  }   
}

/* ------------------------------------------------------------------------- */
		
void generateEight2D( Image2DFilterPointers filters,unsigned int length)
{
  generate2D(filters,1,EIGHT,length);
}

/* ------------------------------------------------------------------------- */
		
void generateFour2D( Image2DFilterPointers filters,unsigned int length)
{
  generate2D(filters,1,FOUR,length);
}

/* ------------------------------------------------------------------------- */

#endif
