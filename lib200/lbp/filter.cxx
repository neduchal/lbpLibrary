#include "filter.hpp"

/* ========================================================================= */

namespace queetech 
{

/* ========================================================================= */

  namespace lbplib 
  {
  
      Filter::Filter()
      {
          this->m_type = 0;
          this->m_nb_size = 1;
          this->m_nb_type = 0;       
      }
       
      Filter::Filter(char type, char nb_size, char nb_type)
      {
          this->m_type = type;
          this->m_nb_size = nb_size;
          this->m_nb_type = nb_type;      
      }
            
      Filter::~Filter()
      {}
      
      /* 
        LBP 8, x   where x is nb_size
      */
      int* Filter::toLbp8_X_Square(int rows, int columns, const int* data)
      {
        const int *p0 = data,
           *p1 = p0 + this->m_nb_size,
           *p2 = p1 + this->m_nb_size,
           *p3 = p2 + columns*this->m_nb_size,
           *p4 = p3 + columns*this->m_nb_size,
           *p5 = p4 - this->m_nb_size,
           *p6 = p5 - this->m_nb_size,
           *p7 = p6 - columns*this->m_nb_size,
		      *center = p7 + this->m_nb_size;

	      int r,c,cntr;
        int* result;
	      unsigned int value;

        memset(result, 0, rows*columns*sizeof(int));
        int *center_res = result;
        center_res = center_res + columns*this->m_nb_size +  this->m_nb_size;

        for (r=0;r<rows-2*this->m_nb_size;r++)
        {
          for (c=0;c<columns-2*this->m_nb_size;c++)
          {
            value = 0;
            cntr = *center - 1;
            
            compab_mask_inc(p0,0);
            compab_mask_inc(p1,1);
            compab_mask_inc(p2,2);
            compab_mask_inc(p3,3);
            compab_mask_inc(p4,4);
            compab_mask_inc(p5,5);
            compab_mask_inc(p6,6);
            compab_mask_inc(p7,7);
            *center_res = value;
            center++;
          }
          p0 += 2*this->m_nb_size;
          p1 += 2*this->m_nb_size;
          p2 += 2*this->m_nb_size;
          p3 += 2*this->m_nb_size;
          p4 += 2*this->m_nb_size;
          p5 += 2*this->m_nb_size;
          p6 += 2*this->m_nb_size;
          p7 += 2*this->m_nb_size;
          center += 2*this->m_nb_size;
        }
        
        return result;     
      
      
      }
      
      void Filter::setType(char type)
      {
        this->m_type = type;
      }
      
      void Filter::setNeighbourhoodSize(char nb_size)
      {
        this->m_nb_size = nb_size;
      }
      
      void Filter::setNeighbourhoodType(char nb_type)
      {
        this->m_nb_type = nb_type;
      }      
      
      char Filter::getType()
      {
        return this->m_type; 
      }
      
      char Filter::getNeighbourhoodSize()
      {
        return this->m_nb_size; 
      }
            
      char Filter::getNeughbourhoodType()
      {
        return this->m_nb_type; 
      }              
      


  };

/* ========================================================================= */

};

/* ========================================================================= */      
