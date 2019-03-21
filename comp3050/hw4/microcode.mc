0:mar := pc; rd; 
1:pc := 1 + pc; rd; 
2:ir := mbr; if n then goto 28; 
3:tir := lshift(ir + ir); if n then goto 19; 
4:tir := lshift(tir); if n then goto 11; 
5:alu := tir; if n then goto 9; 
6:mar := ir; rd; 
7:rd; 
8:ac := mbr; goto 0; 
9:mar := ir; mbr := ac; wr; 
10:wr; goto 0; 
11:alu := tir; if n then goto 15; 
12:mar := ir; rd; 
13:rd; 
14:ac := ac + mbr; goto 0; 
15:mar := ir; rd; 
16:ac := 1 + ac; rd; 
17:a := inv(mbr); 
18:ac := a + ac; goto 0; 
19:tir := lshift(tir); if n then goto 25; 
20:alu := tir; if n then goto 23; 
21:alu := ac; if n then goto 0; 
22:pc := band(ir, amask); goto 0; 
23:alu := ac; if z then goto 22; 
24:goto 0; 
25:alu := tir; if n then goto 27; 
26:pc := band(ir, amask); goto 0; 
27:ac := band(ir, amask); goto 0; 
28:tir := lshift(ir + ir); if n then goto 40; 
29:tir := lshift(tir); if n then goto 35; 
30:alu := tir; if n then goto 33; 
31:a := sp + ir; 
32:mar := a; rd; goto 7; 
33:a := sp + ir; 
34:mar := a; mbr := ac; wr; goto 10; 
35:alu := tir; if n then goto 38; 
36:a := sp + ir; 
37:mar := a; rd; goto 13; 
38:a := sp + ir; 
39:mar := a; rd; goto 16; 
40:tir := lshift(tir); if n then goto 46; 
41:alu := tir; if n then goto 44; 
42:alu := ac; if n then goto 22; 
43:goto 0; 
44:alu := ac; if z then goto 0; 
45:pc := band(ir, amask); goto 0; 
46:tir := lshift(tir); if n then goto 50; 
47:sp := sp + (-1); 
48:mar := sp; mbr := pc; wr; 
49:pc := band(ir, amask); wr; goto 0; 
50:tir := lshift(tir); if n then goto 65; 
51:tir := lshift(tir); if n then goto 59; 
52:alu := tir; if n then goto 56; 
53:mar := ac; rd; 
54:sp := sp + (-1); rd; 
55:mar := sp; wr; goto 10; 
56:mar := sp; sp := sp + 1; rd; 
57:rd; 
58:mar := ac; wr; goto 10; 
59:alu := tir; if n then goto 62; 
60:sp := sp + (-1); 
61:mar := sp; mbr := ac; wr; goto 10; 
62:mar := sp; sp := sp + 1; rd; 
63:rd; 
64:ac := mbr; goto 0; 
65:tir := lshift(tir); if n then goto 73; 
66:alu := tir; if n then goto 70; 
67:mar := sp; sp := sp + 1; rd; 
68:rd; 
69:pc := mbr; goto 0; 
70:a := ac; 
71:ac := sp; 
72:sp := a; goto 0; 
73:alu := tir; if n then goto 76; 
74:a := band(ir, smask); 
75:sp := sp + a; goto 0; 
76:tir := tir + tir; if n then goto 80; {if 11111111 goto 80}
77:a := band(ir, smask); 
78:a := inv(a); 
79:a := a + 1; goto 75; 
80:tir := tir + tir; if n then goto 91;{if 111111111x goto 91}
81:tir := tir + tir; if n then goto 200;{if 1111111101 goto 200}
82:a := lshift(1);{RSHIFT=1111111100}
83:a := lshift(a + 1);
84:a := lshift(a + 1);
85:a := a + 1;
86:b := band(ir, a);
87:b := b + (-1); if n then goto 89;
88:ac := rshift(ac); goto 87;
89:goto 0;
91:tir := tir + tir; if n then goto 255;{if 1111111111}
92:mar := sp; rd;{DIV=1111111110}
93:rd; a := mbr; {get the dividend}
94:mar := sp + 1; rd;
95:rd; b := mbr; {get the divisor}
96:b := b; if z then goto 183; {if divisor 0 then goto 183}
97:c: = 0 {c is our negative flag}
98:a: = a; if n then goto 100;
99:goto 103;
100:c := c + 1;{if dividend negative}
101:a := inv(a); {set a to its absolute value}
102:a := a + 1;
103:b := b; if n then goto 105;
104:goto 108;
105:c := c + (-1); {if both negative or both positive then c is zero}
106:b := inv(b); {set b to its absolute value}
107:b := b + 1; {if abs(divisor) > abs(dividend) goto 185}
108:d := inv(b);
109:d := d + 1;
110:d := d + a; if n then goto 185; {now that these edge cases are handled we can begin dividing}
111:d := a;
112:e := inv(b);
113:e := e + 1;
114:f := 0;
115:f := f + 1;
116:a := a + e; if n then goto 118;
117:goto 115;
118:f := f + (-1); 
119:a := a + b;
120:c := c; if n then goto 122;
121:if n then goto 126;
122:a := inv(a);
123:a := a + 1;
124:b := inv(f);
125:b := b + 1; goto 190;
126:b := f; goto 190;
183:a := (-1); {case divisor 0, remainder = -1}
184:b := 0; goto 190; {quotient = 0}
185:c := c; if n then goto 189; {case divisor > dividend}
186:if z then goto 189;
187:b := inv(a);
188:b := b + 1;
189:a := 0; goto 190; 
190:ac := sp + (-1); {Division Finalization and Return}
191:mar := ac; mbr := a; wr;{push remainder}
192:ac := ac + (-1); wr;
193:mar := ac; mbr := b; wr; {push quotient}
194:ac:= a + 1; wr; if z then goto 196; {if invalid set ac to -1, else set ac to 0}
195:ac: = 0; goto 0;
196:ac: = (-1); goto 0;





200:a := rshift(smask);{MULT=1111111101}
201:a := rshift(a); mar := sp; rd;{get mask 000000111111, also set mar to sp, begn the read}
202:a := band(ir, a);  rd; {a is now the number to multiply with. continue the read}
203:b := mbr; {now we need to find the result of a*b}
204:c := a;
205:d := 0;
206:d := d + a;
207:c := c + (-1); if z then goto  209;
208:goto 206;{now that result finished we can check for overflow}
208:a := a; if n then goto 220;{if one negative goto 220}
209:b := b; if n then goto 230;{if 1 negative go to neg case 230}
210:d := d; if n then goto 240;
211:ac := (-1); goto 0;{failure case}
220:b := b; if n then goto 210;{if 2 negative go to pos case 210}
221:d := d; if n then goto 240;
222:ac := (-1); goto 0;{failure case}
240:mbr := d; wr;   {do stuff if valid}
241:ac := 0; wr; goto 0;
255:rd; wr; {HALT = 1111111111}
