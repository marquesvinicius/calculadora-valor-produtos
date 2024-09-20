# Programa de Cálculo de Valor Final de Produtos

## Descrição

Este é um aplicativo simples de console, desenvolvido em C, que ajuda na definição do valor final de produtos para revenda. O programa permite a inserção de informações como IPI, DIFAL, frete e margem de lucro, e calcula o preço final por unidade de produto.

## Funcionalidades

- **Cálculo do Preço Final**: O programa calcula o valor final de um produto com base no valor inicial, impostos, frete e margem de lucro.
- **Divisão do Preço por Unidade**: O preço final pode ser calculado com base no número de unidades.
- **Ajuda**: Explicação dos termos usados, como DIFAL, IPI, frete, e como o cálculo é realizado.
  
## Como Usar

1. Ao iniciar o programa, você verá um menu com três opções:
   - `1. Inserir dados`: Permite que você insira as informações necessárias para calcular o valor final do produto.
   - `2. Ajuda`: Explica os termos utilizados e como funciona o cálculo do preço final.
   - `3. Encerrar`: Finaliza o programa.

2. Ao escolher a opção de inserção de dados, o programa solicitará as seguintes informações:
   - Valor Inicial do produto
   - Percentual do IPI (se aplicável)
   - Margem de Lucro
   - Se deseja incluir DIFAL e frete no cálculo
   - Número de unidades do produto

3. O programa então calculará e exibirá o valor final por unidade do produto, considerando as opções fornecidas.

4. Você pode repetir o processo para vários produtos até escolher encerrar o programa.

## Fórmula Utilizada

O cálculo do valor final é feito usando a seguinte fórmula:

```
Preço Final = (Valor Inicial + DIFAL + Frete + IPI + Margem de Lucro) / Número de Unidades
```

Onde:
- **DIFAL**: 4.5% do valor inicial (se aplicável)
- **Frete**: 4.5% do valor inicial (se aplicável)
- **IPI**: Percentual informado
- **Margem de Lucro**: Percentual informado

## Compilação e Execução

### Linux / MacOS

1. Abra o terminal e vá até o diretório onde o arquivo `meu_programa.c` está localizado.
2. Compile o programa usando o `gcc`:
   ```bash
   gcc -o meu_programa meu_programa.c
   ```
3. Execute o programa:
   ```bash
   ./meu_programa
   ```

### Windows

1. Use o compilador `MinGW` ou outro compilador compatível para compilar o código:
   ```bash
   gcc -o meu_programa.exe meu_programa.c
   ```
2. Execute o programa:
   ```bash
   meu_programa.exe
   ```

## Termos Explicados

- **DIFAL**: Diferencial de Alíquota do ICMS aplicado em operações interestaduais.
- **IPI**: Imposto sobre Produtos Industrializados, um tributo federal.
- **Frete**: Custos associados ao transporte do produto.
- **Margem de Lucro**: Percentual aplicado sobre o valor inicial para obter lucro na revenda.

## Requisitos

- **Compilador C**: GCC ou outro compilador C.
- **Sistema Operacional**: Compatível com Linux, Windows e macOS.

## Licença

Este projeto está licenciado sob a licença MIT. Para mais detalhes, veja o arquivo `LICENSE`.
