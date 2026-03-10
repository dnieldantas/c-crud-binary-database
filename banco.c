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

void division()
{
    printf("--------------------------------------------------");
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
                printf("\n[1] Confirmar Cadastro\n[2] Editar informações\n[3] Cancelar e Voltar ao Menu\n\n");
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
                printf("\nRealizar novo cadastro?\n\n[1] Sim\n[2] Não\n\n");
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
                if (encontrado == 0)
                {
                    division();
                    printf("\nCadastro não encontrado.\n");
                    division();
                }

                printf("\nRealizar nova consulta?\n\n[1] Sim\n[2] Voltar ao Menu\n\n");
                int novaconsulta;
                scanf(" %d", &novaconsulta);
                if (novaconsulta == 2)
                {
                    break;
                }
            }
            fclose(banco);
        }

        else if (inicio == 3)
        {
            banco = fopen("banco.dat", "rb+");
            if (banco == NULL)
            {
                printf("Erro ao abrir arquivo.\n");
                return 1;
            }

            char busca[100];
            int loops = 0;

            while (loops == 0) // loop de repeticao dentro do arquivo; permite editar diferentes cadastros de acordo com o cpf
            {
                division();
                printf("\nDigite o CPF para edição: ");
                scanf(" %19s", busca);

                int encontrado = 0;
                rewind(banco);
                while (fread(&c1, sizeof(struct cadastro), 1, banco))
                {
                    if (strcmp(c1.cpf, busca) == 0)
                    {
                        encontrado = 1;
                        division();
                        printf("\nNome: %s\n", c1.nome);
                        printf("Nascimento: %s\n", c1.nascimento);
                        printf("CPF: %s\n", c1.cpf);
                        printf("Email: %s\n", c1.email);
                        printf("Telefone: %s\n", c1.telefone);
                        division();
                        break;
                    }
                }

                if (encontrado == 0)
                {
                    division();
                    printf("\nCadastro não encontrado.\n");
                    division();
                    printf("\nRealizar nova consulta?\n\n[1] Sim\n[2] Voltar ao Menu\n\n");
                    int novaconsulta;
                    scanf(" %d", &novaconsulta);
                    if (novaconsulta == 2)
                    {
                        break;
                    }
                }

                else
                {
                    while (loops == 0) // loop de repeticao dentro do cadastro encontrado; permite editar o mesmo varias vezes
                    {
                        printf("\nO que deseja editar?\n\n[1] Nome Completo\n[2] Data de Nascimento\n[3] CPF\n[4] Email\n[5] Telefone\n[6] Editar Tudo\n[7] Voltar ao Menu\n\n");
                        int edicao;
                        scanf(" %d", &edicao);

                        switch (edicao)
                        {
                        case 1:
                            division();
                            printf("\nNome Completo: ");
                            scanf(" %99[^\n]", c1.nome);
                            capitalize(c1.nome);
                            break;
                        case 2:
                            division();
                            printf("\nData de Nascimento (dd/mm/aaaa): ");
                            scanf(" %10s", c1.nascimento);
                            break;
                        case 3:
                            division();
                            printf("\nCPF: ");
                            scanf(" %19s", c1.cpf);
                            break;
                        case 4:
                            division();
                            printf("\nE-mail: ");
                            scanf(" %49s", c1.email);
                            break;
                        case 5:
                            division();
                            printf("\nTelefone: ");
                            scanf(" %24s", c1.telefone);
                            break;
                        case 6:
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
                            break;
                        case 7:
                            loops = 1;
                            break;
                        }
                        if (loops == 1)
                        {
                            break;
                        }

                        division();
                        printf("\nVerificar as informações:\n\n%s\n%s\n%s\n%s\n%s\n", c1.nome, c1.nascimento, c1.cpf, c1.email, c1.telefone);
                        division();
                        printf("\n[1] Confirmar Edição\n[2] Cancelar e Voltar ao Menu\n\n");
                        int editar;
                        scanf(" %d", &editar);
                        if (editar == 2)
                        {
                            loops = 1;
                        }
                        if (loops = 1)
                        {
                            break;
                        }
                        else
                        {
                            fseek(banco, -sizeof(struct cadastro), SEEK_CUR);
                            fwrite(&c1, sizeof(struct cadastro), 1, banco);
                            fseek(banco, -sizeof(struct cadastro), SEEK_CUR);
                            printf("\nEdição realizada com sucesso!\n\n");
                            division();
                        }

                        int novo;
                        printf("\nRealizar nova edição?\n\n[1] Sim\n[2] Não\n[3] Editar outro cadastro\n\n");
                        scanf(" %d", &novo);
                        if (novo == 2)
                        {
                            loops = 1;
                        }
                        else if (novo == 3)
                        {
                            break;
                        }
                    }
                }
            }
            fclose(banco);
        }

        /*else if (inicio == 4)
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