## Queetech LbpLibrary 
## 
## Module : EXTEND
## Author : Ing. Petr Neduchal

cmake_minimum_required(VERSION 2.8)

ADD_LIBRARY(LbpLibraryExtend SHARED lbpexntend.cxx lbpextend.hpp 						
							 extendCxx.cxx extendCxx.hpp
              )
              
TARGET_LINK_LIBRARIES(LbpLibraryExtend ${Libraries} )	

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(DYNLIB "libLbpLibraryExtend.so")
		# Instalace sdilene knihovny
	  install(TARGETS LbpLibrary DESTINATION /lib)  

ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    SET(DYNLIB "LbpLibraryExtend.dll")

ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

set_target_properties(LbpLibraryExtend PROPERTIES
											LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/LbpLibrary/shared
                      LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/LbpLibrary/shared/debug
                      LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/LbpLibrary/shared/release
)  
 
# Konfigurace python wrapperu
CONFIGURE_FILE(python/lbpLibraryExtend.py.temp  ${PROJECT_BINARY_DIR}/LbpLibrary/python/lbpLibraryExtend.py ${DYNLIB})


				 
