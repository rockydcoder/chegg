#include <stdio.h>
#include <string.h>
void DisplayBoysGirls(char [][20],int, char *);
void SearchBoysGirls(char [][20],int, char *);
int ReadFile(char [][20],char [][20]);
main()
{
    char boys[300][20],girls[300][20];
    int retCode, choice, NameCount;
    NameCount = ReadFile(boys,girls);
    printf("NameCount = %d \n", NameCount);

    do
    {
        printf("\n\n\t 1. Search Boy Names\n");
        printf("\t 2. Search Girl Names\n");
        printf("\t 3. Display Boy Names\n");
        printf("\t 4. Display Girl Names\n");
        printf("\t 5. Quit\n\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: SearchBoysGirls(boys,NameCount,"boy");
                    break;
            case 2: SearchBoysGirls(girls,NameCount,"girl");
                    break;
            case 3: DisplayBoysGirls(boys,NameCount,"BOY");
                    break;
            case 4: DisplayBoysGirls(girls,NameCount,"GIRL");
                    break;
        }
    }
    while (choice != 5);
}

int ReadFile(char B[][20],char G[][20])
{
    FILE *inFile;
    int i,NameLen,NameCount=0;
    char rank[4],boy[20], girl[20];
    inFile=fopen("boygirl.txt","r");
    if (inFile == NULL)
    {
        printf("File cannot be opened.");
        fclose(inFile);
        return 1;
    }
    while (fscanf(inFile, "%s%s%s", rank,B[NameCount],G[NameCount])!= EOF)
    {
        NameLen=strlen(B[NameCount]);
        for(i=0;i<NameLen;i++)
            B[NameCount][i]=toupper(B[NameCount][i]);
        NameLen=strlen(G[NameCount]);
        for(i=0;i<NameLen;i++)
            G[NameCount][i]=toupper(G[NameCount][i]);
        NameCount++;
    }
    fclose(inFile);
    return NameCount;
}
void SearchBoysGirls (char BG[][20],int VarieCount, char *BoyGirl)
{
    char name[20];
    int NameLen;
    int flag = 0, i, k = 0;
    if (BoyGirl == "boy") {
        printf("Enter a name of a boy:\n");
        scanf("%s", name);
        while (name[k]) {
            name[k] = toupper(name[k]);
            k++;
        }
        for (i = 0; i < VarieCount; i++) {
            if (strcmp(name, BG[i]) == 0) {
                printf("%s is in the top %d boy names for 2014 with the rank of %d\n", name, VarieCount, i+1);
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf("%s is not in the top %d boy names for 2014.\n", name, VarieCount);
        }
    }

    else {
        printf("Enter a name of a girl:\n");
        scanf("%s", name);
        while (name[k]) {
            name[k] = toupper(name[k]);
            k++;
        }
        for (i = 0; i < VarieCount; i++) {
            if (strcmp(name, BG[i]) == 0) {
                printf("%s is in the top %d girl names for 2014 with the rank of %d\n", name, VarieCount, i+1);
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf("%s is not in the top %d girl names for 2014.\n", name, VarieCount);
        }
    }
}
void DisplayBoysGirls (char BG[][20],int VarieCount, char *BoyGirl)
{
    if (BoyGirl == "BOY") {
        printf("Top %d Boy Names for 2014 Rank Name\n", VarieCount);
        int i;
        for (i = 0; i < VarieCount; i++) {
            printf("%d %s\n", i+1, BG[i]);
        }
    }

    else {
        printf("Top %d Girl Names for 2014 Rank Name\n", VarieCount);
        int i;
        for (i = 0; i < VarieCount; i++) {
            printf("%d %s\n", i+1, BG[i]);
        }
    }
}