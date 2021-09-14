#ifndef LISTA
#define LISTA

typedef struct lista Lista;

Lista* creat();
void inserir(Lista*,int);
void del(Lista*,int);
Lista* inter(Lista*,Lista*);
Lista* difer(Lista*,Lista*);
Lista* uni(Lista*,Lista*);
void imp(Lista*);
int maior(Lista*);
int menor(Lista*);
void ig(Lista*,Lista*);
void tam(Lista*);
void cva(Lista*);
Lista* con(Lista*,Lista*);
void delini(Lista*);
void delinin(Lista*,int);
#endif