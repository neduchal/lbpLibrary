#! /usr/bin/python
# -*- coding: utf-8 -*-

"""
Hlavní soubor pySlam
---------------------

"""

# import funkcí
import sys
import os.path
import numpy as np
import scipy
import lbp3d

def main():
	#points = lbp3d.initPoints(20,0.55)
	points = lbp3d.maskGenerator(20, 512, 512, 4.5, 500, 0.55, 1)
	print points


if __name__ == "__main__":
	main()
