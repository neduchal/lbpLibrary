## Queetech lbp library - CMAKE
## 
## Version 2.0.0
## Modul : Realtime LBP
## Author : Petr Neduchal

cmake_minimum_required(VERSION 2.8)

ADD_LIBRARY(Lbp3d SHARED lbp3d.cxx lbp3d.hpp 
							 lbp3dCxx.cxx lbp3dCxx.hpp  	                     
              )

TARGET_LINK_LIBRARIES(3dLbp ${Libraries} )	

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(DYNLIB lib3dLbp.so)
		# Instalace sdilene knihovny
	  install(TARGETS  Lbp3d DESTINATION /lib)
ELSE()
    SET(DYNLIB 3dLbp.dll)
		# Instalace sdilene knihovny
	  install(TARGETS Lbp3d DESTINATION c:/windows/system32/)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
 
# Konfigurace python wrapperu
#CONFIGURE_FILE(python/realtime_lbp.py.temp  python/realtime_lbp.py ${DYNLIB})

#CONFIGURE_FILE(matlab/loadLbpLibrary.m.temp  matlab/loadLbpLibrary.m ${DYNLIB})
#FILE(COPY lbp.h matlab/imageToLbp.m matlab/realTimeLbp.m matlab/unloadLbpLibrary.m DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/matlab/)
#FILE(COPY img/lena.bmp DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/img/)


				 
