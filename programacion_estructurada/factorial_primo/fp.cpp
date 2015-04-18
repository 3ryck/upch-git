/* Descomponer en funciones y exponer el resultado
al final de la clase; equipos de 3 personas
*/
#include<stdio.h>
#include<math.h>

factorizacion_primos(long x)
{
long i;	/* contador */
long c;	/* producto restante a factorizar */
c = x;
while ((c % 2) == 0) { //que pasa aqui ?
printf("%ld\n",2); //
c = c / 2; //
}
i = 3;
while (i <= (sqrt(c)+1)) { //identificar el proceso
if ((c % i) == 0) { //para obtener los factores
printf("%ld\n",i); // y verificar si es primo
c = c / i;
}
else
i = i + 2;
}
if (c > 1) printf("%ld\n",c);
}
main() {
long p;

while (scanf("%ld",&p)!=EOF) { // pide un numero
printf("factorizacion en primos de p=%ld \n",p);
factorizacion_primos(p);
}
}
