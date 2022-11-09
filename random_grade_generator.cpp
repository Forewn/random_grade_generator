//This will be translated soon

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
	  
}

void printProm01d(float prom,float nota_def[],char nombres[][12], int SD){
	system("cls");
	int x = 2;
	for(int i = 0; i < SD; i++){
		if(nota_def[i] > prom){
			x += 1;
			gotoxy(5, 2+x);  printf("%s", nombres[i]);
			gotoxy(15, 2+x);  printf("%f", nota_def[i]);
		}
	}

	system("pause");
}


int main(){

	srand(time(NULL));
	int const SD01 = 5;
	int const SD02 = 3;
	int const NOMBRE = 12;
	int const NOTAS = 3;

	char nombres_D01[SD01][NOMBRE], nombres_D02[SD02][NOMBRE], nombre_max_D01[5][NOMBRE], nombre_max_D02[5][NOMBRE], MAX_MAX_NOMBRE[5][NOMBRE];
	int notas_D01[SD01][NOTAS], notas_D02[SD02][NOTAS], nota_max_D01[5], nota_max_D02[5], acum, acum1, acum2, i, j;
	float prom_D01, prom_D02, nota_def_D01[SD01], nota_def_D02[SD02];

	acum = 0;
	acum1 = 0;
	prom_D01 = 0;
	prom_D02 = 0;

	printf("Bienvenido al sistema de recopilacion de notas de estudiantes");

	for(i = 0; i < SD01; i++){
		printf("\nIngrese el nombre del estudiante #%d: ", i+1);
		scanf("%s", &nombres_D01[i]);
		acum = 0;
		for (j = 0; j < NOTAS ; j++)
		{
			notas_D01[i][j] = rand() % 20 + 1;
			acum += notas_D01[i][j];
			/*Here's the problem, I have used to for to run over the 20 students and the 3 notes
			but the next for tries to check that the notes do not repeats twice on the same test
			I'm still trying to figure out how to do it*/
			for(int k = i + 1; k < SD01; k++)
			{
				do
				{
					if(notas_D01[i][j] == notas_D01[k][j]){
						notas_D01[i][j] = rand() % 20 + 1;
					}
					else if(notas_D01[i][j] == notas_D01[i-k][j]){
						notas_D01[i][j] = rand() % 20 + 1;
					}
				} while (notas_D01[i][j] == notas_D01[k][j]);
				
				
			}
			printf("%d\n", notas_D01[i][j]);

		}
		nota_def_D01[i] = acum/NOTAS;
		printf("Nota final: %.2f\n", nota_def_D01[i]);
		acum1 += nota_def_D01[i];
	}
	prom_D01 = acum1/SD01;
	printProm01d(prom_D01, nota_def_D01, nombres_D01, SD01);
	system("cls");

	for (i = 0; i < SD02; i++)
	{
		printf("Ingrese el nombre del estudiante #%i: ", i+1);
		fflush;
		scanf("%s", &nombre_max_D02[i]);
		for (j = 0; j < NOTAS; j++)
		{
			printf("Ingrese la nota #%d: ", j);
			scanf("%d", &notas_D02[i][j]);
		}

		nota_def_D02[i] = (notas_D02[i][0] + notas_D02[i][1] + notas_D02[i][2]) / 3;
		printf("Nota final: %f\n", nota_def_D02[i]);
		acum2 += nota_def_D02[i];
	}

	prom_D02 = acum2/SD02;
	printProm01d(prom_D02, nota_def_D02, nombres_D02, SD02);

	return 0;
}
