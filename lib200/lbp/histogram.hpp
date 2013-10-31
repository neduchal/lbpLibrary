#ifndef __histogram_hpp
#define __histogram_hpp

#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <vector>

/* ========================================================================= */

namespace queetech 
{

/* ========================================================================= */

  namespace lbplib 
  {
   
    class IHistogram 
    {  
    public:
      virtual int* getData() const = 0;
      virtual void setData() const = 0;
      virtual int sum() const = 0;
      virtual double compare() const = 0;
      virtual double create() const = 0;
      virtual double* norm() const = 0; 
      
    }
  
    /* =======================================================================*/
    class Histogram
    {
    private:
      int* m_data;
      int  m_length;
    
    public:
      Histogram();
      Histogram(int* data, int length);
      Histogram(list<int> data);
      Histogram(vector<int> data);           
      ~Histogram();
      
      int* getData();
      void setData(int* data);    
      double computeCriterion(Histogram h); 
      static int* Parse();
      void parse();               
    
    };
    
    /* =======================================================================*/
    class SparseData
    {
    public:
      int m_value;
      int m_count;
      
      SparseData(int value, int count)
      {
        this->m_value = value;
        this->m_count = count;
      }
      ~SparseData(){};
    }
    
    /* =======================================================================*/
    class SparseHistogram
    {
    
    
    
    };
  
  };
  
};
