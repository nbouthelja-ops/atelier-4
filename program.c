#include <stdio.h>

#define NB_VALEURS 3
#define MAX_LONGUEUR 50

int main(void)
{
    int valeurs[NB_VALEURS] = { 8, 4, 12 };

    /* Recherche du maximum */
    int maximum = valeurs[0];
    for (int i = 1; i < NB_VALEURS; i++)
    {
        if (valeurs[i] > maximum)
        {
            maximum = valeurs[i];
        }
    }

    /* Echelle : nombre de croix pour une unite */
    double echelle = (double)MAX_LONGUEUR / maximum;

    /* Affichage de l'histogramme */
    for (int i = 0; i < NB_VALEURS; i++)
    {
        int nb_croix = (int)(valeurs[i] * echelle);

        printf("| ");
        for (int j = 0; j < nb_croix; j++)
        {
            printf("x");
        }
        printf(" %d\n", valeurs[i]);
    }

    printf("+-------------------------------------------------------\n");

    return 0;
}