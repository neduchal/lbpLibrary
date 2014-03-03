#! /usr/bin/python
# -*- coding: utf-8 -*-

import json

def readMask(filename):
	f = open(filename, 'r')
	return json.load(f)
	


