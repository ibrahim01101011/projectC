#include <stdio.h>
#include <string.h>
#include "user.h"
#include <stdlib.h>

char *filename= "user.txt";
/*enum
{
	ENOM,
	EPRENOM,
	EROLE,
	ESPE,
	ECIN,
	ETELE,
	ESEXE,
	EDATE_NAISSANCE,
	EDATE_RECRUTEMENT,
	EID,
	EMDP,
	COLUMNS;
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ajouter_user(char *filename , user U){

    FILE *f = fopen("user.txt", "a");
    if (f != NULL)
    {
        fprintf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour,U.DR.mois, U.DR.annee, U.id, U.mdp);
        fclose(f);
        return ;
    }
    else
        return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*	void sexxe (int sexe, char msg[])
{
	if (sexe == 1)
	strcpy(msg, "Homme");

	else if (sexe == 2)
	strcpy (msg, "Femme");
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int modifier_user(char *filename, user nouv){
    int tr = 0;
    user U;
    FILE *f = fopen("user.txt", "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour,U.DR.mois, U.DR.annee, U.id, U.mdp) != EOF){
            if (strcmp(U.id, nouv.id) == 0)
            {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", nouv.nom, nouv.prenom, nouv.role, nouv.cin, nouv.tele, nouv.sexe,
                nouv.DN.jour, nouv.DN.mois, nouv.DN.annee, nouv.DR.jour,nouv.DR.mois, nouv.DR.annee, nouv.id, nouv.mdp);
                tr = 1;
            }
            else
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour,U.DR.mois, U.DR.annee, U.id, U.mdp);
        }
    }
    fclose(f);
    fclose(f2);
    remove("user.txt");
    rename("nouv.txt", "user.txt");
    return tr;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	user chercher_user(char *filename ,char *id){
    user U;
    int tr = 0;
    FILE *f = fopen("user.txt", "r");
    if (f != NULL)
    {
        while (tr == 0 && fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour,U.DR.mois, U.DR.annee, U.id, U.mdp) != EOF)
        {
            if (strcmp(U.id, id) == 0)
                tr = 1;
        }
    }
    fclose(f);
    if (tr == 0)
        strcpy(U.id, ""); // Utilisateur non trouvé, donc le champ id est une chaîne vide.
    return U;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void user_role(char *filename , char role[20]){
    user U;
    FILE *f = fopen("user.txt", "r");
    FILE *f2 = fopen("resultat.txt", "w");

    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour,U.DR.mois, U.DR.annee, U.id, U.mdp) != EOF)
        {
            if (U.role == role)
            {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour,U.DR.mois, U.DR.annee, U.id, U.mdp);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove("user.txt");
    rename("resultat.txt", "user.txt");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void afficher_user(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char nom[50];
    	char prenom[50];
    	int role;
    	char spe[50];
    	int CIN;
    	int tele;
    	int sexe;
    	date date_naissance;
    	date date_recrutement;
    	char id[20];
    	char mdp[20];
	store=NULL;

	FILLE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("role", renderer, "text",EROLE, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("spe", renderer, "text",ESPE, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECIN, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("tele", renderer, "text",ETELE, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("date_naissance", renderer, "text",EDATE_NAISSANCE, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("date_recrutement", renderer, "text",EDATE_RECRUTEMENT, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mdp", renderer, "text",EMDP, NULL);
	gtk_tree_view_append_column (GTK_ TREE _VIEW (liste), column);
	}
	store=gtk_list_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("user.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("user.txt", "a+");
		while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour,U.DR.mois, U.DR.annee, U.id, U.mdp) != EOF)
		{
			gtk_list_store_append (store, &iter)
			gtk_list_store_set (store, &iter, ENOM, nom, EPRENOM, prenom, EROLE, role, ESPE, spe, ECIN, cin, ETELE, tele, ESEXE, sexe, EDATE_NAISSANCE, date_naissance, EDATE_RECRUTEMENT, date_recrutement, EID, id, EMDP, mdp, -1);
		}
		fclose(f)
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void supprimer_user(char *filename , char *id){
	user U;
	user U2;
    FILE *f = fopen("user.txt", "r");
    FILE *f2 = fopen("user2.txt", "w");

	if (f == NULL || f2 == NULL)
		return;
	else
	{
		while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour,U.DR.mois, U.DR.annee, U.id, U.mdp) != EOF)
		{
			if (strcmp(U.nom, U2.nom) != 0 || strcmp(U.prenom, U2.prenom) != 0 || strcmp(U.role, U2.role) != 0 || strcmp(U.cin, U2.cin) != 0 || strcmp(U.tele, U2.tele) != 0 || strcmp(U.sexe, U2.sexe) != 0
            || strcmp(U.DN.jour, U2.DN.jour) != 0 || strcmp(U.DN.mois, U2.DN.mois) != 0 || strcmp(U.DN.annee, U2.DN.annee) != 0 || strcmp(U.DR.jour, U2.DR.jour) != 0 ||strcmp(U.DR.mois, U2.DR.mois) != 0 || strcmp(U.DR.annee, U2.DR.annee) != 0 || strcmp(U.id, U2.id) != 0 || strcmp(U.mdp, U2.mdp) != 0 )

                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U2.nom, U2.prenom, U2.role, U2.cin, U2.tele, U2.sexe,
                U2.DN.jour, U2.DN.mois, U2.DN.annee, U2.DR.jour,U2.DR.mois, U2.DR.annee, U2.id, U2.mdp);
       		 }
   	 }
    fclose(f);
    fclose(f2);
    remove("user.txt");
    rename("user2.txt", "user.txt");
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pourcentage_user(char *filename, float *nbH, float *nbF) {
    user U;
    int TH = 0, TF = 0, TU = 0;

    FILE *f = fopen("user.txt", "r");
    if (f == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, U.role, U.cin, U.tele, U.sexe,
                 U.DN.jour, U.DN.mois, U.DN.annee, U.DR.jour, U.DR.mois, U.DR.annee, U.id, U.mdp) != EOF) {
        int sexe = atoi(U.sexe);
        if (sexe == 1) {
            TH++;
        } else if (sexe == 2) {
            TF++;
        }
        TU++;
    }

    fclose(f);
    *nbH = (float)TH / TU * 100;
    *nbF = (float)TF / TU * 100;
}
