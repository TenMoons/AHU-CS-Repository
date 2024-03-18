;  TWOBALL.ASM这个演示程序使两个小灯按照一定的频率和顺序循环点亮。
;  两个小灯先循环左移一位，然后再循环右移一位。

init_val        equ     3Fh     ; 初始化显示值,发光二极管低电平有效.
                                ; 3F说明最后两个灯亮
dsply_port	equ	90h	; P1口地址

	org	0000h
init:   ljmp    tball

	org	0100h            ;开始主程序
tball:  
	mov     a, #init_val     ; 送入初始化显示的数值
        mov     r3, #06h         ; 移位计数值

lup1:   mov     dsply_port, a    ; A中数值显示

	mov	r0, #00h	 
	mov	r1, #00h
	mov	r2, #02h
	acall	dly		 ; 调用延时程序

	rr	a		; 循环右移一位
        dec     r3               
        cjne    r3, #00h, lup1  ; 计数器减一

        mov     r3, #06h
	
lup2:   mov     dsply_port, a   ; A中数值显示

	mov	r0, #00h	
	mov	r1, #00h
	mov	r2, #02h
	acall	dly		; 调用延时程序

	rl	a		; 循环左移一位
        dec     r3              
        cjne    r3, #00h, lup2  ; 计数器减一
 
        ajmp    tball            ;循环


dly:	dec	r0		; 延时子程序，定义显示频率
	nop
	nop
	cjne	r0, #00h, dly
	dec	r1
	nop
	nop
	cjne	r1, #00h, dly
	dec	r2
	nop
	nop
	cjne	r2, #00h, dly
	ret

	end
