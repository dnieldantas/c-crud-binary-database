#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct record
{
    char name[100];
    char birthdate[11];
    char cpf[20];
    char email[50];
    char phone[25];
};

void division()
{
    printf("------------------------------------------------------------");
}

void capitalize(char word[])
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        word[i] = toupper(word[i]);
    }
}

int main()
{
    division();
    printf("\nWELCOME TO THE CRUD DATABASE SYSTEM!");
    while (1)
    {
        printf("\n");
        division();
        printf("\nMAIN MENU\n");
        division();
        printf("\n[1] Add New Record\n[2] Search Record\n[3] Edit Record\n[4] Delete Record\n[5] View All Records\n[6] Delete All Records\n[7] Close Program\n\n");
        int initiate;
        scanf(" %d", &initiate);

        FILE *database;

        struct record r1;
        if (initiate == 1)
        {
            database = fopen("database.dat", "ab");
            if (database == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }

            while (1)
            {
                division();
                printf("\nFull Name: ");
                scanf(" %99[^\n]", r1.name);
                capitalize(r1.name);

                printf("Birthdate (dd/mm/yyyy): ");
                scanf(" %10s", r1.birthdate);

                printf("CPF: ");
                scanf(" %19s", r1.cpf);

                printf("E-mail: ");
                scanf(" %49s", r1.email);

                printf("Phone Number: ");
                scanf(" %24s", r1.phone);

                division();
                printf("\nCheck Info:\n\n%s\n%s\n%s\n%s\n%s\n", r1.name, r1.birthdate, r1.cpf, r1.email, r1.phone);
                division();
                printf("\n[1] Confirm\n[2] Edit Info\n[3] Cancel and Return to Menu\n\n");
                int change_info;
                scanf(" %d", &change_info);
                if (change_info == 2)
                {
                    continue;
                }

                else if (change_info == 3)
                {
                    break;
                }

                fwrite(&r1, sizeof(struct record), 1, database);
                printf("\nRecord successfully added!\n\n");
                division();

                int another_record;
                printf("\nAdd another record?\n\n[1] Yes\n[2] No\n\n");
                scanf(" %d", &another_record);
                if (another_record == 2)
                {
                    break;
                }
            }
            fclose(database);
        }

        else if (initiate == 2)
        {
            database = fopen("database.dat", "rb");
            if (database == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }

            char search[20];

            while (1)
            {
                division();
                printf("\nEnter CPF to search: ");
                scanf(" %19s", search);

                int record_found = 0;
                rewind(database);
                while (fread(&r1, sizeof(struct record), 1, database))
                {
                    if (strcmp(r1.cpf, search) == 0)
                    {
                        division();
                        printf("\nFull Name: %s\n", r1.name);
                        printf("Birthdate: %s\n", r1.birthdate);
                        printf("CPF: %s\n", r1.cpf);
                        printf("Email: %s\n", r1.email);
                        printf("Phone Number: %s\n", r1.phone);
                        division();
                        record_found = 1;
                        break;
                    }
                }
                if (record_found == 0)
                {
                    division();
                    printf("\nRecord not found.\n");
                    division();
                }

                printf("\nNew Search?\n\n[1] Yes\n[2] No and Return to Menu\n\n");
                int new_search;
                scanf(" %d", &new_search);
                if (new_search == 2)
                {
                    break;
                }
            }
            fclose(database);
        }

        else if (initiate == 3)
        {
            database = fopen("database.dat", "rb+");
            if (database == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }

            char search[20];
            int loops = 0;

            while (loops == 0)
            {
                division();
                printf("\nEnter CPF to edit record: ");
                scanf(" %19s", search);

                int record_found = 0;
                rewind(database);
                while (fread(&r1, sizeof(struct record), 1, database))
                {
                    if (strcmp(r1.cpf, search) == 0)
                    {
                        record_found = 1;
                        division();
                        printf("\nName: %s\n", r1.name);
                        printf("Birthdate: %s\n", r1.birthdate);
                        printf("CPF: %s\n", r1.cpf);
                        printf("Email: %s\n", r1.email);
                        printf("Phone Number: %s\n", r1.phone);
                        division();
                        break;
                    }
                }

                if (record_found == 0)
                {
                    division();
                    printf("\nRecord not found.\n");
                    division();
                    printf("\nTry another CPF?\n\n[1] Yes\n[2] No and Return to Menu\n\n");
                    int new_search;
                    scanf(" %d", &new_search);
                    if (new_search == 2)
                    {
                        break;
                    }
                }

                else
                {
                    while (loops == 0)
                    {
                        printf("\nWhat do you want to edit?\n\n[1] Full Name\n[2] Birthdate\n[3] CPF\n[4] Email\n[5] Phone Number\n[6] Edit All\n[7] Return to Menu\n\n");
                        int edit_record;
                        scanf(" %d", &edit_record);

                        switch (edit_record)
                        {
                        case 1:
                            division();
                            printf("\nFull Name: ");
                            scanf(" %99[^\n]", r1.name);
                            capitalize(r1.name);
                            break;
                        case 2:
                            division();
                            printf("\nBirthdate (dd/mm/yyyy): ");
                            scanf(" %10s", r1.birthdate);
                            break;
                        case 3:
                            division();
                            printf("\nCPF: ");
                            scanf(" %19s", r1.cpf);
                            break;
                        case 4:
                            division();
                            printf("\nE-mail: ");
                            scanf(" %49s", r1.email);
                            break;
                        case 5:
                            division();
                            printf("\nPhone Number: ");
                            scanf(" %24s", r1.phone);
                            break;
                        case 6:
                            division();
                            printf("\nFull Name: ");
                            scanf(" %99[^\n]", r1.name);
                            capitalize(r1.name);

                            printf("Birthdate (dd/mm/yyyy): ");
                            scanf(" %10s", r1.birthdate);

                            printf("CPF: ");
                            scanf(" %19s", r1.cpf);

                            printf("E-mail: ");
                            scanf(" %49s", r1.email);

                            printf("Phone Number: ");
                            scanf(" %24s", r1.phone);
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
                        printf("\nCheck Info:\n\n%s\n%s\n%s\n%s\n%s\n", r1.name, r1.birthdate, r1.cpf, r1.email, r1.phone);
                        division();
                        printf("\n[1] Confirm Edit\n[2] Cancel and Return to Menu\n\n");
                        int confirm_edit;
                        scanf(" %d", &confirm_edit);
                        if (confirm_edit == 2)
                        {
                            loops = 1;
                        }
                        if (loops == 1)
                        {
                            break;
                        }
                        else
                        {
                            fseek(database, -sizeof(struct record), SEEK_CUR);
                            fwrite(&r1, sizeof(struct record), 1, database);
                            fseek(database, -sizeof(struct record), SEEK_CUR);
                            division();
                            printf("\nRecord successfully edited!\n");
                            division();
                        }

                        int new_edit;
                        printf("\nNew Edit?\n\n[1] Yes\n[2] No\n[3] Edit another record\n\n");
                        scanf(" %d", &new_edit);
                        if (new_edit == 2)
                        {
                            loops = 1;
                        }
                        else if (new_edit == 3)
                        {
                            break;
                        }
                    }
                }
            }
            fclose(database);
        }

        else if (initiate == 4)
        {
            while (1)
            {
                FILE *temp;
                temp = fopen("temp.dat", "wb");
                if (temp == NULL)
                {
                    printf("Error opening temporary file.\n");
                    return 1;
                }
                database = fopen("database.dat", "rb");
                if (database == NULL)
                {
                    printf("Error opening file.\n");
                    return 1;
                }

                char search[20];

                division();
                printf("\nEnter CPF to delete record: ");
                scanf(" %19s", search);

                int record_found = 0;

                while (fread(&r1, sizeof(struct record), 1, database))
                {
                    if (strcmp(r1.cpf, search) == 0)
                    {
                        record_found = 1;
                        division();
                        printf("\nCheck Info:\n\n%s\n%s\n%s\n%s\n%s\n", r1.name, r1.birthdate, r1.cpf, r1.email, r1.phone);
                        division();
                    }
                }

                if (record_found == 0)
                {
                    division();
                    printf("\nRecord not found.\n");
                    division();
                    printf("\nTry another CPF?\n\n[1] Yes\n[2] Return to Menu\n\n");
                    int new_search;
                    scanf(" %d", &new_search);
                    if (new_search == 2)
                    {
                        break;
                    }
                }

                else
                {
                    printf("\nAre you sure you want to delete this record?\n\n[1] Delete Permanently\n[2] Cancel and Return to Menu\n\n");
                    int delete;
                    scanf(" %d", &delete);
                    if (delete == 2)
                    {
                        printf("\nRecord not deleted.\n");
                        break;
                    }

                    rewind(database);

                    while (fread(&r1, sizeof(struct record), 1, database))
                    {
                        if (strcmp(r1.cpf, search) != 0)
                        {
                            fwrite(&r1, sizeof(struct record), 1, temp);
                        }
                    }

                    fclose(database);
                    fclose(temp);

                    remove("database.dat");
                    rename("temp.dat", "database.dat");

                    division();
                    printf("\nRecord successfully deleted!\n");
                    division();

                    int new_delete;
                    printf("\nDelete another record?\n\n[1] Yes\n[2] No and Return to Menu\n\n");
                    scanf(" %d", &new_delete);
                    if (new_delete == 2)
                    {
                        break;
                    }
                }
            }
        }
        else if (initiate == 5)
        {
            database = fopen("database.dat", "ab+");

            if (database == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }

            int record_found = 0;

            rewind(database);

            while (fread(&r1, sizeof(struct record), 1, database))
            {
                if (record_found == 0)
                    division();

                printf("\n%s\n%s\n%s\n%s\n%s\n", r1.name, r1.birthdate, r1.cpf, r1.email, r1.phone);
                division();

                record_found = 1;
            }

            if (record_found == 0)
            {
                division();
                printf("\nNo records in the database.");
            }
            fclose(database);
        }

        else if (initiate == 6)
        {
            int deleteall;
            division();
            printf("\nAre you sure you want to delete all records?\n\n[1] Delete All\n[2] Cancel and Return to Menu\n\n");
            scanf(" %d", &deleteall);
            if (deleteall == 1)
            {
                remove("database.dat");
                printf("\nAll records have been deleted.");
            }
            else{
                printf("\nNo records have been deleted.");
            }
        }

        else if (initiate == 7)
        {
            break;
        }

        else
        {
            printf("\nTry a valid option to start.\n");
        }
    }
}