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
 .DATA
	stre DB 8 dup(-3), "int", 0
	a DD 2840930783
	b DD 0A8794E3Ah
	x DW 16, 17, 2000, -2000
	t DD 4.0, 5.0, -1.0
	dop DF 5 DUP(65530)
.CODE

START:
	; ���������� ������
	MOV EAX, a
	MOV ECX, b
	MUL ECX
	SUB EAX, 'A'
	MOV dword ptr stre, EAX
	MOV dword ptr stre[4], EDX
END START

