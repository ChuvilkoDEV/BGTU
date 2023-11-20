.686           ; Тип процессора
.MODEL FLAT, STDCALL ; Модель памяти и стиль вызова подпрограмм
OPTION CASEMAP:NONE ; Чувствительность к регистру

INCLUDE windows.inc
INCLUDE kernel32.inc
INCLUDE user32.inc
INCLUDE msvcrt.inc

.DATA
    f DW ?
    g DD ?
    h DB ?
    result DD 0
    fmtDD db "%d", 0
    fmtDW db "%hd", 0
    fmtDB db "%hhd", 0
	fmtOut db "%hd * %d + %hd / (10^6 * %hhd) - %d^3 / %hhd^2 = %d", 0

.CODE
START:
	; lea eax, x = mov eax, offset x; offset - адрес x

    lea eax, f
    push eax
    lea eax, fmtDD
    push eax
    call crt_scanf
    add esp, 2*4
	
	lea eax, g
    push eax
    lea eax, fmtDW
    push eax
    call crt_scanf
    add esp, 2*4
	
	lea eax, h
    push eax
    lea eax, fmtDB
    push eax
    call crt_scanf
    add esp, 2*4

    ; f * g
    MOV AX, f
    CWDE
    IMUL EAX, g
    MOV result, EAX

    ; (f * g) / (10^6 * h)
    MOV EAX, 1000000
    IMUL h
	CBW
	CWDE
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

 ; (f * g) / (10^6 * h) - f^3 / h^2
    ; Вывод результата
    movzx eax, dword ptr [f]
    push eax
    movzx eax, g
    push eax
    movzx eax, f
    push eax
    movzx eax, h
    push eax
    movzx eax, g
    push eax
    movzx eax, h
    push eax
	movzx eax, result
    push eax
    lea eax, fmtOut
    push eax
    call crt_printf
    add esp, 8*4

    ; Exit the program
    PUSH 0
    CALL ExitProcess

END START
