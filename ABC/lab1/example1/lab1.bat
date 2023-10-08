del lab1.exe
ml /c /coff /I "d:\masm32\include" lab1.asm
link /SUBSYSTEM:CONSOLE /LIBPATH:d:\masm32\lib lab1.obj
pause
lab1.exe
pause
