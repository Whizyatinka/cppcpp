#include <Python.h>
#include <ctime>

static PyObject* addList_add(PyObject* self, PyObject* args)
{
    PyObject* listObj;

    if (!PyArg_ParseTuple(args, "O", &listObj))
        return NULL;

    Py_ssize_t length = PyList_Size(listObj);

    clock_t start_time = clock();

    long sum = 0; 

    for (Py_ssize_t i = 0; i < length; i++) {
        PyObject* temp = PyList_GetItem(listObj, i);
        long elem = PyLong_AsLong(temp);  
        sum += elem;
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;


    return Py_BuildValue("(ld)", sum, time_taken);
}

static PyMethodDef addList_funcs[] = {
    {"add", (PyCFunction)addList_add, METH_VARARGS,
     "add(list) -> (sum, time)"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef addList_module = {
    PyModuleDef_HEAD_INIT,
    "addList",          
    "Add all the lists",
    -1,
    addList_funcs
};

PyMODINIT_FUNC PyInit_addList(void)
{
    return PyModule_Create(&addList_module);
}

