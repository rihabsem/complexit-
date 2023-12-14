#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#define faux 0
#define vrai 1
int menu()
{
    int cod;
    printf("GESTION DES GRAPHES\n");
    printf("--0--FIN\n");
    printf("--1--CREER GRAPH\n");
    printf("--2--DETRUIRE GRAPH\n");
    printf("--3--AJOUTER UN SOMMET\n");
    printf("--4--AJOUTER UN ARC\n");
    printf("--5--ECRIRE GRAPH\n");
    printf("--6--PARCOURS PAR PROFONDEUR\n");
    printf("VOTRE CHOIX?\n");
    scanf("%d", &cod);
    return (cod);
}

int main()
{
    GrapheMat* graphe ;
    booleen trouve = faux;
    while(!trouve)
    {
        switch (menu())
        {
        case 0:
        {
            trouve = vrai;
            break;
            
        }
        case 1:
        {
            int nmax;
            printf("Entrez le nombre maximal de sommet :");
            printf("\n");
            scanf("%d", &nmax);
            booleen value;
            printf("Votre graph est-in value ou non?");
            printf("\n");
            scanf("%d", &value);

            graphe = creerGrapheMat(nmax, value); // Assign the value to graphe
            break;
        }
        case 2:
        {
            printf("detruire graphe");
            detruireGraphe(graphe);
            break;
        }
        case 3:
        {
            printf("Veuillez saisir le nom du sommet a inserer");
            NomSom nouveau;
            scanf("%s", nouveau);
            ajouterUnSommet(graphe, nouveau);
            break;
        }
        case 4:
        {
            printf("Veuillez saisir le nom du premier sommet");
            NomSom s1;
            scanf("%s", s1);
            printf("\n");
            printf("Veuillez saisir le nom du premier sommet");
            NomSom s2;
            scanf("%s", s2);
            printf("\n");
            printf("Veuillez saisir le cout");
            int cout;
            scanf("%d", cout);
            ajouterUnArc(graphe, s1, s2, cout);
            break;
        }
        case 5:
        {
            ecrireGraphe(graphe);
            break;
        }
        case 6:
        {
            parcoursProfond(graphe);
            break;
        }
        case 7:{
        	floyd(graphe);
			break;
		}
        }
    }
    return 0;
}
