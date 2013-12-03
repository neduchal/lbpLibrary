#include "db_engine.hpp"
#include <iostream>

using namespace queetech;
int main()
{             
	std::cout << "OK 1" << std::endl;
	database::Engine en = database::Engine("./test.txt");
	std::cout << "OK 2" << std::endl;
	en.parse();
	std::cout << "OK 3" << std::endl;
	en.setFilename("test2.txt");
	en.writeData();

          
  return 0;
}

