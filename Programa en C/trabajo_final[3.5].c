
/*  +++ Trabajo Final +++
    Trazo de Snoopy por medio de Interpolación de Trazadores Cúbicos

    <<< BRAZO izquierdo (DEDO 2) >>>

    TRAZADOR CUBICO SUJETO  (ver algoritmo 3.5 y ejemplo 1 del Burden, pp. 148-152) 

FUNCIONA CORRECTAMENTE - Para compilar hay que incluir al final la instrucciOn -lm
*/

#include<stdio.h>
#include<math.h>

double distancia(float a, float b);


main()
{

  float h[100], FPO=-0.67, FPN=0.118, alfa[100],l[100],m[100];
  float z[100],a[100],c[100],b[100],d[100],S[100],x, t, intervalo;
  int n=3, j, i;  

  /* ENTRADA VALORES DE X y Y */
  float X[100]={-1.62,-1.52,-1.49,-1.46};
  float Y[100]={2.08,2.01,2.00,2.01};


  /* Abrir Archivo */
  FILE *Resultados;
  Resultados = fopen("snoopy[3.5][FINAL].dat", "w");


  for(i=0;i<=n;i++)
  {
   a[i] = Y[i];
  }

  /* Paso 1 */
  for(i=0;i<=n-1;i++)
  {
   h[i]=X[i+1]-X[i];

   /* Paso 2 */
   alfa[0]=3*(Y[1]-Y[0])/h[0]-3*FPO;
   alfa[n]=3*FPN-3*(Y[n]-Y[n-1])/h[n-1];
  }

  /* Paso 4 */
  l[0]=2*h[0];
  m[0]=0.5;
  z[0]=alfa[0]/l[0];

  /* Paso 3 */
  for(i=1;i<=n-1;i++)
  {
   alfa[i]=(Y[i+1]-Y[i])*3/h[i] - (Y[i]-Y[i-1])*3/h[i-1];  

   /* Paso 5 */
   l[i]=2*(X[i+1]-X[i-1])-h[i-1]*m[i-1];
   m[i]=h[i]/l[i];
   z[i]=(alfa[i]-h[i-1]*z[i-1])/l[i];
  }

  /* Paso 6 */
  l[n]=h[n-1]*(2-m[n-1]);
  z[n]=(alfa[n]-h[n-1]*z[n-1])/l[n];
  c[n]=z[n];

  /* Paso 7 */
  for(j=n-1;j>=0;j--)
  {
   c[j]=z[j]-m[j]*c[j+1];
   b[j]=(Y[j+1]-Y[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3;
   d[j]=(c[j+1]-c[j])/(3*h[j]);
  }

  fprintf(Resultados,"\n# Datos nUm. 1\n#     x  \t S(x)\n");

  /* Paso 7.1 */ /* CreaciOn de Sj(x) */
  for(j=0;j<=n-1;j++)
  {		/* Procedimiento para calcular un nUmero de intervalos proporcional 
		 a la distancia entre X[j] y X[j+1]*/
    t = 1;

    while( ( distancia( X[j+1]-X[j], Y[j+1]-Y[j] )/t ) > 0.01) 
				        	/* 0.01 es la distancia deseada 						  							 entre cada punto interpolado */
      {
       t = t + 1;    /* t es el # de trozos en que se divide 
		       la distancia entre X[j] y X[j+1] */
      }
    
    intervalo = (X[j+1]-X[j]) / t;    /* "intervalo" es la distancia entre cada valor
  				       de x dentro del intervalo [X[j],X[j+1]] */
    x = X[j]; 
    
    while(x <= X[j+1])  
      {
       S[j] = a[j] + b[j]*(x - X[j]) + c[j]*pow((x - X[j]),2) + d[j]*pow((x - X[j]),3) ; 
       x = x + intervalo;

       /* Paso 8 SALIDA */ 
       fprintf(Resultados,"  %.5f \t%.5f\n", x, S[j]);
      }
  } 

  fprintf(Resultados,"\n");
  fprintf(Resultados,"\n# Datos nUm. 2\n#    x \t\t       y\n");
  printf("\n j\t    x \t       a \t   b \t        c \t     d \n");
  for(j=0;j<=n-1;j++)
  {
   printf(" %d\t %.3f\t     %.3f\t%.3f\t     %.3f\t  %.3f\n",j,X[j],a[j],b[j],c[j],d[j]);
   fprintf(Resultados,"  %.3f\t     %.3f\n",X[j],Y[j]);
  }
  printf(" %d\t %.3f\t     %.3f\n",j,X[n],a[n]);
  fprintf(Resultados,"  %.3f\t     %.3f\n",X[n],Y[n]);
  printf("\n");  /* fin del paso 8 */


  /* Cerrar Archivo */
  fclose(Resultados);

} /* fin del main */


double distancia(float a, float b)  /* Calcula la distancia entre a y b */
{
 return( sqrt(pow(a,2) + pow(b,2)) );
}
