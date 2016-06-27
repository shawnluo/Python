TestModule: PythonWithCpp.cpp TestModule.py
	g++ -c -fPIC LibPythonTest.cpp
	g++ -shared LibPythonTest.o -o LibPythonTest.so
clean:
	rm LibPythonTest.o LibPythonTest.so