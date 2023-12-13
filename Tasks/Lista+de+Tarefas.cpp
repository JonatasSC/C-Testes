#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct elemento {
    char item[31];
    elemento *next;
};

int main(void){
	setlocale(LC_ALL, "Portuguese");

    struct elemento *novo,*anterior,*anteriorex,*inicio,*proximo,*busca;
    int i=0,o=0,opcao,sair,terminar;
    char texto[31];
    
    do {
        system("cls");
        printf("\n                       MENU");
        printf("\n          Digite 1 para inserir novo item");
        printf("\n          Digite 2 para alterar o conteudo de algum item");
        printf("\n          Digite 3 para excluir um item");
        printf("\n          Digite 4 para mostrar todos os itens");
        printf("\n          Digite 0 para encerrar");
        printf("\n          Digite sua opção: ");
        scanf("%d",&opcao);

        switch(opcao){

        case 1:
            printf("\nInserindo novo registro...");
            novo = (struct elemento*) malloc(sizeof(struct elemento));

            printf("\n\nInserindo conteudo...\n");
    	    printf("Digite o conteudo do item %d: ",i+1);
            fflush(stdin);
   	        gets(novo->item);
            novo->next = NULL;
        
            if(i==0){
                inicio = novo;
            }
            else{
            	anterior->next = novo;
			}
			proximo = novo;
            anterior = novo;
            i++;	      
        break;

        case 2:
        	
        	terminar = 0;
        	if(inicio == 0){
   	   	    	printf("\nLista Vazia!\n");
   	   	    	system("pause");
			}
			else{
	            printf("\nAlterando o conteudo de um registro...");
    	        printf("\nDigite o texto do registro que deseja alterar: ");
				fflush(stdin);
				gets(texto);
				busca = inicio;

    	  	    while(terminar != 1){
	    	        if (!strcmp(texto,busca->item)){
	    		   	    printf("\nDigite o novo texto: ");
						fflush(stdin);
						gets(busca->item);
						terminar = 1;
					}
	        	    else{	
						if(busca->next == 0){
	    	   	    		printf("\nTexto não encontrado!\n");
	    	   	    		system("pause");
       		            	terminar=1;
        	   	    	}
           		    }
					busca = busca->next;
				}
			}
        break;

        case 3:
        	terminar = 0;
        	if(inicio == 0){
   	   	    	printf("\nLista Vazia!\n");
   	   	    	system("pause");
			}
			else{
	            printf("\nExcluindo um registro...");
    	        printf("\nDigite o texto do registro que deseja excluir: ");
				fflush(stdin);
				gets(texto);
				busca = inicio;
				anteriorex = inicio;
      		    while(terminar != 1){
	        	    if (!strcmp(texto,busca->item)){
						if(busca == inicio){
							inicio = busca->next;
						}
						else{
							anteriorex->next = busca->next;
						}
						free(busca);
	    	   	    	printf("\nRegistro excluido!\n");
						system("pause");
						if(busca->next == NULL){
							anterior = anteriorex;
						}
					terminar = 1;
				}
	        	    else{	
						anteriorex = busca;
						if(busca->next == NULL){
	    	   	    		printf("\nTexto não encontrado!\n");
							system("pause");
    	   	            	terminar = 1;
        	   	    	}
						busca = busca->next;
           	    	}
				}
				if(inicio == NULL){
					printf("\nAgora a lista ficou vazia\n");
					i=0;			
					system("pause");
				}
			}	
        break;

        case 4:
        	if(inicio == 0){
   	   	    	printf("\nLista Vazia!\n");
   	   	    	system("pause");
			}
			else{
	            printf("\nMostrando endereços e conteudos...");
				o=0;
				sair=0;
      	    	while(sair != 1){
               		if(o==0){
		            	printf("\nItem %d: %s",o+1,inicio->item);
  		            	printf("  ...na posição %p",inicio);
  		                printf("  ...e apontando para %p\n",inicio->next);
						proximo = inicio->next;
            	   	}
	 	   			else{
	               	 	printf("\nItem %d: %s",o+1,proximo->item);
  		            	printf("  ...na posição %p",proximo);
  	    		        printf("  ...e apontando para %p\n",proximo->next);
						proximo = proximo->next;
					}
            		if(proximo == NULL){
	 	   				sair = 1;
     	          	}
					o++;
           		}
           		system("pause");
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
	
	while(opcao!=0);

}
