#include <boost/assign/list_of.hpp>       // for 'list_of()'
#include <boost/python.hpp>
#include <boost/python/handle.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace boost::python;
using boost::assign::list_of;

template<class T>
struct VecToList {
    static PyObject* convert(const std::vector<T>& vec) {
        boost::python::list* l = new boost::python::list();
        for(size_t i = 0; i < vec.size(); i++)
            (*l).append(vec[i]);

        return l->ptr();
    }
};


template<class T>
vector<T> extract_vector(const boost::python::object &o) {
    vector<T> output;
    try {
        boost::python::api::object iter_obj = object(handle<>(PyObject_GetIter(o.ptr())));
        while(1) {
            object obj = extract<object>(iter_obj.attr("next")()); // Should always work
            T val = extract<T>(obj); // Should launch an exception if you wannot extract an int ...
            output.push_back(val);
        }
    } catch(error_already_set) {
        PyErr_Clear(); // If there is an exception (no iterator, extract failed or end of the list reached), clear it and exit the function
    }
    return output;
}


vector<string> get_vector() {
    vector<string> v = list_of("test A")
                            ("test B")
                            ("test C")
                            ("test D")
                            ("test E")
                            ("test F")
                            ("test G");
    return v;
}


template<class T>
void display_list(boost::python::object o) {
    vector<T> v = extract_vector<T>(o);
    for(int i = 0; i < v.size(); i++) {
        cout << "    v[" << i << "]: " << v[i] << endl;
    }
}


BOOST_PYTHON_MODULE(vector_ops)
{
    to_python_converter<std::vector<std::string, std::allocator<std::string> >, VecToList<std::string> >();
    def("get_vector", get_vector);
    def("display_strings", display_list<string>);
    def("display_ints", display_list<int>);
}
