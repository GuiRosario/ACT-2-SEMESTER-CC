#ifndef COMPLEX
#define COMPLEX

typedef struct comp Complex;

Complex* creat(float,float);
void del(Complex*);
Complex* soma(Complex*,Complex*);
Complex* sub(Complex*,Complex*);
void imp(Complex*);
#endif