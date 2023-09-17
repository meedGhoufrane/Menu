#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct personne{
	char id[5];
	char nom[50];
	char prenom[50];
	char gmail[50];
	char password[50];	
};

struct table{
	struct personne pr[50];
	int count;
};

struct table t ;
int i ;

int main() {
    
    t.count = 0;
    int choice ;
    char id[5];

   do {
        printf("\n===================================\n");
        printf("            Menu d'application\n");
        printf("===================================\n");
        printf("[1] Afficher les données\n");
        printf("[2] Ajouter une donnée\n");
        printf("[3] Rechercher sur une donnée\n");
        printf("[4] Supprimer une donnée\n");
        printf("[5] Supprimer les données répétées\n");
        printf("[6] Générer le wordlist\n");
        printf("[7] Générer le wordlist dans un fichier .txt\n");
        printf("===================================\n");

        printf("Tapez votre choix [1-7] : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	afficher();
                break;
            case 2:
                add();
                break;
            case 3:
            	printf("donner voter id :\n");
            	scanf("%s",id);
            	if(rechercher(id) == -1){
            		printf(" voter id n exisit pas \n");
            
				}else{
            	    printf("les nom est :%s\nles prenom est :%s\nles gmail est:%s\nles password est:%s\n",t.pr[rechercher(id)].nom,t.pr[rechercher(id)].prenom,t.pr[rechercher(id)].gmail,t.pr[rechercher(id)].password);	
					}
				break; 
            case 4:
                    
            
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while (1);
    getch();

    return 0;
}

void  add(){
	printf("donner le id: \n");
	scanf("%s",t.pr[t.count].id);
	printf("donner le nom: \n");
	scanf("%s",t.pr[t.count].nom);
	printf("donner le prenom : \n");
	scanf("%s",t.pr[t.count].prenom);
	printf("donner le gmail : \n");
	scanf("%s",t.pr[t.count].gmail);
	printf("donner le password: \n");
	scanf("%s",t.pr[t.count].password);
	
	t.count++;
};

 void afficher(){
	
	for( i=0;i < t.count;i++){
	
		printf("les id  est:%s\nles nom est:%s\nles prenom est:%s\nles gmail est:%s\nles password est:%s\n",t.pr[i].id,t.pr[i].nom,t.pr[i].prenom,t.pr[i].gmail,t.pr[i].password);
	}
};


int rechercher(char id[5]){
	int pos;
	pos = -1;
	for( i=0;i<t.count;i++){
		if(strcmp(id,t.pr[i].id) == 0){
			pos=i;
			break;
		}
	}
	return pos;
}


