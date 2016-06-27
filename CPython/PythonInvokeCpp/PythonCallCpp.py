 #!/bin/python
#Filename:PythonCallCpp.py
from ctypes import *
import os
libPythonTest = cdll.LoadLibrary('./LibPythonTest.so')
print libPythonTest.Add(1,1)