.686           ; Тип процессора
.MODEL FLAT, STDCALL ; Модель памяти и стиль вызова подпрограмм
OPTION CASEMAP:NONE ; Чувствительность к регистру

INCLUDE C:\masm32\include\kernel32.inc
INCLUDELIB C:\masm32\lib\kernel32.lib

.DATA
    a db 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h  ; 16 байт 
    b db 02h, 01h, 03h, 01h, 05h, 06h, 0h, 02h, 01h, 00h, 05h, 05h, 05h, 05h, 02h, 01h  ; 16 байт
    r db 16 dup(?) 
.CODE
START:
    CLC
    MOV ECX, 0

    ; Начало цикла
    L1:
        MOV AL, [a + ECX]
        MOV BL, [b + ECX]
        SBB AL, BL
        MOV [r + ECX], AL
        INC ECX

        ; Условие завершения цикла
        CMP ECX, 16
        JL L1

    ; Завершаем программу
    PUSH 0
    CALL ExitProcess

END START
