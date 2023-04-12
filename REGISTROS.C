#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memoria 
#include <locale.h> // biblioteca de alocações de espaço de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registrar() // função responsavel por cadastrar os usuarios no sistema 
{ 
    // inicio criaçõo de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];  
	char  sobrenome[40];
	char cargo[40];
	// final criaçõo de variaveis/strings 
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informações dos usuarios 
	scanf("%s", cpf); // %s refere - se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings 
	
	FILE *file; // cria o arquivo no banco de dados 
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuario para o banco de dados 
	scanf("%s", nome); // %s refere - se a string
	
	file = fopen(arquivo, "a"); // criar arquivo e "a" é para escrever 
	fprintf(file,nome); // salvar o valor da variavel 
	fclose(file); // fecha o arquivo 
		
	file = fopen(arquivo, "a"); // cria o arquivo e "a" escreve 
	fprintf(file, ","); // salvar o valor da variavel
	fclose(file); // fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informações do usuario para o banco de dados 
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
		printf("Não foi possivel abrir o  arquivo, não localizado!. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações  do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar() // função de deletar o usuario  do sistema
{
	char cpf[40];
	printf("Por favor, digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //  função para dizer ao usuario que não encontrou o cpf cadastrado3
	{
		printf("O usuário não encontra no sistema, por favor tente novamente! \n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; // definindo variáveis
	int laco=1;
		
	for(laco=1;laco=10;)
	{ // inicio do laço
	 
	    system("cls");
	   
 	    setlocale(LC_ALL, "Portuguese");// definindo a linguagem 
	
	    printf("### Registros Alunos e Funcionarios EBAC! ###\n\n"); // inico do menu principal
     	printf(" Escolha uma das opções a seguir: \n\n "); 
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Você deseja sair do sistema?\n\n");
    	printf("Opção:"); // fim do menu principal
 	
	    scanf("%d" ,  &opcao); // armazenando a escolha do usuario
	
	    system("cls");
	    
	    
	    
	    switch(opcao) // inicio da seleção do menu
	    {
	    	case 1: // chamada de funçoes
	        registrar();
	    	break; 
	    	
	    	case 2:
	    	consultar();
	    	break;
	    	 
	    	case 3:
	    	deletar();
  	    	break;
  	    	
  	    	case 4:
  	    	printf("Obrigado por usar nosso sistema, qualquer duvida estaremos a disposição! \n\n Volte sempre!");
  	    	return 0;
  	    	
  	    	default:
  	    	printf("Essa opção não está disponivel!\n");
   	    	system("pause");
	   	}
	    
    }// fim do laço
}
