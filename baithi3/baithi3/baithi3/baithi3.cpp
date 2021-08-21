#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>
class ptr
{
private:
    float x1;
    float x2;
public:
    void giai(float k, float l, float m)
    {
        float delta = l * l - 4 * k * m;
        if (delta < 0)
        {
            printf("non exist x1 x2");
        }
        else if (delta == 0)
        {
            x1 = x2 = -l / (2 * k);
            printf("x1= %.2f and x2= %.2f", x1, x2);
        }
        else
        {
            delta = sqrt(delta);
            x1 = (-l + delta) / (2 * k);
            x2 = (-l - delta) / (2 * k);
            printf("x1= %.2f and x2= %.2f", x1, x2);
        }

    }
};

int main()
{
    ptr thu1;
    float a = 0;
    float b = 0;
    float c = 0;
    printf("AX^2 +BX +C =0; enter A B C to solve: \r\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    thu1.giai(a, b, c);
    return 0;
}