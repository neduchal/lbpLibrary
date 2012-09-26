#ifndef __imageToLbpFilter_h
#define  __imageToLbpFilter_h

/**
 \file imageToLbpFilter.h
 \details Filter class for work with LBP library.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */

/* Necessary headers */  
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

/** \def MAX_SAMPLES 
 *  Max number of samples around center of LBP mask
*/
#define MAX_SAMPLES             32
/** \def MAX_RADIUS
 *  Max radian (It is only optional preference)
*/
#define MAX_RADIUS               16
/** \def LBP_BASIC 
 *  Basic LBP algorithm.
*/
#define LBP_BASIC             0x01
/** \def  LBP_UNIFORM  
 *  Uniform Patterns algorithm.
*/
#define LBP_UNIFORM           0x02
/** \def LBP_ROTMIN 
 *  Minimum of rotation 
*/
#define LBP_ROTMIN            0x03



/* ------------------------------------------------------------------------- */

namespace itk
{

/** \class ImageToLbpFilter
 * \brief Filter creates LBP data from input image.
 */
template <class TInputImage, class TOutputImage>
class ITK_EXPORT ImageToLbpFilter: public ImageToImageFilter<TInputImage,TOutputImage> 
{

/* ------------------------------------------------------------------------- */

public:
  /* Standard class typedefs. */
  /** \typedef typedef ImageToLbpFilter   Self;
    ITK internal Typedef
  */
  typedef ImageToLbpFilter                              Self;
  /** \typedef typedef ImageToImageFilter<TInputImage,TOutputImage>  Superclass;
    ITK internal Typedef
  */
  typedef ImageToImageFilter<TInputImage,TOutputImage>  Superclass;
  /** \typedef typedefSmartPointer<Self>   Pointer;
     ITK internal Typedef
  */
  typedef SmartPointer<Self>                            Pointer;
  /** \typedef typedef SmartPointer<const Self> ConstPointer;
    ITK internal Typedef
  */
  typedef SmartPointer<const Self>                      ConstPointer;

 /** \fn itkNewMacro(Self);
  Method for creation through the object factory.
 */
  itkNewMacro(Self);
  
 /** \fn itkTypeMacro(ImageToLbpFilter, ImageToImageFilter);
  Run-time type information (and related methods). 
 */
  itkTypeMacro(ImageToLbpFilter, ImageToImageFilter);

  /* Typedefs */
  /** \typedef typedef TInputImage InputImageType;
    Input image data type
  */
  typedef TInputImage                            InputImageType;
  /** \typedef typedef typename    InputImageType::Pointer    InputImagePointer;
    Input image data type pointer
  */
  typedef typename    InputImageType::Pointer    InputImagePointer;
  /** \typedef typedef typename    InputImageType::RegionType InputImageRegion;  
    Input image data type region
  */
  typedef typename    InputImageType::RegionType InputImageRegion;  
  /** \typedef typedef typename    InputImageType::PixelType  InputImagePixelType; 
    Input image data pixel type
  */
  typedef typename    InputImageType::PixelType  InputImagePixelType; 
  /** \typedef typedef typename     InputImageType::IndexType  InputImagePixelIndex;  
    Input image data pixel index
  */
  typedef typename    InputImageType::IndexType  InputImagePixelIndex;   
  /** \typedef typedef typename     TOutputImage   OutputImageType;
    Output image data type
  */
  typedef TOutputImage                            OutputImageType;
  /** \typedef typedef typename     OutputImageType::Pointer    OutputImagePointer;
    Output image data type pointer
  */
  typedef typename    OutputImageType::Pointer    OutputImagePointer;
  /** \typedef typedef typename   OutputImageType::RegionType OutputImageRegion;
    Output image data type region
  */
  typedef typename    OutputImageType::RegionType OutputImageRegion;
  /** \typedef typedef typename  OutputImageType::PixelType  OutputImagePixelType;
    Output image data pixel type
  */
  typedef typename    OutputImageType::PixelType  OutputImagePixelType;
  /** \typedef typedef typename  itk::ImageRegionIterator< InputImageType >  IteratorType;
    Iterator type for input image data
  */
  typedef typename itk::ImageRegionIterator< InputImageType >                               
                                                  IteratorType;
  /** \typedef typedef typename  itk::ImageRegionIterator< OutputImageType >  OutIteratorType;
    Iterator type for output image data
  */
  typedef typename itk::ImageRegionIterator< OutputImageType >     
                                                  OutIteratorType;
  /** \typedef typedef typename  std::vector< InputImagePointer >  ImageFilters;
    List of Image Filters (LBP masks)
  */
  typedef typename std::vector< InputImagePointer >                                         
                                                  ImageFilters;
  /** \typedef typedef typename   ImageFilters::iterator         ImageFiltersIterator;
    Image Filters iterator type
  */
  typedef typename ImageFilters::iterator         ImageFiltersIterator;
  /** \typedef typedef typename  ImageFilters                *ImageFiltersPointer;
    Image Filters iterator type pointer
  */
  typedef ImageFilters                            *ImageFiltersPointer;
  /** \typedef typedef typename   ImageFilters::size_type        ImageFiltersLength;
    Image filter size type
  */
  typedef typename ImageFilters::size_type        ImageFiltersLength;

/* ------------------------------------------------------------------------- */
  
/**
 * \fn void SetMaskProperties(unsigned int radius, unsigned int samples);
 *
 * \brief Mask properties are radius and samples. 
 *
 * Radius is distance between sample and center of mask. Samples is number of samples around center of mask. 
 * \param radius Radius of sample points around the center of mask.
 * \param samples Number of points around the center of mask.
 */
  void SetMaskProperties(unsigned int radius, unsigned int samples); 
 
/* ------------------------------------------------------------------------- */  
  
/**
 * \fn void SetAlgorithmType(unsigned int type);
 *
 * \brief Function parameter type is integer value of LBP algorithm type (basic, uniform, rotmin). 
 * 
 * \param type Type of LBP algorithm
 * \see LBP_BASIC
 * \see LBP_UNIFORM
 * \see LBP_ROT_MIN8
 * \see LBP_ROT_MIN16
 * \see LBP_ROT_MIN32
 */
  void SetAlgorithmType(unsigned int type);

/* ------------------------------------------------------------------------- */  

  /**
 * \fn   unsigned int GetAlgorithmType();
 *
 * \brief Function returns int value of LBP algoritgm type
 *
 * \return LBP algorithm type.
 * \see LBP_BASIC
 * \see LBP_UNIFORM
 * \see LBP_ROT_MIN8
 * \see LBP_ROT_MIN16
 * \see LBP_ROT_MIN32
 */
  unsigned int GetAlgorithmType();
  
/* ------------------------------------------------------------------------- */
  
  /**
 * \fn unsigned int GetSamples();
 *
 * \brief Function returns number of samples around the center of mask.
 *
 * \return Number of samples.
 */
  unsigned int GetSamples();
  
/* ------------------------------------------------------------------------- */
  
  /**
 * \fn unsigned int GetRadius();
 *
 * \brief Function returns radius around the center of mask.
 *
 * \return Radius of mask.
 */ 
  unsigned int GetRadius();

/* ------------------------------------------------------------------------- */

protected:

/* ------------------------------------------------------------------------- */

/**
 * \fn ImageToLbpFilter();
 *
 * \brief Constructor.
 */ 
  ImageToLbpFilter();
/**
 * \fn virtual ~ImageToLbpFilter() {};
 *
 * \brief Destructor.
 */ 
  virtual ~ImageToLbpFilter() {};

/* ------------------------------------------------------------------------- */

  /**
 * \fn void PrintSelf(std::ostream& os, Indent indent) const;
 *
 * \brief PrintSelf function of this class.
 * \param os Output stream (Console/File)
 * \param indent Indent
 */ 
  void PrintSelf(std::ostream& os, Indent indent) const;
/**
 * \fn GenerateData(void);
 *
 * \brief Internal ITK function for generating data when the pipeline update request is called.
 */ 
  void GenerateData(void);

/* ------------------------------------------------------------------------- */
  
  /* member variables*/
  /**
   \var m_filters 
   List of LBP masks (filters)
  */
  ImageFilters m_filters;
  /**
   \var m_mapping 
   Type of LBP mapping (algorithm)
  */
  unsigned int m_mapping;
  /**
   \var m_samples
   Number of samples around center of mask
  */
  unsigned int m_samples;
  /**
   \var m_radius
   Radius of mask
  */
  unsigned int m_radius;

/* ------------------------------------------------------------------------- */

private:

/* ------------------------------------------------------------------------- */

 /** \fn ImageToLbpFilter(const Self&);
  ITK - internal function
 */
  ImageToLbpFilter(const Self&); //purposely not implemented
 /** \fn void operator=(const Self&);
  ITK - internal function
 */
  void operator=(const Self&); //purposely not implemented
};


} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "imageToLbpFilter.txx"
#endif

/* ------------------------------------------------------------------------- */

#endif
