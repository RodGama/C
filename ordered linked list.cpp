#include <stdio.h>
#include <stdlib.h>

//Definicao de tipos
typedef struct No {      //representa cada elemento da lista
   int valor;
   struct No *prox;
} TNo;

typedef TNo *TLista;    //ponteiro para um no da lista

//Definicao de constantes
#define TRUE 1           //constantes simulando os valores logicos TRUE e FALSE
#define FALSE 0

//Prototipos das funcoes
int inserir (TLista *L, int num,TLista *aux1,TLista *aux2);
int remover (TLista *L, int num);
int alterar (TLista L, int num1, int num2,TLista *aux1,TLista *aux2);
TLista buscar (TLista L, int num);
void exibir (TLista L);

int menu ();


//----------------------------Implementacao da Main-----------------------------
int main ()
{
   TLista L = NULL;     //A lista, inicialmente vazia
    
   int opcao, num1, num2;
   TLista pos;
   TLista aux1, aux2;	
    
   //Um menu sera exibido ao usuario ate que este opte pela saida do sistema
   do {
      //E exibido o menu ao usuario e retornada a alternativa escolhida  
      opcao = menu ();
      
      switch (opcao) {
         //Inserir    
         case 1: printf ("Entre com o numero a ser inserido: ");
                 scanf ("%d", &num1);
                 if(L == NULL){
                   if (inserir (&L, num1,&aux1,&aux2) == TRUE) {  //ou apenas: if (inserir (&L, num))
                    printf ("Elemento inserido com sucesso!\n");
                   } else {
                    printf ("ERRO: Elemento nao inserido!\n");
                   }
                 }
                 else{
                 	pos = buscar(L,num1);
                 	if(pos == NULL)
                 	{
                 		if (inserir (&L, num1,&aux1,&aux2) == TRUE) {  
                          printf ("Elemento inserido com sucesso!\n");
                         }  else {
                         printf ("ERRO: Elemento ja existe!\n");
                             }	
                 	}
                 	else printf ("ERRO: Elemento ja existe!\n");
                 }
                 break;
                 
         //Remover    
         case 2: printf ("Entre com o numero a ser removido: ");
                 scanf ("%d", &num1);
                 
                 if (remover (&L, num1)) {
                    printf ("Elemento removido com sucesso!\n");
                 } else {
                    printf ("ERRO: Elemento nao removido!\n");
                 }
                 break;
                 
         //Alterar    
         case 3: printf ("Entre com o numero a ser alterado: ");
                 scanf ("%d", &num1);
                 
                 printf ("Entre com o novo numero: ");
                 scanf ("%d", &num2);
                 
                 if (alterar (L, num1,num2,&aux1,&aux2)) {
                    printf ("Elemento alterado com sucesso!\n");
                 } else {
                    printf ("ERRO: Elemento ja existe!\n");
                 }
                 break;
                 
         //Buscar    
         case 4: printf ("Entre com o numero a ser buscado: ");
                 scanf ("%d", &num1);
                 
                 pos = buscar (L, num1);
                 
                 //O elemento foi encontrado e retornada a posi??o de sua
                 //primeira ocorr?ncia
                 if (pos != NULL) {   //o mesmo que if (pos)
                    printf ("Elemento encontrado na lista (posicao %p)!\n", pos);
                 } else {
                    printf ("ERRO: Elemento nao encontrado!\n");
                 }
                 break;
                 
         //Exibir
         case 5: exibir (L);
                 break;
                 
         //Sair
         case 6: printf ("Fim do programa!\n");
                 break; 
                 
         //Opcao invalida!
         default: printf ("Opcao invalida! Tente novamente!\n");
                 
      }
      system ("pause");
   } while (opcao != 6);
}


//--------------Implementacao das funcoes de manipulacao da lista---------------

//Tenta inserir 'num' na lista L, retornado TRUE ou FALSE indicando se a operacao
//foi ou nao realizada
int inserir (TLista *L, int num,TLista *aux1,TLista *aux2)
{
   //Passo 1: alocar memoria 
   TLista aux = (TLista) malloc (sizeof(TNo));
  while (aux1 != NULL && aux2 != NULL)
 {
   *aux1 = *L;
   *L = (*L)->prox; 
  // *aux2 = aux1->prox;
  if(L == NULL)
  {
   if (aux == NULL)  // if (!aux)
   {
      return FALSE;
   }
   else
   {
      //Passo 2: armazenando o novo elemento na memoria recem-alocada
      aux->valor = num;
      
      //Passo 3: fazer o aux apontar para o "ate entao" primeiro elemento
      aux->prox = *L;
      
      //Passo 4: atualizar o L para apontar para o novo elemento
      *L = aux;
      
      return TRUE;
   }
  }
  else if (aux1->prox < num > aux2->valor)
   {
   	//Passo 2: armazenando o novo elemento na memoria recem-alocada
      aux->valor = num;
      
      //Passo 3: fazer o aux apontar para o "ate entao" primeiro elemento
      aux->prox = aux1->prox;
      
      return TRUE;
   }
   *aux1 = aux1->prox;
   *aux2 = aux2->prox;
 }
}

//Tenta remover as ocorroncias de 'num' na lista L
int remover (TLista *L, int num)
{
    int c = 0;
    
    TLista aux1, aux2;
    
    //verificando a existencia de num no inicio de L
    while ((*L)->valor == num)  //while (L) = while (L != NULL)
    {
       aux1 = *L;
       *L = (*L)->prox; //ou *L = aux1->prox;
       free (aux1);
       c++;
      return c;
	}   
    
    //Verificando se ainda ha elementos a examinar
    if (*L)
    {
       aux2 = *L;
       aux1 = aux2->prox; //ou aux1 = L->prox;
       
       while (aux1) //while (aux1 != NULL)
       {
          //elemento encontrado   
          if (aux1->valor == num)
          {
             aux2->prox = aux1->prox;
             free (aux1);
             aux1 = aux2->prox;
             c++;
             return c;
          }
          else
          {
             aux2 = aux1;
             aux1 = aux1->prox;
          }
       }
    }
}

//Altera todas as ocorroncias de 'num1' por 'num2'
int alterar (TLista L, int num1, int num2,TLista *aux1,TLista *aux2)
{
   TLista aux = L;
   int c = 0;
   
   while (aux1 != NULL)   //while (aux)
   {   
     aux1=L->prox;
     aux2=aux1->prox;

     if(aux->valor == num2) exit;
      if (aux->valor  == num1)
      {
      	if(aux1->valor < num1 > aux2->valor){
         aux->valor = num2;
         c++;}
      }
      else exit; 
      aux1=aux1->prox;
      aux2=aux2->prox;
      
   }
   
   return c;
}

//Busca 'num' na lista. Se encontrar, retorna a posicao de sua
//primeira ocorrencia; caso contrario, NULL e retornado
TLista buscar (TLista L, int num)
{
   TLista aux = L;
   
     
   while (aux != NULL)  //while (aux)
   {
   /*	if(aux->valor> num)
	{
   	  return NULL;
    }
    else */if (aux->valor == num)
      {
         return aux;
      }
      
      aux = aux->prox;      
   }
}

//Exibe todos os elementos da lista
void exibir (TLista L)
{
   TLista aux = L;
   
   if (!L) {
      printf ("Lista vazia\n");
   } else {
     printf ("Lista: ");
     
     while (aux != NULL)  //while (aux)
     {
        printf ("%d ", aux->valor);
      
        aux = aux->prox;      
     }
     printf ("\n");
   }
}

//Exibe um menu de operacoes ao usuario e retorna a opcao selecionada
int menu ()
{
   int op;
    
   system ("cls");
   printf ("Menu de Operacoes:\n\n");
   printf ("1) Inserir\n2) Remover\n3) Alterar\n");
   printf ("4) Buscar\n5) Exibir\n6) Sair\n\n");
   printf ("Entre com a opcao: ");
   
   scanf ("%d", &op);
   return op;
}
