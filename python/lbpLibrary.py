from PIL import Image
import ctypes


def loadLbpLibrary() :
    lbplib = ctypes.cdll.LoadLibrary("./liblbp.so")
    return lbplib

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

def realTimeLbpIm(lbplib, im) :
    w,h = im.size
    img = (ctypes.c_long * (w*h))()
    res = (ctypes.c_long * 256)()
    for i in range(w) :
        for j in range(h) :
            img[(w*i) + j] = im.getpixel((i, j))
    lbplib.realTimeLbp(w,h,ctypes.byref(img), ctypes.byref(res))
    return res

def imageToLbp(lbplib, filename, type = 1, radius = 1, samples = 8) :
    im = Image.open(filename)
    w,h = im.size
    img = (ctypes.c_double * (w*h))()
    for i in range(w) :
        for j in range(h) :
            img[(w*i) + j] = im.getpixel((i, j))
    lbplib.imageToLbp(w,h, ctypes.byref(img), type, radius, samples)
    return img
    