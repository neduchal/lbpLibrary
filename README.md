LbpLibrary
==========

![logo projektu](http://neduchal.cz/images/lbp200_logo.png)


* VERSION 2.0.0 RC1 RELEASED. 
* BIG CHANGES IN THIS VERSION


Required Dependencies
---------------------
* C/C++ Compiler 

* Cmake

* Python ( NumPy, ctypes )

Installation Guide LINUX DIST. (TESTED : MINT 15)
-------------------------------

	git clone git@github.com:neduchal/lbpLibrary.git // For developers
	
	git clone https://github.com/neduchal/lbpLibrary.git
	
	or
	
	Download zip of this repository

Create build folder. For example 

	mkdir /home/user/projects/build/lbpLibrary
	
Create project and compile whole library :
	
	cd /home/user/projects/build/lbpLibrary
	
	cmake /home/user/projects/git/lbpLibrary
	
	sudo make install
	
	sudo python setup.py install
	
Now, the library is installed in system. You can try this code :

	python
	
	import lbpLibrary 
	
	lbpLibrary
	
You should get something like this :

	<module 'lbpLibrary' from '/usr/local/lib/python2.7/dist-packages/lbpLibrary.pyc'>

	
Folder LbpLibrary will be created in build folder. There are few tests and there will be some examples to.

Installation Guide Windows 7 (We are working on new version of this guide)
--------------------------------------------------------------------------
	Download ZIP of this repository
	
Create project by cmake gui and compile it in Visual Studio.

Folder LbpLibrary will be created in project folder. 

	LbpLibrary ---> python ---> python scripts
	            |
	            --> shared ---> debug ---> debug shared libraries (.dll) 
	            	        or  release ---> release shared libs.



