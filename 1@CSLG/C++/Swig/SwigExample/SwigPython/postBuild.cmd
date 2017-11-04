set INPUT_DIR=%~1%
set OUTPUT_DIR=%~2%

echo postBuild.cmd: copy python generated scripts to output.

copy /y "%INPUT_DIR%SwigPython\example.py" "%OUTPUT_DIR%"
copy /y "%INPUT_DIR%x64\Release\_example.pyd" "%OUTPUT_DIR%"