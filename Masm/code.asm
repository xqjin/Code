; Calculate the 2*4 using add
;
;assume cs:code
;code segment
;	mov ax,0H
;	mov cx,2H
;addNum: add ax,4H
;	loop addNum
;	
;	mov ax,4c00H
;	int 21H
;code ends
;end


; sum the num from adress: FFFF:0~FFFF:F 
; Save the result in dx
; �ַ���ͷ�����ݣ�����ʹ��0��Ϊǰ׺��
;assume cs:code
;code segment
;
;	mov dx,0H
;	mov ax,0FFFFH; ��ʼ����ŵ�ַ�ĶμĴ���
;	mov ds,ax
;	
;	mov bx,0H;��ʼ����ŵ�ַ��ƫ�ƼĴ���
;
;	mov cx,10H;��ʼ��ѭ�������ļĴ���
;SumIt:
;	mov al,ds:[bx]
;	mov ah,0H
;	add dx,ax
;	inc bx

;	mov ax,4c00H
;	int 21H
;loop SumIt
;
;code ends
;end

; copy the data[FFFF:0~FFFF:F]  to  [0:200~0:20F]
; Method-one
;assume cs:code
;code segment

;	mov cx,10H
;	mov bx,0H
;copyData:
;	mov ax,0FFFFH
;	mov ds,ax
;	mov dl,ds:[bx]
	
;	mov ax,0020H
;	mov ds,ax
;	mov ds:[bx],dl
;	inc bx

;	loop copyData
	
;	mov ax,4c00H
;	int 21H
;code ends
;end


; copy the data[FFFF:0~FFFF:F]  to  [0:200~0:20F]
; Method-two
; Question: how to copy instruction;
; mov ax,cs  ; data from
; mov ds,ax

;assume cs:code
;code segment
;	mov cx,10H
;	mov bx,0H
	
;	mov ax,0FFFF; data from
;	mov ds,ax
	
;	mov ax,0020H; data to put
;	mov es,ax
;copyData:
;	mov dl,ds:[bx]
;	mov es:[bx],dl
;	inc bx
;	loop copyData
	
;	mov ax,4c00H
;	int 21H
;code ends
;end


; add the data:  0123H,1234H,2345H,4567H
; save the result into dx;
; ���ǿ����ڴ���ζ������ݣ����Ǳ�����ʾָ�������ִ��λ�ã�
;assume cs:code
;code segment
;dw	0123H,1234H,2345H,4567H; define the word data
;start:	
;	mov cx,4H
;	mov ax,cs
;	mov ds,ax
;	mov bx,0H
;addNum:
;	mov ax,ds:[bx]
;	add dx,ax
;	add bx,2H
;	loop addNum
;	mov ax,4c00H
;	int 21H
;code ends
;end start


;�ڴ�����У�ʹ��ջ�ռ䣬�����ݶ� �����ݷ�ת��
;0123H,1234H,2345H,4567H
;assume cs:code
;code segment
;dw 0123H,1234H,2345H,4567H; define the data segment
;dw 0000H,0H,0H,0H; define the stack segment
;dw 0H,0H,0H,0000H
;start:
;	mov ax,cs
;	mov ss,ax
;	mov sp,18H
;	
;	mov ax,cs
;	mov ds,ax
;	mov bx,0
;	
;	mov cx,4H
;pushData:
;	push ds:[bx]
;	add bx,2
;	loop pushData
;
;	mov cx,4H
;	mov bx,0H
;popData:
;	pop ds:[bx]
;	add bx,2
;	loop popData
;
;	mov ax,4c00H
;	int 21H
;code ends
;end start



; �������еĴ���Σ����ݶ� ��ջ�� �ֿ�д��
;assume cs:code, ss:stack, ds:data

;stack segment stack
;	dw 0H,0H,0H,0H; define the stack segment
;stack ends

;data segment
;	dw 0123H,1234H,2345H,4567H; define the data segment
;data ends

;code segment
;start:
	; initial stack data
;	mov ax, stack
;	mov ss,ax
;	mov sp,8H
	
;	mov ax,data
;	mov ds,ax
;	mov bx,0H
	
	; do something
	; do something
	; do something
	; do something
	
;	mov ax,4c00H
;	int 21H		
;code ends
;end start


; ��д���򣬽�a�μ�b�ε�ֵ������c��
; �Լ�ʵ�ֵ��е�agly
;
;assume cs:code

;a segment
;	db	1,2,3,4,5,6,7,8
;a ends

;b segment
;	db	1,2,3,4,5,6,7,8
;b ends

;c segment
;	db	0,0,0,0,0,0,0,0
;c ends

;code segment
;	start:
;		mov cx,8H
;		mov bx,0H
;	addIt:
;		mov ax,0H
;		
;		mov dx,a
;		mov ds,dx
;		add al,ds:[bx]
;		
;		mov dx,b
;		mov ds,dx
;		add al,ds:[bx]
;		
;		mov dx,c
;		mov es,dx
;		mov es:[bx],al
;		inc bx
;		loop addIt
;		
;		mov ax,4c00H
;		int 21H
;code ends
;end start


; �����ݶ��е�ÿ�����ʵ�ǰ�ĸ���ĸ��ɴ�д��
assume cs:code,ds:data,ss:stack
stack segment stack
	dw 0H,0H,0H,0H,0H,0H,0H,0H; define the stack segment
stack ends

data segment
	db '1. display      '
	db '2. display      '
	db '3. display      '
	db '4. display      '
data ends

code segment
start:
	;initial the stack
	mov ax,stack
	mov ss,ax
	mov sp,16
	
	mov ax,data
	mov ds,ax
	mov es,ax
	mov bx,0
	
	mov cx,4
	mov si,3
loopTop:
	push cx
	push si
	
	mov cx,4
	loopDown:
		mov al,ds:[bx+si]
		and al,11011111B
		mov es:[bx+si],al
		inc si
		loop loopDown 
	pop si
	pop cx
	add bx,16
	loop loopTop
	
	mov ax,4c00H
	int 21
code ends
end start