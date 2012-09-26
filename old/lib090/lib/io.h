#ifndef __io_h
#define __io_h

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: io.h $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */ 
#include <iostream>
#include "itkImage.h"
#include "itkImageRegionIterator.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRescaleIntensityImageFilter.h"

/* ------------------------------------------------------------------------- */

/**
  Funkce loadImage nacte obrazek ze zadaneho umisteni.

  Vstupni parametry :
    TInputImage::Pointer  *image - pointer na predpripraveny image pointer v ITK.
	std::string  filename - Cesta k obrazku, ktery se ma nacist.

  Vystup funkce :
	Nacteny obrazek je ulozen do parametru image.
*/
template <class TInputImage>
int loadImage(typename TInputImage::Pointer *image, std::string filename);

/* ------------------------------------------------------------------------- */
	
/**
  Funkce rescaleImageIntensity prepocita pixely obrazku tak, aby odpovidaly
  zadanemu rozmezi.

  Vstupni parametry :
    TInputImage::Pointer *image - Pointer na obrazek, ktery chceme upravovat
    TInputImage::Pointer *image2 - Pointer na obrazek, do ktereho chceme
							       ulozit vysledek
*/
template <class TInputImage, class TOutputImage>
void rescaleImageIntensity(typename TInputImage::Pointer *image,
  typename TOutputImage::Pointer *image2, unsigned int min, unsigned int max);
	
/* ------------------------------------------------------------------------- */
	
/**
  Funkce saveImage8bit ulozi obrazek pod zadanym nazvem (pro kazdy pixel 8 bitu)
  (Ukladany obrazek musi mit pixely take 8 bitove) 

  Vstupni parametry :
    TInputImage::Pointer image - Obraze, ktery chceme ulozit
    std::string filename - cesta a jméno ukladaneho souboru
*/
template <class TInputImage>
int saveImage8bit(typename TInputImage::Pointer image, std::string filename);

/* ------------------------------------------------------------------------- */
	
/**
  Funkce saveImage16bit ulozi obrazek pod zadanym nazvem (pro kazdy pixel 16 bitu) 
  (Ukladany obrazek musi mit pixely take 16 bitove) 

  Vstupni parametry :
    TInputImage::Pointer image - Obrazek, ktery chceme ulozit
	std::string filename - cesta a jméno ukladaneho souboru
*/
template <class TInputImage>
int saveImage16bit(typename TInputImage::Pointer image, std::string filename);

/* ------------------------------------------------------------------------- */

#endif
