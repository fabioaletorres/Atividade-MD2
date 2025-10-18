#include <stdio.h>
#include <stdlib.h>

/*
    Bruno de Oliveira: 180062778
	Fabio Alessandro Torres Santos: 200037170
*/

int mdc(int a, int b){ // Função que retorna o Máximo Divisor Comum (MDC) entre dois números usando o algoritmo de Euclides
    int resto = a % b;
    if(resto == 0) return b;
    return( mdc(b, resto)) ;
}

int mmc(int x, int y){ // Função para determinar o Menor Múltiplo Comum (MMC) entre dois números
    // Fórmula: mmc(x, y) = (x * y) / mdc(x, y)
    return( (x * y) / mdc( x, y) );
}

int main(){

    int n;
    printf("\n Digite a quantidade de chaves que serão usadas (Entre 1 e 10) \n> ");
    scanf("%d", &n);

    int array_c[n];
    printf("Digite as %d chaves a serem usadas (Entre 2 e 20) \n> ", n);
    for(int i = 0; i < n; i++) scanf("%d", &array_c[i]);

    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n \tCalculo do ano:\n");

    /* Calculando o MMC de todos os números do array de forma sequencial, aproveitando a propriedade associativa do MMC:
        Primeiro passo: ano = array_c[0]
        Segundo passo: ano = mmc(array_c[0], array_c[1])
        Em cada passo seguinte, usamos o MMC do resultado anterior com o próximo número do array:
        Exemplo: mmc = mmc(ano, array_c[2]) → que equivale a mmc(mmc(array_c[0], array_c[1]), array_c[2])
        Isso permite obter o MMC de todos os valores de forma iterativa, mostrando cada cálculo intermediário.
    */

    int ano = array_c[0];
    for(int i = 0; i < n-1; i++){
        printf("MMC de %d e %d = %d \n", ano, array_c[i+1], mmc(ano, array_c[i+1]));
        ano = mmc(ano, array_c[i+1]);
    }

    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    if(ano > 0 && ano < 51){
        printf("As chaves podem ser usadas no ano  %d\n", ano);
    }
    else{
        printf("Erro: limite ultrapassou 50 anos!!! \n");
    }
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

    return 0;
}
