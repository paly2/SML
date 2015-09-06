#include <stdio.h>
#include <stdlib.h>
#include "SML.h"

int main(int argc, char *argv[]){
	char add[10] = "", sub[10] = "", mul[10] = "", div[10] = "";
	unsigned long long rest;
	
	sml_add("8556", "7368", add);
	printf("Add : %s\n", add);
	
	sml_sub("132", "23", sub);
	printf("Sub : %s\n", sub);
	
	sml_mul("748", "53", mul);
	printf("Mul : %s\n", mul);
	
	sml_div("759", 21, div, &rest);
	printf("Div : %s Rest : %d\n", div, rest);
}
