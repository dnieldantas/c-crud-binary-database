#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct cadastro
{
    char nome[100];
    char nascimento[11];
    char cpf[20];
    char email[50];
    char telefone[25];
};

void division(){
    printf("-------------------------------------------------");
}

void capitalize(char palavra[])
{
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        palavra[i] = toupper(palavra[i]);
    }
}

int main()
{
    while (1)
    {
        printf("\n");
        division();
        printf("\nMENU PRINCIPAL\n");
        division();
        printf("\n[1] Adicionar\n[2] Consultar\n[3] Editar\n[4] Apagar\n[5] Sair\n\n");
        int inicio;
        scanf(" %d", &inicio);

        FILE *banco;

        struct cadastro c1;
        if (inicio == 1)
        {
            banco = fopen("banco.dat", "wb");
            if (banco == NULL)
            {
                printf("Erro ao abrir arquivo.\n");
                return 1;
            }

            while (1)
            {
                division();
                printf("\nNome Completo: ");
                scanf(" %99[^\n]", c1.nome);
                capitalize(c1.nome);

                printf("Data de Nascimento (dd/mm/aaaa): ");
                scanf(" %10s", c1.nascimento);

                printf("CPF: ");
                scanf(" %19s", c1.cpf);

                printf("E-mail: ");
                scanf(" %49s", c1.email);

                printf("Telefone: ");
                scanf(" %24s", c1.telefone);

                division();
                printf("\nVerificar as informações:\n\n%s\n%s\n%s\n%s\n%s\n", c1.nome, c1.nascimento, c1.cpf, c1.email, c1.telefone);
                division();
                printf("\n[1] Confirmar Cadastro\n[2] Editar informações\n[3] Voltar ao menu\n\n");
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

                fwrite(&c1, sizeof(struct cadastro), 1, banco);
                printf("\nCadastro realizado com sucesso!\n\n");
                division();

                int novo;
                printf("Realizar novo cadastro?\n\n[1] Sim\n[2] Não\n\n");
                scanf(" %d", &novo);
                if (novo == 2)
                {
                    break;
                }
            }
            fclose(banco);
        }
        else if (inicio == 2)
        {
            banco = fopen("banco.dat", "rb");
            if (banco == NULL)
            {
                printf("Erro ao abrir arquivo.\n");
                return 1;
            }

            char busca[100];

            while (1)
            {
                division();
                printf("\nDigite o CPF para consulta: ");
                scanf(" %19s", busca);
                
                int encontrado = 0;
                rewind(banco);
                while (fread(&c1, sizeof(struct cadastro), 1, banco))
                {
                    if (strcmp(c1.cpf, busca) == 0)
                    {
                        division();
                        printf("\nNome: %s\n", c1.nome);
                        printf("Nascimento: %s\n", c1.nascimento);
                        printf("CPF: %s\n", c1.cpf);
                        printf("Email: %s\n", c1.email);
                        printf("Telefone: %s\n", c1.telefone);
                        division();
                        encontrado = 1;
                        break;
                    }
                }
                if (encontrado == 0){
                    division();
                    printf("\nCadastro não encontrado.\n");
                    division();
                }

                printf("\nRealizar nova consulta?\n\n[1] Sim\n[2] Voltar para o menu\n\n");
                int novaconsulta;
                scanf(" %d", &novaconsulta);
                if (novaconsulta == 2)
                {
                    break;
                }
            }
            fclose(banco);
        }

        /*else if (inicio == 3)
        {
            // edicao
        }
        else if (inicio == 4)
        {
            // deletar
        }*/

        else if (inicio == 5)
        {
            break;
        }

        else
        {
            printf("\nTente uma opção válida.\n");
        }
    }
}
