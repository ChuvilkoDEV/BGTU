 .686 ; ��� ����������
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
ente DB 13, 10, 0
a DW 5
b DW 5
result DD ?
p DF 17.5
ten DT 15.5
.CODE
START:
	XOR CX, CX
	MOV CX, b
	XOR AX, AX
	MOV AX, a
	MUL CX
	MOV result, EAX
	push 0
	call ExitProcess
END START
