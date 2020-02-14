// hello_world.h file is automatically generated according to ABI each
// time before compilation by deploy script.
#include "hello_world.h"

// Function "compute" is a public method -- it is declared in ABI, and its
// name is fixed in an external interface to the contract. However, public
// methods calling conventions are quite different from C conventions,
// they are defined in toolchain and ABI docs. For example, they accept a
// slice instead of values on stack, the arguments must be deserialized by
// special library funcitons, and so on.
//
// So, the public functions are defined in hello_world_wrapper.c file,
// auto generated by the toolchain. These functions are wrappers around
// real contract functions and along with implementation calls contain code
// for parameter deserialization and result serialization.
//
// The contract programmer deals with implementation functions only (those
// with suffix _Impl added to their names). These functions should be
// defined according to ABI definitions, their prototypes are declared in
// auto-generated hello_world.h file.
unsigned compute_Impl () {
    tvm_accept();

    // The return value is packed into an external message and sent at the exit
    // from the method. Unfortunately, now blockchain does not have instruments
    // to see it.
    return 2 + 2;
}

// Contract constructor implementation
void constructor_Impl () {
    tvm_accept();
}
