#include <stdio.h>
#include<math.h>
#include<resultadosmake.h>

void resultados() 
{
int z=0,epsilon3=0;
float epsilon2,epsilon1;
char prenom[20];
FILE *results;
FILE *inicial;
FILE *data;
int i,j,n;

data=fopen("datos.txt","r");
fscanf(data,"%i",&n);
fscanf(data,"%f",&epsilon1);
fclose(data);
n=n+2;

float T[n][n];
float To[n][n];

inicial = fopen("inicial.txt","r");
for(j=0; j<n; j++)
{
for(i=0; i<n; i++)
{
fscanf(inicial,"%f \n",&T[i][j]);
}
}
fclose(inicial);

do {
for(j=1;j<n-1;j++){
for(i=1;i<n-1;i++) {
T[i][j]=(T[i+1][j]+T[i-1][j]+T[i][j+1]+T[i][j-1])/4;

T[i][j]=(T[i][j]*1.5)+((1-1.5)*To[i][j]);

epsilon2=0;

if(sqrt(pow((((T[i][j]-To[i][j])/(To[i][j]))*100),2))>epsilon2){
epsilon2=sqrt(pow((((T[i][j]-To[i][j])/(To[i][j]))*100),2));
}
To[i][j]=T[i][j];
}

}

sprintf(prenom,"%iresultados.txt",z);
	if(epsilon2>epsilon1 && z%5==0){
	results=fopen(prenom,"w");
	}
	else{
	results=fopen("balance.txt","w");
	}

	for(j=1;j<n-1;j++){
		for(i=1;i<n-1;i++){
			fprintf(results,"%f\t",T[i][j]);
		}
		fprintf(results,"\n");
	}
fclose(results);
z=z+1; 
}

while(epsilon2>epsilon1 && epsilon3<3100);

}
