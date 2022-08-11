#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nos
{
    int texec;
    int tcheg;
    int te;
    int ex;
    int esp;
    char processo[20];
	struct nos *proximo;
}inicio,fim;

int insere_ordenado(struct nos **inicio, struct nos **fim, int texec, int tcheg, char processo[20]){
    struct nos *atual;
    struct nos *r;
    struct nos *q;
    struct nos *p;
    struct nos *esse;
    struct nos *desse;
    int cont;

    atual=*inicio;


if(*inicio==NULL) //adicionando o primeiro no
    {

              p = (struct nos *) malloc(sizeof(struct nos));
              if(p){
			  p->texec = texec;
			  p->tcheg = tcheg;
			  p->te = texec;
			  p->ex = 0;
			  p->esp = 0;
			  strcpy(p->processo,processo);
			  p->proximo = NULL;
			  if(*inicio == NULL)
				*inicio = p;
			  else
             (*fim)->proximo = p;
              *fim = p;
              *inicio = p;
              atual =p;
                   }
    }

else if(atual->proximo==NULL)//se um único nó
    {
			 if(atual->tcheg >=tcheg) //insere no inicio
         	 {
		  	  r = (struct nos *) malloc(sizeof(struct nos));
	          r->texec = texec;
			  r->tcheg = tcheg;
			  r->te = texec;
			  r->ex = 0;
			  r->esp = 0;
			  strcpy(r->processo,processo);
			  r->proximo = atual; //o atual sera o primeiro nó inserido que é maior que esse
		      *fim = r->proximo;
              *inicio = r;
	 	     }
      	 	 else
             {
	   		 struct nos *p;
              p = (struct nos *) malloc(sizeof(struct nos));
              if(p)
                   {
		      p->texec = texec;
              p->tcheg = tcheg;
              p->te = texec;
              p->ex = 0;
			  p->esp = 0;
              strcpy(p->processo,processo);
			  p->proximo = NULL;
			  if(*inicio == NULL)
				*inicio = p;
			  else
             (*fim)->proximo = p;
              *fim = p;
              atual = p;
                   }
             }
     }

else{//se mais de um nó 
      esse = *inicio;
      desse = *fim;
           if(tcheg > esse->tcheg && tcheg < desse->tcheg)//se nao for menor que o primeiro nem menor que o ultimo
           {
              volta:
              if(tcheg >= esse->tcheg && tcheg <= esse->proximo->tcheg)
              {
                     q = (struct nos *) malloc(sizeof(struct nos));
                     q->texec = texec;
                     q->tcheg = tcheg;
                     q->te = texec;
                     q->ex = 0;
                     q->esp = 0;
			         strcpy(q->processo,processo);

                     q->proximo = esse->proximo;
                     esse->proximo = q;
                     atual= *fim;
              }
               else
               {
                   esse= esse->proximo;
                   goto volta;
               }
            }

            else
            {
                if (tcheg <= esse->tcheg)//se menor que o primeiro nó ou igual
             {
              r = (struct nos *) malloc(sizeof(struct nos));
	          r->texec = texec;
              r->tcheg = tcheg;
              r->te = texec;
              r->ex = 0;
              r->esp = 0;
			  strcpy(r->processo,processo);
			  r->proximo = atual;
		      *inicio = r;
             }
            if (tcheg >= desse->tcheg && desse->proximo==NULL)//se maior que o ultimo nó
            {
                       struct nos *p;
              p = (struct nos *) malloc(sizeof(struct nos));
              if(p)
                   {
			  p->texec = texec;
              p->tcheg = tcheg;
              p->te = texec;
              p->ex = 0;
			  p->esp = 0;
              strcpy(p->processo,processo);

			  p->proximo = NULL;
			  if(*inicio == NULL)
				*inicio = p;
			  else
                  (
             *fim)->proximo = p;
              *fim = p;
              atual = p;
                   }
               }
     }

    }

};



int imprime(struct nos **inicio)
{
		struct nos *prox;
		prox = *inicio;
		while(prox != NULL)
        {
			printf("\nProcesso: %s \n\n", prox->processo);
			printf("\nTempo de execucao: %i \n\n", prox->texec);
			printf("\nTempo de chegada: %i \n\n", prox->tcheg);
			prox = prox->proximo;
        }

};

int fifo(struct nos **inicio)
{
        int i;
		int tesp=0, tresp=0;
		int somaexec=0;
        struct nos *prox;
		prox = *inicio; //ponta pro inicio
		while(prox != NULL) //vai indo um por um
        {
			printf("\nProcesso: %s ", prox->processo);
			printf("\nTempo de execucao: %i  ", prox->texec);
			printf("\nTempo de chegada: %i  \n\n", prox->tcheg);

            tesp= somaexec - prox->tcheg;

            tresp= somaexec + prox->texec - prox->tcheg;

            printf("Tempo de espera: %d\n", tesp);
            printf("Tempo de resposta: %d\n_------------------\n", tresp);

            somaexec= somaexec + prox->texec;
		    prox = prox->proximo;
        }
};


/*void ordenar(struct nos **inicio){
    //ordenar os nós restantes
}; */

void sjf(struct nos **inicio, struct nos **fim)
{
		int tesp=0, tresp=0;
		int somaexec=0;
        int asoma;
		int auxtexec, auxtcheg;
		char auxprocesso[20];
        struct nos *atual;
        struct nos *esse;
        struct nos *desse;
        struct nos *segundo;//nome pra por no segundo nó
        struct nos *seguinte;
        struct nos *seg;
        
        atual = *inicio; //ponta pro inicio
        segundo = atual->proximo;
        
     //calcula o primeiro nó 
            printf("\nProcesso: %s ", atual->processo);
	        printf("\nTempo de execucao: %i  ", atual->texec);
			printf("\nTempo de chegada: %i  \n\n", atual->tcheg);
            tesp= somaexec - atual->tcheg;
            tresp= somaexec + atual->texec - atual->tcheg;
            printf("Tempo de espera: %d\n", tesp);
            printf("Tempo de resposta: %d\n_------------------\n", tresp);
            somaexec= somaexec + atual->texec;        
      //deleta o primeiro nó
		     segundo = atual->proximo;// segundo =segundo elemento
		     *inicio = segundo;//agora o inicio aponta pro segundo elemento
             free(atual);//deleta o espaço do primeiro nó
             atual = NULL;
      
      //ordena por menor nº de exec  
       atual = *inicio;
       esse = *inicio;
       segundo = esse->proximo;
       desse = *fim;
       asoma=somaexec;
        
       for(atual = *inicio; atual != NULL;atual=atual->proximo)
       {
       esse = *inicio;//pra cada nó que for analisar ver com esse no inicio          
       if(atual->texec > esse->texec && atual->texec < desse->texec) //se entre o primeiro e o ultimo
       {   
         seguinte=atual->proximo;             
          
		 if(atual->texec >= seguinte->texec)
         {    
              auxtexec=atual->texec;
              auxtcheg=atual->tcheg;
              strcpy(auxprocesso,atual->processo);
                    
              atual->texec = seguinte->texec;
              atual->tcheg = seguinte->tcheg;
              strcpy(atual->processo,seguinte->processo);
                    
              seguinte->texec=auxtexec;
              seguinte->tcheg=auxtcheg;
              strcpy(seguinte->processo,auxprocesso);                
         }
       }
       if(atual->texec >= desse->texec)//se maior ou igual ao ultimo
       {
                    auxtexec=atual->texec;
                    auxtcheg=atual->tcheg;
                    strcpy(auxprocesso,atual->processo);
                    
                    atual->texec = desse->texec;
                    atual->tcheg = desse->tcheg;
                    strcpy(atual->processo,desse->processo);
                    
                    desse->texec=auxtexec;
                    desse->tcheg=auxtcheg;
                    strcpy(desse->processo,auxprocesso);   
       }
       if(atual->texec <= esse->texec)//se menor ou igual ao primeiro
                {
                    auxtexec=atual->texec;
                    auxtcheg=atual->tcheg;
                    strcpy(auxprocesso,atual->processo);
                    
                    atual->texec = esse->texec;
                    atual->tcheg = esse->tcheg;
                    strcpy(atual->processo,esse->processo);
                    
       
                    esse->texec=auxtexec;
                    esse->tcheg=auxtcheg;
                    strcpy(esse->processo,auxprocesso);                
               }
        
       }
       
          //Não deixar o processador ocioso se possível
 
      asoma=somaexec;    
             for(atual = *inicio; atual != NULL; atual=atual->proximo)
       {         
             seguinte=atual->proximo;             
          	   if(atual->texec > asoma && seguinte != NULL)
             {    
              if(seguinte->tcheg < atual->tcheg)
              {
              auxtexec=atual->texec;
              auxtcheg=atual->tcheg;
              strcpy(auxprocesso,atual->processo);
                    
              atual->texec = seguinte->texec;
              atual->tcheg = seguinte->tcheg;
              strcpy(atual->processo,seguinte->processo);
                    
              seguinte->texec=auxtexec;
              seguinte->tcheg=auxtcheg;
              strcpy(seguinte->processo,auxprocesso);                               
              }
              }  
         asoma = asoma + atual->texec;
       }
        
   //calcular e escrever os tempos e etc    
        atual = *inicio;
        while(atual != NULL)
   {     
            printf("\nProcesso: %s ", atual->processo);
	        printf("\nTempo de execucao: %i  ", atual->texec);
			printf("\nTempo de chegada: %i  \n\n", atual->tcheg);
            tesp= somaexec - atual->tcheg;
            tresp= somaexec + atual->texec - atual->tcheg;
            printf("Tempo de espera: %d\n", tesp);
            printf("Tempo de resposta: %d\n_------------------\n", tresp);
            somaexec= somaexec + atual->texec;    
            atual=atual->proximo;
    }
};
void roundrobim(struct nos **inicio, struct nos **fim)
{
int quantun, verif=0, eixox=0,m;
int tesp=0, tresp=0;
struct nos *esse;
struct nos *atual;
struct nos *desse;
desse = *fim;
atual=*inicio;
printf("Digite a fatia de tempo\n");
scanf("%d", &quantun);  
 
 do
{
for(atual = *inicio; atual != NULL; atual=atual->proximo)//tratamento do nó atual 
 {              
                
  if((atual-> te == quantun ||atual-> te > quantun || atual-> te < quantun) && atual->te !=0)  
  {                                                      
    if(atual-> te == quantun)
    {        
       for(esse = *inicio; esse != atual; esse=esse->proximo)//tratamento do nó atual 
       {
       if(esse->te != 0)
       {                             
       esse->esp = esse->esp + quantun;               
       }
       }
       for(esse = atual->proximo; esse != NULL && atual!=*fim ; esse=esse->proximo)
       {
       if(esse->te != 0)
       {               
       esse->esp= esse->esp + quantun;
       }
       }
     
     eixox=eixox+quantun;
     atual->te = atual->te - quantun; //=0 
     atual->ex = eixox;   
        
    }
    
    if(atual->te > 0 && atual->te < quantun)
    {
     eixox=eixox + atual->te;
     m = atual->te;
     atual->te = atual->te - atual->te; //=0 
     atual->ex = eixox;
       for(esse = *inicio; esse != atual; esse=esse->proximo)//tratamento do nó atual 
       {              
       if(esse->te != 0)
       {               
       esse->esp = esse->esp + m;                   
       }
       }
      for(esse = atual->proximo; esse != NULL && atual!=*fim ; esse=esse->proximo)
       {
       if(esse->te != 0)
       {               
       esse->esp= esse->esp + m;
       }
       }
    }
    
    if(atual->te > quantun)
    {
     eixox=eixox+quantun;
     atual->te = atual->te - quantun;  
     
       for(esse = *inicio; esse != atual;esse=esse->proximo)//tratamento do nó atual 
       {       
       if(esse->te != 0)
       {               
       esse->esp = esse->esp + quantun;                   
       }
       }
       
       for(esse = atual->proximo; esse != NULL && atual!=*fim ; esse=esse->proximo)//calculando os nós do atual até o final
       {
       if(esse->te != 0)
       {               
       esse->esp= esse->esp + quantun;
       }
       }
       
    }
  }
 } 
  
 //fazendo a parada do do while   
verif=0;
for(atual = *inicio; atual != NULL; atual=atual->proximo) //se tiver pelo menos um com te dif de 0
 {                                                         //ele continua dando volta no loop
 if(atual-> te != 0) verif++; //mudar pra diferente depois dos testes
 }   
}while(verif != 0);// !=0 nos dois 
////calcular tesp e tresp
        atual = *inicio;
        while(atual != NULL)
   {     
            printf("\nProcesso: %s ", atual->processo);
	        printf("\nTempo de execucao: %d  ", atual->texec);
			printf("\nTempo de chegada: %d  \n\n", atual->tcheg);
            
            tesp= atual->esp - atual->tcheg;
            tresp= atual->ex - atual->tcheg;
            
            printf("Tempo de espera: %d\n", tesp);
            printf("Tempo de resposta: %d\n_------------------\n", tresp);
            
            atual=atual->proximo;
    }
};


int main(){
      system("color 0F");
      char processo[20];
      int texec, tcheg;
      int op,valor, n, m, x;
	  struct nos *fim=NULL;
	  struct nos *inicio= NULL;
	  do{
	  do{
	  printf("\n                                MENU          \n\n");
      printf("\t\t1 - INSERIR PROCESSO\n\t\t2 - IMPRIMIR\n\t\t3 - SAIR\n\t\t4 - FIFO\n\t\t5 - SJF\n\t\t6 - Round-Robin\n\n");
	  scanf("%d",&op);
	  switch(op){
	  	  case 1: system("cls");
			   	  printf("\nProcesso: ");
				  scanf("%s",&processo);
				  printf("\nTempo de chegada: ");
				  scanf("%d",&tcheg);
				  printf("\nTempo de execucao: ");
				  scanf("%d",&texec);
				  fflush(stdin);
				  insere_ordenado(&inicio,&fim,texec,tcheg,processo);
  	              break;
		  case 2: system("cls");
                  imprime(&inicio); break;
		  case 3: system("cls"); break;
		  case 4: fifo(&inicio); break;
		  case 5: sjf(&inicio,&fim); break;
          case 6: roundrobim(&inicio,&fim); break; 
  	              break;
          default: system("cls"); printf("\nDigite uma opcao valida!\n\n"); break;
      }
	  }while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6);
	  }while(op!=3);
            return 0;
}
