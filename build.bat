RMDIR /Q /S build > nul 2>&1 
MKDIR build > nul 2>&1 
CD build

cmake .. -T host=x86 -A Win32 -DCMAKE_INSTALL_PREFIX="%LocalAppData%" -DENABLE_TESTS=OFF
cmake.exe --build . --target INSTALL --config Release

CD ..