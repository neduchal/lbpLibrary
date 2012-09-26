#ifndef __const_h
#define __const_h


/**
 \file const.h
 \details File contain useful types and constants.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */

/* Necessary headers */   
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

/* ------------------------------------------------------------------------- */

    /*  Image2D - Zakladni 2d obrazek v ITK  */
  /** \typedef typedefitk::Image< float, 2> Image2D;
    ITK 2D image type. Pixels are floats.
  */
    typedef  itk::Image< float, 2>                      Image2D;
  /** \typedef typedef Image2D::Pointer  Image2DPointer;
    Pointer on 2D image.
  */
    typedef  Image2D::Pointer                           Image2DPointer;
  /** \typedef typedef Image2D::RegionType    Image2DRegion;   
    2D image region.
  */
    typedef  Image2D::RegionType                        Image2DRegion;   
  /** \typedef typedef Image2D::IndexType  Image2DIndex;  
    Index type of 2D image.
  */
    typedef  Image2D::IndexType                         Image2DIndex;   
  /** \typedef typedef Image2D::SizeType   Image2DSize; 
    Size type of 2D image.
  */
    typedef  Image2D::SizeType                          Image2DSize; 
  /** \typedef typedef  Image2D::PixelType   Image2DPixel;    
    Pixel type of 2D image.
  */
    typedef  Image2D::PixelType                         Image2DPixel;    
  /** \typedef typedef itk::ImageRegionIterator< Image2D >   Image2DIterator;
    Iterator of 2D image type.
  */
    typedef  itk::ImageRegionIterator< Image2D >        Image2DIterator;

/* ------------------------------------------------------------------------- */
    
  /** \typedef typedef std::vector< Image2DPointer >  Image2DFilters;
    List of 2D images (List of LBP masks in this case)
  */
    typedef  std::vector< Image2DPointer >              Image2DFilters;
  /** \typedef typedef Image2DFilters   *Image2DFilterPointers;
    Pointer on list of 2D images.
  */
    typedef  Image2DFilters                             *Image2DFilterPointers;
  /** \typedef typedef Image2DFilters::size_type  Image2DFiltersLength;
    Size type of 2d Image list.
  */
    typedef  Image2DFilters::size_type                  Image2DFiltersLength;
  /** \typedef typedef  Image2DFilters::iterator Image2DFiltersIterator;
    List iterator
  */
    typedef  Image2DFilters::iterator                   Image2DFiltersIterator;
    
/* ------------------------------------------------------------------------- */

  /** \typedef typedef unsigned char LBP8PixelType;
    Pixel type for LBP  8-bit (Max 8 samples)
  */
    typedef unsigned char                               LBP8PixelType;
  /** \typedef typedef unsigned short LBP16PixelType;
    Pixel type for LBP  16-bit (Max 16 samples)
  */
    typedef unsigned short                              LBP16PixelType;
  /** \typedef typedef unsigned int LBP32PixelType;
    Pixel type for LBP  32-bit (Max 32 samples)
  */
    typedef unsigned int                                LBP32PixelType;
  /** \typedef typedef itk::Image< LBP8PixelType, 2> LBP8bit2D;
    LBP image type (max 8 samples)
  */
    typedef  itk::Image< LBP8PixelType, 2>              LBP8bit2D;
  /** \typedef typedef itk::Image< LBP16PixelType, 2> LBP16bit2D;
    LBP image type (max 16 samples)
  */
    typedef  itk::Image< LBP16PixelType, 2>             LBP16bit2D;
  /** \typedef typedef itk::Image< LBP32PixelType, 2> LBP32bit2D;
    LBP image type (max 32 samples)
  */
    typedef  itk::Image< LBP32PixelType, 2>             LBP32bit2D;

/* ------------------------------------------------------------------------- */

  /** \typedef typedef itk::ImageFileReader< Image2D > Image2DReaderType;
    File reader for 2D image type
  */
    typedef itk::ImageFileReader< Image2D >             Image2DReaderType;
  /** \typedef typedef itk::ImageFileWriter< Image2D >  Image2DWriterType;
    File writer for 2D image type
  */
    typedef itk::ImageFileWriter< Image2D >             Image2DWriterType;
  /** \typedef typedefitk::RescaleIntensityImageFilter< Image2D, Image2D > Image2DRescaleType;
    Rescale intensity filter for 2D image type
  */
    typedef itk::RescaleIntensityImageFilter< Image2D,
                                              Image2D > Image2DRescaleType;

/* ------------------------------------------------------------------------- */

  /** \typedef typedef itk::VnlFFTRealToComplexConjugateImageFilter< Image2DPixel, 2 >  FftFilterType;
    FFT filter type
  */
    typedef itk::VnlFFTRealToComplexConjugateImageFilter< Image2DPixel, 2 >
                                                        FftFilterType;
  /** \typedef typedef FftFilterType::Pointer  FftFilterPointer;
    Pointer on FFT filter type
  */
    typedef FftFilterType::Pointer                      FftFilterPointer;
  /** \typedef typedef itk::VnlFFTComplexConjugateToRealImageFilter< Image2DPixel, 2 > IFftFilterType; 
     IFFT filter type
  */
    typedef itk::VnlFFTComplexConjugateToRealImageFilter< Image2DPixel, 2 >   IFftFilterType;                      
  /** \typedef typedef IFftFilterType::Pointer  IFftFilterPointer;
    Pointer on IFFT filter type
  */
    typedef IFftFilterType::Pointer                     IFftFilterPointer;  
  /** \typedef typedef FftFilterType::OutputImageType SpectralImageType;
    Spectral image type (Complex Image of Fourier space)
  */
    typedef FftFilterType::OutputImageType              SpectralImageType;
  /** \typedef typedef itk::MultiplyImageFilter< SpectralImageType, SpectralImageType, SpectralImageType>       MultiplyFilterType;
    Filter for multiply two Spectral images.
  */
    typedef itk::MultiplyImageFilter< SpectralImageType, 
            SpectralImageType, SpectralImageType>       MultiplyFilterType;
  /** \typedef typedef MultiplyFilterType::Pointer MultiplyFilterPointer;
    Pointer on multiply filter.
  */
    typedef MultiplyFilterType::Pointer                 MultiplyFilterPointer;
	
/* ------------------------------------------------------------------------- */

  /** \typedef typedef itk::Statistics::ScalarImageToListAdaptor< Image2D > AdaptorType;
    Adaptor type (See ITK documentation for information about ITK histograms)
  */
    typedef itk::Statistics::ScalarImageToListAdaptor< Image2D > 
                                                        AdaptorType;
  /** \typedef typedef AdaptorType::Pointer AdaptorPointer;
    Pointer on adaptor type.
  */
    typedef AdaptorType::Pointer                        AdaptorPointer;
  /** \typedef typedef itk::Statistics::ListSampleToHistogramGenerator< AdaptorType, Image2DPixel > GeneratorType;
    Generator type (See ITK documentation for information about ITK histograms)
  */
    typedef itk::Statistics::ListSampleToHistogramGenerator< AdaptorType, 
            Image2DPixel >                              GeneratorType;
  /** \typedef typedef GeneratorType::Pointer GeneratorPointer;
    Pointer on generator type.
  */
	  typedef GeneratorType::Pointer                      GeneratorPointer;
  /** \typedef typedef GeneratorType::HistogramType HistogramType;
    Histogram type
  */
	  typedef GeneratorType::HistogramType                HistogramType;
  /** \typedef typedef HistogramType::ConstPointer HistogramPointer;
    Pointer on histogram type.
  */
	  typedef HistogramType::ConstPointer                 HistogramPointer;
  /** \typedef typedef HistogramType::SizeType HistogramSize;
    Size type for histogram.
  */
	  typedef HistogramType::SizeType                     HistogramSize;

/* ------------------------------------------------------------------------- */

#endif
