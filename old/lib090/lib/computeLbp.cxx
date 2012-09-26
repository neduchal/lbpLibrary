/* -------------------------------------------------------------------------

      Program:   LBP filter for C++
      Module:    $RCSfile: computeLbp.cxx $
      Language:  C++
      Date:      $Date: 2012-07-18 12:50:00 $
      Version:   $Revision: 0.9.0 $

   ------------------------------------------------------------------------- */

/* Pripojeni knihoven a hlavickovych souboru */
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

// Pouziti potrebnych jmennych prostoru
using namespace itk;
using namespace std;

// Vytvoreni typu pro prevedeni dat z 16 do 8 bit 
typedef itk::CastImageFilter< LBP16bit2D, LBP8bit2D > CastFilterType;


// Funkce vypisujici napovedu
void help() 
{
 cout << "Napoveda k programu computeLBP " << endl;
 cout << "-------------------------------------------------- " << endl;
 cout << "Parametry programu :" << endl;
 cout << "  Zdroj - obrazek jehoz texturu chceme vypocitat " << endl;
 cout << "  Cil   - soubor do ktereho chceme ulozit vysledek" << endl;
 cout << "  Metoda - Jedna z nasledujicich metod : " << endl ;
 cout << "                1 - basic   " << endl ;
 cout << "                2 - rotmin " << endl ;
 cout << "                3 - uniform " << endl ;
 cout << "  Samples - pocet bodu v okoli stredoveho bodu" << endl ;
 cout << "  Polomer - vzdalenost bodu od stredoveho bodu" << endl ;
}

// Hlavni funkce programu
int main(int argc , char* argv[])
{
  // Potrebne promenne
  int argNum = argc;
  int method;
  int samples;
  int radius;
  string source;
  string sink;
  
  // Zjisteni poctu parametru predanych do programu a reakce na ne
  if  (argNum < 2) {
    help();
    return -1;
  }
  if (argNum == 2)
  {
    source = argv[1];
    sink = "vystup.png";
    method = 1;
    samples = 8;
    radius = 1;
  }
  if (argNum == 3)
  {
    source = argv[1];
    sink = argv[2];
    method = 1;
    samples = 8;
    radius = 1;
  }
  if (argNum == 4)
  {
    source = argv[1];
    sink = argv[2];
    method = atoi(argv[3]);
    samples = 8;
    radius = 1;
  }
  if (argNum > 4) {
    try {
      int a = atoi(argv[4]);
      if (argNum > 5) {
        int b = atoi(argv[5]);
        b = b+b;
      }
      a = a+ a;
    }
    catch( itk::ExceptionObject & err )
    {
        std::cerr << "ExceptionObject caught !" << std::endl;
        std::cerr << err << std::endl;
        return EXIT_FAILURE;
    }
  }
  if (argNum == 5)
  {
    source = argv[1];
    sink = argv[2];
    method = atoi(argv[3]);
    samples = atoi(argv[4]);
    radius = 1;
  }
  if (argNum == 6)
  {
    source = argv[1];
    sink = argv[2];
    method = atoi(argv[3]);
    samples = atoi(argv[4]);
    radius = atoi(argv[5]);
  }

  // Nastaveni vypoctu LBP hodnoty 
  if(method == 1)
  {
    method = LBP_BASIC; // Klasicke LBP
  }
  else if((method == 2)&&(samples <= 8))
  {
    method = LBP_ROT_MIN8; // Minimum rotace 8 bit
  }
  else if((method == 2)&&(samples > 8))
  {
    method = LBP_ROT_MIN16; // Minimum rotace 16 bit
  }
  else 
  {
    method = LBP_UNIFORM; // Uniform patterns LBP
  }

  // Oznameni pro uzivatele
  cout << "Nacitam obrazek : " << source <<endl;
  // Vytvoreni filtru
  ImageToLbpFilter<Image2D, LBP16bit2D>::Pointer LbpFilter = ImageToLbpFilter<Image2D, LBP16bit2D>::New(); 
  // Nastaveni LBP filtru
  LbpFilter->SetMappingType(method);
  LbpFilter->SetMaskProperties(radius, samples);
  // Nacteni obrazku a nastaveni na vstup filtru
  Image2DPointer image = Image2D::New();
  loadImage< Image2D >(&image,source);
  LbpFilter->SetInput(image);
  // Prevod do LBP
  LbpFilter->Update();

  // Ulozeni 
  if (samples <= 8) {
    // Ulozeni do 8 bit verze
    CastFilterType::Pointer castFilter = CastFilterType::New();
    castFilter->SetInput( LbpFilter->GetOutput() );
    castFilter->Update();
    saveImage8bit<LBP8bit2D>(castFilter->GetOutput(),sink);
  }
  else {
    // Ulozeni do 16 bit verze
    saveImage16bit<LBP16bit2D >(LbpFilter->GetOutput(),sink);
  }	    
  // Vysledne oznameni a konec programu
  cout << "Vysledek ulozen do souboru : " << sink <<endl;  
  return 0; 
}
