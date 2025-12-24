#include <Python.h>
#include <ctime>

// C-функция: суммирование элементов списка + замер времени
static PyObject* addList_add(PyObject* self, PyObject* args)
{
    PyObject* listObj;

    // Ожидаем один аргумент: список
    if (!PyArg_ParseTuple(args, "O", &listObj))
        return NULL;

    Py_ssize_t length = PyList_Size(listObj);

    clock_t start_time = clock();

    long sum = 0;  // сумма как long, чтобы не переполнялся int

    for (Py_ssize_t i = 0; i < length; i++) {
        PyObject* temp = PyList_GetItem(listObj, i);
        long elem = PyLong_AsLong(temp);  // считаем, что элементы — int
        sum += elem;
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    // Возвращаем кортеж (сумма, время)
    return Py_BuildValue("(ld)", sum, time_taken);
}

// Таблица функций модуля
static PyMethodDef addList_funcs[] = {
    {"add", (PyCFunction)addList_add, METH_VARARGS,
     "add(list) -> (sum, time)"},
    {NULL, NULL, 0, NULL}
};

// Описание модуля
static struct PyModuleDef addList_module = {
    PyModuleDef_HEAD_INIT,
    "addList",          // имя модуля (import addList)
    "Add all the lists",
    -1,
    addList_funcs
};

// Инициализация модуля
PyMODINIT_FUNC PyInit_addList(void)
{
    return PyModule_Create(&addList_module);
}