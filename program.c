#include <stdio.h>

#define NB_VALEURS 3
#define MAX_LIGNES 15

/* Affiche une ligne de l'histogramme vertical.
   Une colonne contient "xxx" si sa valeur est superieure ou egale a y. */
void afficher_ligne_histov(const int valeurs[], int taille, double y)
{
    printf("| ");
    for (int j = 0; j < taille; j++)
    {
        if (valeurs[j] >= y)
        {
            printf("xxx ");
        }
        else
        {
            printf("    ");
        }
    }
    printf("\n");
}

int main(void)
{
    int valeurs[NB_VALEURS] = { 8, 4, 12 };

    /* Recherche du maximum (etape 2) */
    int maximum = valeurs[0];
    for (int i = 1; i < NB_VALEURS; i++)
    {
        if (valeurs[i] > maximum)
        {
            maximum = valeurs[i];
        }
    }

    /* Affichage ligne par ligne, de haut en bas */
    for (int i = 0; i < MAX_LIGNES; i++)
    {
        /* Attention : (double) pour eviter la division entiere */
        double y = maximum - (double)i * maximum / MAX_LIGNES;
        afficher_ligne_histov(valeurs, NB_VALEURS, y);
    }

    printf("+---------------------------------------\n");

    return 0;
}