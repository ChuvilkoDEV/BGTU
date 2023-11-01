 .386 ; Тип процессора
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
 ; --- Сегмент данных ---
 .data 
	;ente DB 13, 10, 0
	;a DW 5
	;b DW 5
	;result DD ?
	;p DF 17.5
	;ten DT 15.5
	
	nam db "name", 	9, "size", 9, "type", 13, 10, 0 
	ente db "ente", 	9, "3", 9, "DB", 13, 10, 0
	a db "a", 	9, "2", 9, "DW", 13, 10, 0
	b db "b", 	9, "2", 9, "DW", 13, 10, 0
	result db "result", 	9, "4", 9, "DD", 13, 10, 0
	p db "p", 	9, "6", 9, "DF", 13, 10, 0
	ten db "ten", 	9, "10", 9, "DT", 13, 10, 0
 ; --- Сегмент кода ---
 .code
 start:
	push offset nam
	call crt_printf
	push offset ente
	call crt_printf
	push offset a
	call crt_printf
	push offset b
	call crt_printf
	push offset result
	call crt_printf
	push offset p
	call crt_printf
	push offset ten
	call crt_printf
  	push NULL
  	call ExitProcess ; Выход из программы
 end start
