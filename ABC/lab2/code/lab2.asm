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
