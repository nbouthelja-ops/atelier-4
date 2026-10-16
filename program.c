#include <stdio.h>

#define NB_VALEURS 3
#define MAX_LONGUEUR 50
#define PAS_GRADUATION 2   /* une graduation tous les 2 */

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

    double echelle = (double)MAX_LONGUEUR / maximum;

    /* repere[c] vaut 1 si la colonne c porte une graduation */
    char repere[MAX_LONGUEUR] = { 0 };
    for (int g = PAS_GRADUATION; g <= maximum; g += PAS_GRADUATION)
    {
        int colonne = (int)(g * echelle) - 1;
        if (colonne >= 0 && colonne < MAX_LONGUEUR)
        {
            repere[colonne] = 1;
        }
    }

    /* Barres avec lignes de suivi ('.') */
    for (int i = 0; i < NB_VALEURS; i++)
    {
        int nb_croix = (int)(valeurs[i] * echelle);

        printf("| ");
        for (int c = 0; c < MAX_LONGUEUR; c++)
        {
            if (c < nb_croix)
            {
                printf("x");
            }
            else if (repere[c])
            {
                printf(".");
            }
            else
            {
                printf(" ");
            }
        }
        printf(" %d\n", valeurs[i]);
    }

    /* Axe avec les graduations '+' */
    printf("+-");
    for (int c = 0; c < MAX_LONGUEUR; c++)
    {
        printf("%c", repere[c] ? '+' : '-');
    }
    printf("\n");

    /* Nombres sous les graduations */
    char etiquettes[MAX_LONGUEUR + 10];
    for (int k = 0; k < MAX_LONGUEUR + 9; k++)
    {
        etiquettes[k] = ' ';
    }
    etiquettes[MAX_LONGUEUR + 9] = '\0';
    etiquettes[0] = '0';

    for (int g = PAS_GRADUATION; g <= maximum; g += PAS_GRADUATION)
    {
        char nombre[12];
        int longueur = snprintf(nombre, sizeof(nombre), "%d", g);
        int colonne = (int)(g * echelle) - 1;
        int debut = 2 + colonne - (longueur - 1);   /* dernier chiffre sous la graduation */

        for (int k = 0; k < longueur; k++)
        {
            etiquettes[debut + k] = nombre[k];
        }
    }
    printf("%s\n", etiquettes);

    return 0;
}