#include "lbp_constants.h"
#include <iostream>

int main()
{
  std::cout << queetech::lbplib::PROJECT_NAME << " Version : "<<queetech::lbplib::Version::MAJOR << "." <<
          queetech::lbplib::Version::MINOR << "." <<
          queetech::lbplib::Version::PATCH << std::endl;
  std::cout << queetech::lbplib::Version::check(2,0,0,CHECK_VERSION_SIMPLE) << std::endl;
  std::cout << queetech::lbplib::Version::check(2,0,1,CHECK_VERSION_SIMPLE) << std::endl;
  std::cout << queetech::lbplib::Version::check(2,0,1,CHECK_VERSION_COMPLETE) << std::endl;
  std::cout << queetech::lbplib::Version::check(2,0,0,CHECK_VERSION_COMPLETE) << std::endl;
  std::cout << queetech::lbplib::Version::check(1,9,9,CHECK_VERSION_COMPLETE) << std::endl;                
          
  return 0;
}

