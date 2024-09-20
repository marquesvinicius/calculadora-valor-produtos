#include <stdio.h>
#include <ctype.h>

void exibir_mensagem_boas_vindas() {
    printf("--- Bem-vindo ao Programa de Calculo de Valor Final de Produtos! ---\n");
    printf("Este programa ajuda a calcular o valor final de um produto para revenda.\n");
    printf("Por favor, escolha uma das seguintes opcoes:\n");
    printf("1. Inserir dados\n");
    printf("2. Ajuda - Como usar o programa e explicacao de termos como DIFAL e IPI\n");
    printf("3. Encerrar o programa\n");
}
char ler_opcao(const char* mensagem) {
    char opcao;
    do {
        printf("%s (S/N): ", mensagem);
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        if(opcao != 'S' && opcao != 'N') {
            printf("Entrada invalida. Por favor, insira 'S' para Sim ou 'N' para Nao.\n");
        }
    } while(opcao != 'S' && opcao != 'N');
    return opcao;
}

float ler_valor_float(const char* mensagem) {
    float valor;
    printf("%s", mensagem);
    while(scanf("%f", &valor) != 1) {
        printf("Entrada invalida. Por favor, insira um numero.\n");
        // Limpa o buffer de entrada
        while(getchar() != '\n');
        printf("%s", mensagem);
    }
    return valor;
}

int ler_valor_int(const char* mensagem) {
    int valor;
    printf("%s", mensagem);
    while(scanf("%d", &valor) != 1 || valor <= 0) {
        if (valor <= 0) {
            printf("O numero de unidades deve ser positivo e maior que zero.\n");
        } else {
            printf("Entrada invalida. Por favor, insira um numero inteiro.\n");
        }
        // Limpa o buffer de entrada
        while(getchar() != '\n');
        printf("%s", mensagem);
    }
    return valor;
}

void configurar_precos(float* valor_ipi, float* margem_lucro, char* incluir_difal, char* incluir_frete) {
    *incluir_difal = ler_opcao("\nDeseja acrescentar ao valor final o valor do DIFAL (4,5%)?");
    *incluir_frete = ler_opcao("Deseja acrescentar ao valor final o valor do frete (4,5%)?");
    *valor_ipi = ler_valor_float("Qual e o valor do IPI em porcentagem? (Digite 0 se nao tiver): ");
    *margem_lucro = ler_valor_float("Qual e a margem de lucro em porcentagem?: ");
}

int main() {
    int opcao;
    char incluir_difal, incluir_frete;
    float valor_ipi, margem_lucro;
    float valor_inicial, valor_final;
    int unidades;
    int produto_numero = 1;

    while(1) {
        exibir_mensagem_boas_vindas();
        printf("Escolha uma opcao: ");
        opcao = ler_valor_int("");

        if(opcao == 3) {
            printf("\n--- Programa encerrado. Obrigado por usar nosso sistema! ---\n");
            break;
        } else if(opcao == 1) {
            configurar_precos(&valor_ipi, &margem_lucro, &incluir_difal, &incluir_frete);

            do {
                printf("\n--- Insercao de dados do produto numero %d ---\n\n", produto_numero);
                valor_inicial = ler_valor_float("Qual e o valor inicial do produto? (Digite um valor negativo para voltar ao menu): ");
            
                if(valor_inicial < 0) {
                    produto_numero = 1;
                    break; // Sai do loop interno e volta ao menu inicial.
                }

                unidades = ler_valor_int("Em quantas unidades esse valor final deve ser dividido?: ");

                valor_final = valor_inicial;
                if (incluir_difal == 'S') {
                    valor_final += valor_inicial * 0.045;
                }
                if (incluir_frete == 'S') {
                    valor_final += valor_inicial * 0.045;
                }
                if (valor_ipi > 0) {
                    valor_final += valor_inicial * (valor_ipi / 100);
                }
                if (margem_lucro > 0) {
                    valor_final += valor_inicial * (margem_lucro / 100);
                }

                valor_final /= unidades;

                printf("O valor final do produto %d e: R$ %.2f\n", produto_numero, valor_final);

                produto_numero++;
            } while(1);
            
        }   else if(opcao == 2) {
            printf("\n--- Ajuda sobre termos utilizados no programa ---\n");
            printf("Valor Inicial: Valor de aquisicao do produto, constante na nota fiscal.\n");
            printf("Valor Final: Valor de revenda do produto, apos adicao de impostos e margem de lucro.\n");
            printf("DIFAL: Diferencial de Aliquota do ICMS, aplicado em operacoes interestaduais.\n");
            printf("IPI: Imposto sobre Produtos Industrializados, tributo federal sobre a industrializacao de produtos.\n\n");
            printf("OBSERVACAO: Sempre utilize numeros decimais no formato '0.00' com um '.' separando a parte inteira da decimal.\n");
            printf("Caso utilize virgula, o programa nao ira funcionar.\n\n");
            printf("Para mais informacoes, consulte a legislacao tributaria vigente ou um contador.\n\n");

            printf("Calculo do Preco Final:\n");
            printf("1. Valor Inicial: O valor de aquisicao do produto, constante na nota fiscal.\n");
            printf("2. DIFAL (Diferencial de Aliquota): Se incluido, acrescenta 4,5%% do valor inicial ao preco final.\n");
            printf("3. Frete: Se incluido, acrescenta 4,5%% do valor inicial ao preco final.\n");
            printf("4. IPI (Imposto sobre Produtos Industrializados): Se informado um valor maior que 0, acrescenta ao preco final com base na porcentagem fornecida.\n");
            printf("5. Margem de Lucro: Se informada uma margem de lucro maior que 0, acrescenta ao preco final com base na porcentagem fornecida.\n");
            printf("6. Divisao pelo numero de unidades: Divide o preco final pelo numero de unidades para obter o preco final por unidade.\n\n");
        
            printf("\nExpressao Matematica do Calculo do Preco Final:\n");
            printf("Preco Final = Valor Inicial + (DIFAL * 0.045 * Valor Inicial) + (Frete * 0.045 * Valor Inicial) + (IPI * Valor Inicial / 100) + (Margem de Lucro * Valor Inicial / 100) / Numero de Unidades\n\n\n");

        } else {
            printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }

    return 0;
}