
#ifndef __filter_hpp
#define __filter_hpp

#include <iostream>
#include <cmath>
#include <string>

// Helping macro for real-time algorithm
#define compab_mask_inc(ptr,shift) \
{ value |= ((unsigned int)(cntr - *ptr) & 0x80000000) \
>> (31-shift); ptr++; }

/* ========================================================================= */

namespace queetech 
{

/* ========================================================================= */

  namespace lbplib 
  {

    class Filter
    {

    private :
      char m_type; // LBP Algorithm Type
      char m_nb_size; // Neighbourhood size                         
      char m_nb_type; // Neighbourhood type         
    
    public :
    
      const char LBP_TYPE_BASIC   =                     0;
      const char LBP_TYPE_ROTMIN  =                     1;
      const char LBP_TYPE_UNIFORM =                     2; 
    
      const char LBP_MAX_RADIUS   =                    16;
      const char LBP_MAX_SAMPLES  =                    32;
    
      const char LBP_NEIGHBOURHOOD_TYPE_SQUARE =        0;
      const char LBP_NEIGHBOURHOOD_TYPE_CIRCLE =        1;  
      
      Filter();
      Filter(char type, char nb_size, char nb_type);      
      ~Filter();
      
      void toLbp8x(int rows, int columns, const int* data, int* result)
      
      void setType(char type);
      void setNeighbourhoodSize(char nb_size);
      void setNeughbourhoodType(char nb_type);
      char getType();
      char getNeighbourhoodSize();
      char getNeighbourhoodType();      
  
    };


  };

/* ========================================================================= */

};

/* ========================================================================= */

#endif

/* ========================================================================= */
