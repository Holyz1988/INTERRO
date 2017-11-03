#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1;

    //boucle for et while qui comptent de 1 � 10.
    while (i<=10)
    {
        printf("%d\n", i);
        i++;
    }

    for (i=1;i <= 10; i++)
    {
        printf("%d\n", i);
    }

    /*
    Le #define va "b�tement remplacer" ce qui est d�fini par la
    valeur associ�, sans prendre de l'espace en m�moire.
    La constante est une valeur � d�clarer qui va prendre
    de l'espace en m�moire, et qu'on ne peut pas modifier.

    */

    //d�claration de la variable choixMenu
    int choixMenu;

    printf("1. Pizza\n");
    printf("2. Salades\n");
    printf("3. Plats\n");
    printf("4. Boisson\n");
    printf("5. Dessert\n");
    printf("Votre Choix : \n");

    fseek(stdin, 0, SEEK_END);
    scanf("%d", &choixMenu);

    //Affichage d'un menu � l'aide de if..else
    if (choixMenu == 1)
    {
        printf("Bienvenue dans le menu des Pizzas !\n");
    }
    else if (choixMenu == 2)
    {
        printf("Bienvenue dans le menu des Salades !\n");
    }
    else if (choixMenu == 3)
    {
        printf("Bienvenue dans le menu des Plats ! \n");
    }
    else if (choixMenu == 4)
    {
        printf("Bienvenue dans le menu des Boissons ! \n");
    }
    else
    {
        printf("Bienvenue dans le menu des Dessert ! \n");
    }

    //Affichage du m�me menu en utilisant un switch.
    switch(choixMenu)
    {
    case 1:
        printf("Bienvenue dans le menu des Pizzas !\n");
        break;
    case 2:
        printf("Bienvenue dans le menu des Salades !\n");
        break;
    case 3:
        printf("Bienvenue dans le menu des Plats ! \n");
        break;
    case 4:
        printf("Bienvenue dans le menu des Boissons ! \n");
        break;
    default:
        printf("Bienvenue dans le menu des Dessert ! \n");
    }

    return 0;
}
