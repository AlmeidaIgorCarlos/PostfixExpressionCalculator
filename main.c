#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char infixa[50];
	int infixaPonteiro = 0;
	
	char posfixa[50];
	int posfixaPonteiro = 0;
	
	char operadores[50];
	int operadoresPonteiro = 0;
	
	char dado;
	int i;
	
	printf("Digite a expressao infixa, por favor: \n");
	fflush(stdin);
	gets(infixa);

	for(i = 0; i < 50; i++){
		if(isdigit(infixa[i])){
			
			//Posfixa armazena o dígito
			posfixa[posfixaPonteiro] = infixa[i];
			posfixaPonteiro++;
			
		}else{
			if(infixa[i] == '*' || infixa[i] == '/'){
				while(operadoresPonteiro > 0){
					//Desempilha operador
					operadoresPonteiro--;
					dado = operadores[operadoresPonteiro];
					
					if(dado != '+' && dado != '-'){
						//Posfixa armazena o operador
						posfixa[posfixaPonteiro] = dado;
						posfixaPonteiro++;
					}else{
						//Empilha operador
						operadores[operadoresPonteiro] = dado;
						operadoresPonteiro++;
						break;
					}
				}
			}else{
				while(operadoresPonteiro > 0){
					
					//Desempilha operador
					operadoresPonteiro--;
					dado = operadores[operadoresPonteiro];
					
					//Posfixa armazena o operador
					posfixa[posfixaPonteiro] = dado;
					posfixaPonteiro++;
				}
			}
			
			//Empilha caracter
			operadores[operadoresPonteiro] = infixa[i];
			operadoresPonteiro++;
		}
	}
	
	while(operadoresPonteiro > 0){
		//Desempilha o operador
		operadoresPonteiro--;
		dado = operadores[operadoresPonteiro];
		
		//Posfixa armazena o operador
		posfixa[posfixaPonteiro] = dado;
		posfixaPonteiro++;
	}
	
	printf("\n\nInfixa: %s\n", infixa);
	printf("Posfixa: %s\n\n", posfixa);
}
