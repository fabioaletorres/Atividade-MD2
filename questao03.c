/*
    Bruno de Oliveira: 180062778
	Fabio Alessandro Torres Santos: 200037170
*/

#include <stdio.h>
#include <math.h>

int main() {
    
    int N;
    printf("Insira um numero N (1<= N <= 105): ");
    scanf("%d", &N);
    
    // Validacao da entrada
    if(N < 1 || N > 105){
        printf("Erro! N deve ser entre 1 e 105\n");
        return 1;
    }

    printf("Pela Fatoracao de %d:\n", N);
    
    int temp = N;
    int fatores[100][2]; // Array para armazenar fatores primos e expoentes
    int contador = 0; // Contador de fatores primos
    
    // Metodo: Trial Division (Divisao por Tentativa)

    // Justificativa: Para N <= 105, este metodo e suficiente e eficiente

    // Percorremos todos os numeros de 2 ate sqrt(N)
    for (int p = 2; p * p <= temp; p++) {
        if (temp % p == 0) {
            // Encontramos um fator primo
            fatores[contador][0] = p;
            fatores[contador][1] = 0;
            
            // Calculamos o expoente do fator primo
            while (temp % p == 0) {
                fatores[contador][1]++;
                temp /= p;
            }
            contador++;
        }
    }
    
    // Se sobrou algum valor maior que 1, ele e primo
    if (temp > 1) {
        fatores[contador][0] = temp;
        fatores[contador][1] = 1;
        contador++;
    }
    
    // Exibir resumo da fatoracao
    for (int i = 0; i < contador; i++) {
        printf("Primo= %d^%d\n", fatores[i][0], fatores[i][1]);
    }

    //  Parte 2: Calculo De Tau(N) 

    // Formula: tau(N) = produto de (expoente_i + 1)

    // Justificativa: Cada fator primo p_i^a_i contribui com (a_i + 1) divisores
    int tau = 1;
    for (int i = 0; i < contador; i++) {
        tau *= (fatores[i][1] + 1);
    }

    //  Parte 3: Calculo De Sigma(N) 

    // Formula: sigma(N) = produto de soma das potencias de cada fator primo

    // Para cada fator primo p^a: soma = 1 + p + p^2 + ... + p^a
    int sigma = 1;
    for (int i = 0; i < contador; i++) {
        int p = fatores[i][0];
        int a = fatores[i][1];
        int soma = 1;
        int power = 1;
        
        for (int j = 0; j < a; j++) {
            power *= p;
            soma += power;
        }
        sigma *= soma;
    }

    //  Parte 4: Calculo da razao de eficiencia 

    // Formula: Razao = sigma(N) / tau(N)
    double razao = (double)sigma / tau;

    printf("\n Resultado \n");
    printf(" Para N = %d:\n", N);
    printf(" Tau = %d\n", tau);
    printf(" Sigma = %d\n", sigma);
    printf(" Razao de Eficiencia = %.2f\n", razao);

    return 0;
}