# include <stdio.h>
# include <omp.h>
# define NRA 1000 /* Numero de filas matriz A limite 1000*/
# define NCA 1000 /* Numero de columnas matriz A, Numero de filas matriz B limite 1000 */
# define NCB 1000 /* Numero de columnas matriz B limite 1000*/

void initialize(unsigned long int ** a,unsigned long int ** b,unsigned long int ** c);
void multiplication(unsigned long int ** a,unsigned long int ** b,unsigned long int ** c);
void print(unsigned long int ** a,unsigned long int ** b,unsigned long int ** c);
void free(unsigned long int ** a,unsigned long int ** b,unsigned long int ** c);

int main(int argc, char *argv[]){

	unsigned long int ** A = new unsigned long int * [NRA]; /* Matriz A a multiplicar */ 
	unsigned long int ** B = new unsigned long int * [NCA]; /* Matriz B a multiplicar */
	unsigned long int ** C = new unsigned long int * [NRA]; /* Matriz C resultado */

	/* Inicializacion de matrices */
	initialize(A,B,C);

	/* Multiplicacion */
	multiplication(A,B,C);
	
	/* Resultados */
	// print(A,B,C);
	

	/* Liberar Memoria */
	free(A,B,C);

	return 0;
};

void initialize(unsigned long int ** a, unsigned long int ** b, unsigned long int ** c){
	unsigned long int i,j;
	/* Matriz A */
	for(i=0;i<NRA;i++) a[i] = new unsigned long int [NCA];
	for(i=0;i<NRA;i++){
		for(j=0;j<NCA;j++){
			a[i][j] = i+j;
		}
	}
	/* Matriz B*/
	for(i=0;i<NCA;i++) b[i] = new unsigned long int [NCB];
	for(i=0;i<NCA;i++){
		for(j=0;j<NCB;j++){
			b[i][j] = i+j;
		}
	}
	/* Matriz C */
	for(i=0;i<NRA;i++) c[i] = new unsigned long int [NCB];
	for(i=0;i<NRA;i++){
		for(j=0;j<NCB;j++){
			c[i][j] = 0;
		}
	}
};

void multiplication(unsigned long int ** a,unsigned long int ** b,unsigned long int ** c){
	unsigned long int i,j,k;
	#pragma omp parallel shared(a,b,c) private(i,j,k)
	{
		#pragma omp for 
		for(i=0;i<NRA;i++){
			// printf("Thread %d is working on %ld row\n",omp_get_thread_num(),i);
			for(j=0;j<NCB;j++){
				for(k=0;k<NCA;k++){
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
	}
	
};

void print(unsigned long int ** a,unsigned long int ** b,unsigned long int ** c){
	unsigned long int i,j;
	printf("%s\n","Matriz A");
	for(i=0;i<NRA;i++){
		for(j=0;j<NCA;j++){
			printf("%ld\t",a[i][j]);
		}
		printf("\n");
	}

	printf("%s\n","Matriz B");
	for(i=0;i<NCA;i++){
		for(j=0;j<NCB;j++){
			printf("%ld\t",b[i][j]);
		}
		printf("\n");
	}

	printf("%s\n","Resultado");
	for(i=0;i<NRA;i++){
		for(j=0;j<NCB;j++){
			printf("%ld\t",c[i][j]);
		}
		printf("\n");
	}
};

void free(unsigned long int ** a,unsigned long int ** b,unsigned long int ** c){
	unsigned long int i;
	for(i=0;i<NRA;i++) delete [] a[i];
	for(i=0;i<NCA;i++) delete [] b[i];
	for(i=0;i<NRA;i++) delete [] c[i];
	delete [] a;
	delete [] b;
	delete [] c;
};