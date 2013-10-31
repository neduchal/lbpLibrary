#include "criterion.hpp"

/* ========================================================================= */

namespace queetech 
{

/* ========================================================================= */

  namespace lbplib 
  {
  
    static double Criterion::euclidean(int* h1, int* h2, int length)
    {
      int* p1 = h1;
      int* p2 = h2;
      
      double sum = 0;
      for(int i = 0; i < length; i++)
      {
        sum += ((*p1)-(*p2))*((*p1)-(*p2));        
        p1++;
        p2++;       
      }   
      sum = sqrt(sum);
      return sum;
    }
    
    static double Criterion::city(int* h1, int* h2)
    {
    
    }
    
    static double Criterion::minmax(int* h1, int* h2, int length)
    {
      int* p1 = h1;
      int* p2 = h2;
      
      double sum = 0;
      double sum1 = 0;
      double sum2 = 0; 
      for(int i = 0; i < length; i++)
      {   
        sum1 += min((*p1),(*p2));
        sum1 += max((*p1),(*p2));   
        p1++;
        p2++;         
      }
      sum = sum1/sum2;
      return sum;      
    }    
  
  
  };
  
};
