## Queetech LbpLibrary 
## 
## Module : 3D
## Author : Ing. Petr Neduchal

cmake_minimum_required(VERSION 2.8)

ADD_LIBRARY(LbpLibrary3d SHARED lbp3d.cxx lbp3d.hpp 
							 lbp3dCxx.cxx lbp3dCxx.hpp  	                     
              )

TARGET_LINK_LIBRARIES(LbpLibrary3d ${Libraries} )	

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(DYNLIB libLbpLibrary3d.so)
		# Instalace sdilene knihovny
	  install(TARGETS  LbpLibrary3d DESTINATION /lib)
		#install(TARGETS LbpLibrary3d.so DESTINATION ${PROJECT_BINARY_DIR}/LbpLibrary/shared)
ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    SET(DYNLIB LbpLibrary3d.dll)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux") 

set_target_properties(LbpLibrary3d PROPERTIES
											LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/LbpLibrary/shared
                      LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/LbpLibrary/shared/debug
                      LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/LbpLibrary/shared/release
)
 
# Konfigurace python wrapperu
CONFIGURE_FILE(python/lbpLibrary3d.py.temp  ${PROJECT_BINARY_DIR}/LbpLibrary/python/lbp/lbp3d.py ${DYNLIB})


				 
