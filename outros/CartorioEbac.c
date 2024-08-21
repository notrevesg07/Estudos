#include <stdio.h>  //biblioteca de comunicação
#include <stdlib.h> //biblioteca de Memoria
#include <locale.h> //biblioteca de Acentuação
#include <string.h> //biblioteca de strings

int inserir() // Função inserir
{
	setlocale(LC_ALL,"portuguese"); // Aceitar pontuação português 
	
	char arquivo[40]; // Criar Strings 				    
	char cpf[40]; // Criar Strings						
	char nome[40]; // Criar Strings						
	char sobrenome[40]; // Criar Strings					
	char cargo[40]; // Criar Strings						
	
	
	printf("Qual seu CPF?"); // guardar cpf do usuario
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); // função para copiar string
	
	FILE *file; // criar Arquivo
	
	file = fopen(arquivo,"w"); // abrir primera vez arquivo
	fprintf(file,cpf);
	fclose(file); //fechar arquivo

	file = fopen(arquivo,"a"); // atualizar arquivo com ,
	fprintf(file,",");
	fclose(file); //fechar arquivo

	printf("Qual seu nome?"); // guardar nome do usuario
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); // atualizar arquivo com nome
	fprintf(file,nome);
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo,"a"); // atualizar arquivo com ,
	fprintf(file,",");
	fclose(file); //fechar arquivo
	

	printf("Qual seu sobrenome?"); // guardar sobrenome do usuario
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a"); // atualizar arquivo com sobrenome
	fprintf(file,sobrenome);
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo,"a"); // atualizar arquivo com ,
	fprintf(file,",");
	fclose(file); //fechar arquivo
	
	
	printf("Qual seu cargo?"); // guardar cargo do usuario
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); // atualizar arquivo com cargo
	fprintf(file,cargo);
	fclose(file); //fechar arquivo
	
	
}

int consultar(){ //Função consuta
	
	setlocale(LC_ALL,"portuguese"); // Aceitar pontuação português 

	char cpf[40]; // strings criadas
	char conteudo[200]; // strings criadas
	 
	printf("Digite o CPF:"); // guardar cpf do usuario
	scanf("%s",cpf);
	
	FILE *file; // abrir arquivo
	file = fopen(cpf,"r");
	

	if(file == NULL) // verificar se são dados validos
	{
		printf("Arquivo não  encontrado!!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) // exibir dados solicitados
	{
		printf("\nEsse são os dados solicitados:\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause"); // pausar sistema para Visualização 
	fclose(file); //fechar arquivo
	
}

int excluir(){ // Função Excluir
	char cpf[40]; 
	
	printf("Digite o CPF do usuário a ser deletado:"); // guardar cpf do usuario
	scanf("%s",cpf);

	FILE *file; // abrir arquivo
	file = fopen(cpf,"r");
	fclose(file); //fechar arquivo
	
	if (file == NULL) // verificar se são dados validos
	{
		printf("\nCPF não encontrado!\n\n"); // dado inexistente
		system("pause");
	}
	else
	{
		if (remove(cpf) == 0) // remover dado
		{ 
			printf("\nCPF deletado com sucesso!\n\n"); // Informa que foi apagado
			system("pause");
		}
	}
}


int main() // Função Principal
{
		
	setlocale(LC_ALL,"portuguese"); // Aceitar pontuação português 
	
	int opcao=0; // criar variavel inteiro
	int loco=1; // criar variavel inteiro
	int comparacao1; // criar variavel inteiro
	int comparacao2; // criar variavel inteiro
	char login[10]= "a"; // Criar Strings com valor a
	char senha[10]="a"; // Criar Strings com valor a
	
	printf("### Cartório Everton ###\n\n");  // Menu para Usuario		
	printf("Login de ADM!\n\nDigite seu usuario: ");  // Menu para Usuario		
	scanf("%s",login); // guardar senha do usuario
	
	printf("Digite a sua senha: ");  // Menu para Usuario		
	scanf("%s",senha); // guardar senha do usuario
	
	comparacao1 = strcmp(login,"everton"); // funcao para comparar Strings
	comparacao2 = strcmp(senha,"12345"); // funcao para comparar Strings

	
	if (comparacao1 == 0 && comparacao2 == 0) // verificar se são dados validos
	{
	
		for(loco=1;loco=1;){ // laço de repetiçõo
			system("cls"); // limpar console
			
			
			printf("### Cartório Everton ###\n"); // Menu para Usuario			
			printf("Escolha a opção desejada do menu:\n\n");	 
			printf("\t1 - registar nome\n");				  
			printf("\t2 - consultar nome \n");				 	
			printf("\t3 - deletar nome\n");
			printf("\t4 - Sair Do Sistema\n\n");					
			printf("Opção: "); // Menu para Usuario									
			
			
			scanf("%d",&opcao); // guardar Opção escolida do usuario
			system("cls"); // limpar console
			
			 
			switch(opcao){ // Verificações das opções do menu
				case 1:
				inserir(); // chanar Função inserir
				break;
				
				case 2:
				consultar(); // chanar Função consultar
				break;
				
				case 3:
				excluir(); // chanar Função excluir
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema flw\n"); // Sair Do Sistema 
				return 0;
				break;
						
				default:
				printf("Você escolheu opção Que não existe\n"); // informar que opções nao existe
				system("pause");
				break;
			} 
		}
	}
	else
	{
		printf("Você Digitou usuario ou Senha Errado"); // informar erro de senha
	}
}
