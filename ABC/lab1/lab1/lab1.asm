 .386 ; ��� ����������
 .model flat, stdcall ; ������ ������ � ����� ������ �����������
 option casemap: none ; ���������������� � ��������
 ; --- ����������� ������ � �����, ���������, �����������, ����������� ������� � �.�.
 include windows.inc
 include kernel32.inc
 include user32.inc
 include msvcrt.inc
 ; --- ������������ ���������� ---
 includelib user32.lib
 includelib kernel32.lib
 includelib msvcrt.lib
 ; --- ������� ������ ---
 .data 
	caption db "lab1", 0
	db "hello", 0
	str1 DB "MASM32", 0
	DB 250, 251, 252, 254
	a DW 500
	b DW 2
	c1 DW 250
	c2 DD 255*255*255*255, 100000
	c3 DD 0FFh, 0001FFFAh, 11223344h 
	float1 DD 13.5
	float2 DD 26.5
	double1 dq 11.01
	dmas DQ 5 DUP (5)
	message db "Hello World!", 0
	format 	db "str1", 	9, "%p", 9, "%p", 13, 10, 0
		db "a", 	9, "%p", 9, "%p", 13, 10
		db "b", 0
 ; --- ������� ���� ---
 .code
 start:
	; printf("str1\t%p\t%p", str1, str1 + 6)
	push (offset a - 1) 	; str1 + 6 - ����� ����� ������
 	push offset str1	; str1 - ����� ������ ������
	push offset format	; "str1\t%p\t%p" - ������ �������
	call crt_printf		; ����� ������������ 
	; ������� �����
	add esp, 3*4	; 3 ���������, ������ �������� 4 ����� 
	
	push 0			; ��� ����
	push offset caption	; ���������
	push offset message	; ���������
	push 0			; ���������� ����
	call MessageBoxA	
	
	push offset message
	call crt_puts
	add esp, 4
	call crt__getch
  	push NULL
  	call ExitProcess ; ����� �� ���������
 end start
