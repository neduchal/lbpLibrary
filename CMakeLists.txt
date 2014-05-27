## QUEETECH LBP LIBRARY - MAIN CMAKE FILE 
## 
## author : Ing. Petr Neduchal
## version : 2.0.0. BETA
## last update : 27.5.2014

cmake_minimum_required(VERSION 2.8)

# Project name
PROJECT(QUEETECH_LbpLibrary)

###############################################################################

# The version number.
set (QUEETECH_LbpLibrary_VERSION_MAJOR 2)
set (QUEETECH_LbpLibrary_VERSION_MINOR 0)
set (QUEETECH_LbpLibrary_VERSION_PATCH 0)
set (QUEETECH_LbpLibrary_VERSION_STRING ${QUEETECH_LbpLibrary_VERSION_MAJOR}.${QUEETECH_LbpLibrary_VERSION_MINOR}.${QUEETECH_LbpLibrary_VERSION_PATCH})


message("PROJECT QUEETECH LbpLibrary ${QUEETECH_LbpLibrary_VERSION_STRING}")

configure_file (
  "${PROJECT_SOURCE_DIR}/lbp_constants.h.in"
  "${PROJECT_BINARY_DIR}/lbp_constants.h"
  )

configure_file (
  "${PROJECT_SOURCE_DIR}/setup.py.in"
  "${PROJECT_BINARY_DIR}/setup.py"
  )

include_directories("${PROJECT_BINARY_DIR}")

###############################################################################

# Option Build LbpLibrary MAIN (2D) MODULE
option (BUILD_MAIN_MODULE
        "Build Main module of LbpLibrary" ON)

# Option Build LbpLibrary 3D MODULE
option (BUILD_3D_MODULE
        "Build 3D Module LbpLibrary" ON)        
        
# Option Build LbpLibrary 3D MODULE
option (BUILD_EXTEND_MODULE
        "Build Extend Module LbpLibrary" OFF)       
        
# Option Build LbpLibrary Tests
option (BUILD_TESTS
        "Build tests" ON)       

# Option Build LbpLibrary Python Utils
option (BUILD_PYTHON_UTILS
        "Build python utils" ON)  
        
# Option Build LbpLibrary Octave Utils
option (BUILD_OCTAVE_UTILS
        "Build octave utils" ON)            

# Option Build LbpLibrary MAsks
option (BUILD_MASKS
        "Build python utils" ON)   
        
###############################################################################

# Build Main Module
if(BUILD_MAIN_MODULE)  
	add_subdirectory(lbp_2d)
	message("Main module was successfully configured.")
ENDIF(BUILD_MAIN_MODULE)   

# Build 3D Module
if(BUILD_3D_MODULE)  
	add_subdirectory(lbp_3d)
	message("3D Module was successfully configured.")
ENDIF(BUILD_3D_MODULE)  

# Build EXTEND Module
if(BUILD_EXTEND_MODULE)  
	add_subdirectory(lbp_extend)
	message("Extend Module was successfully configured.")
ENDIF(BUILD_EXTEND_MODULE)  

# Build Tests
if(BUILD_TESTS)  
	add_subdirectory(tests)
	message("TESTS was successfully configured.")
ENDIF(BUILD_TESTS)   

# Build Python utils
if(BUILD_PYTHON_UTILS)  
	FILE(COPY python_utils/  DESTINATION ${PROJECT_BINARY_DIR}/LbpLibrary/python/utils/)
	message("Python utils was successfully configured.")
ENDIF(BUILD_PYTHON_UTILS)  

# Build Python utils
if(BUILD_OCTAVE_UTILS)  
	FILE(COPY octave_utils/  DESTINATION ${PROJECT_BINARY_DIR}/LbpLibrary/octave/utils/)
	message("Octave utils was successfully configured.")
ENDIF(BUILD_OCTAVE_UTILS) 

# Build Tests
if(BUILD_MASKS)  
	FILE(COPY masks/  DESTINATION ${PROJECT_BINARY_DIR}/LbpLibrary/masks/)
	message("Masks was successfully configured.")
ENDIF(BUILD_MASKS)                            
                         

				 
