#include "qt_test.h"
#include "pybind11/pybind11.h"
#include <pybind11/embed.h>
#include <iostream>
#include <string>


namespace py = pybind11;


Qt_test::Qt_test()
{
	py::initialize_interpreter();
}

extern "C" QT_TEST_EXPORT void Qt_test::py_print(std::string toPrint)
{
    //py::scoped_interpreter guard{}; // start the interpreter and keep it alive
    py::print(toPrint); // use the Python API
}
extern "C" QT_TEST_EXPORT void Qt_test::tf_test(){
	py::object scipy = py::module::import("scipy");
	py::print(scipy.attr("__version__"));
//    py::object keras = py::module::import("tensorflow").attr("keras");
}
