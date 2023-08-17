#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<float.h>
#include<math.h>
#include<fenv.h>
#include<string.h>
#include"libaux.h"

float findLargest(float num)
{
    fesetround(FE_UPWARD);
    return num;
}


float findSmallest(float num)
{
    return nextafterf(num, -INFINITY);
}

/* Faz a soma de dois intervalos */
Range_t addRange(Range_t num1, Range_t num2)
{
    Range_t res;

    res.smallest = findSmallest(num1.smallest + num2.smallest);
    res.largest = findLargest(num1.largest + num2.largest);
    
    return res;
}

/* Faz a subtração de dois intervalos */
Range_t subtractRange(Range_t num1, Range_t num2)
{
    Range_t res;

    res.smallest = findSmallest(num1.smallest - num2.largest);
    res.largest = findLargest(num1.largest - num2.smallest);
    
    return res;
}

/* Faz a multiplicação de dois intervalos */
Range_t timeRange(Range_t num1, Range_t num2)
{
    Range_t res;
    
    float m1, m2, m3, m4;

    /* Faz as multiplicações dos intervalos */
    m1 = num1.smallest * num2.smallest;
    m2 = num1.smallest * num2.largest;
    m3 = num1.largest * num2.smallest;
    m4 = num1.largest * num2.largest;

    /* Encontra o smallest valor do intervalo */
    res.smallest = findSmallest(fminf(fminf(m1, m2), fminf(m3,m4)));
    /* Encontrar o largest valor do intervalo */
    res.largest = findLargest(fmaxf(fmaxf(m1, m2), fmaxf(m3,m4)));
    
    return res;
}

/* Inverte o range e faz a troca dos valores */
Range_t invertRange(Range_t num)
{
    Range_t res;
    
    res.smallest = 1 / num.largest;
    res.largest = 1 / num.smallest;
    
    return res;
}

/* Faz a divisão de dois intervalos */
Range_t divisionRange(Range_t num1, Range_t num2)
{
    Range_t res, aux;
    
    if((fabs(num2.smallest) == 0) || (fabs(num2.largest) == 0) )
    {

        res.largest = INFINITY;
        res.smallest = -INFINITY;
    }
    else
    {
        invertRange(aux);
        res = timeRange(num1, aux);
    }
    
    return res;
}

/* Conveter de Float para Int */
int32_t floatToInt(float f)
{
    int32_t i;
    memcpy(&i, &f, sizeof(float));
    return i;
} 

int32_t ulpsDistance(float smallest, float largest)
{
    int32_t a;
    int32_t b;

    /* Verificar se forem iguais retorna 0*/
    if(smallest == largest)
        return 0;

    /* Converte de float para int */
    a = floatToInt(smallest);
    b = floatToInt(largest);

    if((a < 0) != (b < 0));
    
    /* Faz a difenreça para verificar as ULPs */
    int32_t ulpsDiff = abs(a - b);
    
    return ulpsDiff;
}

/* Dado um numero float, cria um intervalo */
Range_t createRange(float num)
{
    Range_t range;

    if(fabs(num) == 0)
    {
        range.largest = +0;
        range.smallest = -0;
    }
    else
    {
        range.largest = findLargest(num);
        range.smallest = findSmallest(num);
    }

    return range;
}

/* Imprime o intervalo */
void printRange(Range_t range)
{
    printf("[%1.8e,%1.8e]", range.smallest, range.largest);
}

/* Imprime os calculos de EA, ER e ULPs */
void printResults(Range_t range)
{
    float erro;
    int ulps;

    erro = range.largest - range.smallest;
    printf("\nEA:%1.8e; ", erro);
    erro = erro / range.smallest;
    printf("ER:%1.8e; ", erro);
    ulps = ulpsDistance(range.smallest, range.largest);
    printf("ULPs: %d\n", ulps);
}