## CMake soubor projektu Queetech lbp library
##
## K přeložení je potřeba program CMAKE v požadované verzi (viz níže).
## Přeložení programem CMAKE vytvoří potřebný make soubor, případně projektový
## soubor některého IDE programu pro tvorbu v C++. 
## Poté se zavolá příkaz make, respektive vytvoří build v IDE.

# Minimální verze programu CMAKE 
cmake_minimum_required(VERSION 2.8)

# Název projektu
PROJECT(queetech_lbp_library)
# Nalezení ITK v počítači
FIND_PACKAGE(ITK)
# Co dělat, když CMake (ne)najde ITK
IF(ITK_FOUND)
	INCLUDE(${ITK_USE_FILE})
ELSE(ITK_FOUND)
	MESSAGE(FATAL_ERROR
	"ITK not found. Please set ITK_DIR.")
ENDIF(ITK_FOUND)

SET(Libraries ${ITK_LIBRARIES})

file(GLOB headers *.h)
file(GLOB templates *.txx)

# Doplnit programy TEST , MAKELBP , COMPARE 
# TEST - vyzkouší vsechny vlastnosti knihovny s podrobnym vypisem
# MAKELBP - vytvori LBP reprezentaci zdrojoveho obrazu a ulozi ji 
#           pod zadanym nazvem. (moznost vybrat vlastnosti a typ LBP)
# COMPARE - porovna 2 LBP reprezentace a spocte jejich podobnost (vzdalenost)

# Vytvoření spustitelného souboru test
IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
ADD_library(lbp SHARED lbp.c lbp.h lbpCxx.cxx lbpCxx.h  	          
  	                 ${headers}
	                 ${templates}               
              )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
ADD_library(lbp SHARED lbpLinux.c lbpLinux.h lbpCxx.cxx lbpCxx.h  	          
  	                 ${headers}
	                 ${templates}               
              )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

ADD_EXECUTABLE(computeLbp computeLbp.cxx 
  	                 ${headers}
	                 ${templates} 
              )
                
ADD_EXECUTABLE(compareLbp compareLbp.cxx 
  	                 ${headers}
	                 ${templates} 
              ) 
               			   
# Připojení potřebných knihoven k jednotlivým programům
TARGET_LINK_LIBRARIES(computeLbp ${Libraries} )
					 
TARGET_LINK_LIBRARIES(compareLbp ${Libraries} )		

TARGET_LINK_LIBRARIES(lbp ${Libraries} )					 
