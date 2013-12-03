## QUEETECH LBP LIBRARY - CMAKE
## 
## author : Petr Neduchal

cmake_minimum_required(VERSION 2.8)

# Project name
PROJECT(QUEETECH_LbpLibrary)

# The version number.
set (QUEETECH_LbpLibrary_VERSION_MAJOR 2)
set (QUEETECH_LbpLibrary_VERSION_MINOR 0)
set (QUEETECH_LbpLibrary_VERSION_PATCH 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/lbp_constants.h.in"
  "${PROJECT_BINARY_DIR}/lbp_constants.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

# Option Build LbpLibrary ITK Realtime
option (LBPLIB_BUILD_REALTIME
        "Build Realtime LbpLibrary" ON) 

# Option Build LbpLibrary ITK Support
option (LBPLIB_BUILD_ITK 
        "Build LbpLibrary version for ITK" OFF) 
        
# Option Build  LbpLibrary OPENCV Support
option (LBPLIB_BUILD_OPENCV 
        "Build  LbpLibrary version for OPENCV" OFF) 

# Option Build LbpLibrary Eigen Support
option (LBPLIB_BUILD_EIGEN
        "Add Eigen version of some functions" OFF)
        
# Option Build Queetech database engine
option (LBPLIB_BUILD_DB 
        "Build LbpLibrary Texture database engine" ON) 
        
# Option Add Boost support 
option (LBPLIB_ADD_BOOST
        "Add Boost support " OFF)     

# Build Realtime LbpLibrary
if(LBPLIB_BUILD_REALTIME)  
	add_subdirectory(lbp_realtime)
	message("Realtime modul byl bez problemu nakonfigurovan.")
ENDIF(LBPLIB_BUILD_REALTIME)   

# Build LbpLibrary Texture database engine
if(LBPLIB_BUILD_DB)  
	add_subdirectory(lbp_db)
ENDIF(LBPLIB_BUILD_DB )                            
        
if (LBPLIB_ITK)
  FIND_PACKAGE(ITK)
  IF(ITK_FOUND)
    INCLUDE(${ITK_USE_FILE})
  ELSE(ITK_FOUND)
    MESSAGE(FATAL_ERROR "ITK not found. Please set ITK_DIR.")
  ENDIF(ITK_FOUND)

  SET(Libraries ${ITK_LIBRARIES})

  file(GLOB ItkFiles ${PROJECT_SOURCE_DIR}/lbpItk/*.*)
  ADD_library(lbpItk SHARED ${ItkFiles} )
              			  
  #TARGET_LINK_LIBRARIES(computeLbp ${Libraries} )
	#TARGET_LINK_LIBRARIES(compareLbp ${Libraries} )		
  TARGET_LINK_LIBRARIES(lbpItk ${Libraries} )	
  IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(DYNLIB libLbpItk.so)
  ELSE()
    SET(DYNLIB lbpItk.dll)
  ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
ENDIF(LBPLIB_ITK)     

#ADD_EXECUTABLE(test test.cxx)

#CONFIGURE_FILE(python/lbpLibrary.py.temp  python/lbpLibrary.py ${DYNLIB})
#CONFIGURE_FILE(matlab/loadLbpLibrary.m.temp  matlab/loadLbpLibrary.m ${DYNLIB})
#FILE(COPY lbp.h matlab/imageToLbp.m matlab/realTimeLbp.m matlab/unloadLbpLibrary.m DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/matlab/)
#FILE(COPY img/lena.bmp DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/img/)


				 
