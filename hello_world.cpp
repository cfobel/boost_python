#include <boost/python.hpp>
#include <string>

using namespace std;

string greet()
{
   return "hello, world";
}

BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
    def("greet", greet);
}
