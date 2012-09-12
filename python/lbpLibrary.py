# Python wrapper for LbpLibrary 
# verison 0.2.0
# Author : Petr Neduchal
# Last update : 12.9.2012
# Issues : - Only for unix/linux

from PIL import Image
import ctypes

# Function loads dynamic library (./liblbp.so)
def loadLbpLibrary() :
    lbplib = ctypes.cdll.LoadLibrary("./liblbp.so")
    return lbplib

# Function calls extern function realTimeLbp 
# Params : lbplib - library pointer (see loadLbpLibrary)
#          filename - (string) path to the image file. 
def realTimeLbp(lbplib, filename) :
    im = Image.open(filename)
    w,h = im.size
    img = (ctypes.c_long * (w*h))()
    res = (ctypes.c_long * 256)()
    for i in range(w) :
        for j in range(h) :
            img[(w*i) + j] = im.getpixel((i, j))
    lbplib.realTimeLbp(w,h,ctypes.byref(img), ctypes.byref(res))
    return res

# Function calls extern function realTimeLbp 
# Params : lbplib - library pointer (see loadLbpLibrary)
#          im - Instance of Image class from PIL module
def realTimeLbpIm(lbplib, im) :
    w,h = im.size
    img = (ctypes.c_long * (w*h))()
    res = (ctypes.c_long * 256)()
    for i in range(w) :
        for j in range(h) :
            img[(w*i) + j] = im.getpixel((i, j))
    lbplib.realTimeLbp(w,h,ctypes.byref(img), ctypes.byref(res))
    return res

# Function calls extern function realTimeLbp 
# Params : lbplib - library pointer (see loadLbpLibrary)
#          data - (ctypes.c_long * (size of the image)) C type array 
#                 with Image data
#          w - image width
#          h - image height
def realTimeLbpArr(lbplib, data, w, h) :
    res = (ctypes.c_long * 256)()
    lbplib.realTimeLbp(w,h,ctypes.byref(data), ctypes.byref(res))
    return res

# Function calls extern function imageToLbp
# Params : lbplib - library pointer (see loadLbpLibrary)
#          filename - (string) path to the image file. 
#          type -  Type of LBP algorithm
#          radius - Radius of samples in LBP mask.
#          samples - Number of samples around the main point in LBP mask
def imageToLbp(lbplib, filename, type = 1, radius = 1, samples = 8) :
    im = Image.open(filename)
    w,h = im.size
    img = (ctypes.c_double * (w*h))()
    for i in range(w) :
        for j in range(h) :
            img[(w*i) + j] = im.getpixel((i, j))
    lbplib.imageToLbp(w,h, ctypes.byref(img), type, radius, samples)
    return img

# Function calls extern function imageToLbp
# Params : lbplib - library pointer (see loadLbpLibrary)
#          im - Instance of Image class from PIL module
#          type -  Type of LBP algorithm
#          radius - Radius of samples in LBP mask.
#          samples - Number of samples around the main point in LBP mask
def imageToLbpIm(lbplib, im, type = 1, radius = 1, samples = 8) :
    w,h = im.size
    img = (ctypes.c_double * (w*h))()
    for i in range(w) :
        for j in range(h) :
            img[(w*i) + j] = im.getpixel((i, j))
    lbplib.imageToLbp(w,h, ctypes.byref(img), type, radius, samples)
    return img

# Function calls extern function imageToLbp
# Params : lbplib - library pointer (see loadLbpLibrary)
#          data - (ctypes.c_long * (size of the image)) C type array 
#                 with Image data
#          w - image width
#          h - image height
#          type -  Type of LBP algorithm
#          radius - Radius of samples in LBP mask.
#          samples - Number of samples around the main point in LBP mask

def imageToLbpArr(lbplib, data, w, h, type = 1, radius = 1, samples = 8) :
    lbplib.imageToLbp(w,h, ctypes.byref(data), type, radius, samples)
    return img
    