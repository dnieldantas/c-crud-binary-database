#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct cadastro
{
    char nome[100];
    char nascimento[11];
    char email[50];
    char telefone[25];
};

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

    struct cadastro c1;

    while (1)
    {
        printf("\nNome: ");
        scanf(" %99[^\n]", c1.nome);
        capitalize(c1.nome);

        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf(" %10s", c1.nascimento);

        printf("E-mail: ");
        scanf(" %29s", c1.email);

        printf("Telefone: ");
        scanf(" %24s", c1.telefone);

        printf("\nVerificar as informações:\n\n%s\n%s\n%s\n%s\n\n", c1.nome, c1.nascimento, c1.email, c1.telefone);
        printf("O que deseja?\n\n[1] Confirmar\n[2] Editar informações\n[3] Cancelar e Sair\n\n");
        int editar;
        scanf(" %d", &editar);
        if (editar == 2)
        {
            continue;
        }

        else if (editar == 3)
        {
            break;
        }

        fprintf(dados, "Nome: %s\nData de Nascimento: %s\nE-mail: %s\nTelefone: %s\n\n", c1.nome, c1.nascimento, c1.email, c1.telefone);
        printf("\nCadastro realizado com sucesso!\n\n");

        int novo;
        printf("Realizar novo cadastro?\n\n[1] Sim\n[2] Não\n\n");
        scanf(" %d", &novo);
        if (novo == 2)
        {
            break;
        }
    }
    fclose(dados);
}