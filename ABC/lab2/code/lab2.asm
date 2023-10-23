 .686 ; Тип процессора
 .model flat, stdcall ; Модель памяти и стиль вызова подпрограмм
 option casemap: none ; Чувствительность к регистру
 ; --- Подключение файлов с кодом, макросами, константами, прототипами функций и т.д.
 include windows.inc
 include kernel32.inc
 include user32.inc
 include msvcrt.inc
 ; --- Подключаемые библиотеки ---
 includelib user32.lib
 includelib kernel32.lib
 includelib msvcrt.lib
.CODE
START:
	CMP ESP, 100 
	MOV BYTE PTR [EBP], 'Q'
	ADD AX, [ESI] 
	XOR [EBX*2+ECX+2], EDX 
	SUB CX, AX 
	push 0
	call ExitProcess
END START
