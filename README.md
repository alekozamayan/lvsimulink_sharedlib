# lvsimulink_sharedlib
This project aims to implement a simple build environment to create NI Realtime Linux shared library for x86 platforms from generated C code of Simulink model. It is designed to easily wrap Simulink models which have 

- only Input and Output structure as the interface
- only "initialize" and "step" functions implemented

It is designed to work under Windows (host machine), however can be ported easily in Linux. It can only be used with one of the NI Realtime Linux GNU Cross Compiling toolchains in the link below (tested with version 2018-2019)  

[NI Realtime Linux GNU C & C++ Compile Tools x64](https://www.ni.com/en/support/downloads/software-products/download.gnu-c---c---compile-tools-x64.html#477802)

### Setup
- Download toolchain and extract to some directory.
- Download the repository
In repo,
- Copy the generated Simulink C code to "algsrc" directory.
- Modify the environment variable values in "setenv.bat" according to the instructions inside file, using a text editor.
- Call "getinterface.bat". That will process a regex search on the model header file and return the expected input and output structure.
In Labview,
- Add "Call Library Function Node" in your model.
- Follow the instructions written in "deflist.h" and according to your VI, modify the "deflist.h" NI_INPUT_LIST and NI_OUTPUT_LIST macros.

Call "build.bat" to build the shared library. After a successful build, take your .so file to the target system and set the path in "Call Library Function Node", and you're done.

Notes:
- The compiler warning flags "conversion" and "sign-conversion" converted to errors with the compiler flags "-Werror=conversion -Werror=sign-conversion" to cancel build if there is any implicit casting operation in the code, which may result in data/resolution loss. This is used to locate any unmatched interface definitions in "deflist.h".
