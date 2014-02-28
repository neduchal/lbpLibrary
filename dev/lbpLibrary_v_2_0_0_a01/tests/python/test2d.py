#!/usr/bin/env python

import numpy as np
import unittest
import lbpLibrary


class TestLbp2d(unittest.TestCase):
	def setUp(self):
		self.img = np.zeros([9,9], dtype = np.int)
		pass

	def test_01loadLibrary(self):
		print('\nTEST Load LbpLibrary \n')	
		libLbp = lbpLibrary.loadLbpLibrary()
		self.assert_(libLbp is not None)
		
	def test_02lbp_1x8(self):
		libLbp = lbpLibrary.loadLbpLibrary()	
		im = self.img[0:3,0:3]
		im[1,1] = 1		
		print('\nTEST LBP 1x8\n')
		im[0,0] = 2		
		res = lbpLibrary.lbp1x8(libLbp, im);
		assert(np.argmax(res) == 1)
		im[0,1] = 2													
		pass

	def test_03lbp_2x8(self):
		libLbp = lbpLibrary.loadLbpLibrary()	
		im = self.img[0:5,0:5]
		im[2,2] = 1		
		print('\nTEST LBP 2x8\n')
		im[0:2,0:2] = 2
		res = lbpLibrary.lbp2x8(libLbp, im);
		assert(np.argmax(res) == 1)												
		pass
			
	def test_04lbp_3x10(self):
		libLbp = lbpLibrary.loadLbpLibrary()	
		im = self.img[0:7,0:7]
		im[3,3] = 1	
		print('\nTEST LBP 3x10\n')
		im[0:2,2:4] = 2
		res = lbpLibrary.lbp3x10(libLbp, im);
		assert(np.argmax(res) == 3)												
		pass
			
	def test_05lbp_4x12(self):			
		libLbp = lbpLibrary.loadLbpLibrary()	
		im = self.img[0:9,0:9]
		im[4,4] = 1		
		print('\nTEST LBP 4x12\n')		
		im[0:2,2:3] = 2
		res = lbpLibrary.lbp4x12(libLbp, im);
		assert(np.argmax(res) == 1)	
		pass
			
	def test_06uniformLbp(self):
		print('\nTEST Uniform Lbp Algorithm\n')			
		libLbp = lbpLibrary.loadLbpLibrary()
		hist = np.zeros([10,1], dtype = np.int32)
		hist[1] = 1 		
		hist[3] = 1 
		hist[5] = 1		
		res = lbpLibrary.uniformLbp(libLbp, hist)
		assert(res[0] == 1)	
		assert(res[1] == 1)		
		assert(res[3] == 1)				
		pass
			
	def test_07rotationMinLbp(self):
		print('\nTEST Rotation Minimum Lbp Algorithm\n')			
		libLbp = lbpLibrary.loadLbpLibrary()
		hist = np.zeros([10,1], dtype = np.int32)
		hist[1] = 1 		
		hist[4] = 1 
		hist[6] = 1		
		res = lbpLibrary.rotationMinLbp(libLbp, hist)
		assert(res[1] == 2)		
		assert(res[3] == 1)				
		pass	
		pass
		
if __name__ == '__main__':
    unittest.main()
