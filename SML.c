#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sml_add(const char *op1, const char *op2, char *dest){
	int len_op1 = strlen(op1), len_op2 = strlen(op2);
	int i, f_de = 0;
	int dif;
	
	
	
	if(op1[0] + op2[0] - 48 > '9'){ // If there is more numbers in the destination string than others strings
		f_de = 1;
		dest[0] = '0';
	}
	
	
	// Calculate
	if(len_op1 <= len_op2){
		dif = len_op2 - len_op1;
		for(i = 0 ; i < dif ; i++){
			dest[i+f_de] = op2[i];
			if(dest[i+f_de] > '9'){
				dest[i+f_de]-=10;
				dest[i+f_de-1]++;
			}
		}
		for(i = 0 ; i < len_op1 ; i++){
			dest[i+f_de+dif] = op1[i] + op2[i+dif] - 48;
			if(dest[i+f_de+dif] > '9'){
				dest[i+f_de+dif]-=10;
				dest[i+f_de+dif-1]++;
			}
		}
		dest[i+dif+1] = '\0';
	}
	else{
		dif = len_op1 - len_op2;
		for(i = 0 ; i < dif ; i++){
			dest[i+f_de] = op1[i];
			if(dest[i+f_de] > '9'){
				dest[i+f_de]-=10;
				dest[i+f_de-1]++;
			}
		}
		for(i = 0 ; i < len_op2 ; i++){
			dest[i+f_de+dif] = op2[i] + op1[i+dif] - 48;
			if(dest[i+f_de+dif] > '9'){
				dest[i+f_de+dif]-=10;
				dest[i+f_de+dif-1]++;
			}
		}
		dest[i+dif+1] = '\0';
	}
	
	return EXIT_SUCCESS;
}



int sml_sub(const char *op1, const char *op2, char *dest){
	int len_op1 = strlen(op1), len_op2 = strlen(op2);
	int i;
	int dif;
	
	
	// Calculate
	if(len_op1 <= len_op2){
		dif = len_op2 - len_op1;
		for(i = 0 ; i < dif ; i++){
			dest[i] = op2[i];
			if(dest[i] < '0'){
				dest[i]+=10;
				dest[i-1]--;
			}
		}
		for(i = 0 ; i < len_op1 ; i++){
			dest[i+dif] = op1[i] - op2[i+dif] + 48;
			if(dest[i+dif] < '0'){
				dest[i+dif]+=10;
				dest[i+dif-1]--;
			}
		}
		dest[i] = '\0';
	}
	else{
		dif = len_op1 - len_op2;
		for(i = 0 ; i < dif ; i++){
			dest[i] = op1[i];
			if(dest[i] < '0'){
				dest[i]+=10;
				dest[i-1]--;
			}
		}
		for(i = 0 ; i < len_op2 ; i++){
			dest[i+dif] = op1[i+dif] - op2[i] + 48;
			if(dest[i+dif] < '0'){
				dest[i+dif]+=10;
				dest[i+dif-1]--;
			}
		}
		dest[i+dif] = '\0';
	}
	
	return EXIT_SUCCESS;
}


int sml_mul(const char *op1, const char *op2, char *dest){
	int len_op1 = strlen(op1), len_op2 = strlen(op2);
	int i1, i2;
	int f_de = len_op2 - 1;
	
	for(i1 = 0 ; i1 < f_de+1+len_op1 ; i1++){
		dest[i1] = '0';
	}
	
	for(i2 = len_op2-1 ; i2 >= 0 ; i2--){
		for(i1 = 0 ; i1 < len_op1 ; i1++){
			dest[i1+1+f_de] += (op2[i2]-48)*(op1[i1]-48);
			if(dest[i1+1+f_de] > '9'){
				dest[i1+f_de]+=((dest[i1+1+f_de]-48)/10);
				dest[i1+1+f_de]=((dest[i1+1+f_de]-48)%10)+48;
			}
		}
		f_de--;
	}
	return EXIT_SUCCESS;
}


int sml_div(const char *op1, const unsigned long long op2, char *dest, unsigned long long *rest){
	int len_op1 = strlen(op1);
	unsigned long long int_number = 0;
	int i1, i2 = 0;
	
	// Find the first number to divise
	for(i1 = 0 ; i1 < len_op1 ; i1++){
		int_number *= (i1*10);
		int_number += (op1[i1]-48);
		if(int_number >= op2)
			break;
	}
	if(i1 == len_op1)
		return EXIT_FAILURE;
	
	
	// Calculate
	for(i1+=1; i1 < len_op1 ; i1++){
		dest[i2] = int_number/op2+48;
		int_number %= op2;
		int_number *= 10;
		int_number += (op1[i1]-48);
		i2++;
	}
	dest[i2] = int_number/op2+48;
	int_number %= op2;
	*rest = int_number;
	
	return EXIT_SUCCESS;
}
