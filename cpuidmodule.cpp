/**
 * Copyright (c) 2017-2021 Fernando Pelliccioni
 */

#include <Python.h>
#include "cpuid.h"

// ---------------------------------------------------------

#ifdef __cplusplus
extern "C" {  
#endif

PyObject* cpuid_native_get_cpuid(PyObject* self, PyObject* args) {
    unsigned int py_leaf;

    if ( ! PyArg_ParseTuple(args, "I", &py_leaf))
        return NULL;

    unsigned int eax, ebx, ecx, edx;
    int res = __get_cpuid(py_leaf, &eax, &ebx, &ecx, &edx);

    return Py_BuildValue("iIIII", res, eax, ebx, ecx, edx);
}

PyObject* cpuid_native_get_cpuid_count(PyObject* self, PyObject* args) {
    unsigned int py_leaf;
    unsigned int py_subleaf;
    
    if ( ! PyArg_ParseTuple(args, "II", &py_leaf, &py_subleaf))
        return NULL;

    unsigned int eax, ebx, ecx, edx;
    int res = __get_cpuid_count(py_leaf, py_subleaf, &eax, &ebx, &ecx, &edx);

    return Py_BuildValue("iIIII", res, eax, ebx, ecx, edx);
}

PyObject* cpuid_native_xgetbv(PyObject* self, PyObject* args) {
    int py_ctr;
    
    if ( ! PyArg_ParseTuple(args, "I", &py_ctr)) {
        return NULL;
    }

    uint64_t res = xgetbv(py_ctr);
    return Py_BuildValue("K", res);
}

PyObject* cpuid_native_rdtscp(PyObject* self, PyObject* args) {
    unsigned int ui;
    uint64_t res = rdtscp(&ui);

    return Py_BuildValue("(KI)", res, ui);
}




// ---------------------------------------------------------


static
PyMethodDef CpuidNativeMethods[] = {
    {"get_cpuid",  cpuid_native_get_cpuid, METH_VARARGS, "..."},
    {"get_cpuid_count",  cpuid_native_get_cpuid_count, METH_VARARGS, "..."},
    {"xgetbv",  cpuid_native_xgetbv, METH_VARARGS, "..."},
    {"rdtscp",  cpuid_native_rdtscp, METH_VARARGS, "..."},
    
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

struct module_state {
    PyObject *error;
};

#if PY_MAJOR_VERSION >= 3
#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))
#else //PY_MAJOR_VERSION >= 3
#define GETSTATE(m) (&_state)
static struct module_state _state;
#endif //PY_MAJOR_VERSION >= 3

#if PY_MAJOR_VERSION >= 3

static 
int myextension_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static 
int myextension_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static 
struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "cpuid_native",
        NULL,
        sizeof(struct module_state),
        CpuidNativeMethods,
        NULL,
        myextension_traverse,
        myextension_clear,
        NULL
};

#define INITERROR return NULL

PyMODINIT_FUNC
PyInit_cpuid_native(void)


#else /* PY_MAJOR_VERSION >= 3 */

#define INITERROR return

void /*PyMODINIT_FUNC*/
initcpuid_native(void)

#endif /* PY_MAJOR_VERSION >= 3 */

{
    // Make sure the GIL has been created since we need to acquire it in our
    // callback to safely call into the python application.
    if (! PyEval_ThreadsInitialized()) {
        PyEval_InitThreads();
    }


#if PY_MAJOR_VERSION >= 3
    PyObject *module = PyModule_Create(&moduledef);
#else
    PyObject *module = Py_InitModule("cpuid_native", CpuidNativeMethods);
    // (void) Py_InitModule("cpuid_native", CpuidNativeMethods);
#endif

    if (module == NULL) {
        INITERROR;
    }

    struct module_state *st = GETSTATE(module);

    st->error = PyErr_NewException((char*)"myextension.Error", NULL, NULL);
    
    if (st->error == NULL) {
        Py_DECREF(module);
        INITERROR;
    }

#if PY_MAJOR_VERSION >= 3
    return module;
#endif
}


#ifdef __cplusplus
} // extern "C"
#endif  

