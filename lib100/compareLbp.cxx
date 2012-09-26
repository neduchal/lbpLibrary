/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: compareLbp.cxx $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */
#include <iostream>
#include <stddef.h>
#include <time.h>
#include "const.h"
#include "mask.h"
#include "mapping.h"
#include "imageToLbpFilter.h"
#include "itkCastImageFilter.h"
#include "histogram.h"
#include "histogram.txx"
#include "distance.h"
#include "distance.txx"
#include "io.h"
#include "io.txx"

// Pouziti potrebnych jmennych prostoru
using namespace itk;
using namespace std;

// Vytvoreni typu pro prevedeni dat z 16 do 8 bit 
typedef itk::CastImageFilter< LBP16bit2D, LBP8bit2D > CastFilterType;

/* ------------------------------------------------------------------------- */ 

void help() 
{
 cout << "Napoveda k programu compareLBP " << endl;
 cout << "-------------------------------------------------- " << endl;
 cout << "Parametry programu :" << endl;
 cout << "  LBP data 1 - Prvni LBP reprezentace  " << endl;
 cout << "  LBP data 2 - Druha LBP reprezentace  " << endl;
}

/* ------------------------------------------------------------------------- */ 

int main(int argc , char* argv[])
{
  // Zjisteni, zda ma program k dispozici potrebne parametry
  if  (argc != 3) {
    help();
    return -1;
  }
  
  // Nastaveni parametru
  string source1 = argv[1];
  string source2 = argv[2];

  // Nacteni zdrojovych dat
  Image2DPointer image1 = Image2D::New();
  Image2DPointer image2 = Image2D::New();
  loadImage< Image2D >(&image1,source1);
  loadImage< Image2D >(&image2,source2);  
  
  // Vytvoreni typu pro histogram
 // HistogramPointer histogram1 = HistogramType::New();
   HistogramPointer histogram1;// = HistogramType::New();
  HistogramPointer histogram2; // = HistogramType::New();
  
  // Vytvoreni histogramu ze zdrojovych dat
  createSimpleHistogram< Image2D , HistogramType>(image1, &histogram1, 256);
  createSimpleHistogram< Image2D , HistogramType>(image2, &histogram2, 256);
  
  // Vypsani vysledku v podobe vzdalenosti a podobnosti
  cout << "Euklidovska vzdalenost : " 
       << (euclideanDistance<HistogramType>(histogram1, histogram2)) << endl;
  cout << "MinaMax podobnost : " 
       << (minMaxDistance<HistogramType>(histogram1, histogram2)) << endl;  

  return 0; 
}

/* ------------------------------------------------------------------------- */ 
