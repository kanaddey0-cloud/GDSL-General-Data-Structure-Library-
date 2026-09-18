Creating a separate file (for example, `gdsl_instantiations.cpp`) allows you to centralize the generation of commonly used template specializations for your library.

In this file, you simply include your template headers and write statements such as:


template class ARRAY<int>;
template class LIST<float>;


or similar for the types you want to support.

These statements instruct the compiler to generate the machine code for those template instances once while building the library, instead of generating the same code repeatedly in every source file that uses them.

This can reduce compilation time, avoid duplicate code generation across translation units, and provide precompiled implementations for frequently used types such as `int`, `float`, `double`, or `std::string`.

It does **not** replace templates or make the library non-generic. Users can still instantiate `ARRAY<MyClass>`, `LIST<Employee>`, or any other user-defined type normally.

The file simply acts as a central place where the library prebuilds the most common template specializations, improving build efficiency while keeping the original template-based design unchanged.

By convention, this file is placed in the library's **`src/`** directory since it is an implementation source file that is compiled as part of the library, while the template declarations and definitions remain in the **`include/`** directory.
