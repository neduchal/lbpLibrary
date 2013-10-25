#ifndef __criterion_h
#define __criterion_h

#include <iostream>
#include <math.h>
#include <string>
#include <list>
#include <vector>
#include "histogram.h"

/* ========================================================================= */

namespace queetech 
{

/* ========================================================================= */

  namespace lbplib 
  {
  
    class Criterion
    {
    public:
      const char EUCLIDEAN   =                     0;
      const char CITY        =                     1;
      const char MINMAX      =                     2;
      
      Criterion(){};
      ~Criterion(){};
      static double euclidean(Histogram *h1, Histogram *h2);
      static double city(Histogram *h1, Histogram *h2);
      static double minmax(Histogram *h1, Histogram *h2);      
       
    }
  
  
  };
  
};