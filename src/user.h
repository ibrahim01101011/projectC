 #ifndef CRUD_H_INCLUDED
#define CRUD_H_INCLUDED

typedef struct
{
    char jour[5];
    char mois[5];
    char annee[5];
} date;

typedef struct
{
    char nom[30];
    char prenom[30];
    char role[20];
    char cin[20];
    char tele[20];
    char sexe[20];
    date DN;
    date DR;
    char id[20];
    char mdp[20];

} user;
	
	void ajouter_user(char *filename , user U);
	void sexxe (int sexe, char msg[]);
	int modifier_user(char *filename, user nouv);
	void supprimer_user(char *filename , char *id);
	user chercher_user(char *filename ,char *id);
	//void afficher_user(GtkWidget *liste);
	void user_role(char *filename , char role[20]);
	void pourcentage_user(char *filename , float *nbH, float *nbF);

#endif // CRUD_H_INCLUDED

