#! /usr/bin/python
# -*- coding: utf-8 -*-

import os
import sys

path_to_script = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(path_to_script, "../"))

import numpy as np
import unittest
import lbpLibrary3d
from utils import *

class TestLbp3d(unittest.TestCase):
	def setUp(self):
		self.data = np.zeros([9,9,9], dtype = np.int)
		pass

	def test_01loadLibrary(self):
		print('\nTEST Load LbpLibrary3D \n')	
		libLbp = lbpLibrary3d.loadLbp3DLibrary()
		self.assert_(libLbp is not None)
		
	def test_02lbp3D(self):
		mask = {}
		im = self.data
		im[:,:,:] = 2
		libLbp = lbpLibrary3d.loadLbp3DLibrary()	
		im[3:6,3:6,3:6] = 1
		maskJSON = inout.readMask('../../masks/mask3D_8.json')
		mask['mask'] = maskJSON['mask']['points']
		mask['maskCoef'] = maskJSON['mask']['coefs']
		mask['center'] = maskJSON['mask']['center']
		res = lbpLibrary3d.lbp3d(libLbp, im, maskJSON['mask']['pointsNum'], mask, maskJSON['mask']['size'][0])
		print('\nTEST 3D LBP\n')
		assert(np.argmax(res) == 255)											
		pass

		
if __name__ == '__main__':
    unittest.main()
