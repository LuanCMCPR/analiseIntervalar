#include<stdio.h>
#include<stdint.h>

/* Reutilizamos a union do código apresentado em aula */
typedef union
{
    int32_t i;
    float f;
    struct
    {   // Bitfields for exploration (32 bits = sign|exponent|mantissa)
        uint32_t mantissa : 23; // primeiros 23 bits (da direita para a esquerda)
        uint32_t exponent : 8;  // próximos 8 bits
        uint32_t sign : 1;      // proximo bit (ou seja, o bit mais a esquerda)
    } parts;
} Float_t;

/* imprime a union Float_t como ponto flutuante, hexadecimal e 
 * suas partes na forma de inteiros */

// void printfloat( Float_t num )
// {
//     printf("f:%1.8e, ix:0x%08lX, s:%d, e:%d, mx:0x%06X\n",
//             num.f, num.i,num.parts.sign, num.parts.exponent, num.parts.mantissa
//           );
// } 

typedef struct range
{
    float smallest;
    float largest;
} Range_t;

/* Faz a soma de dois intervalos */
Range_t addRange(Range_t num1, Range_t num2);

/* Faz a subtração de dois intervalos */
Range_t subtractRange(Range_t num1, Range_t num2);

/* Retorna o menor numero em um intervalo de multiplicação */
float findMin(Range_t num1, Range_t num2);

/* Retorna o maior numero em um intervalo de multiplicação */
float findMax(Range_t num1, Range_t num2);

/* Faz a multiplicação de dois intervalos */
Range_t timeRange(Range_t num1, Range_t num2);

Range_t invertRange(Range_t num);

/* Faz a divisão de dois intervalos */
Range_t divisionRange(Range_t num1, Range_t num2);

int AlmostEqualUlps(float smallest, float largest);

/* Dado um numero float, cria um intervalo */
Range_t createRange(float num);
/* Imprime o intervalo */
void printRange(Range_t range);

/* Imprime os calculos de EA, ER e ULPs*/
void printResults(Range_t range);