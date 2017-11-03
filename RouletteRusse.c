#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Génère un nombre aléatoire entre min et max
int nbAleatoire(int min, int max)
{
    return rand()%(max-min+1)+min;
}

int testCouleur(int resultatRoulette)
{
    if (resultatRoulette==0)
    {
        return 0; // 0
    }
    else if (resultatRoulette%2!=0)
    {
        return 1; // NOIR
    }
    else if (resultatRoulette%2==0)

    {
        return 2; // ROUGE
    }
}

int partieRoulette(int nbJetonJoueur)
{
    int nbJetonMisee;
    int choixCouleur;
    int resultatRoulette;

    while((nbJetonJoueur > 0) && (nbJetonJoueur < 100))
    {
        /*On redemande la mise tant que la mise
        du joueur et superieur a son nombre de jetons*/
        do
        {
            printf("Vous possedez %d jetons\n", nbJetonJoueur);
            printf("Vous pouvez miser entre 1 et 25 jetons :\n");
            scanf("%d", &nbJetonMisee);

            //SI le nombre de jeton misée et superieur à 25
            if (nbJetonMisee > 25)
            {
                printf("Vous devez misez au moins 1 jeton et au maximum 25 jetons :\n");
                printf("Vous possedez %d jetons\n", nbJetonJoueur);
            }
            //Si le nombre de jeton misee et > nombre de jeton joueur
            else if (nbJetonMisee > nbJetonJoueur)
            {
                printf("Vous ne possedez que %d jetons\n", nbJetonJoueur);
            }

        }
        while ((nbJetonMisee > nbJetonJoueur) || (nbJetonMisee > 25));

        //Choix de la couleur
        do
        {
            printf("Veuillez choisir la couleur :\n");
            printf("1 pour le NOIR\n");
            printf("2 pour le ROUGE\n");
            scanf("%d", &choixCouleur);
        }
        while(choixCouleur!=2 && choixCouleur!=1);

        //On joue à la roulette
        resultatRoulette=nbAleatoire(0,36);
        printf("%d\n", resultatRoulette);

        do
        {

            switch(testCouleur(resultatRoulette))
            {
            case 0: //On fait un zero
                printf("Oups, vous etes tombé sur le 0\n");
                nbJetonJoueur -= nbJetonMisee;
                break;
            case 1://On tombe sur la couleur Noir
                if (choixCouleur==1)
                {
                    nbJetonJoueur += nbJetonMisee;
                    printf("Bravo, vous avez fait un %d et vous etes tombe sur le noir !\n", resultatRoulette);
                }
                else
                {
                    nbJetonJoueur -= nbJetonMisee;
                    printf("Oups, il fallait choisir le noir ...\n");
                }
                break;
            case 2://On tombe sur la couleur Rouge
                if (choixCouleur==2)//La couleur est la même que la mise du joueur
                {
                    nbJetonJoueur += nbJetonMisee;
                    printf("Bravo, vous avez fait un %d et vous etes tombe sur le rouge !\n", resultatRoulette);
                }
                else // La couleur est différente de la mise du joueur
                {
                    nbJetonJoueur -= nbJetonMisee;
                    printf("Oups, il fallait choisir le rouge...\n");
                }
            }
            break;
        }
        while (nbJetonJoueur > 0);
    }
    return nbJetonJoueur;
}

int partieRouletteRusse(int *nbJetonJoueur, int joueurEnVie)
{
    int detente;
    int i=0;
    int barillet[6] = {0, 0, 0, 0, 0, 0};
    int rejouerRoulette = 0;

    //On met une balle aléatoirement dans la chambre
    barillet[nbAleatoire(0,5)] = 1;

    //Le joueur presse la détente
    printf("Appuyez sur la detente ! (saisir la touche 1)\n");
    scanf("%d", &detente);

    //Si on tombe sur la balle, le joueur meurt, on renvoi 0
    if (barillet[i]==1)
    {
        printf("RIP in peace, le joueur est mort\n");
        return 0;
    }
    //Si la balle n'est pas dans le barillet
    else if (barillet[i]==0)
    {
        //On déplace le barillet d'un cran
        for (i=0; i<5; i++)
        {
            int tmp;
            tmp = barillet[i];
            barillet[i] = barillet[i+1];
            barillet[i+1] = tmp;
        }
        (*nbJetonJoueur)+=20;
        printf("Vous possedez %d jetons\n", *nbJetonJoueur);
        printf("continuer la roulette russe (1) ou repartir a la roulette classique(2) ?\n");
        scanf("%d", &rejouerRoulette);

        if (rejouerRoulette == 1)//Si on veut rejouer, on renvoi 1
        {
            return 1;
        }
        i++;
    }

    if (*nbJetonJoueur >= 100)
    {
        printf("WIN");
    }
}

int main()
{
    srand(time(NULL));  //On initialise une et une seul fois avec le random

    //Le Joueur commence avec 10 Jetons
    int nbJetonJoueur = 10;
    int joueurEnVie = 1;
    int rejouerRoulette = 1;


    printf("Bienvenue a la Roulette, Russes et Roulette russe\n");

    //Do while créer pour rejouer à la roulette si le joueur souhaite rejouer après une détente
    do
    {
        //On joue à la roulette
        nbJetonJoueur = partieRoulette(nbJetonJoueur);

        //Si on a plus de 100 jetons, on gagne
        if (nbJetonJoueur >= 100)
        {
            printf("WIN\n");
            return 0;
        }


        //Buggé, on ne peut pas rejouer à la roulette normal
        //On joue à la roulette russe tant que le nombre de jeton n'est pas superieur à 100
        while ((joueurEnVie != 0) || (nbJetonJoueur >= 100))
        {
            //On joue à la roulette russe
            joueurEnVie=partieRouletteRusse(&nbJetonJoueur, joueurEnVie);
        }
    }
    while ((rejouerRoulette==1) && (nbJetonJoueur > 0) && (joueurEnVie == 1));



    return 0;

}
