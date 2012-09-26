from PIL import Image
import ctypes
import lbpLibrary as lbpLib

im = Image.open("lena.png")


lbp = lbpLib.loadLbpLibrary()

res = lbpLib.realTimeLbp(lbp, "lena.png")
res = lbpLib.realTimeLbpIm(lbp, im)

for i in range(256) : print(res[i])

res = lbpLib.imageToLbp(lbp, "lena.png", 1 ,1 ,8)

for i in range(256) : 
    print(res[i])

