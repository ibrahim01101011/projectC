#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "user.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

int sexe;





void
on_radiobutton_mod_homme_WT_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	sexe=1;
}


void
on_radiobutton_mod_femme_WT_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	sexe=2;
}


void
on_radiobutton_aj_homme_WT_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	sexe=1;
}

void
on_radiobutton_aj_femme_WT_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	sexe=2;
}




void
on_button_aj_ajouter_WT_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	user U;
	int JN,MN,AN;
	int JR,MR,AR;

	GtkWidget *nom;
	GtkWidget *prenom;
	GtkWidget *role;
	GtkWidget *cin;
	GtkWidget *tele;
	GtkWidget *id;
	GtkWidget *mdp;

    	nom = lookup_widget(objet_graphique, "entry_aj_nom_WT");
	strcpy(U.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

	prenom=lookup_widget(objet_graphique, "entry_aj_prenom_WT");
	strcpy(U.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

	role=lookup_widget(objet_graphique, "comboboxentry_aj_role_WT");
	strcpy(U.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX (role)));

	cin=lookup_widget(objet_graphique, "entry_aj_cin_WT");
	strcpy(U.cin,gtk_entry_get_text(GTK_ENTRY(cin)));

	tele=lookup_widget(objet_graphique, "entry_aj_telephone_WT");
	strcpy(U.tele,gtk_entry_get_text(GTK_ENTRY(tele)));

	id=lookup_widget(objet_graphique, "entry_aj_id_WT");
	strcpy(U.id,gtk_entry_get_text(GTK_ENTRY(id)));

	mdp=lookup_widget(objet_graphique, "entry_aj_mdp_WT");
	strcpy(U.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));

	//sexe

	if(sexe==1)
	{strcpy(U.sexe,"Homme");}
	else if(sexe==2){strcpy(U.sexe,"Femme");}


	//date de naissance

	GtkWidget *JourN;
	GtkWidget *MoisN;
	GtkWidget *AnneeN;
	JourN=lookup_widget (objet_graphique, "spinbutton_aj_jour_naissance_WT");
	MoisN=lookup_widget (objet_graphique, "spinbutton_aj_mois_naissance_WT");
	AnneeN=lookup_widget(objet_graphique, "spinbutton_aj_annee_naissance_WT");

	JN=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (JourN));
	MN=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (MoisN));
	AN=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (AnneeN));
	sprintf(U.DN.jour,"%d",JN);
	sprintf(U.DN.mois,"%d",MN);
	sprintf(U.DN.annee,"%d",AN);

	//date de recrutement

	GtkWidget *JourR;
	GtkWidget *MoisR;
	GtkWidget *AnneeR;
	JourR=lookup_widget (objet_graphique, "spinbutton_aj_jour_recrut_WT");
	MoisR=lookup_widget (objet_graphique, "spinbutton_aj_mois_recrut_WT");
	AnneeR=lookup_widget(objet_graphique, "spinbutton_aj_annee_recrut_WT");

	JR=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (JourR));
	MR=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (MoisR));
	AR=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (AnneeR));
	sprintf(U.DR.jour,"%d",JR);
	sprintf(U.DR.mois,"%d",MR);
	sprintf(U.DR.annee,"%d",AR);

	ajouter_user("user.txt" , U);

/*user U;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11;
GtkWidget *Ajouter_window;
GtkWidget *Utilisateurs_window;
GtkWidget *treeview1;

Ajouter_window=lookup_widget(objet,"Ajouter_window");

input1=lookup_widget(objet_graphique,"nom");
input2=lookup_widget(objet_graphique,"prenom");
input3=lookup_widget(objet_graphique,"role");
input4=lookup_widget(objet_graphique,"spe");
input5=lookup_widget(objet_graphique,"CIN");
input6=lookup_widget(objet_graphique,"tele");
input7=lookup_widget(objet_graphique,"sexe");
input8=lookup_widget(objet_graphique,"date_naissance");
input9=lookup_widget(objet_graphique,"date_recrutement");
input10=lookup_widget(objet_graphique,"id");
input11=lookup_widget(objet_graphique,"mdp");

strcpy(U.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(U.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(U.role,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(U.spe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(U.CIN,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(U.tele,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(U.sexe,gtk_entry_get_text(GTK_ENTRY(input7)));
//strcpy(U.date_naissance,gtk_entry_get_text(GTK_ENTRY(input8)));
//strcpy(U.date_recrutement,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(U.id,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(U.mdp,gtk_entry_get_text(GTK_ENTRY(input11)));

ajouter_user(U);

Ajouter_window=lookup_widget(objet,"Ajouter_window");

gtk_widget_destroy(Ajouter_window);
Utilisateurs_window=lookup_widget(objet,"Utilisateurs_window");
Utilisateurs_window=create_Utilisateurs_window();

gtk_widget_show(Utilisateurs_window);

treeview1=lookup_widget(Utilisateurs_window,"treeview1");

afficher_user(treeview1);

*/
}

void
on_button_aj_annuler_WT_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_mod_modif_WT_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	user U;	
	user nouv;
	int JN,MN,AN;
	int JR,MR,AR;

	GtkWidget *nom;
	GtkWidget *prenom;
	GtkWidget *role;
	GtkWidget *cin;
	GtkWidget *tele;
	GtkWidget *id;
	GtkWidget *mdp;

    	nom = lookup_widget(objet_graphique, "entry_mod_nom_WT");
	strcpy(nouv.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

	prenom=lookup_widget(objet_graphique, "entry_mod_prenom_WT");
	strcpy(nouv.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

	role=lookup_widget(objet_graphique, "comboboxentry_mod_role_WT");
	strcpy(nouv.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX (role)));

	cin=lookup_widget(objet_graphique, "entry_mod_cin_WT");
	strcpy(nouv.cin,gtk_entry_get_text(GTK_ENTRY(cin)));

	tele=lookup_widget(objet_graphique, "entry_mod_telephone_WT");
	strcpy(nouv.tele,gtk_entry_get_text(GTK_ENTRY(tele)));

	id=lookup_widget(objet_graphique, "entry_mod_id_WT");
	strcpy(nouv.id,gtk_entry_get_text(GTK_ENTRY(id)));

	mdp=lookup_widget(objet_graphique, "entry_mod_mdp_WT");
	strcpy(nouv.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));

	//sexe

	if(sexe==1)
	{strcpy(nouv.sexe,"Homme");}
	else if(sexe==2){strcpy(nouv.sexe,"Femme");}


	//date de naissance

	GtkWidget *JourN;
	GtkWidget *MoisN;
	GtkWidget *AnneeN;
	JourN=lookup_widget (objet_graphique, "spinbutton_mod_jour_naissance_WT");
	MoisN=lookup_widget (objet_graphique, "spinbutton_mod_mois_naissance_WT");
	AnneeN=lookup_widget(objet_graphique, "spinbutton_mod_annee_naissance_WT");

	JN=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (JourN));
	MN=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (MoisN));
	AN=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (AnneeN));
	sprintf(nouv.DN.jour,"%d",JN);
	sprintf(nouv.DN.mois,"%d",MN);
	sprintf(nouv.DN.annee,"%d",AN);

	//date de recrutement

	GtkWidget *JourR;
	GtkWidget *MoisR;
	GtkWidget *AnneeR;
	JourR=lookup_widget (objet_graphique, "spinbutton_mod_jour_recrut_WT");
	MoisR=lookup_widget (objet_graphique, "spinbutton_mod_mois_recrut_WT");
	AnneeR=lookup_widget(objet_graphique, "spinbutton_mod_annee_recrut_WT");

	JR=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (JourR));
	MR=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (MoisR));
	AR=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (AnneeR));
	sprintf(nouv.DR.jour,"%d",JR);
	sprintf(nouv.DR.mois,"%d",MR);
	sprintf(nouv.DR.annee,"%d",AR);

	modifier_user("user.txt", nouv);

}


void
on_button_mod_annuler_WT_clicked       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_Supprimer_WT_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *Supprimer_window;
	Supprimer_window =create_Supprimer_window ();
	gtk_widget_show (Supprimer_window);
}


void
on_treeview_liste_row_WT_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gintptr* role ;
	gchar* spe;
	gintptr* CIN;
	gintptr* tele;
	gintptr* sexe;
	date* date_naissance;
	date* date_recrutement;
	gchar* id;
	gchar* mdp;
	user U;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &nom, 1, &prenom, 2, &role, 3, &spe,4, &CIN, 5, &tele, 6, &sexe, 7, &date_naissance, 8, &date_recrutement, 9, &id, 10, &mdp, -1);
		// // kopie des voleurs dans la variable pdu type personne pour le passer à la fonction de suppression
		strcpy(U.nom, nom);
		strcpy(U.prenom, prenom);
		strcpy(U.role, role);
		strcpy(U.spe, spe);
		strcpy(U.CIN, CIN);
		strcpy(U.tele, tele);
		strcpy(U.sexe, sexe);
		//strcpy(U.date_naissance, date_naissance);
		//strcpy(U.date_recrutement, date_recrutement);
		strcpy(U.id, id);
		strcpy(U.mdp,mdp);
	}

		//appel de la fonction de suppression
		supprimer_user(id);
		// mise à jour de l'affichage de la treeview
		afficher_user(treeview);


*/

}

void
on_button_Supprimer_oui_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_Supprimer_Annuler_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


