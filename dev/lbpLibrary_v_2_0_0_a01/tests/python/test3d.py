#! /usr/bin/python
# -*- coding: utf-8 -*-

import numpy as np
import unittest
import lbpLibrary3d

class TestLbp3d(unittest.TestCase):
	def setUp(self):
		self.data = np.zeros([9,9,9], dtype = np.int)
		pass

	def test_01loadLibrary(self):
		print('\nTEST Load LbpLibrary3D \n')	
		libLbp = lbpLibrary3d.loadLbp3DLibrary()
		self.assert_(libLbp is not None)
		
	def test_02lbp3D(self):
		libLbp = lbpLibrary3d.loadLbp3DLibrary()	
		im = self.data[0:5,0:5,0:5]
		im[:,:,:] = 2
		im[2,2,2] = 1
		mask = lbpLibrary3d.maskGenerator(24, 3, 3, 2, 50, 0.5, 1)
		res = lbpLibrary3d.lbp3d(libLbp, im, 24, mask, 2)
		print('\nTEST 3D LBP\n')
		print(mask['mask'])
		print(np.argmax(res))
		assert(np.argmax(res) == 1)											
		pass

		
if __name__ == '__main__':
    unittest.main()
