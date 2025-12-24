#include <Python.h>
#include <ctime>

// C-ôóíêöèÿ: ñóììèðîâàíèå ýëåìåíòîâ ñïèñêà + çàìåð âðåìåíè
static PyObject* addList_add(PyObject* self, PyObject* args)
{
    PyObject* listObj;

    // Îæèäàåì îäèí àðãóìåíò: ñïèñîê
    if (!PyArg_ParseTuple(args, "O", &listObj))
        return NULL;

    Py_ssize_t length = PyList_Size(listObj);

    clock_t start_time = clock();

    long sum = 0;  // ñóììà êàê long, ÷òîáû íå ïåðåïîëíÿëñÿ int

    for (Py_ssize_t i = 0; i < length; i++) {
        PyObject* temp = PyList_GetItem(listObj, i);
        long elem = PyLong_AsLong(temp);  // ñ÷èòàåì, ÷òî ýëåìåíòû — int
        sum += elem;
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    // Âîçâðàùàåì êîðòåæ (ñóììà, âðåìÿ)
    return Py_BuildValue("(ld)", sum, time_taken);
}

// Òàáëèöà ôóíêöèé ìîäóëÿ
static PyMethodDef addList_funcs[] = {
    {"add", (PyCFunction)addList_add, METH_VARARGS,
     "add(list) -> (sum, time)"},
    {NULL, NULL, 0, NULL}
};

// Îïèñàíèå ìîäóëÿ
static struct PyModuleDef addList_module = {
    PyModuleDef_HEAD_INIT,
    "addList",          // èìÿ ìîäóëÿ (import addList)
    "Add all the lists",
    -1,
    addList_funcs
};

// Èíèöèàëèçàöèÿ ìîäóëÿ
PyMODINIT_FUNC PyInit_addList(void)
{
    return PyModule_Create(&addList_module);
}
