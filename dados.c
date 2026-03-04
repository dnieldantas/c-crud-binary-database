#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void capitalize(char palavra[])
{
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        palavra[i] = toupper(palavra[i]);
    }
}

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
    while (1)
    {
        char nome[100];
        char nascimento[11];
        char email[30];
        char telefone[25];

        printf("Nome: ");
        scanf(" %99[^\n]", nome);
        capitalize(nome);

        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf(" %10s", nascimento);

        printf("E-mail: ");
        scanf(" %29s", email);

        printf("Telefone: ");
        scanf(" %24s", telefone);

        int len_telefone = strlen(telefone);
        char id[8] = {nome[0], nascimento[0], nascimento[1], nome[1], telefone[len_telefone - 2], telefone[len_telefone - 1], nome[2], '\0'};

        fprintf(dados, "%s\n", id);
        fprintf(dados, "%s\n", nome);
        fprintf(dados, "%s\n", nascimento);
        fprintf(dados, "%s\n", email);
        fprintf(dados, "%s\n\n", telefone);

        printf("\nCadastro de %s feito!\n\n", nome);

        int novo;
        printf("Realizar novo cadastro?\n\n[1] Sim\n[2] Não\n\n");
        scanf("%d", &novo);
        if (novo == 2)
        {
            break;
        }
    }
    fclose(dados);
}