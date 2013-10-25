#ifndef __yaml_engine_h
#define __yaml_engine_h

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <list>
#include <vector>
using namespace std;

namespace queetech 
{

  namespace lbplib 
  {
    /* --------------------------------------------------------------------- */
    class InnerData
    {
    private:
      string m_property;
      string m_value;
    public:
      InnerData(string data_property, string data_value);
      ~InnerData();
      string getProperty();
      string getValue();
      void setProperty(string data_property);
      void setValue(string data_value);
    };

    /* --------------------------------------------------------------------- */
    class DataNode
    {
    private:
      string m_name;
      list<InnerData *> m_innerData;

    public:
      DataNode(string name);
      ~DataNode();
      string getValue(string data_property);
      void setValue(string data_property, string data_value);
      void addData(string data_property, string data_value);
      void toFile(fstream &f);
    };

    /* --------------------------------------------------------------------- */
    class DbEngine
    {
    private:
      fstream *m_file;  

      list<DataNode *> m_data;
      list<DataNode *>::iterator m_it;
  
    public: 
      DbEngine(string filename);
      ~DbEngine();
           
      void parse();
      string readLine();
      void writeData();
      void close();    

      bool addDataSingle(string file_name, string node_name, list<YamlInnerData *> node_data );
      bool removeDataByProperty(string node_property, string node_value);


      bool rewind();
      bool nextNode();
      bool previousNode();
      YamlDataNode * getFirst();
      YamlDataNode * getLast();
      YamlDataNode * getActual();
      
    };
  
  };
  
};

#endif
