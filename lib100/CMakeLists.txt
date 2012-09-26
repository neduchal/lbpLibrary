## Queetech lbp library - CMAKE
## 
## version 1.0.0
## author : Petr Neduchal

cmake_minimum_required(VERSION 2.8)


PROJECT(queetech_lbp_library)

FIND_PACKAGE(ITK)

IF(ITK_FOUND)
	INCLUDE(${ITK_USE_FILE})
ELSE(ITK_FOUND)
	MESSAGE(FATAL_ERROR
	"ITK not found. Please set ITK_DIR.")
ENDIF(ITK_FOUND)

SET(Libraries ${ITK_LIBRARIES})

file(GLOB headers *.h)
file(GLOB templates *.txx)

ADD_library(lbp SHARED lbp.c lbp.h lbpCxx.cxx lbpCxx.h  	          
  	                 ${headers}
	                 ${templates}               
              )

ADD_EXECUTABLE(computeLbp computeLbp.cxx 
  	                 ${headers}
	                 ${templates} 
              )
                
ADD_EXECUTABLE(compareLbp compareLbp.cxx 
  	                 ${headers}
	                 ${templates} 
              ) 
               			   

TARGET_LINK_LIBRARIES(computeLbp ${Libraries} )
					 
TARGET_LINK_LIBRARIES(compareLbp ${Libraries} )		

TARGET_LINK_LIBRARIES(lbp ${Libraries} )	



IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(DYNLIB libLbp.so)
ELSE()
    SET(DYNLIB lbp.dll)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

CONFIGURE_FILE(python/lbpLibrary.py.temp  python/lbpLibrary.py ${DYNLIB})
CONFIGURE_FILE(matlab/loadLbpLibrary.m.temp  matlab/loadLbpLibrary.m ${DYNLIB})
FILE(COPY lbp.h matlab/imageToLbp.m matlab/realTimeLbp.m matlab/unloadLbpLibrary.m DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/matlab/)
FILE(COPY img/lena.bmp DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/img/)


				 
