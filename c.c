#include <stdio.h>
float promedioVentas(float ventas[], int dias);
float buscarMayor(float ventas[], int dias);
float buscarMenor(float ventas[], int dias);
int contarSuperiores(float ventas[], int n, float referencia);

int main() {
    printf("--- TECNOSTORE - SISTEMA DE VENTAS ---\n");
    
int dias;
printf("Ingrese la cantidad de dias a registrar: ");
scanf("%d", &dias);

if (dias <= 0) {
printf("Error: Debe ingresar un numero positivo de dias.\n");
return 1;
}

float ventas[dias];

printf("\n--- INGRESO DE VENTAS DIARIAS ---\n");
for(int i = 0; i < dias; i++) {
printf("Ingrese las ventas del dia %d: $", i + 1);
scanf("%f", &ventas[i]);
        
if (ventas[i] < 0) {
printf("Error: Las ventas no pueden ser negativas.\n");
return 1;
}
}
float total = 0;
for(int i = 0; i < dias; i++) {
total += ventas[i];
}
    
float promedio = promedioVentas(ventas, dias);
float mayor = buscarMayor(ventas, dias);
float menor = buscarMenor(ventas, dias);

float referencia;
printf("\nIngrese el monto de referencia para contar dias superiores: $");
scanf("%f", &referencia);

int diasSuperiores = contarSuperiores(ventas, dias, referencia);

printf("--- INFORME DE VENTAS ---\n");
    
printf("\n--- VENTAS REGISTRADAS ---\n");
for(int i = 0; i < dias; i++) {
printf("Dia %d: $%.2f\n", i + 1, ventas[i]);
}
  
printf("\n--- ESTADISTICAS ---\n");
printf("Total de ventas: $%.2f\n", total);
printf("Promedio diario: $%.2f\n", promedio);
printf("Mayor venta: $%.2f\n", mayor);
printf("Menor venta: $%.2f\n", menor);
printf("Dias con ventas superiores a $%.2f: %d\n", referencia, diasSuperiores);    

return 0;
}

float promedioVentas(float ventas[], int dias) {
float suma = 0;
for(int i = 0; i < dias; i++) {
suma += ventas[i];
}
return suma / dias;
}

float buscarMayor(float ventas[], int dias) {
float mayor = ventas[0];
for(int i = 1; i < dias; i++) {
if (ventas[i] > mayor) {
mayor = ventas[i];
}
}
return mayor;
}

float buscarMenor(float ventas[], int dias) {
float menor = ventas[0];
for(int i = 1; i < dias; i++) {
if (ventas[i] < menor) {
menor = ventas[i];
}
}
return menor;
}

int contarSuperiores(float ventas[], int n, float referencia) {
if (n == 0) {
return 0;
}

int count = contarSuperiores(ventas, n - 1, referencia);

if (ventas[n - 1] > referencia) {
return count + 1;
} 
else {
return count;
}
}