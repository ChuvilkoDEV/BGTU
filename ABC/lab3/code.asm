.686           ; Тип процессора
.MODEL FLAT, STDCALL ; Модель памяти и стиль вызова подпрограмм
OPTION CASEMAP:NONE ; Чувствительность к регистру

INCLUDE windows.inc
INCLUDE kernel32.inc
INCLUDE user32.inc
INCLUDE msvcrt.inc

.DATA
    f DW -5
    g DD 1000
    h DB 2
    result DD 0

.CODE
START:
    ; f * g
    MOV AX, f
    CWDE
    IMUL EAX, g
    MOV result, EAX

    ; (f * g) / (10^6 * h)
    MOV EAX, 1000000
    IMUL h
    CDQ   
    IDIV result
    MOV result, EAX

    ; f^3 / h^2
    MOV AX, f
    CWDE
    IMUL f
    IMUL f
    MOVZX ECX, h
    CDQ
    IDIV ECX
	CDQ
    IDIV ECX

    ; (f * g) / (10^6 * h) - f^3 / h^2
    SUB result, EAX
	
	mov EAX, result

    ; Exit the program
    PUSH 0
    CALL ExitProcess

END START