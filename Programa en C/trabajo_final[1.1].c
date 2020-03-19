
/*  +++ Trabajo Final +++
    Trazo de Snoopy por medio de Interpolación de Trazadores Cúbicos

    <<< Parte Superior >>>

    TRAZADOR CUBICO SUJETO  (ver algoritmo 3.5 y ejemplo 1 del Burden, pp. 148-152) 

FUNCIONA CORRECTAMENTE - Para compilar hay que incluir al final la instrucciOn -lm
*/

#include<stdio.h>
#include<math.h>

double distancia(float a, float b);


main()
{

float h[100], FPO=12.5, FPN=25, alfa[100],l[100],m[100];
float z[100],a[100],c[100],b[100],d[100],S[100],x;

/* ENTRADA VALORES DE X1 y Y1 */
float X1[100]={-6.32,-6.29,-6.28,-6.24,-6.22,-6.21,-6.20,-6.19,-6.18,-6.13,-6.10,-6.06,-6.02,-5.88,-5.78,-5.66,-5.55,-5.23,-4.78,-4.31,-4.09,-3.85,-3.68,-3.50,-3.39,-3.21,-3.11,-2.99,-2.40,-2.00,-1.64,-1.55,-1.44,-1.37,-1.29,-1.16,-1.10,-1.08,-1.04,-1.00,-0.98,-0.94,-0.93,-0.86,-0.67,-0.49,-0.45,-0.41,-0.39,-0.38,-0.37,-0.35,-0.345,-0.34,-0.33,-0.32,-0.28,-0.27,-0.26,-0.24,-0.22,-0.20,-0.19};

float Y1[100]={3.05,3.08,3.11,3.16,3.20,3.40,3.48,3.59,3.73,3.90,3.92,3.94,3.98,4.09,4.11,4.08,4.18,4.39,4.48,4.44,4.35,4.15,3.89,3.31,3.11,2.99,2.99,3.01,3.28,3.37,3.34,3.31,3.19,3.11,3.12,3.13,3.13,3.14,3.14,3.14,3.15,3.15,3.24,3.68,3.97,4.03,4.02,4.01,3.99,3.95,3.81,3.64,3.59,3.55,3.53,3.52,3.51,3.49,3.47,3.43,3.40,3.28,3.00};

float X[100], Y[100], t, intervalo;
int n=62, j, i;  


/* Abrir Archivo */
FILE *Resultados;
Resultados = fopen("snoopy[1.1].dat", "w");


for(i=0;i<=n;i++){
a[i] = Y1[i];
//printf("\n  \n");
}

/* Paso 1 */
for(i=0;i<=n-1;i++){
h[i]=X1[i+1]-X1[i];

/* Paso 2 */
alfa[0]=3*(Y1[1]-Y1[0])/h[0]-3*FPO;
alfa[n]=3*FPN-3*(Y1[n]-Y1[n-1])/h[n-1];
}

/* Paso 4 */
l[0]=2*h[0];
m[0]=0.5;
z[0]=alfa[0]/l[0];

/* Paso 3 */
for(i=1;i<=n-1;i++){
alfa[i]=(Y1[i+1]-Y1[i])*3/h[i] - (Y1[i]-Y1[i-1])*3/h[i-1];  

/* Paso 5 */
l[i]=2*(X1[i+1]-X1[i-1])-h[i-1]*m[i-1];
m[i]=h[i]/l[i];
z[i]=(alfa[i]-h[i-1]*z[i-1])/l[i];
}

/* Paso 6 */
l[n]=h[n-1]*(2-m[n-1]);
z[n]=(alfa[n]-h[n-1]*z[n-1])/l[n];
c[n]=z[n];

/* Paso 7 */
for(j=n-1;j>=0;j--){
c[j]=z[j]-m[j]*c[j+1];
b[j]=(Y1[j+1]-Y1[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3;
d[j]=(c[j+1]-c[j])/(3*h[j]);
}

fprintf(Resultados,"\n# Datos nUm. 1\n#     x' \t S(x')\n");

/* Paso 7.1 */ /* CreaciOn de Sj(x) */
for(j=0;j<=n-1;j++)
{		/* Procedimiento para calcular un nUmero de intervalos proporcional 
		 a la distancia entre X1[j] y X1[j+1]*/
  t = 1;

  while( ( distancia( X1[j+1]-X1[j], Y1[j+1]-Y1[j] )/t ) > 0.01) 
				        	/* 0.01 es la distancia deseada 						  							 entre cada punto interpolado */
     {
      t = t + 1;    /* t es el # de trozos en que se divide 
		       la distancia entre X1[j] y X1[j+1] */
     }
  //printf("\n t = %f\n\n", t);
  
  intervalo = (X1[j+1]-X1[j]) / t;    /* "intervalo" es la distancia entre cada valor
  				       de x dentro del intervalo [X1[j],X1[j+1]] */
  x = X1[j]; 

  while(x <= X1[j+1])  
    {
     S[j] = a[j] + b[j]*(x - X1[j]) + c[j]*pow((x - X1[j]),2) + d[j]*pow((x - X1[j]),3) ; 
     x = x + intervalo;
     fprintf(Resultados,"  %.5f \t%.5f\n", x, S[j]);
    }
    
} 

fprintf(Resultados,"\n");


/* Paso 7.2 */ /* Reacomodo de los ejes */
for(i=0;i<=n;i++){
X[i] = Y1[i];
Y[i] = -1*X1[i];
}

fprintf(Resultados,"\n# Datos nUm. 2\n#   x'\t      y'\t\t x\t      y\n");

/* Paso 8 SALIDA */
printf("\n j\t   x'\t      a'\t  b'\t       c'\t    d'\n");
for(j=0;j<=n-1;j++){
printf(" %d\t %.2f\t     %.2f\t%.2f\t     %.2f\t  %.2f\n",j,X1[j],a[j],b[j],c[j],d[j]);
fprintf(Resultados,"  %.2f\t     %.2f\t        %.2f\t     %.2f\n",X1[j],a[j],X[j],Y[j]);
}
printf(" %d\t %.2f\t     %.2f\n",j,X1[n],a[n]);
fprintf(Resultados,"  %.2f\t     %.2f\t        %.2f\t     %.2f\n",X1[n],a[n],X[n],Y[n]);
printf("\n"); 


/* Cerrar Archivo */
fclose(Resultados);

} /* fin del main */


double distancia(float a, float b)  /* Calcula la distancia entre a y b */
{
return( sqrt(pow(a,2) + pow(b,2)) );
}
