@echo off
setlocal

REM setup environment
call setenv.bat

SET "ALG_HEADER_PATH=%~dp0algsrc\%MODEL_NAME%.h"

SET "STRUCT_REGEX_TEMPLATE=typedef\s+struct\s*[\w\d]*\s*{([^}]*)}\s*#STRUCT_TYPENAME#\s*;|struct\s+#STRUCT_TYPENAME#\s*{([^}]*)}\s*;"

ECHO Algorithm input interface:
ECHO ------------------------
CALL :FIND_REGEX "%ALG_HEADER_PATH%" "%%STRUCT_REGEX_TEMPLATE:#STRUCT_TYPENAME#=ExtU_%MODEL_NAME%_T%%"
ECHO ------------------------
ECHO.
ECHO Algorithm output interface:
ECHO ------------------------
CALL :FIND_REGEX "%ALG_HEADER_PATH%" "%%STRUCT_REGEX_TEMPLATE:#STRUCT_TYPENAME#=ExtY_%MODEL_NAME%_T%%"
ECHO ------------------------
ECHO.

pause
endlocal & EXIT /B

REM %1 : File path
REM %2 : Regex pattern
:FIND_REGEX
setlocal
SET "FILE_PATH=%~1"
SET "REGEX_PATTERN=%~2"
powershell -Command "& {Get-Content -Raw %FILE_PATH% | select-string -Pattern '%REGEX_PATTERN%' -AllMatches | %% { $_.Matches } | %% { $_.Value } }"
ENDLOCAL & EXIT /B