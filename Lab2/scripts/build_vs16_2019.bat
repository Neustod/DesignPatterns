@echo off
cd ../
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -S ../ -B ./
pause