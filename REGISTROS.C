#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> // biblioteca de aloca��es de espa�o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings

int registrar() // fun��o responsavel por cadastrar os usuarios no sistema 
{ 
    // inicio cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];  
	char  sobrenome[40];
	char cargo[40];
	// final cria��o de variaveis/strings 
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��es dos usuarios 
	scanf("%s", cpf); // %s refere - se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings 
	
	FILE *file; // cria o arquivo no banco de dados 
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usuario para o banco de dados 
	scanf("%s", nome); // %s refere - se a string
	
	file = fopen(arquivo, "a"); // criar arquivo e "a" � para escrever 
	fprintf(file,nome); // salvar o valor da variavel 
	fclose(file); // fecha o arquivo 
		
	file = fopen(arquivo, "a"); // cria o arquivo e "a" escreve 
	fprintf(file, ","); // salvar o valor da variavel
	fclose(file); // fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��es do usuario para o banco de dados 
	scanf("%s", sobrenome); // %s refere -  se a strings 
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
	
	}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");// definindo a linguagem 

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o  arquivo, n�o localizado!. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es  do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar() // fun��o de deletar o usuario  do sistema
{
	char cpf[40];
	printf("Por favor, digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //  fun��o para dizer ao usuario que n�o encontrou o cpf cadastrado3
	{
		printf("O usu�rio n�o encontra no sistema, por favor tente novamente! \n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; // definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Registros Alunos e Funcionarios EBAC! ###\n\n"); 
	printf("Login de administrador!\n\nDigite sua senha:");
	scanf ("%s", senhadigitada);
	
	
	comparacao = strcmp(senhadigitada, "27102022");
	
		if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{	

			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
			printf("### Registros Alunos e Funcionarios EBAC!  ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Voc� deseja sair do sistema?\n\n");
			printf("Op��o: ");//fim do menu
				
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
			system("cls"); //responsavel por limpar a tela
	
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
				registrar();
				break;
			
				case 2:
				consultar();
				break;
		
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n\n Volte Sempre!");
				return 0;
				break;
			
	
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
		
			} //fim da sele��o
		}
	}
	
	else
		printf("Senha incorreta!");	
}
