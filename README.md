lbpLibrary
==========

Required Dependencies
---------------------

* ITK version 3.x.x - recommended instalation example
Download :  http://www.itk.org/ITK/resources/software.html
Unzip : C:/projects/itk
Cmake : C:/projects/itk/bin cmake or cmake-gui (win/lin)  (option : Build shared libraries) 
Make : C:/projects/itk/bin/ sudo make install (lin)  or build in MSVC (win)

* Python

* Matlab (This version does not support Octave)

Installation Guide Ubuntu 12.04 
-------------------------------

ITK

sudo apt-get install cmake insighttoolkit3-examples libinsighttoolkit3-dev libgdcm2-dev

Installation Guide Windows 7 
-------------------------------
Download last version of lbpLibrary
Unzip libxxx (for example lib100 ) foledr to C:/projects/lbp
Cmake : C:/projects/lbp/bin
MSVC : Build library

Using library
-------------

* Matlab
Use files in Matlab folder in your build and lbp.dll dynamic library.

* Python
Use files in Python folder in your build and lbp.dll dynamic library.

* C++
Use only headers and cxx files in source of lbpLibrary. In zip-file there are two sample applications computeLBP and compare.Lbp



