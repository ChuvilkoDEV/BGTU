del lab2.exe
ml /c /coff /I "d:\masm32\include" lab2.asm
link /SUBSYSTEM:CONSOLE /LIBPATH:d:\masm32\lib lab2.obj
pause
lab2.exe
pause
