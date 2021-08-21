#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdint.h>
//bai1

void func(int16_t k)
{
	int8_t low = 0;
	int8_t high = 0;
	int8_t* diachiLow;
	diachiLow = &k;
	low = *diachiLow;
	high = *(diachiLow + 1);

	printf("high: 0x%x, low: 0x%x \r\n", high, low);
}
void main()
{
	int q = 0;
	scanf("%d", &q);
	int16_t a = (int16_t)q;
	func(a);

}


