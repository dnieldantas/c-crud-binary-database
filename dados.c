#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *dados;
    dados = fopen("dados.txt", "a");

    if (dados == NULL) 
    {
    printf("Erro ao abrir arquivo.\n");
    return 1;
    }

    int i = 0;
    while(1)
    {
        char nome[100];
        char nascimento[11];
        char email[30];
        char telefone[25];

        printf("Nome: ");
        scanf(" %99[^\n]", nome);
        fprintf(dados, "Nome: %s\n", nome);

        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf(" %10s", nascimento);
        fprintf(dados, "%s\n", nascimento);

        printf("E-mail: ");
        scanf(" %29s", email);
        fprintf(dados, "%s\n", email);

        printf("Telefone: ");
        scanf(" %24s", telefone);
        fprintf(dados, "%s\n\n", telefone);

        printf("\nCadastro de %s feito!\n\n", nome);

        int novo;
        printf("Realizar novo cadastro?\n\n[1] Sim\n[2] Não\n\n");
        scanf( "%d", &novo);
        if(novo == 2)
        {
            break;
        }
    }
    fclose(dados);
}