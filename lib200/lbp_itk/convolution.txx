#ifndef __convolution_txx
#define __convolution_txx

/* ------------------------------------------------------------------------- 
  
      Program:   LBP filter for C++
      Module:    $RCSfile: convolution.txx $
      Language:  C++
      Date:      $Date: 2012-07-02 19:03:00 $
      Version:   $Revision: 1.0.0 $ 

   ------------------------------------------------------------------------- */

/* Necessary headers */ 
#include "convolution.h"

/* ------------------------------------------------------------------------- */

template <class TInputImage, class  TFilterType >
  void convolutionFFT(const TInputImage *image, TFilterType *filters)
{
  // Vytvoreni ukazatele na fourieruv obraz zdrojovych dat 
  FftFilterPointer image_FFT =  FftFilterType::New();
  // Vypocet fourierova obrazu zdrojovych dat
  image_FFT->SetInput(image);
  image_FFT->Update();
  // Typ iteratoru dat - pro pristup k jednotlivym filtrum		
  typename TFilterType::iterator it;
  // Cyklus provadejici konvoluci s filtry
  for(it  = filters->begin(); it != filters->end(); it++) 
  {
    // Vytvoreni ukayatelu pro jednotive filtry
    IFftFilterPointer filter_final = IFftFilterType::New(); 
    FftFilterPointer filter_FFT =  FftFilterType::New(); 
    MultiplyFilterPointer multi = MultiplyFilterType::New(); 
    // Vytvoreni fourierova obrazu i-teho filtru
    filter_FFT->SetInput(*it);
    filter_FFT->Update();
    // Nastaveni obou vstupu MultiplyImageFilter filtru (viz ITK guide)
    multi->SetInput1(image_FFT->GetOutput());
    multi->SetInput2(filter_FFT->GetOutput());
    // Zpetna fourierova transformace po vynasobeni obrazu 
    filter_final->SetInput(multi->GetOutput());
    filter_final->Update();
    // Prirazeni vystupu zpet do pole filtru 
    (*it) = filter_final->GetOutput();
  } 
} 

/* ------------------------------------------------------------------------- */

#endif
