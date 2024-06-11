@ECHO OFF
SETLOCAL

call setenv.bat

SET "PATH=%TOOLCHAIN_PATH%;%PATH%"

SET "PROJECT_DIR=%~dp0"

call environment-setup-core2-64-nilrt-linux.bat

make clean -C %PROJECT_DIR%
make all -C %PROJECT_DIR%

pause
ENDLOCAL & EXIT /B