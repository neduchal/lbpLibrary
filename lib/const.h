#ifndef __const_h
#define __const_h

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: const.h $
      Language:  C++
      Date:      $Date: 2012-07-02 19:10:00 $
      Version:   $Revision: 0.9.0 $ 

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */ 
#include <vector>
#include "itkImage.h"
#include "itkImageRegionIterator.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkVnlFFTRealToComplexConjugateImageFilter.h"
#include "itkVnlFFTComplexConjugateToRealImageFilter.h"
#include "itkMultiplyImageFilter.h"
#include "itkImageRegionIterator.h"
#include "itkScalarImageToListAdaptor.h"
#include "itkListSampleToHistogramGenerator.h"

/* Definovani pomocnych typu pro praci s knihovnou - soubor lze upravovat    */ 

/* ------------------------------------------------------------------------- */

    /*  Image2D - Zakladni 2d obrazek v ITK  */
    typedef  itk::Image< float, 2>                      Image2D;
    typedef  Image2D::Pointer                           Image2DPointer;
    typedef  Image2D::RegionType                        Image2DRegion;   
    typedef  Image2D::IndexType                         Image2DIndex;   
    typedef  Image2D::SizeType                          Image2DSize; 
    typedef  Image2D::PixelType                         Image2DPixel;    
    typedef  itk::ImageRegionIterator< Image2D >        Image2DIterator;

/* ------------------------------------------------------------------------- */
    
    /* Image2DFilters - Vektor 2D obrazku v ITK - Vetsinou pouzit pro filtry */
    typedef  std::vector< Image2DPointer >              Image2DFilters;
    typedef  Image2DFilters                             *Image2DFilterPointers;
    typedef  Image2DFilters::size_type                  Image2DFiltersLength;
    typedef  Image2DFilters::iterator                   Image2DFiltersIterator;
    
/* ------------------------------------------------------------------------- */

    /* Typy LBP pixelu a  LBP obrazku */
    typedef unsigned char                               LBP8PixelType;
    typedef unsigned short                              LBP16PixelType;
    typedef unsigned int                                LBP32PixelType;
    typedef  itk::Image< LBP8PixelType, 2>              LBP8bit2D;
    typedef  itk::Image< LBP16PixelType, 2>             LBP16bit2D;
    typedef  itk::Image< LBP32PixelType, 2>             LBP32bit2D;

/* ------------------------------------------------------------------------- */

    /* Typ readeru, writeru a menice intenzity pixelu pro image2D v ITK  */
    typedef itk::ImageFileReader< Image2D >             Image2DReaderType;
    typedef itk::ImageFileWriter< Image2D >             Image2DWriterType;
    typedef itk::RescaleIntensityImageFilter< Image2D,
                                              Image2D > Image2DRescaleType;

/* ------------------------------------------------------------------------- */

    /* Typy pro FFT, IFFT a nasobeni obrazku pixel po pixelu */ 
    typedef itk::VnlFFTRealToComplexConjugateImageFilter< Image2DPixel, 2 >
                                                        FftFilterType;
    typedef FftFilterType::Pointer                      FftFilterPointer;
    typedef itk::VnlFFTComplexConjugateToRealImageFilter< Image2DPixel, 2 >                         
                                                        IFftFilterType; 
    typedef IFftFilterType::Pointer                     IFftFilterPointer;  
    typedef FftFilterType::OutputImageType              SpectralImageType;
    typedef itk::MultiplyImageFilter< SpectralImageType, 
            SpectralImageType, SpectralImageType>       MultiplyFilterType;
    typedef MultiplyFilterType::Pointer                 MultiplyFilterPointer;
	
/* ------------------------------------------------------------------------- */

	  /* Typy pro histogram v ITK */
	  typedef itk::Statistics::ScalarImageToListAdaptor< Image2D > 
                                                        AdaptorType;
	  typedef AdaptorType::Pointer                        AdaptorPointer;
	  typedef itk::Statistics::ListSampleToHistogramGenerator< AdaptorType, 
            Image2DPixel >                              GeneratorType;
	  typedef GeneratorType::Pointer                      GeneratorPointer;
	  typedef GeneratorType::HistogramType                HistogramType;
	  typedef HistogramType::ConstPointer                 HistogramPointer;
	  typedef HistogramType::SizeType                     HistogramSize;

/* ------------------------------------------------------------------------- */

#endif
