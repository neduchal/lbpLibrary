#include "_engine.h"

using namespace std;

namespace queetech
{

  namespace lbplib
  {

    /* 
    ===========================================================================
    */
    InnerData::InnerData(string data_property, string data_value)
    {
      this->m_property = data_property;
      this->m_value    = data_value;
    }

    InnerData::~InnerData()
    {}

    string InnerData::getProperty()
    {
      return this->m_property;
    }

    string InnerData::getValue()
    {
      return this->m_value;
    }

    void InnerData::setProperty(string data_property)
    {
      this->m_property = data_property;
    }

    void InnerData::setValue(string data_value)
    {
      this->m_value = data_value;
    }

    /* 
    ===========================================================================
    */

    DataNode::DataNode(string name)
    {
      this->m_name = name;
    }
    
    DataNode::~DataNode()
    {}

    /* */
    string DataNode::getValue(string data_property)
    {
      list<InnerData *>::iterator it = this->m_innerData.begin();
      for(it; it != this->m_innerData.end(); it++)
      {
        if((*it)->getProperty().compare(data_property))
        {
          return (*it)->getValue();
        }
      }  
      return "";
    }
    
    /* */
    void DataNode::setValue(string data_property, string data_value)
    {
      list<InnerData *>::iterator it = this->m_innerData.begin();
      for(it; it != this->m_innerData.end(); it++)
      {
        if((*it)->getProperty().compare(data_property))
        {
          (*it)->setValue(data_value);
          break;
        }
      }   
    }    
     
    /* */  
    void DataNode::addData(string data_property, string data_value)
    {
      InnerData *newData = new InnerData(data_property, data_value);
      this->m_innerData.push_back(newData);    } 
    
    void DataNode::toFile(fstream &f)
    {
      f << this->m_name << " : {\n";
      list<InnerData *>::iterator it = this->m_innerData.begin();
      for(it; it != this->m_innerData.end(); it++)
      {
        f << "    " << (*it)->getProperty() << " : " << (*it)->getValue() << "\n";
      }   
      f << "}\n";
    }

    /* 
    ===========================================================================
    */

    Engine::Engine(string filename)
    {
      this->m_file = new fstream(filename.c_str());      
      this->parse();
    }

    Engine::~Engine() {}
      
    void Engine::parse() {};


    string Engine::readLine()
    {
      if (!this->m_file->eof())
      {
        string temp;
        getline(*this->m_file,temp);
        if(temp.compare("")) 
          temp = this->readLine();
        return temp;
      }
      return "...";
    }

    void Engine::writeData()
    {
      list<DataNode *>::iterator it = this->m_data.begin();

      for (it; it != this->m_data.end(); it++)
      {
        (*it)->toFile(*this->m_file);
      }
    }

    void Engine::close()
    {
      this->m_file->close();
    }

    bool addDataSingle(string file_name, string node_name, string );
    bool addDataSingle();
    bool addDataGroup();
    bool removeDataSingle(int node_id);
    bool removeDataSingle(string node_name);
    bool removeDataGroup(vector<int> node_ids);
    bool removeDataByProperty(string node_property, string node_value);

    bool rewind();
    bool nextNode();
    bool previousNode();
    DataNode * getFirst();
    DataNode * getLast();
    DataNode * getActual();

  };

};
