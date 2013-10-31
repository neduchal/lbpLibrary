#ifndef __criterion_hpp
#define __criterion_hpp

#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <vector>
#include "histogram.hpp"

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
