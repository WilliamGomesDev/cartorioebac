#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// In�cio cria��o das vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da cria��o das vari�veis/string
    
    printf("Informe o CPF para cadastro:  "); // Coletando informa��o do usu�rio
    scanf("%s", cpf); // %s refere-se a string 
    
    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo,"w"); // Cria o arquivo
    fprintf(file,cpf); // Salvo o valor da vari�vel
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // V�rgula
    fprintf(file, ","); // V�rgula
    fclose(file); // V�rgula
    
    printf("Informe o NOME para cadastro:  ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // V�rgula
    fprintf(file, ","); // V�rgula
    fclose(file); // V�rgula
    
    printf("Informe o SOBRENOME para cadastro:  ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // V�rgula
    fprintf(file, ","); // V�rgula
    fclose(file); // V�rgula
    
    printf("Informe o CARGO para cadastro:  ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta() // Fun��o respons�vel por realizar a consulta dos usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
	
	// In�cio cria��o das vari�veis/string
	char cpf[40];
	char conteudo[200];
	// Final da cria��o das vari�veis/string
	
	printf("Informe o CPF para consulta:   "); // Fornecendo informa��o ao usu�rio
	scanf("%s",cpf);  // %s refere-se a string 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF informado n�o localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
	
}

int deletar() // Fun��o respons�vel por deletar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
	
	char cpf[40];
	
	printf("Informe o CPF do usu�rio que deseja DELETAR:  "); // Obtendo dados para a��o de deletar
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no sistema.\n");
		system("pause");
	}
}


int main()

{
	int opcao=0; // Definindo as vari�veis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	  system("cls"); // Respons�vel por limpar a tela
	
      setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
    
      printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu.
      printf("Escolha a op��o desejada do menu e aperte ENTER.\n\n");
      printf("\t1 - Registrar Nomes.\n");
      printf("\t2 - Consultar Nomes.\n");
      printf("\t3 - Deletar Nomes.\n\n");
      printf("\t4 - Sair do sistema.\n\n");
	  printf("Op��o: "); // Fim do menu.
    
      scanf("%d", &opcao); // Armazenando a escolha do usu�rio
    
      system ("cls");
      
      
      switch(opcao) // In�cio da sele��o do menu.
      {
      	case 1:
		registro(); // Chamada de fun��es
    	break;
    	
    	case 2:
    	consulta();
    	break;
    	
    	case 3:
    	deletar();
    	break;
    	
    	case 4:
    	printf("Obrigado por utilizar o sistema, volte sempre que precisar.\n");
    	return 0;
    	break;
    	
    	default:
    	printf("Infelizmente essa op��o n�o est� dispon�vel. Por favor, escolha entre as op��es 1, 2 ou 3 para prosseguir.\n\n");
		system("pause");
		break; // Fim da sele��o
      	
	  } 
	
	}
}





