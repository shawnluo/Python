#include<iostream>
#include<Python.h>
using namespace std;
int main(int argc, char* argv[])
{
    Py_Initialize();

    //run python code by using Python lib API
    PyRun_SimpleString("print 'Python Start'");

    //import current path, otherwise the modules cannot be imported right
    PyRun_SimpleString("import sys");  
    PyRun_SimpleString("sys.path.append('./')");  

    //import python module
    PyObject *pModule = PyImport_ImportModule("TestModule");
    //get dictionary attribute
    PyObject *pDict = PyModule_GetDict(pModule);

    //get the function in module
    PyObject *pFunc = PyObject_GetAttrString(pModule, "Hello");

    //transfer a string (c/c++ type) to python type
    PyObject *pArg = Py_BuildValue("(s)", "Hello Charity");

    //invoke the function, and pass parameters
    PyEval_CallObject(pFunc, pArg);

    //get function from dictionary attribute
    pFunc = PyDict_GetItemString(pDict, "Add");
    //transfer parameters type, and pass two interger parameters
    pArg = Py_BuildValue("(i, i)", 1, 2);

    //invoke function, and get the return python type value
    PyObject *result = PyEval_CallObject(pFunc, pArg);
    
	//using charater c to save c/c++ type return value
    int c;
    //transfer the python tpye return value to c/c++ type return value
    PyArg_Parse(result, "i", &c);
    
    printf("a+b=%d\n", c);

        PyObject *pClass = PyDict_GetItemString(pDict, "Test");

    //instantied the class
    PyObject *pInstance = PyInstance_New(pClass, NULL, NULL);
    //invoke the method of the class 
    result = PyObject_CallMethod(pInstance, "SayHello", "(s)", "Charity");
    //output the return value
    char* name=NULL;
    PyArg_Parse(result, "s", &name);
    printf("%s\n", name);

    PyRun_SimpleString("print 'Python End'");

    //Finalize python
    Py_Finalize();
    //getchar();
    return 0;
}