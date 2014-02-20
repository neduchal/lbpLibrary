## Queetech lbp library - CMAKE
## 
## Version 2.0.0 beta
## Modul : LBP 3D
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
ELSE()
    SET(DYNLIB LbpLibrary3d.dll)
		# Instalace sdilene knihovny
	  install(TARGETS LbpLibrary3d DESTINATION c:/windows/system32/)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
 
# Konfigurace python wrapperu
CONFIGURE_FILE(python/lbpLibrary3d.py.temp  python/lbpLibrary3d.py ${DYNLIB})

#CONFIGURE_FILE(matlab/loadLbpLibrary.m.temp  matlab/loadLbpLibrary.m ${DYNLIB})
#FILE(COPY lbp.h matlab/imageToLbp.m matlab/realTimeLbp.m matlab/unloadLbpLibrary.m DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/matlab/)
#FILE(COPY img/lena.bmp DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/img/)


				 
