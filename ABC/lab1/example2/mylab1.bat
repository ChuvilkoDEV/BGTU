del mylab1.exe
ml /c /coff /I "d:\masm32\include" mylab1.asm
link /SUBSYSTEM:CONSOLE /LIBPATH:d:\masm32\lib mylab1.obj
pause
mylab1.exe
pause
