#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
    // Início criação das variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação das variáveis/string
    
    printf("Informe o CPF para cadastro:  "); // Coletando informação do usuário
    scanf("%s", cpf); // %s refere-se a string 
    
    strcpy(arquivo, cpf); // Responsável por copiar os valores das string
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo,"w"); // Cria o arquivo
    fprintf(file,cpf); // Salvo o valor da variável
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Vírgula
    fprintf(file, ","); // Vírgula
    fclose(file); // Vírgula
    
    printf("Informe o NOME para cadastro:  ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // Vírgula
    fprintf(file, ","); // Vírgula
    fclose(file); // Vírgula
    
    printf("Informe o SOBRENOME para cadastro:  ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // Vírgula
    fprintf(file, ","); // Vírgula
    fclose(file); // Vírgula
    
    printf("Informe o CARGO para cadastro:  ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta() // Função responsável por realizar a consulta dos usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
	
	// Início criação das variáveis/string
	char cpf[40];
	char conteudo[200];
	// Final da criação das variáveis/string
	
	printf("Informe o CPF para consulta:   "); // Fornecendo informação ao usuário
	scanf("%s",cpf);  // %s refere-se a string 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF informado não localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
	
}

int deletar() // Função responsável por deletar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
	
	char cpf[40];
	
	printf("Informe o CPF do usuário que deseja DELETAR:  "); // Obtendo dados para ação de deletar
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado no sistema.\n");
		system("pause");
	}
}


int main()

{
	int opcao=0; // Definindo as variáveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	  system("cls"); // Responsável por limpar a tela
	
      setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
    
      printf("### Cartório da EBAC ###\n\n"); // Início do menu.
      printf("Escolha a opção desejada do menu e aperte ENTER.\n\n");
      printf("\t1 - Registrar Nomes.\n");
      printf("\t2 - Consultar Nomes.\n");
      printf("\t3 - Deletar Nomes.\n\n");
	  printf("Opção: "); // Fim do menu.
    
      scanf("%d", &opcao); // Armazenando a escolha do usuário
    
      system ("cls");
      
      
      switch(opcao) // Início da seleção do menu.
      {
      	case 1:
		registro(); // Chamada de funções
    	break;
    	
    	case 2:
    	consulta();
    	break;
    	
    	case 3:
    	deletar();
    	break;
    	
    	default:
    	printf("Infelizmente essa opção não está disponível. Por favor, escolha entre as opções 1, 2 ou 3 para prosseguir.\n\n");
		system("pause");
		break; // Fim da seleção
      	
	  } 
	
	}
}





