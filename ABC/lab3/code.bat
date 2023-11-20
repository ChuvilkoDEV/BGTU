del code.exe
ml /c /coff /I "d:\masm32\include" code.asm
LINK /SUBSYSTEM:CONSOLE /LIBPATH:d:\masm32\lib code.obj kernel32.lib msvcrt.lib
pause
code.exe
pause
