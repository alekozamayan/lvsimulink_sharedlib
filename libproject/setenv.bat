REM Toolchain path
REM This can be downloaded from "https://www.ni.com/en/support/downloads/software-products/download.gnu-c---c---compile-tools-x64.html"
REM Toolchain version: 2018-2019
SET "TOOLCHAIN_PATH=C:\oecore-i686-core2-64-toolchain-6.0\"

REM Simulink Model Name should be entered here correctly.
REM (Model name is e.g. the common prefix of the files
REM "Blabla.h" "Blabla.c" "Blabla_private.h" "Blabla_data.c" "Blabla_types.h" 
REM files in the algsrc directory. In this case, model name is "Blabla")
SET "MODEL_NAME=ClusterAlg"
