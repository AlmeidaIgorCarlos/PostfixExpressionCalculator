#include <stdio.h>
#include <string.h>
#include <ctype.h>

//define

int main(){
	//Arrays
	char infixa[50];
	char posfixa[50];
	char pilha[50];
	
	char dado;
	
	//i -> For
	int i;
	
	//Ponteiro para indicar o topo da pilha
	int pilhaPonteiro = 0;
	
	//Lendo a expressão infixa
	printf("Digite a expressao infixa, por favor: \n");
	fflush(stdin);
	gets(infixa);
	
	
	for(i = 0; i < 50; i++){
		if(isdigit(infixa[i])){
			posfixa[i] = infixa[i];
		}else{
			//É * ou /
			if(infixa[i] == '/' || infixa[i] == '*'){
				for(pilhaPonteiro; pilhaPonteiro<=0; pilhaPonteiro--){
					if(pilha[pilhaPonteiro] == '*' || pilha[pilhaPonteiro] == '/'){
						posfixa[i] = pilha[pilhaPonteiro];
						pilhaPonteiro--;
					}
					pilhaPonteiro++;
					pilha[pilhaPonteiro] = infixa[i];
				}
				pilhaPonteiro++;
				pilha[pilhaPonteiro] = posfixa[i];
				}
			else{
				//Zerando pilha
				for(pilhaPonteiro; pilhaPonteiro<=0; pilhaPonteiro--){
					if(pilha[pilhaPonteiro] == '*' || pilha[pilhaPonteiro] == '/' || pilha[pilhaPonteiro] == '+' || pilha[pilhaPonteiro] == '-'){
						for(i = 0; i <= 50; i++){
							if(posfixa[i] == '\0'){
								posfixa[1] = pilha[pilhaPonteiro];
								pilhaPonteiro--;
								break;
							}
						}
					}
				}
				pilhaPonteiro++;
				pilha[pilhaPonteiro] = infixa[i];
			}
		}
	}
	
	//Zerando pilha
	for(pilhaPonteiro; pilhaPonteiro<=0; pilhaPonteiro--){
		if(pilha[pilhaPonteiro] == '*' || pilha[pilhaPonteiro] == '/' || pilha[pilhaPonteiro] == '+' || pilha[pilhaPonteiro] == '-'){
			for(i = 0; i <= 50; i++){
				if(posfixa[i] == '\0'){
					posfixa[1] = pilha[pilhaPonteiro];
					pilhaPonteiro--;
					break;
				}
			}
		}
	}
	
	printf("Expressao infixa: %s", puts(infixa));
	printf("Expressao posfixa: %s", puts(posfixa));
	printf("Pilha: %s", puts(pilha));
}
