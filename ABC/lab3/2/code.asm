.686           ; ��� ����������
.MODEL FLAT, STDCALL ; ������ ������ � ����� ������ �����������
OPTION CASEMAP:NONE ; ���������������� � ��������

INCLUDE C:\masm32\include\kernel32.inc
INCLUDELIB C:\masm32\lib\kernel32.lib

.DATA
    a db 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h, 05h  ; 16 ���� 
    b db 02h, 01h, 03h, 01h, 05h, 06h, 0h, 02h, 01h, 00h, 05h, 05h, 05h, 05h, 02h, 01h  ; 16 ����
    r db 16 dup(?) 
.CODE
START:
    CLC
    MOV ECX, 0

    ; ������ �����
    L1:
        MOV AL, [a + ECX]
        MOV BL, [b + ECX]
        SBB AL, BL
        MOV [r + ECX], AL
        INC ECX

        ; ������� ���������� �����
        CMP ECX, 16
        JL L1

    ; ��������� ���������
    PUSH 0
    CALL ExitProcess

END START
