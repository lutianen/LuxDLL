import ctypes
from distutils.sysconfig import PREFIX
import os
from ctypes import c_bool, c_char_p, c_int, c_ubyte, CDLL

FILE_PREFIX = "./"

dll = CDLL(FILE_PREFIX + 'build/libLuxDLL.dll', winmode=0)

dll.LuxFlushStdOut()

# dll.bar.restype = ctypes.c_double

fileName = os.path.join(FILE_PREFIX ,"images/internal_only_disp.raw")
outF = os.path.join(FILE_PREFIX, "images/2222222")
dll.LuxLoadImageDataFromFile(c_char_p(fileName.encode()), 
                            c_int(2), 
                            c_int(720), 
                            c_int(576),
                            c_int(12),
                            c_int(1), 
                            c_char_p(outF.encode()),
                            c_bool(True),
                            c_bool(False),
                            c_bool(True),
                            c_int(46))

print("end")

