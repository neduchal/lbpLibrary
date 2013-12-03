#include "db_engine.hpp"

using namespace std;

namespace queetech
{

  namespace database
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
      this->m_innerData.push_back(newData);    
		} 
    
    void DataNode::toFile(fstream &f)
    {
      f << this->m_name << "\n";
      list<InnerData *>::iterator it = this->m_innerData.begin();
      for(it; it != this->m_innerData.end(); it++)
      {
        f << "::" << (*it)->getProperty() << "::" << (*it)->getValue() << "\n";
      }   
    }

    /* 
    ===========================================================================
    */

    Engine::Engine(string filename)
    {
			this->m_filename = filename;
      this->m_file = new fstream(filename.c_str());  
			this->m_file->close();   
    }

    Engine::~Engine() {}
      
    void Engine::parse() 
		{
			string sep("::");
			string eof("...");
			cout << this->m_filename.c_str() << endl;
			this->m_file->open(this->m_filename.c_str(), ios_base::in);
   		string line = this->readLine();
			cout << line << endl;
			int ij = 0;
			while(line.compare(0,3,eof) != 0)
			{
				ij++;
				if(ij > 7) break;
				
				if(line.compare(0,2,sep) != 0)
				{
					DataNode *node = new DataNode(line);
					this->m_data.push_back(node);
					cout << line << endl;
				}
				else
				{
					string data = line.substr(2);
					int pos = data.find(sep);
					string property = data.substr(0,pos);
					string value = data.substr(pos+2);
					this->m_data.back()->addData(property, value);
					cout << "  "<< property << " = "<< value << endl;
				}
				line = this->readLine();
			}
			this->m_file->close();

		}


    string Engine::readLine()
    {
        char temp[256];
        this->m_file->getline(temp, 256);
				string temp2(temp);
        return temp2;
    }

    void Engine::writeData()
    {

			this->m_file->open(this->m_filename.c_str(), ios_base::out);
      list<DataNode *>::iterator it = this->m_data.begin();

      for (it; it != this->m_data.end(); it++)
      {
        (*it)->toFile(*this->m_file);
      }
			(*this->m_file) << "...";
			this->m_file->close();
    }

    bool Engine::addNode(string property, string value);
    bool Engine::addGroup(string groupName);
		bool Engine::addNodeToGroup(string property, string value, string groupName);


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
