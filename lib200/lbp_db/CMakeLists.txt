## Queetech lbp library - CMAKE
## 
## Version 2.0.0
## Modul : Realtime LBP
## Author : Petr Neduchal

cmake_minimum_required(VERSION 2.8)

ADD_EXECUTABLE(test db_engine.hpp db_engine.cxx test.cxx 	                     
              )

#TARGET_LINK_LIBRARIES(RealtimeLbp ${Libraries} )	

#IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#    SET(DYNLIB libRealtimeLbp.so)
		# Instalace sdilene knihovny
#	  install(TARGETS RealtimeLbp DESTINATION /lib)
#ELSE()
#    SET(DYNLIB RealtimeLbp.dll)
		# Instalace sdilene knihovny
#	  install(TARGETS RealtimeLbp DESTINATION c:/windows/system32/)
#ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
 
# Konfigurace python wrapperu
#CONFIGURE_FILE(python/realtime_lbp.py.temp  python/realtime_lbp.py ${DYNLIB})

#CONFIGURE_FILE(matlab/loadLbpLibrary.m.temp  matlab/loadLbpLibrary.m ${DYNLIB})
#FILE(COPY lbp.h matlab/imageToLbp.m matlab/realTimeLbp.m matlab/unloadLbpLibrary.m DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/matlab/)
#FILE(COPY img/lena.bmp DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/img/)


				 
