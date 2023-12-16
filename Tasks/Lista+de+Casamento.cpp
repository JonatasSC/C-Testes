#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

using namespace std;

struct convidados {
    char nome[31];
    char presente[31];
    convidados *nom,*pres;
};

int main(void){
    setlocale (LC_ALL, "portuguese" );

    struct convidados *novo,*anterior,*anteriorp,*anteriorex,*anteriorexp,*inicio,*iniciop,*proximo,*proximop,*busca,*buscap;
    int n=0,p=0,o=0,i=0,opcao,sair,terminar;
    char texto[31];

    do{
        system("cls");
        printf("\n                  		 Menu\n");
        printf("\n          Digite 1 para adicionar um convidado e escolher o presente");
        printf("\n          Digite 2 para ver a lista de convidados e os seus presentes");
        printf("\n          Digite 3 para remover o convidado e o presente");
        printf("\n          Digite 0 para sair");
		printf("\n          Digite sua opção: ");
        
        scanf("%d",&opcao);
        
        switch (opcao){
        	
        case 1:
            printf("\nAdicionando convidado...");
            novo = (struct convidados*) malloc(sizeof(struct convidados));
            
            printf("\n\nInserindo...");
            printf("\nNome do convidado %d: ",n+1);
            fflush(stdin);
            gets (novo->nome);
            novo->nom = NULL;
            
            if (n == 0){
            	inicio = novo;
			}
			else {anterior->nom = novo;
			}
			proximo = novo;
			anterior = novo;
			n++;
			
			printf("\nAdicionando presente...");
			
			printf("\n\nInserindo...");
			printf("\nQual é o presente? %d:",p+1);
			fflush(stdin);
			gets (novo->presente);
			novo->pres = NULL;
			
			if (p == 0){
				iniciop = novo;
			}
			else {anteriorp->pres = novo;
			}
			
			proximop = novo;
			anteriorp = novo;
			p++;
			
		break;
		
		case 2:
			
			terminar = 0;
			if(inicio == 0){
				printf("\nLista vazia!\n");
				system("pause");
			}
			else{
				printf("\nmostrando a lista de convidados e os presentes...");
				o=0;
				sair=0;
				while(sair != 1){
					if(o==0){
						printf("\nConvidado: %d %s ",o+1,inicio->nome);
						printf("...Presente: %d %s\n\n",o+1,iniciop->presente);
						proximo = inicio->nom;
						proximop = iniciop->pres;
					}
					else{
						printf("\nConvidado: %d %s ",o+1,proximo->nome);
						printf("...Presente: %d %s\n\n",o+1,proximo->presente);
						proximo = proximo->nom;
						proximop = proximop->pres;
					}
					if(proximo == NULL){
						sair = 1;
					}
					o++;
				}
				system("pause");		
			}
		break;	
		
		case 3:
			terminar = 0;
			if(inicio == 0){
				printf("\nLista Vazia!\n");
				system("pause");
			}else{
			printf("\nRemovendo convidado e presente...\n\n");
			printf("Digite o nome do convidado que quer remover: ");
			fflush(stdin);
			gets(texto);
			busca = inicio,iniciop;
			anteriorex = inicio,iniciop;
			while(terminar != 1){
				if(!strcmp(texto,busca->nome)){
					if(busca == inicio){
						inicio = busca->nom;
						iniciop = busca->pres;
					}
					else{
						anteriorex->nom = busca->nom;
						anteriorexp->pres = busca->pres;
					}
					free(busca);
					printf("\nConvidado removido...");
					system("pause");
					if(busca->nom == NULL){
						anterior = anteriorex;
						anteriorp = anteriorexp;
					}
					terminar = 1;
				}
				
					else{
						anteriorex = busca;
						if(busca->nom == NULL);
						printf("\nConvidado não encontrado...");
						system("pause");
						terminar = 1;
					}
					busca = busca->nom;
			}
			if(inicio == NULL){
			
				printf("\nAgora a lista esta vazia...\n\n");
				o=0;
				system("pause");
				}
			}
		break;
			
        case 0:
			printf("\nAté mais...\n");
			opcao = 0;
		break;

        default:
        	 printf("\nOpção invalida\n");
			system("pause");
        }
    } 
    
	while (opcao!=0);
	
}
