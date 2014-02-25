LbpLibrary
==========
* VERSION 2.0.0 ALPHA 01 RELEASED. 

Required Dependencies
---------------------
* C/C++ Compiler 

* Cmake

* Python ( NumPy )


Installation Guide LINUX DIST. (TESTED : MINT 15)
-------------------------------
	git clone git@github.com:neduchal/lbpLibrary.git
	
	or
	
	Download zip of this repository

Create project in cmake gui and run this command in project folder :
	
	sudo make install
	
Folder LbpLibrary will be created in project folder. 

	LbpLibrary ---> python ---> python scripts
	            |
	            --> shared ---> shared libraries (.so) 

Installation Guide Windows 7 
-------------------------------
	Download ZIP of this repository
	
Create project in cmake gui and compile it in Visual Studio.

Folder LbpLibrary will be created in project folder. 

	LbpLibrary ---> python ---> python scripts
	            |
	            --> shared ---> debug ---> debugshared libraries (.dll) 
	            						or  release ---> release shared libs.



