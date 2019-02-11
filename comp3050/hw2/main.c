/*****************************************************************/
/*  Assign 2*/
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef union float_32{
        float   floating_value_in_32_bits;
        int     arg_32;
        struct  sign_exp_mantissa{
                unsigned  mantissa:23;
                unsigned  exponent:8;
                unsigned      sign:1;
        } f_bits;
	struct single_bits{
		unsigned  b0 :1;
		unsigned  b1 :1;
		unsigned  b2 :1;
		unsigned  b3 :1;
		unsigned  b4 :1;
		unsigned  b5 :1;
		unsigned  b6 :1;
		unsigned  b7 :1;
		unsigned  b8 :1;
		unsigned  b9 :1;
		unsigned  b10:1;
		unsigned  b11:1;
		unsigned  b12:1;
		unsigned  b13:1;
		unsigned  b14:1;
		unsigned  b15:1;
		unsigned  b16:1;
		unsigned  b17:1;
		unsigned  b18:1;
		unsigned  b19:1;
		unsigned  b20:1;
		unsigned  b21:1;
		unsigned  b22:1;
		unsigned  b23:1;
		unsigned  b24:1;
		unsigned  b25:1;
		unsigned  b26:1;
		unsigned  b27:1;
		unsigned  b28:1;
		unsigned  b29:1;
		unsigned  b30:1;
		unsigned  b31:1;
	}bit;
	struct bit_array{
		unsigned bit[32];
	}bit2;
} FLOAT_32;
//wrapper functions to more easily get data from the struct
int getManta(FLOAT_32 my_float){
	return my_float.f_bits.mantissa;
}
int getExponent(FLOAT_32 my_float){
	return my_float.f_bits.exponent;
}
int getSign(FLOAT_32 my_float){
	return my_float.f_bits.sign;
}
float getFloat(FLOAT_32 my_float){
	return my_float.floating_value_in_32_bits;
}



// A function to print out bits from a 32 bit container
// provided by the union FLOAT_UN above, and using 
// a text string as a label for the bit string
// as passed in the second argument

int print_bits(FLOAT_32 float_32, char * text){
	char bit_string[43];
	int i,j;

	for(i=0; i<42; i++){
		bit_string[i] = ' ';
	}
	bit_string[42] = '\0';

bit_string[0] = float_32.bit.b31?'1':'0';

bit_string[2] = float_32.bit.b30?'1':'0';
bit_string[3] = float_32.bit.b29?'1':'0';
bit_string[4] = float_32.bit.b28?'1':'0';
bit_string[5] = float_32.bit.b27?'1':'0';

bit_string[7] = float_32.bit.b26?'1':'0';
bit_string[8] = float_32.bit.b25?'1':'0';
bit_string[9] = float_32.bit.b24?'1':'0';
bit_string[10] = float_32.bit.b23?'1':'0';

bit_string[12] = float_32.bit.b22?'1':'0';
bit_string[13] = float_32.bit.b21?'1':'0';
bit_string[14] = float_32.bit.b20?'1':'0';

bit_string[16] = float_32.bit.b19?'1':'0';
bit_string[17] = float_32.bit.b18?'1':'0';
bit_string[18] = float_32.bit.b17?'1':'0';
bit_string[19] = float_32.bit.b16?'1':'0';

bit_string[21] = float_32.bit.b15?'1':'0';
bit_string[22] = float_32.bit.b14?'1':'0';
bit_string[23] = float_32.bit.b13?'1':'0';
bit_string[24] = float_32.bit.b12?'1':'0';

bit_string[26] = float_32.bit.b11?'1':'0';
bit_string[27] = float_32.bit.b10?'1':'0';
bit_string[28] = float_32.bit.b9?'1':'0';
bit_string[29] = float_32.bit.b8?'1':'0';

bit_string[31] = float_32.bit.b7?'1':'0';
bit_string[32] = float_32.bit.b6?'1':'0';
bit_string[33] = float_32.bit.b5?'1':'0';
bit_string[34] = float_32.bit.b4?'1':'0';

bit_string[36] = float_32.bit.b3?'1':'0';
bit_string[37] = float_32.bit.b2?'1':'0';
bit_string[38] = float_32.bit.b1?'1':'0';
bit_string[39] = float_32.bit.b0?'1':'0';

printf("%23s  %s\n",text, bit_string);
return 0;
}










int main(int argc, char * argv[])
{
for (int count = 0; count < 10; ++count){
FLOAT_32 float_32_s1, float_32_s2, float_32_rslt, fun_arg;

/**local helper variables**/

float	the_hardware_result;
int	mant_s1, mant_s2, mant_res, exp_s1, exp_s2;
int	i, j, k, shift_count;
int 	s1_normalized, s2_normalized;
/* Request two FP numbers */

printf("please enter your first floating point number and new-line: ");
scanf("%g", &float_32_s1.floating_value_in_32_bits);

printf("please enter your second floating point number and new-line: ");
scanf("%g", &float_32_s2.floating_value_in_32_bits);

/* generate floating point hardware result */
the_hardware_result =  getFloat(float_32_s1) + getFloat(float_32_s2);
printf("According to the hardware, %f + %f = %f\n", getFloat(float_32_s1), getFloat(float_32_s2), the_hardware_result);

/* Get the mantissa and exponent components */
/*   into the helper variables */

mant_s1 = float_32_s1.f_bits.mantissa;
mant_s2 = float_32_s2.f_bits.mantissa;
exp_s1  = float_32_s1.f_bits.exponent;
exp_s2  = float_32_s2.f_bits.exponent;

/** check for normalization and slam in the **/
/** hidden bit if normalized **/
s1_normalized = (exp_s1);
s1_normalized = (exp_s2);
if (s1_normalized){
	mant_s1 += 1 << 23;
}
if (s2_normalized){
	mant_s2 += 1 << 23;
}
/** The rest is left to you */




int exponent;
unsigned *mantissa = (unsigned*)malloc(32);
//if normalized, remove the bias
if(s1_normalized){
	exp_s1 -=127;
}
if(s2_normalized){
	exp_s2 -=127;
}

//find the larger exp and shift mantissa accordingly
if (exp_s1 > exp_s2){
	exponent = exp_s1 - exp_s2;
	mant_s2 = mant_s1 >> exponent;
	exponent = exp_s1;
}
else if (exp_s2 > exp_s1){
	exponent = exp_s2 - exp_s1;
	mant_s1 = mant_s1 >> exponent;
	exponent = exp_s1;
}
//now that everything is adjusted, the mantissa can be added together
*mantissa = mant_s1 + mant_s2;


unsigned *mask = (unsigned*)malloc(32);

//put the mantissa in the result
int position = 0;
*mask = 1;
for (i =0; i < 128; ++i){
	if(*mask & *mantissa){
		position = i;
	}
	*mask = (*mask) << 1;
}
*mask = 0xEFFFFF;
/*if (position > 22){
	int i = 0;
	while (i < 103){
		*mask = (*mask) << 1;
		i ++;
	}
	if (!s1_normalized && !s2_normalized){
		*mask = (*mask) << 1;
	}


}*/
/*for (int i = 0; i < 103; ++i){//getting the mask ready
	*mask = (*mask) << 1;
}
if (!s1_normalized && !s2_normalized){
	*mask = (*mask) << 1;
}*/





float_32_rslt.f_bits.mantissa = (*mantissa) & (*mask);

//exponent result getting
*mask = 0xFF;
if (s1_normalized || s2_normalized){//re-adding the bias
exponent +=127;
}
float_32_rslt.f_bits.exponent = exponent & (*mask);

//making the sign be positive
float_32_rslt.f_bits.sign = 0;

//print the result
printf("According to this program, %f + %f = %f\n\n\n\n", getFloat(float_32_s1), getFloat(float_32_s2), float_32_rslt.floating_value_in_32_bits);

free(mantissa);
free(mask);

}
}



















