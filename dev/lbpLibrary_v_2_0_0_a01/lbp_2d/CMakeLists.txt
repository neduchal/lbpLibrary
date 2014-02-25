## Queetech LbpLibrary 
## 
## Module : MAIN
## Author : Ing. Petr Neduchal

cmake_minimum_required(VERSION 2.8)

ADD_LIBRARY(LbpLibrary SHARED lbp.cxx lbp.hpp 
							 lbpCxx.cxx lbpCxx.hpp  	                     
							 lbp2x8Cxx.cxx lbp2x8Cxx.hpp
							 lbp3x10Cxx.cxx lbp3x10Cxx.hpp
							 lbp4x12Cxx.cxx lbp4x12Cxx.hpp
							 specialCxx.cxx specialCxx.hpp
              )
              
TARGET_LINK_LIBRARIES(LbpLibrary ${Libraries} )	

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(DYNLIB "libLbpLibrary.so")
		# Instalace sdilene knihovny
	  install(TARGETS LbpLibrary DESTINATION /lib)  

ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    SET(DYNLIB "LbpLibrary.dll")

ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

set_target_properties(LbpLibrary PROPERTIES
											LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/LbpLibrary/shared
                      LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/LbpLibrary/shared/debug
                      LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/LbpLibrary/shared/release
)  
 
# Konfigurace python wrapperu
CONFIGURE_FILE(python/lbpLibrary.py.temp  ${PROJECT_BINARY_DIR}/LbpLibrary/python/lbpLibrary.py ${DYNLIB})


				 
