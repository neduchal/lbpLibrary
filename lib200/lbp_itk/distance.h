#ifndef __distance_h
#define __distance_h

/**
 \file distance.h
 \details File contains methods for computation the distance of two input histograms.
 \author Petr Neduchal
 \version 1.0.0
 \date 2012
 */

/* Necessary headers */ 
#include <math.h>

/* ------------------------------------------------------------------------- */

/**
 * \fn template <class THistogramType > double euclideanDistance(typename THistogramType::ConstPointer histogram1, typename THistogramType::ConstPointer histogram2);
 *
 * \brief Function computes Euclidean distance of two input histograms.
 *
 * It's necessary to determine correct template parameter. Function returns the distance in double variable. The distance grows with difference of input histograms.
 * \tparam THistogramType Type of input histogram data.
 * \param  histogram1 First histogram data.
 * \param  histogram2 Second histogram data.
 * \return Euclidean distance in double variable.
 */
template <class THistogramType >
double euclideanDistance(typename THistogramType::ConstPointer histogram1,
	typename THistogramType::ConstPointer histogram2);

/* ------------------------------------------------------------------------- */

/**
 * \fn template <class THistogramType > double minMaxDistance(typename THistogramType::ConstPointer histogram1, typename THistogramType::ConstPointer histogram2);
 *
 * \brief Function computes min max distance of two input histograms.
 *
 * It's necessary to determine correct template parameter. Function returns the distance in double variable. The distance falls with difference of input histograms. Rather we should call it       similarity than distance. If we multiply the result with 100 we get the result in percent form. 
 * \tparam THistogramType Type of input histogram data.
 * \param  histogram1 First histogram data.
 * \param  histogram2 Second histogram data.
 * \return Min max distance in double variable.
 */
template <class THistogramType >
double minMaxDistance(typename THistogramType::ConstPointer histogram1,
	typename THistogramType::ConstPointer histogram2);

/* ------------------------------------------------------------------------- */

#endif
