#! /usr/bin/python
# -*- coding: utf-8 -*-


import numpy as np
import unittest

import os
import sys

path_to_script = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(path_to_script, "../"))


from lbp import *


class TestLbpExtend(unittest.TestCase):
	def setUp(self):
		self.img = np.zeros([9,9], dtype = np.int)
		pass
    
	def test_01uniformLbp(self):
		print('\nTEST Uniform Lbp Algorithm\n')			
		libLbp = extend.load()
		hist = np.zeros([10,1], dtype = np.int32)
		hist[1] = 1 		
		hist[3] = 1 
		hist[5] = 1		
		res = extend.uniformLbp(libLbp, hist)
		assert(res[0] == 1)	
		assert(res[1] == 1)		
		assert(res[3] == 1)				
		pass
			
	def test_02rotationMinLbp(self):
		print('\nTEST Rotation Minimum Lbp Algorithm\n')			
		libLbp = extend.load()
		hist = np.zeros([10,1], dtype = np.int32)
		hist[1] = 1 		
		hist[4] = 1 
		hist[6] = 1		
		res = extend.rotationMinLbp(libLbp, hist)
		assert(res[1] == 2)		
		assert(res[3] == 1)				
		pass	
		pass    

if __name__ == '__main__':
    unittest.main()
