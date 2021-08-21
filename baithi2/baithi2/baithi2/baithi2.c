#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdint.h>
typedef struct datareal
{
	char device[6];
	char status[4];
} real;

void main()
{
	FILE* px = fopen("data.txt", "a+");
	if (px != 0) printf("\t\t\t\tOpen file successful\r\n");
	else printf("Open file NOT successful\r\n");
	real line[3] = { 0 };
	char bientam[20] = { 0 };
	char k = 0;
	char l = 0;
	char m = 0;
	int32_t ss[3] = { ' ' };
	char* ssa = ss;
	for (int i = 0; i < 6; i++)
	{
		fgets(bientam, sizeof(bientam), px);
		for (int j = 0; j < 20; j++)
		{
			if (bientam[0] != '"')
				break;
			if (bientam[j + 1] == '"')
				k++;
			if (k == 0)
				line[l].device[j] = bientam[j + 1];
			if (k == 2)
			{
				if (bientam[j + 2] == '"')
					continue;
				line[l].status[m] = bientam[j + 2];
				m++;
			}
			if (k == 3)
			{
				l++;
				break;
			}

		}
		memset(bientam, 0, 20);
		m = 0;
		k = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			*(ssa + j + k) = line[i].status[j];
		}
		k += 4;
		printf(" Device: %s \t-\t-\t-\t-\r\n\t\t\t Status: %s\r\n\r\n", line[i].device, &ss[i]);
	}

	fclose(px);
}