#ifndef __mapping_hpp
#define __mapping_hpp

/**
 \file mapping.h
 \details File contains methods with several LBP algorithms.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */


/* Necessary headers */  
#include <vector>
#include <iostream>
#include <cmath>
#include "itkImage.h"
#include "itkImageRegionIterator.h"
#include "const.hpp"

/* ------------------------------------------------------------------------- */
  
/**
 * \fn template <class TLbpImageType, class TFilterType > void basic(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);
 *
 * \brief Basic LBP algorithm.
 *
 * It's necessary to determine correct template parameters. Function returns the LBP image in LbpImage parameter.
 * \tparam  TLbpImageType Type of output Lbp image data.
 * \tparam  TFilterType Type of filters (LBP masks) data.
 * \param  *LbpImage  Pointer on output LBP data.
 * \param *filters Set of lbp masks with respons on convolution.
 * \return LBP image data.
 */
template <class TLbpImageType, class TFilterType >
void basic(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);

/* ------------------------------------------------------------------------- */
       
/**
 * \fn template <class TLbpImageType, class TFilterType > void rotmin(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);
 *
 * \brief Minimum of rotation (8-bit = max 8 samples in mask) LBP algorithm.
 *
 * It's necessary to determine correct template parameters. Function returns the LBP image in LbpImage parameter.
 * \tparam  TLbpImageType Type of output Lbp image data.
 * \tparam  TFilterType Type of filters (LBP masks) data.
 * \param  *LbpImage  Pointer on output LBP data.
 * \param *filters Set of lbp masks with respons on convolution.
 * \return LBP image data.
 */ 
template <class TLbpImageType, class TFilterType >
void rotmin(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);

/* ------------------------------------------------------------------------- */

/**
 * \fn template <class TLbpImageType, class TFilterType > void uniform(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);
 *
 * \brief Uniform patterns LBP algorithm.
 *
 * It's necessary to determine correct template parameters. Function returns the LBP image in LbpImage parameter.
 * \tparam  TLbpImageType Type of output Lbp image data.
 * \tparam  TFilterType Type of filters (LBP masks) data.
 * \param  *LbpImage  Pointer on output LBP data.
 * \param *filters Set of lbp masks with respons on convolution.
 * \return LBP image data.
 */ 
template <class TLbpImageType, class TFilterType >
void uniform(typename TLbpImageType::Pointer *LbpImage, TFilterType *filters);

/* ------------------------------------------------------------------------- */

#endif
