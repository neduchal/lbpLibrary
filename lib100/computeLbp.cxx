/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: computeLbp.cxx $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 1.0.0 $

   ------------------------------------------------------------------------- */

/* Necessary headers */  
#include <iostream>
#include <stddef.h>
#include <time.h>
#include "mask.h"
#include "mapping.h"
#include "imageToLbpFilter.h"
#include "itkCastImageFilter.h"
#include "histogram.h"
#include "histogram.txx"
#include "io.h"
#include "io.txx"

using namespace itk;
using namespace std;

// Type for conversion between 16-bit and 8-bit version of LBP image .
typedef itk::CastImageFilter< LBP16bit2D, LBP8bit2D > CastFilterType;


// Help Function
void help() 
{
 cout << "HELP :  computeLbp " << endl;
 cout << "-------------------------------------------------- " << endl;
 cout << "Parameters :" << endl;
 cout << "  Source - File with input image data. " << endl;
 cout << "  Dest   - File for output image data" << endl;
 cout << "Optional parameters :" << endl;
 cout << "  Algorithm - Number of one option below : " << endl ;
 cout << "                1 - Basic   " << endl ;
 cout << "                2 - Minimum of rotation " << endl ;
 cout << "                3 - Uniform Patterns " << endl ;
 cout << "  Samples - Number of samples around center of mask" << endl ;
 cout << "  Radius - Radius of mask" << endl << endl ;
 cout << "Examples : "<< endl  ;
 cout << "  computeLbp src.jpg dst.jpg 1 8 1" << endl ;
 cout << "  computeLbp src.jpg dst.jpg" << endl ;

}

// Main function
int main(int argc , char* argv[])
{
  // Variables
  int argNum = argc;
  int algorithm;
  int samples;
  int radius;
  string source;
  string sink;
 
  if  (argNum < 2) {
    help();
    return -1;
  }
  if (argNum == 2)
  {
    source = argv[1];
    sink = "dst.png";
    algorithm = 1;
    samples = 8;
    radius = 1;
  }
  if (argNum == 3)
  {
    source = argv[1];
    sink = argv[2];
    algorithm = 1;
    samples = 8;
    radius = 1;
  }
  if (argNum == 4)
  {
    source = argv[1];
    sink = argv[2];
    algorithm = atoi(argv[3]);
    samples = 8;
    radius = 1;
  }
  if (argNum == 5)
  {
    source = argv[1];
    sink = argv[2];
    algorithm = atoi(argv[3]);
    samples = atoi(argv[4]);
    radius = 1;
  }
  if (argNum == 6)
  {
    source = argv[1];
    sink = argv[2];
    algorithm = atoi(argv[3]);
    samples = atoi(argv[4]);
    radius = atoi(argv[5]);
  }

  cout << "IMAGE : " << source <<endl;
  // LBP Filter
  ImageToLbpFilter<Image2D, LBP16bit2D>::Pointer LbpFilter = ImageToLbpFilter<Image2D, LBP16bit2D>::New(); 
  // Set preferences of filter
  LbpFilter->SetAlgorithmType(algorithm);
  LbpFilter->SetMaskProperties(radius, samples);
  cout << "DONE : CREATING FILTER. " << endl;
  // Image Loading
  Image2DPointer image = Image2D::New();
  loadImage< Image2D >(&image,source);
  cout << "DONE : IMAGE LOADING. " << endl;
  LbpFilter->SetInput(image);
  LbpFilter->Update();
  cout << "DONE : CREATING RESULT. " << endl;
  if (samples <= 8) {
    CastFilterType::Pointer castFilter = CastFilterType::New();
    castFilter->SetInput( LbpFilter->GetOutput() );
    castFilter->Update();
    saveImage<LBP8bit2D>(castFilter->GetOutput(),sink);
  }
  else {
    saveImage<LBP16bit2D >(LbpFilter->GetOutput(),sink);
  }	    
  cout << "DONE : IMAGE SAVING . " << endl;

  cout << "RESULT IS IN FILE : " << sink <<endl;  
  return 0; 
}
