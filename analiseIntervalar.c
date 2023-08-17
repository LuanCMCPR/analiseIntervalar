/*
 * source: https://randomascii.wordpress.com/2012/01/11/tricks-with-the-floating-point-format/
 * Descrição: Programa para explorar as operação de analise intervalar de uma expressão
 * Autores: Luan Carlos Maia Cruz e Leonardo Marin
 * Data: 13/08/2023
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<float.h>
#include<math.h>
#include<fenv.h>
#include<string.h>
#include"libaux.h"

int main()
{
 
    float num,n1, n2, n3, n4, n5;
    Range_t r2, r1, res;
    // char op[4];
    // float n[5];

    // /* Le a expressao */
    // printf("Digite a expressao: ");
    // scanf("%f %c %f %c %f %c %f %c %f",
    //        &n[0], &op[0], &n[1], &op[1], 
    //        &n[2], &op[2], &n[3], &op[3], &n[4]);
    
    // /* Cria os dois primeiros intervalos */
    // num.f = n[0];
    // r1 = createRange(num);
    // num.f = n[1];
    // r2 = createRange(num);

    // /* Faz as operações */
    // for(int i = 0; i < 4; i++)
    // {
    //     printf("%d:\n", i+1);        
    //     printRange(r1);
    //     printf("%c", op[i]);
    //     printRange(r2);

    //     switch (op[i])
    //     {
    //     case '+':
    //         res = addRange(r1,r2);
    //         break;
    //     case '-':
    //         res = subtractRange(r1,r2);
    //         break;
    //     case '*':
    //         res = timeRange(r1,r2);
    //         break;
    //     case '/':
    //         res = divisionRange(r1,r2);
    //         break;
    //     }

    //     printf("\n");
    //     /* Imprime Intervalo Resultante */
    //     printRange(res);
    //     /* Imprime EA, ER e ULPs */
    //     printResults(res);
    //     /* Atualiza variaveis de intervalo */
    //     r1 = res;
    //     num.f = n[i+2];
    //     r2 = createRange(num);
    // }


    n1 = 2.347e-40;
    n2 = 0.001;
    n3 = 1.1e+10;
    n4 = 0.75e-39;
    n5 = 0.00;

    r1 = createRange(n1);
    r2 = createRange(n2);
    printf("1:\n");
    printRange(r1);
    printf("*");
    printRange(r2);
    res = timeRange(r1,r2);
    printf("\n");
    printRange(res);
    printResults(res);

    printf("\n2:\n");
    r1 = res;
    r2 = createRange(n3);
    printRange(r1);
    printf("+");
    printRange(r2);
    res = addRange(r1,r2);
    printf("\n");
    printRange(res);
    printResults(res);

    printf("\n3:\n");
    r1 = res;
    r2 = createRange(n4);
    printRange(r1);
    printf("-");
    printRange(r2);
    res = subtractRange(r1,r2);
    printf("\n");
    printRange(res);
    printResults(res);

    printf("\n4:\n");
    r1 = res;
    r2 = createRange(n5);
    printRange(r1);
    printf("/");
    printRange(r2);
    res = divisionRange(r1,r2);
    printf("\n");
    printRange(res);
    printResults(res); 

   return 0;
}
