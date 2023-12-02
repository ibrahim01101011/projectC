#include <stdio.h>
#include <stdlib.h>

#include "user.h"

int ajouter(char *utilisateur, user U)
{
    FILE *f = fopen(utilisateur, "a");
    if (f != NULL)
    {
        fprintf(f, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                U.nom, U.prenom, U.role, U.spe, U.CIN, U.tele, U.sexe, U.id, U.mdp,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour, U.DR.mois, U.DR.annee);
        fclose(f);
        return 1;
    }
    else
    {
        return 0;
    }
}

int modifier(char *utilisateur, char id[20], user nouv)
{
    int tr = 0;
    user U;
    FILE *f = fopen(utilisateur, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                      U.nom, U.prenom, &U.role, U.spe, &U.CIN, &U.tele, &U.sexe, U.id, U.mdp,
                      &U.DN.jour, &U.DN.mois, &U.DN.annee, &U.DR.jour, &U.DR.mois, &U.DR.annee) != EOF)
        {
            if (strcmp(U.id, id) == 0) // Utilisez strcmp pour comparer des chaînes
            {
                fprintf(f2, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                        nouv.nom, nouv.prenom, nouv.role, nouv.spe, nouv.CIN, nouv.tele, nouv.sexe, nouv.id, nouv.mdp,
                        nouv.DN.jour, nouv.DN.mois, nouv.DN.annee, nouv.DR.jour, nouv.DR.mois, nouv.DR.annee);
                tr = 1;
            }
            else
            {
                fprintf(f2, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                        U.nom, U.prenom, U.role, U.spe, U.CIN, U.tele, U.sexe, U.id, U.mdp,
                        U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour, U.DR.mois, U.DR.annee);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(utilisateur);
    rename("nouv.txt", utilisateur);
    return tr;
}

int supprimer(char *utilisateur, int id)
{
    int tr = 0;
    user U;
    FILE *f = fopen(utilisateur, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                      U.nom, U.prenom, &U.role, U.spe, &U.CIN, &U.tele, &U.sexe, U.id, U.mdp,
                      &U.DN.jour, &U.DN.mois, &U.DN.annee, &U.DR.jour, &U.DR.mois, &U.DR.annee) != EOF)
        {
            if (U.id == id)
                tr = 1;
            else
                fprintf(f2, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                        U.nom, U.prenom, U.role, U.spe, U.CIN, U.tele, U.sexe, U.id, U.mdp,
                        U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour, U.DR.mois, U.DR.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove(utilisateur);
    rename("nouv.txt", utilisateur);
    return tr;
}

user chercher(char *utilisateur, char id[20])
{
    user U;
    int tr = 0;
    FILE *f = fopen(utilisateur, "r");
    if (f != NULL)
    {
        while (tr == 0 && fscanf(f, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                                U.nom, U.prenom, &U.role, U.spe, &U.CIN, &U.tele, &U.sexe, U.id, U.mdp,
                                &U.DN.jour, &U.DN.mois, &U.DN.annee, &U.DR.jour, &U.DR.mois, &U.DR.annee) != EOF)
        {
            if (strcmp(U.id, id) == 0)
                tr = 1;
        }
    }
    fclose(f);
    if (tr == 0)
        U.id = -1;

    return U;
}

void UserRole(char *utilisateur, int role)
{
    user U;

    FILE *f = fopen(utilisateur, "r");
    FILE *f2 = fopen("resultat.txt", "w");

    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                      U.nom, U.prenom, &U.role, U.spe, &U.CIN, &U.tele, &U.sexe, U.id, U.mdp,
                      &U.DN.jour, &U.DN.mois, &U.DN.annee, &U.DR.jour, &U.DR.mois, &U.DR.annee) != EOF)
        {
            if (U.role == role)
            {
                fprintf(f2, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                        U.nom, U.prenom, U.role, U.spe, U.CIN, U.tele, U

void pourcentageUser(char *utilisateur, float *nbH, float *nbF) {
    FILE *f = fopen(utilisateur, "r");

    if (f == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    user U;
    int TH = 0, TF = 0, TU = 0;

    while (fscanf(f, "%s %s %d %s %d %d %d %s %s %d %d %d %d %d %d \n",
                  U.nom, U.prenom, &U.role, U.spe, &U.CIN, &U.tele, &U.sexe, U.id, U.mdp,
                  &U.DN.jour, &U.DN.mois, &U.DN.annee, &U.DR.jour, &U.DR.mois, &U.DR.annee) != EOF)
    {
        if (U.sexe == 1)
        {
            TH++;
        }
        else if (U.sexe == 2)
        {
            TF++;
        }

        TU++;
    }

    fclose(f);

    *nbH = ((float)TH / TU) * 100;
    *nbF = ((float)TF / TU) * 100;
}


