## QUEETECH LBP LIBRARY - MAIN CMAKE FILE 
## 
## author : Ing. Petr Neduchal
## version : 2.0.0. ALPHA 01 
## last update : 24.2.2014

cmake_minimum_required(VERSION 2.8)

# Project name
PROJECT(QUEETECH_LbpLibrary)

###############################################################################

# The version number.
set (QUEETECH_LbpLibrary_VERSION_MAJOR 2)
set (QUEETECH_LbpLibrary_VERSION_MINOR 0)
set (QUEETECH_LbpLibrary_VERSION_PATCH 0)
set (QUEETECH_LbpLibrary_VERSION_STRING ${QUEETECH_LbpLibrary_VERSION_MAJOR}.${QUEETECH_LbpLibrary_VERSION_MINOR}.${QUEETECH_LbpLibrary_VERSION_PATCH})

configure_file (
  "${PROJECT_SOURCE_DIR}/lbp_constants.h.in"
  "${PROJECT_BINARY_DIR}/lbp_constants.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

###############################################################################

# Option Build LbpLibrary MAIN (2D) MODULE
option (BUILD_MAIN_MODULE
        "Build Main module of LbpLibrary" ON)

# Option Build LbpLibrary 3D MODULE
option (BUILD_3D_MODULE
        "Build Realtime LbpLibrary" ON)          
        
###############################################################################

# Build Realtime LbpLibrary
if(BUILD_MAIN_MODULE)  
	add_subdirectory(lbp_2d)
	message("Main module was successfully configured.")
ENDIF(BUILD_MAIN_MODULE)   

# Build Realtime LbpLibrary
if(BUILD_3D_MODULE)  
	add_subdirectory(lbp_3d)
	message("3D Module was successfully configured.")
ENDIF(BUILD_3D_MODULE)                           

				 
