#include <stdio.h> // Biblioteca responsável por mostrar texto ao usuário.
#include <stdlib.h> // Biblioteca responsável por alocar espaço na memória.
#include <locale.h> // Biblioteca responsável por identificar texto por região.
#include <string.h> // Biblioteca responsável por cuidar das strings.

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/strings
	
	printf("\tVocê selecionou registro.\n\n\tDigite o cpf a ser cadastrado: ");  // Coletando a informação do usuário para definir o cpf
	scanf("%s", cpf);  // "%s" serve para armazenar uma string
	
	strcpy(arquivo, cpf);  // strcpy() serve para copiar o valor de uma variável de string para outra variável
	
	FILE *file;  // FILE cria o arquivo
	file = fopen(arquivo,"w"); // fopen abre o arquivo e "w" escreve os dados da variável.
	fprintf(file,cpf);  // fprintf serve para salvar a variável.
	fclose(file);  // fclose fecha o arquivo.
	
	file = fopen(arquivo,"a");  // "a" server para atualizar o arquivo existente
	fprintf(file, ",");
	fclose(file);
	
	printf("\tDigite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");  // "a" server para atualizar o arquivo existente
	fprintf(file, ",");
	fclose(file);
	
	printf("\tDigite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");  // "a" server para atualizar o arquivo existente
	fprintf(file, ",");
	fclose(file);
	
	printf("\tDigite o cargo da pessoa cadastrada: ");
	scanf("%s", cargo);
	system("pause"); //Pausa o programa até  seleção de uma nova opção pelo usuário
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\tDigite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");  // "r" utilizado para ler os arquivos
	
	if(file == NULL)  // Validação caso o arquivo seja inexistente.
	{
		printf("\tNão foi possível encontrar o cadastro.\n\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\tInformações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	fclose(file);
}

int excluir()
{
	char cpf[40];
	
	printf("\tDigite o CPF a ser excluido: ");
	scanf("%s", cpf);
	
	remove(cpf);  // Exclui realmente o cpf 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) // Validação caso o arquivo seja inexistente.
	{
		printf("\tO usuário não foi encontrado no sistema.\n\n");
		system("pause");
	}
}

int main()  // Função principal, o progrma sempre retornará nesta função
{
	int opcao=0;  // Variável de escolha do usuário para opção
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");  // Comando para limpar a tela de prompt
		
		setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
		printf("\t### Cartório EBAC ### \n\n");  // Início do menu
		printf("  Selecione a opção desejada: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n\n");
		printf("\tOpção: ");  // Final da informação do menu
	
		scanf("%d", &opcao);  //Seleção da opção por parte do usuário  // "%d" é utilizado para armazenar uma variável
	
		system("cls");  // Comando para limpar a tela de prompt
		
		switch(opcao)  // Início da seleção de menus
		{
			case 1:
			registro();  // Chamada da função registro();
			break;
			
			case 2:
			consulta();  // Chamado da função consulta();
			break;
			
			case 3:
			excluir();  // Chamado da função excluir();
			break;
			
			default:
			printf("\tEssa opção não existe\n\n");  
			system("pause");  //Pausa o programa até  seleção de uma nova opção pelo usuário
			break;	
		} // Final da seleção de menus
	
	
	}
	
	printf("Esse software foi desenvolvido por Francisco Wanderer");
}
