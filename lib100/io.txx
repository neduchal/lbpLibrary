#ifndef __io_txx
#define __io_txx

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: io.txx $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 1.0.0 $ 

   ------------------------------------------------------------------------- */

/* Necessary headers */     
#include "io.h"

/* ------------------------------------------------------------------------- */

template <class TInputImage>
int loadImage(typename TInputImage::Pointer *image, std::string filename)
{

  typename itk::ImageFileReader< TInputImage >::Pointer reader 
            = itk::ImageFileReader< TInputImage >::New();
  reader->SetFileName( filename );

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

  (*image) = reader->GetOutput();
  return 0;
}

/* ------------------------------------------------------------------------- */
	
template <class TInputImage, class TOutputImage>
void rescaleImageIntensity(typename TInputImage::Pointer *imageIn,
  typename TOutputImage::Pointer *imageOut, unsigned int min, unsigned int max)
{
  
  typename itk::RescaleIntensityImageFilter< TInputImage, TOutputImage >::Pointer rescale =
    itk::RescaleIntensityImageFilter< TInputImage, TOutputImage >::New();
  
  rescale->SetOutputMinimum( min );
  rescale->SetOutputMaximum( max );
  
  rescale->SetInput((*imageIn));
  rescale->Update();
  (*imageOut) = rescale->GetOutput();
}

/* ------------------------------------------------------------------------- */
	
template <class TInputImage>
int saveImage(typename TInputImage::Pointer image, std::string filename)
{

  typename itk::ImageFileWriter< TInputImage >::Pointer writer
    = itk::ImageFileWriter< TInputImage >::New();
  writer->SetFileName( filename );

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

  return 0;
}

/* ------------------------------------------------------------------------- */
	

#endif
