#! /usr/bin/python
# -*- coding: utf-8 -*-

import os
import sys

path_to_script = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(path_to_script, "../"))

import json
import numpy as np
import unittest
from lbp import *

class TestLbp3d(unittest.TestCase):
	def setUp(self):
		self.data = np.zeros([9,9,9], dtype = np.int)
		pass

	def test_01loadLibrary(self):
		print('\nTEST Load LbpLibrary3D \n')	
		libLbp = lbp3d.load()
		self.assert_(libLbp is not None)
		
	def test_02lbp3D(self):
		mask = {}
		im = self.data
		im[:,:,:] = 2
		libLbp = lbp3d.load()
		im[3:6,3:6,3:6] = 1
		f = open('../../masks/mask3D_8_4.json', 'r')
		maskJSON = json.load(f)
		mask = maskJSON['mask']
		lbp3d.coordToPoints(mask, 9, 9)
		res = lbp3d.compute(libLbp, im, mask)
		print('\nTEST 3D LBP\n')
		assert(np.argmax(res) == 255)											
		pass

		
if __name__ == '__main__':
    unittest.main()
