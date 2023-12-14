#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

static void razMarque(GrapheMat* graphe){
	int i;
	for(i=0;i<graphe->n;i++) graphe->marque[i] = faux;
}
//
GrapheMat* creerGrapheMat (int nMax, int value){
	int i,j;
	GrapheMat* graphe = (GrapheMat*)malloc(sizeof(GrapheMat));
	graphe->n = 0;
	graphe->value = nMax;
	graphe->nomS = (NomSom*)malloc(sizeof(NomSom)*nMax);
	graphe->marque = (booleen*)malloc(sizeof(booleen)*nMax);
	graphe->element = (int*)malloc(sizeof(int)*nMax*nMax);
	graphe->valeur = (int*)malloc(sizeof(int)*nMax*nMax);
	
	for(i=0;i<nMax;i++)
	{
		for(j=0;j<nMax;j++)
		{
			graphe->element [i*nMax+j] = faux;
			graphe->valeur [i*nMax+j] = INFINI;
		}
	}
	razMarque(graphe);
}
//
void detruireGraphe (GrapheMat* graphe){
	free(graphe->nomS);
	free(graphe->marque);
	free(graphe->element);
	free(graphe->valeur);
	free(graphe);
}
//
static int rang (GrapheMat* graphe, NomSom nom)
{
	int i=0;
	booleen trouve = faux;
	while((i<graphe->n) && !trouve)
	{
		trouve = strcmp(graphe->nomS[i],nom) == 0;
		if(!trouve) i++;
	}
	return trouve ? i : -1;
}
//
void ajouterUnSommet (GrapheMat* graphe, NomSom nom)
{
	nom = malloc(50*sizeof(NomSom));
	if(rang (graphe,nom) == -1){
		strcpy (graphe->nomS [graphe->n++],nom);
	}
	else{
		printf("\n%s deja defini\n",nom);
	}
	free(nom);
}
//
void ajouterUnArc (GrapheMat* graphe, NomSom somD, NomSom somA, int cout)
{
	int nMax = graphe->nMax;
	int rd = rang(graphe,somD);
	int rg = rang(graphe,somA);
	graphe->element [rd*nMax+rg];
	graphe->valeur [rd*nMax+rg];
}
//
void ecrireGraphe (GrapheMat* graphe){
	int nMax = graphe->nMax;
	int i,j;
	for(i=0;i<graphe->n;i++)
	{
		printf("\n%s:",graphe->nomS[i]);
		for(j=0;j<graphe->n;j++)
		{
			if(graphe->element[i*nMax+j]==vrai)
			{
				printf("%s",graphe->nomS[j]);
				if(graphe->value)
				{
					printf("(%d)",graphe->valeur[i*nMax+j]);
				}
			}
		}
		printf(";");
	}
}
//
static void profondeur (GrapheMat* graphe, int numSommet){
	int i;
	int nMax = graphe->nMax;
	graphe->marque [numSommet] = vrai;
	printf("%s\n",graphe->nomS [numSommet]);
	for(i = 0;i<graphe->n;i++)
	{
		if(graphe->element [numSommet*nMax+i]==vrai && !graphe->marque[i])
		profondeur (graphe,i);
	}
}
//
void parcoursProfond (GrapheMat* graphe)
{
	razMarque (graphe);
	int i;
	for(i=0;i<graphe->n;i++)
	{
		if(!graphe->marque[i]) profondeur (graphe,i);
	}
}
//


