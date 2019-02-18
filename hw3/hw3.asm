INIT: JUMP MAIN:
-1
num1: 0
num2: 0
FIBADDRESS: 0
data: d0:						;int data[] = {3,9,18,23,25}
d0:	0 	
	1	
	2	
	3	
	4	
	5
	6
	7
	8
	9
	10
	11
	12
	13
	14
	15
	16
	17
	18
	19
	20
results: f0:					;int results[] = {0,0,0,0,0}
f0: 0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
	0
FIBZER: LODD c0:				;return 0
RETN
FIBONE: LODD c1:				;return 1
RETN
c0:	0
c1:	1
DONE:	halt
temp: 0
retnAddress: 0
PasCount: 15
nData: size:
size: 0
-1
-1
-1
-1
-1
-1
-1
-1
MAIN:	LODD PasCount:			;while (PasCount != 0)
		JZER DONE:				
		SUBD c1:				;--PasCount
		STOD PasCount:			
		LODD data:				;int x =   data[size]
		ADDD size:
		PSHI
		CALL FIB:				;results[nData] = fib(x)
		STOD temp:
		LODD results:
		ADDD size:
		STOD FIBADDRESS:
		LODD temp:
		PUSH
		LODD FIBADDRESS:
		POPI
		LODD size:				;++nData
		ADDD c1:
		STOD size:
		POP
		JUMP MAIN:
		-1			;2045:	-1
		-1			;2046:	-1
		-1			;2047:	retn
		-1			;2048:	num
		-1			;bottom of stack	
FIB:	POP					;save returnAddress
		STOD retnAddress:
		POP					;int temp = num
		STOD temp:
		PUSH
		LODD retnAddress:	;push returnAddress
		PUSH
		LODD temp:		
		JZER FIBZER:		;if (num == 0) return 0
		SUBD c1:			;if (num == 1) return 1
		JZER FIBONE:		;
		PUSH				;num1 = fib(n-1)
		call FIB:			
		STOD num1:
		POP					;num2 = fib(n-2)
		SUBD c1:			;
		STOD temp:			;push temp,num1
		LODD num1:			;
		PUSH				;
		LODD temp:			;
		PUSH				;
		call FIB:			;
		STOD num2:			;
		POP					;
		LODD num2:			;
		ADDD num1:			;return num1 + num2
		STOD num1:
		LODD c1:
		INSP 1
		LODD num1:
		RETN
-1	
-1	
