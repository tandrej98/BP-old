#include "qt_test.h"
#include "pybind11/pybind11.h"

namespace py = pybind11;


Qt_test::Qt_test()
{
}

extern "C" QT_TEST_EXPORT void Qt_test::py_print()
{
    py::object tf = py::module::import("tensorflow");
    py::object Decimal = py::module::import("decimal").attr("Decimal");
    py::object pi = Decimal("3.14159");
    py::object exp_pi = pi.attr("exp")();
    py::print(py::str(exp_pi));
}
