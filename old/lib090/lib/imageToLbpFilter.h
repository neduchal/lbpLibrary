
/*=========================================================================

  Program:   LBP filter for C++
  Module:    $RCSfile: imageToLbpFilter.h,v $
  Language:  C++
  Date:      $Date: 2011-01-30 15:28:00 $
  Version:   $Revision: 0.1.0 $

=========================================================================*/

#ifndef __imageToLbpFilter_h
#define  __imageToLbpFilter_h

/* Pripojeni knihoven a hlavickovych souboru */ 
#include <vector>
#include "itkImageToImageFilter.h"
#include "itkImage.h"
#include "itkVnlFFTRealToComplexConjugateImageFilter.h"
#include "itkVnlFFTComplexConjugateToRealImageFilter.h"
#include "itkMultiplyImageFilter.h"
#include "itkImageRegionIterator.h"
#include "const.h"
#include "mask.h"
#include "mask.txx"
#include "mapping.h"
#include "mapping.txx"
#include "convolution.h"
#include "convolution.txx"

/* Definice typu a pomocnych konstant */
#define MAX_SAMPLES             16
#define MAX_RADIUS               4
#define LBP_BASIC             0x01
#define LBP_UNIFORM           0x02
#define LBP_ROT_MIN8          0x03
#define LBP_ROT_MIN16         0x04
#define LBP_ROT_MIN32         0x05

/* ------------------------------------------------------------------------- */

namespace itk
{

/** \class ImageToLbpFilter
 * \brief Filtr vytvori LBP reprezentaci obrazovych dat.
 */
template <class TInputImage, class TOutputImage>
class ITK_EXPORT ImageToLbpFilter: public ImageToImageFilter<TInputImage,TOutputImage> 
{

/* ------------------------------------------------------------------------- */

public:
  /** Standard class typedefs. */
  typedef ImageToLbpFilter                              Self;
  typedef ImageToImageFilter<TInputImage,TOutputImage>  Superclass;
  typedef SmartPointer<Self>                            Pointer;
  typedef SmartPointer<const Self>                      ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);
  
  /** Run-time type information (and related methods). */
  itkTypeMacro(ImageToLbpFilter, ImageToImageFilter);

  /** Další užiteèné typedef pro tuto tridu. */
  typedef TInputImage                            InputImageType;
  typedef typename    InputImageType::Pointer    InputImagePointer;
  typedef typename    InputImageType::RegionType InputImageRegion;  
  typedef typename    InputImageType::PixelType  InputImagePixelType; 
  typedef typename    InputImageType::IndexType  InputImagePixelIndex;   
  typedef TOutputImage                            OutputImageType;
  typedef typename    OutputImageType::Pointer    OutputImagePointer;
  typedef typename    OutputImageType::RegionType OutputImageRegion;
  typedef typename    OutputImageType::PixelType  OutputImagePixelType;
  typedef typename itk::ImageRegionIterator< InputImageType >                               
                                                  IteratorType;
  typedef typename itk::ImageRegionIterator< OutputImageType >     
                                                  OutIteratorType;
  typedef typename std::vector< InputImagePointer >                                         
                                                  ImageFilters;
  typedef typename ImageFilters::iterator         ImageFiltersIterator;
  typedef ImageFilters                            *ImageFiltersPointer;
  typedef typename ImageFilters::size_type        ImageFiltersLength;

/* ------------------------------------------------------------------------- */

  /* Funkce tridy slouzici k nastaveni parametru a jejich zpetnemu zjisteni */
  
  /**
    Funkce SetMaskProperties nastavi polomer LBP masky a pocet pocitanych bodu

    Vstupni parametry :
      unsigned int radius - polomer LBP masky.
	    unsigned int samples - pocet bodu LBP masky.
  */
  void SetMaskProperties(unsigned int radius, unsigned int samples); 
 
/* ------------------------------------------------------------------------- */  
  
  /**
    Funkce SetMappingType nastavi polomer LBP masky a pocet pocitanych bodu

    Vstupni parametry :
      unsigned int type - typ vypoctu LBP .
    Mozne konstanty a jejich hodnoty : 
    
      #define LBP_BASIC             0x10
      #define LBP_UNIFORM           0x11
      #define LBP_ROT_MIN8          0x12
      #define LBP_ROT_MIN16         0x13
      #define LBP_ROT_MIN32         0x14      
  */  
  void SetMappingType(unsigned int type);

/* ------------------------------------------------------------------------- */  
  
  /**
    Funkce GetMappingType vrati typ vypoctu LBP
  */  
  unsigned int GetMappingType();
  
/* ------------------------------------------------------------------------- */
  
  /**
    Funkce GetSamples vrati pocet bodu LBP masky
  */   
  unsigned int GetSamples();
  
/* ------------------------------------------------------------------------- */
  
  /**
    Funkce GetRadius vrati polomer masky
  */  
  unsigned int GetRadius();

/* ------------------------------------------------------------------------- */

protected:

/* ------------------------------------------------------------------------- */

  /* konstruktor and destruktor */
  ImageToLbpFilter();
  virtual ~ImageToLbpFilter() {};

/* ------------------------------------------------------------------------- */

  /* clenske funkce */
  void PrintSelf(std::ostream& os, Indent indent) const;
  void GenerateData(void);

/* ------------------------------------------------------------------------- */
  
  /* clenske promenne */
  ImageFilters m_filters;
  unsigned int m_mapping;
  unsigned int m_samples;
  unsigned int m_radius;

/* ------------------------------------------------------------------------- */

private:

/* ------------------------------------------------------------------------- */

  ImageToLbpFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};


} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "imageToLbpFilter.txx"
#endif

/* ------------------------------------------------------------------------- */

#endif
