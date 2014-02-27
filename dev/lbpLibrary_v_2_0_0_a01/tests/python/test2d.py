#!/usr/bin/env python

import numpy as np
import unittest
import lbpLibrary


class TestLbp2d(unittest.TestCase):
	def setUp(self):
		self.img = np.zeros([9,9], dtype = np.int)
		pass

	def test_loadLibrary(self):
		libLbp = lbpLibrary.loadLbpLibrary()
		self.assert_(libLbp is not None)
		
	def test_lbp_1x8(self):
		libLbp = lbpLibrary.loadLbpLibrary()	
		im = self.img[0:3,0:3]
		im[1,1] = 1		
		print('\nTEST LBP 1x8\n')
		im[0,0] = 2		
		res = lbpLibrary.lbp1x8(libLbp, im);
		assert(np.argmax(res) == 1)
		im[0,1] = 2													
		pass

	def test_lbp_2x8(self):
		libLbp = lbpLibrary.loadLbpLibrary()	
		im = self.img[0:5,0:5]
		im[2,2] = 1		
		print('\nTEST LBP 2x8\n\n')
		im[0:2,0:2] = 2
		res = lbpLibrary.lbp2x8(libLbp, im);
		assert(np.argmax(res) == 1)												
		pass
			
	def test_lbp_3x10(self):
		libLbp = lbpLibrary.loadLbpLibrary()	
		im = self.img[0:7,0:7]
		im[3,3] = 1	
		print('\nTEST LBP 3x10\n')
		im[0:2,2:5] = 2
		print(im)
		res = lbpLibrary.lbp3x10(libLbp, im);
		print(res)
		#assert(np.argmax(res) == 1)												
		pass
			
	def test_lbp_4x12(self):			
		libLbp = lbpLibrary.loadLbpLibrary()	
		im = self.img[0:9,0:9]
		im[4,4] = 1		
		print('\nTEST LBP 4x12\n')
		im[0:2,0:2] = 2
		res = lbpLibrary.lbp3x10(libLbp, im);
		print(res)		
		pass
			
	def test_uniformLbp(self):
		pass
			
	def test_rotationMinLbp(self):
		pass
		


if __name__ == '__main__':
    unittest.main()
