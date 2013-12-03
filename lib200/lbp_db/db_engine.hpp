#ifndef __db_engine_hpp
#define __db_engine_hpp

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <list>
#include <vector>
using namespace std;

namespace queetech 
{

	/**
		@namespace database
			
		Namespace obsahující třídy pro správu jednoduché souborové databáze 
		založeného na základních vlastnostech standardu YAML

	*/
  namespace database 
  {

    /* --------------------------------------------------------------------- */

		/**
			@class InnerData
			
			Třída polozky databázového systému pro ukládání jednoduchých dat

		*/
    class InnerData 
    {
    private:
      string m_property; // Vlastnost polozky
      string m_value; // Hodnota polozky
    public:
      InnerData(string data_property, string data_value);
      ~InnerData();
      string getProperty();
      string getValue();
      void setProperty(string data_property);
      void setValue(string data_value);
    };

    /* --------------------------------------------------------------------- */

		/**
			@class DataNode
			
			Třída skupiny položek db systému pro ukládání jednoduchých dat

		*/
    class DataNode
    {
    private:
      string m_name; // Název skupiny
      list<InnerData *> m_innerData; // Položky skupiny

    public:
      DataNode(string name);
      ~DataNode();
      string getValue(string data_property);
      void setValue(string data_property, string data_value);
      void addData(string data_property, string data_value);
      void toFile(fstream &f);
    };

    /* --------------------------------------------------------------------- */

		/**
			@class DbEngine
			
			Třída databázového systému pro ukládání jednoduchých dat

		*/
    class Engine
    {
    private:
			string 	m_filename;
      fstream *m_file;  

      list<DataNode *> m_data;
      list<DataNode *>::iterator m_it;
  
    public: 
      Engine(string filename);
      ~Engine();
           
      void parse();
      string readLine();
      void writeData();
      void close();    
			void setFilename(string filename) { this->m_filename = filename;}

    	bool addNode(string property, string value);
    	bool addGroup(string groupName);
			bool addNodeToGroup(string property, string value, string groupName);
      bool removeDataByProperty(string node_property, string node_value);
			

      bool rewind();
      bool nextNode();
      bool previousNode();
      DataNode * getFirst();
      DataNode * getLast();
      DataNode * getActual();
      
    };
  
  };
  
};

#endif
