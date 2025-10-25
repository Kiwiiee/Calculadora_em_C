#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcular(double resultado1);
void print_num(double x);

int main(){
    while(1){
        int escolha, continuar = 0;
        double num1, num2, resultado1;
        char operador;

        printf("Escolha a operacao:\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Modulo\n");
        printf("6. Sair\n");
        printf("Digite o numero da operacao desejada: ");
        scanf("%d", &escolha);

        if (escolha == 6) {
            printf("Saindo da calculadora.\n");
            break;
        }
        if (escolha < 1 || escolha > 5) {
            printf("Opcao invalida, tente novamente.\n");
            continue;
        }
        else {
            printf("digite a operacao:\n");
            scanf("%lf %c %lf", &num1, &operador, &num2);
            switch(operador){
                case '+':
                    resultado1 = num1 + num2;
                    print_num(resultado1);
                    printf("\n");
                    printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                    scanf("%d", &continuar);
                    if (continuar == 1) {
                        calcular(resultado1);
                    }
                    continue;
                case '-':
                    resultado1 = num1 - num2;
                    print_num(resultado1);
                    printf("\n");
                    printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                    scanf("%d", &continuar);
                    if (continuar == 1) {
                        calcular(resultado1);
                    }
                    continue;
                case '*':
                    resultado1 = num1 * num2;
                    print_num(resultado1);
                    printf("\n");
                    printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                    scanf("%d", &continuar);
                    if (continuar == 1) {
                        calcular(resultado1);
                    }
                    continue;
                case '/':
                    if(num2 != 0){
                        resultado1 = num1 / num2;
                        print_num(resultado1);
                        printf("\n");
                        printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                        scanf("%d", &continuar);
                        if (continuar == 1) {
                            calcular(resultado1);
                        }
                    }
                    else {
                        printf("Erro: Divisao por zero nao e permitida.\n");
                    }
                    continue;
                case '%':
                    if(num2 != 0){
                        resultado1 = fmod(num1, num2);
                        print_num(resultado1);
                        printf("\n");
                        printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                        scanf("%d", &continuar);
                        if (continuar == 1) {
                            calcular(resultado1);
                        }
                    }
                    else {
                        printf("\n");
                        printf("Erro: Divisao por zero nao e permitida.\n");
                    }
                    continue;
                default:
                    printf("Operador invalido. Tente novamente.\n");
                    continue;
            }
        }
    } 
    return 0;
}

int calcular(double resultado1){
    int continuar = 0, escolha;
    double resultado2 = resultado1, num;
    char operador;
    while(1){
        printf("Escolha a operacao para a continuacao:\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Modulo\n");
        printf("6. Sair da continuacao\n");
        printf("Digite o numero da operacao desejada: ");
        scanf("%d", &escolha);
        if (escolha == 6) {
            printf("Saindo da continuacao.\n");
            break;
        }
        if (escolha < 1 || escolha > 5) {
            printf("Opcao invalida, tente novamente.\n");
            continue;
        }
        else{
            print_num(resultado2);
            scanf(" %c %lf", &operador, &num);
            switch(operador){
                case '+':
                    resultado2 = resultado2 + num;
                    print_num(resultado2);
                    printf("\n");
                    printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                    scanf("%d", &continuar);
                    if(continuar == 0) return 0;
                    continue;
                case '-':
                    resultado2 = resultado2 - num;
                    print_num(resultado2);
                    printf("\n");
                    printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                    scanf("%d", &continuar);
                    if(continuar == 0) return 0;
                    continue;
                case '*':
                    resultado2 = resultado2 * num;
                    print_num(resultado2);
                    printf("\n");
                    printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                    scanf("%d", &continuar);
                    if (continuar == 0) return 0;
                    continue;
                case '/':
                    if(num != 0){
                        resultado2 = resultado2 / num;
                        print_num(resultado2);
                        printf("\n");
                        printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                        scanf("%d", &continuar);
                        if (continuar == 0) return 0;
                    }
                    else{
                        printf("Erro: Divisao por zero nao e permitida.\n");
                    }
                    continue;
                case '%':
                    if(num != 0){
                        resultado2 = fmod(resultado2, num);
                        print_num(resultado2);
                        printf("\n");
                        printf("voce quer continuar com esse resultado? (1 para sim / 0 para nao): ");
                        scanf("%d", &continuar);
                        if (continuar == 0) return 0;
                    }
                    else{
                        printf("\n");
                        printf("Erro: Divisao por zero nao e permitida.\n");
                    }
                    continue;
                default:
                    printf("Operador invalido. Tente novamente.\n");
                    continue;
            }
        }
    }
    return 0;
}

void print_num(double x) {
    double intpart;
    double frac = fabs(modf(x, &intpart));
    const double eps = 1e-9;
    if (frac < eps) printf("%.0f", intpart);
    else printf("%.2f", x);
}