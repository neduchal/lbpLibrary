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
		self.reader = datareader.DataReader()
		dcmdir = "/home/petr/Dokumenty/statistics/sliver07/training-part3/liver-orig013.mhd"		
		self.data = self.reader.Get3DData(dcmdir)[0]
		print self.data.shape
		pass

#	def test_01loadLibrary(self):
#		print('\nTEST Load LbpLibrary3D \n')	
#		libLbp = lbpLibrary3d.loadLbp3DLibrary()
#		self.assert_(libLbp is not None)
		
	def test_02lbp3D(self):
		mask = {}
		im = self.data
		libLbp = lbpLibrary3d.loadLbp3DLibrary()	
		maskJSON = inout.readMask('../../masks/mask3D_8_4_512x512.json')
		mask['mask'] = maskJSON['mask']['points']
		mask['maskCoef'] = maskJSON['mask']['coefs']
		mask['center'] = maskJSON['mask']['center']
		res = lbpLibrary3d.lbp3d(libLbp, im, maskJSON['mask']['pointsNum'], mask, maskJSON['mask']['size'][0])
		print('\nTEST 3D LBP\n')
		print res
		assert(np.argmax(res) == 255)											
		pass					
		
if __name__ == '__main__':
    unittest.main()
