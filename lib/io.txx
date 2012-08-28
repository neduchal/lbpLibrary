#ifndef __io_txx
#define __io_txx

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: io.txx $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */    
#include "io.h"

/* ------------------------------------------------------------------------- */

/** Funkce loadImage(*image, filename) */
template <class TInputImage>
int loadImage(typename TInputImage::Pointer *image, std::string filename)
{
  // Vytvoreni a nastaveni readeru obrazku
  typename itk::ImageFileReader< TInputImage >::Pointer reader 
            = itk::ImageFileReader< TInputImage >::New();
  reader->SetFileName( filename );
  // Pokus o nacteni obrazku
  try
  {
    reader->Update();
  }
  catch( itk::ExceptionObject & err )
  {
    std::cerr << "Chyba pri nacitani obrazovych dat!" << std::endl;
    std::cerr << err << std::endl;
    return EXIT_FAILURE;
  }
  // Vraceni obrazku do programu
  (*image) = reader->GetOutput();
  return 0;
}

/* ------------------------------------------------------------------------- */
	
/** Funkce rescaleImageIntensity(*image, *image2, min, max) */
template <class TInputImage, class TOutputImage>
void rescaleImageIntensity(typename TInputImage::Pointer *image,
  typename TOutputImage::Pointer *image2, unsigned int min, unsigned int max)
{
  // Vytvoreni filtru pro zmenu rozsahu pixelu v obrazu
  typename itk::RescaleIntensityImageFilter< TInputImage, TOutputImage >::Pointer rescale =
    itk::RescaleIntensityImageFilter< TInputImage, TOutputImage >::New();
  // Nastaveni rozsahu
  rescale->SetOutputMinimum( min );
  rescale->SetOutputMaximum( max );
  // Nastaveni vstupu a vraceni vysledku
  rescale->SetInput((*image));
  rescale->Update();
  (*image2) = rescale->GetOutput();
}

/* ------------------------------------------------------------------------- */
	
/** Funkce saveImage8bit(image, filename) */
template <class TInputImage>
int saveImage8bit(typename TInputImage::Pointer image, std::string filename)
{
  // Vytvoreni zapisovaciho objektu a nastaveni jmena souboru
  typename itk::ImageFileWriter< TInputImage >::Pointer writer
    = itk::ImageFileWriter< TInputImage >::New();
  writer->SetFileName( filename );
  // Nastaveni vstupu a pokus o ulozeni
  writer->SetInput((image));
  try
  {
    writer->Update();
  }
  catch( itk::ExceptionObject & err )
  {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return EXIT_FAILURE;
  }
  // Vraceni hodnoty 1 v pripade uspechu
  return 1;
}

/* ------------------------------------------------------------------------- */
	
/** Funkce saveImage16bit(image, filename) */
template <class TInputImage>
int saveImage16bit(typename TInputImage::Pointer image, std::string filename)
{
  // Vytvoreni zapisovaciho objektu a nastaveni jmena souboru
  typename itk::ImageFileWriter< TInputImage >::Pointer writer
    = itk::ImageFileWriter< TInputImage >::New();
  writer->SetFileName( filename );
  // Nastaveni vstupu a pokus o ulozeni
  writer->SetInput((image));
  try
  {
    writer->Update();
  }
  catch( itk::ExceptionObject & err )
  {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return EXIT_FAILURE;
  }
  // Vraceni hodnoty 1 v pripade uspechu
  return 1;
}
	
/* ------------------------------------------------------------------------- */

#endif
