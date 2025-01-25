//#include <C:\Users\papin\AppData\Local\Programs\Python\Python311\Lib\site-packages\pybind11\include\pybind11\pybind11.h>
//#include <C:\Users\papin\AppData\Local\Programs\Python\Python311\Lib\site-packages\pybind11\include\pybind11\attr.h>
#include <pybind11\pybind11.h>
#include <iostream>
#include "MyString.h"
namespace py = pybind11;
//using namespace std;

PYBIND11_MODULE(MyString, m) {
    py::class_<MyString>(m, "MyString")
        /* 
        .def(py::init<const char*>())
        .def(py::init<const std::string&>())
        .def(py::init<const char*, int>())
        .def(py::init<int, const char>())
        */
        .def(py::init<const MyString&>());
        /* 
     
        */
 /* 
   
        .def("size", &MyString::size)
        .def("capacity", &MyString::capacity)
        .def("length", &MyString::length)
        .def("c_str", &MyString::c_str)

        .def("insert", static_cast<void (MyString::*)(int, int,char)>(&MyString::insert))
        .def("insert", static_cast<void (MyString::*)(int,const char*)>(&MyString::insert))
        .def("insert", static_cast<void (MyString::*)(int, const char*, int)>(&MyString::insert))
        .def("insert", static_cast<void (MyString::*)(int, std::string)>(&MyString::insert))
        .def("insert", static_cast<void (MyString::*)(int, std::string, int)>(&MyString::insert))
        //def("insert", &MyString::insert)  
        
        .def("find", static_cast<int (MyString::*)(const char*, int)>(&MyString::find))
        .def("find", static_cast<int (MyString::*)(const char*)>(&MyString::find))
        .def("find", static_cast<int (MyString::*)(std::string, int)>(&MyString::find))
        .def("find", static_cast<int (MyString::*)(std::string)>(&MyString::find))

        .def("substr", static_cast<MyString (MyString::*)(int)>(&MyString::substr))
        .def("substr", static_cast<MyString(MyString::*)(int, int)>(&MyString::substr))


        //.def("substr", &MyString::substr)
        //.def("replace", &MyString::replace)
        .def("replace", static_cast<void (MyString::*)(int, int, const char*)>(&MyString::replace))
        .def("replace", static_cast<void (MyString::*)(int, int, std::string)>(&MyString::replace))


        .def("clear", &MyString::clear)
        .def("empty", &MyString::empty)
        .def("erase", &MyString::erase)
        .def("shrink_to_fit", &MyString::shrink_to_fit)
        .def("data", &MyString::data)

       // .def("append", &MyString::append)
       .def("append", static_cast<void (MyString::*)(int, char)>(&MyString::append))
       .def("append", static_cast<void (MyString::*)(const char*)>(&MyString::append))
       .def("append", static_cast<void (MyString::*)(const char*, int, int)>(&MyString::append))
       .def("append", static_cast<void (MyString::*)(std::string)>(&MyString::append))
       .def("append", static_cast<void (MyString::*)(std::string,int, int)>(&MyString::append))

  
       // .def("[]", &MyString::operator[])
        .def("index", &MyString::operator[])
        //.def("+", &MyString::operator+)
         .def("add", &MyString::operator+)
        //.def("=", &MyString::operator=)
        .def("assign", &MyString::operator=)
       // .def("+=", &MyString::operator+=)
        .def("assignadd", &MyString::operator=+)
        //.def(">", &MyString::operator>)
         .def("more", &MyString::operator>)
        //.def(">=", &MyString::operator>=)
         .def("moreeq", &MyString::operator>=)
        //.def("<", &MyString::operator<)
         .def("less", &MyString::operator<)
        //.def("<=", &MyString::operator<=)
         .def("lesseq", &MyString::operator<=)
        //.def("==", &MyString::operator==)
         .def("equal", &MyString::operator==)
        //.def("!=", &MyString::operator!=)
         .def("notequal", &MyString::operator!=);
   */     
}

