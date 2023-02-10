#include <stdio.h>
#include <stdlib.h>

typedef struct strNodo{
    int num;
    struct strNodo *ant;
    struct strNodo *sig;
}NODO;

typedef struct{
    int tam;
    NODO *ini;
    NODO *fin;
}LISTA;

LISTA lista;
NODO *ult;
NODO *tem;

void iniLis(LISTA *lista){
    lista->tam=0;
    lista->ini=NULL;
    lista->fin=NULL;
}

void iniTem(void){
    tem=(NODO *) malloc(sizeof(NODO));
    if(tem==NULL){
        printf("Problemas al asignar memoria!\n");
        exit(0);
    }
}

void nuevoNumero(LISTA *lista){
    int numero;
    printf("Ingresa un numero: ");
    scanf("%d",&numero);
    iniTem();
    tem->num=numero;
    tem->ant=NULL;
    tem->sig=NULL;
    if(!lista->ini){
        lista->ini=lista->fin=ult=tem;
    }else{
        ult->sig=tem;
        tem->ant=ult;
        ult=tem;
    }
    lista->tam++;
}

void imprimirLista(LISTA *lista){
    char respuesta;
    int con=0;
    printf("La lista tiene %d numeros\n", lista->tam);
    printf("De que forma quiere imprimir la lista\?\n");
    printf("a) Del primero al ultimo\n");
    printf("b) Del ultimo al primero\nRespuesta: ");
    scanf(" %c",&respuesta);
    if(respuesta=='a'){
        tem=lista->ini;
        while(tem!=NULL){
            con++;
            printf("El %d numero agregado es: %d\n",con,tem->num);
            tem=tem->sig;
        }
    }else{
        tem=lista->fin;
        con=lista->tam;
        while(tem!=NULL){
            printf("El %d numero agregado es: %d\n",con,tem->num);
            tem=tem->ant;
            con--;
        }
    }
}

void insertarAlInicio(void){
    NODO *auxiliar;
    int numero;
    auxiliar=lista.ini;
    printf("Ingresa un numero: ");
    scanf("%d",&numero);
    iniTem();
    tem->num=numero;
    tem->ant=NULL;
    tem->sig=auxiliar;
    auxiliar->ant=tem;
    lista.ini=tem;
    lista.tam++;
}
void insertarAlFinal(void){
    int numero;
    printf("Ingresa un numero: ");
    scanf("%d",&numero);
    iniTem();
    tem->num=numero;
    tem->sig=NULL;
    ult->sig=tem;
    tem->ant=ult;
    ult=tem;
    lista.fin=tem;
    lista.tam++;
}
void eliminarNumero(void){
    NODO *auxiliar;
    NODO *auxiliar2;
    NODO *auxiliar3;
    int numero;
    int con=1;
    printf("Ingresa la posicion del numero que deseas eliminar: ");
    scanf("%d",&numero);
    auxiliar=lista.ini;
    while(con<numero){
        auxiliar=auxiliar->sig;
        if(auxiliar==NULL){
            printf("La posicion que ingresaste no se encuetra en la lista\n");
            break;
        }
        con++;
    }
    if(con==numero){
        if(auxiliar->ant==NULL){
            auxiliar2=auxiliar->sig;
            auxiliar2->ant=NULL;
            lista.ini=auxiliar2;
            lista.tam--;
        }else{
            if(auxiliar->ant!=NULL&auxiliar->sig!=NULL){
                auxiliar2=auxiliar->ant;
                auxiliar3=auxiliar->sig;
                auxiliar2->sig=auxiliar3;
                auxiliar3->ant=auxiliar2;
                lista.tam--;
            }else{
                if(auxiliar->sig==NULL){
                    auxiliar2=auxiliar->ant;
                    auxiliar2->sig=NULL;
                    lista.fin=auxiliar2;
                    lista.tam--;
                }
            }
        }
    }
    if(auxiliar!=NULL){
        printf("El numero de la Posicion %d ha sido eliminada\n",numero);
    }
}

void modificarLis(void){
    char res;
    printf("\n^-^^-^^-^ MENU ^-^^-^^-^\n");
    printf("a) Agregar un numero al inicio de la lista \n");
    printf("b) Agregar un numero al final de la lista\n");
    printf("c) Eliminar numero de la lista\n");
    printf("d) Imprimir lista\nRespuesta: ");
    scanf(" %c",&res);
    switch(res){
        case 'a':
            insertarAlInicio();
            break;
        case 'b':
            insertarAlFinal();
            break;
        case 'c':
            eliminarNumero();
            break;
        default:
            imprimirLista(&lista);
    }
}

int main(){
    char respuesta;
    iniLis(&lista);
    printf("^-^^-^^-^ LISTA ^-^^-^^-^\n");
    do{
        nuevoNumero(&lista);
        printf("Deseas agregar otro numero\? (s/n) ");
        scanf(" %c",&respuesta);
    }while(respuesta=='s');
    lista.fin=ult;
    do{
        modificarLis();
        printf("Deseas regresar al menu\? (s/n) ");
        scanf(" %c",&respuesta);
    }while(respuesta=='s');
    return 0;
}
