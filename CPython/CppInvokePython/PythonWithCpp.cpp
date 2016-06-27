#include<iostream>
#include<Python.h>
using namespace std;
int main(int argc, char* argv[])
{
    //��ʼ��python
    Py_Initialize();

    //ֱ������python����
    PyRun_SimpleString("print 'Python Start'");

    //���뵱ǰ·��,��������ģ�鲻����������
    PyRun_SimpleString("import sys");  
    PyRun_SimpleString("sys.path.append('./')");  

    //����ģ��
    PyObject *pModule = PyImport_ImportModule("TestModule");
    //��ȡģ���ֵ�����
    PyObject *pDict = PyModule_GetDict(pModule);

    //ֱ�ӻ�ȡģ���еĺ���
    PyObject *pFunc = PyObject_GetAttrString(pModule, "Hello");

    //��������ת��������һ���ַ�������c/c++���͵��ַ���ת��Ϊpython���ͣ�Ԫ���е�python���Ͳ鿴python�ĵ�
    PyObject *pArg = Py_BuildValue("(s)", "Hello Charity");

    //����ֱ�ӻ�õĺ����������ݲ���
    PyEval_CallObject(pFunc, pArg);

    //���ֵ������л�ȡ����
    pFunc = PyDict_GetItemString(pDict, "Add");
    //��������ת���������������Ͳ���
    pArg = Py_BuildValue("(i, i)", 1, 2);

    //���ú��������õ�python���͵ķ���ֵ
    PyObject *result = PyEval_CallObject(pFunc, pArg);
    //c��������c/c++���͵ķ���ֵ
    int c;
    //��python���͵ķ���ֵת��Ϊc/c++����
    PyArg_Parse(result, "i", &c);
    //�������ֵ
    printf("a+b=%d\n", c);

    //ͨ���ֵ����Ի�ȡģ���е���
    PyObject *pClass = PyDict_GetItemString(pDict, "Test");

    //ʵ������ȡ����
    PyObject *pInstance = PyInstance_New(pClass, NULL, NULL);
    //������ķ���
    result = PyObject_CallMethod(pInstance, "SayHello", "(s)", "Charity");
    //�������ֵ
    char* name=NULL;
    PyArg_Parse(result, "s", &name);
    printf("%s\n", name);

    PyRun_SimpleString("print 'Python End'");

    //�ͷ�python
    Py_Finalize();
    getchar();
    return 0;
}