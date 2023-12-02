#include <gtk/gtk.h>

void
on_button_aj_ajouter_WT_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_aj_annuler_WT_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_mod_modif_WT_clicked         (GtkButton       *objet_graphique,

                                        gpointer         user_data);
void
on_button_mod_annuler_WT_clicked       (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_Supprimer_WT_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview_liste_row_WT_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobutton_aj_homme_WT_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_aj_femme_WT_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_mod_homme_WT_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_mod_femme_WT_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_button_Supprimer_oui_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_Supprimer_Annuler_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


