#include <stdio.h>

int main()
{
    printf("Calculadora em C");
    
    char operacao;
    double num1, num2, resultado;

    printf("\nQual operação matemática deseja fazer: \n'+'ADIÇÃO\n'-'SUBTRAÇÃO\n'*'MULTIPLICAÇÃO\n'/'DIVISÃO\n Escolha: ");
    scanf("%c", &operacao);
    
    printf("Digite o primeiro número: ");
    scanf("%lf", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%lf", &num2);
    
    switch(operacao){
        case '+':
            resultado = num1 + num2;
            printf("%.2lf", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("%.2lf", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("%.2lf", resultado);
            break;
        case '/':
            resultado = num1 / num2;
            printf("%.2lf", resultado);
            break;
        default:
            printf("Ta burro?");
    }

    return 0;
}
