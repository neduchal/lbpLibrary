#! /usr/bin/python
# -*- coding: utf-8 -*-


import numpy as np
import unittest

import os
import sys

path_to_script = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(path_to_script, "../"))


from lbp import *


class TestLbp2d(unittest.TestCase):
	def setUp(self):
		self.img = np.zeros([9,9], dtype = np.int)
		pass

	def test_01loadLibrary(self):
		print('\nTEST Load LbpLibrary \n')	
		libLbp = lbp2d.load()
		self.assert_(libLbp is not None)
		
	def test_02lbp_1x8(self):
		libLbp = lbp2d.load()
		im = self.img[0:3,0:3]
		im[1,1] = 1		
		print('\nTEST LBP 1x8\n')
		im[0,0] = 2		
		res = lbp2d.lbp1x8(libLbp, im);
		assert(np.argmax(res) == 1)
		im[0,1] = 2													
		pass

	def test_03lbp_2x8(self):
		libLbp = lbp2d.load()
		im = self.img[0:5,0:5]
		im[2,2] = 1		
		print('\nTEST LBP 2x8\n')
		im[0:2,0:2] = 2
		res = lbp2d.lbp2x8(libLbp, im);
		assert(np.argmax(res) == 1)												
		pass
			
	def test_04lbp_3x10(self):
		libLbp = lbp2d.load()
		im = self.img[0:7,0:7]
		im[3,3] = 1	
		print('\nTEST LBP 3x10\n')
		im[0:2,2:4] = 2
		res = lbp2d.lbp3x10(libLbp, im);
		assert(np.argmax(res) == 3)												
		pass
			
	def test_05lbp_4x12(self):			
		libLbp = lbp2d.load()
		im = self.img[0:9,0:9]
		im[4,4] = 1		
		print('\nTEST LBP 4x12\n')		
		im[0:2,2:3] = 2
		res = lbp2d.lbp4x12(libLbp, im);
		assert(np.argmax(res) == 1)	
		pass    
		
if __name__ == '__main__':
    unittest.main()
