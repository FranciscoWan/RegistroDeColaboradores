#include <stdio.h> // Biblioteca respons�vel por mostrar texto ao usu�rio.
#include <stdlib.h> // Biblioteca respons�vel por alocar espa�o na mem�ria.
#include <locale.h> // Biblioteca respons�vel por identificar texto por regi�o.
#include <string.h> // Biblioteca respons�vel por cuidar das strings.

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	int laco=1;
	for (laco=1;laco=1;)
	{
		//In�cio da cria��o de vari�veis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Final da cria��o de vari�veis/strings
		
		printf("\tVoc� selecionou registro.\n\n\tDigite o cpf a ser cadastrado: ");  // Coletando a informa��o do usu�rio para definir o cpf
		scanf("%s", cpf);  // "%s" serve para armazenar uma string
		
		strcpy(arquivo, cpf);  // strcpy() serve para copiar o valor de uma vari�vel de string para outra vari�vel
	
		FILE *file;  // FILE cria o arquivo
		file = fopen(arquivo,"w"); // fopen abre o arquivo e "w" escreve os dados da vari�vel.
		fprintf(file,cpf);  // fprintf serve para salvar a vari�vel.
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
	
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
	
		// Cria��o da vari�vel que ir� defiir se os dado ser�o salvos ou excluidos
		int salvar=0;
		
		printf("\n\n\tOs dados cadastrados est�o corretos?\n");
		printf("\t1 - Sim, os dados est�o corretos.\n");  //Op��o 1 mant�m os dados salvos
		printf("\t2 - N�o, escrever novamente os dados.\n");  // Op��o 2 exclui os dados rec�m escritos e pede novamente para escrever os dados
		printf("\tSelecione uma op��o: ");
		scanf("%d", &salvar);  // Define o valor da vari�vel inteira salvar
		if (salvar==1)
		{
			printf("\n\tOs dados foram salvados com sucesso.\n");
			printf("\tRetornando ao menu inicial.\n\t");
			system("pause");
			break; // Sai do loop 
		}
		else if (salvar==2)
		{
			remove(arquivo);
			printf("\n\tOs dados n�o foram salvos.\n\tReiniciando o registro.\n\t");
			system("pause");
			system("cls");
		}
		else
		{
			printf("\n\tOp��o inv�lida, cadastro reiniciado.\n\n");
			system("pause");
		}
	}
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
	
	if(file == NULL)  // Valida��o caso o arquivo seja inexistente.
	{
		printf("\tN�o foi poss�vel encontrar o cadastro.\n\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\tInforma��es do usu�rio: ");
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
	
	if(file == NULL) // Valida��o caso o arquivo seja inexistente.
	{
		printf("\tO usu�rio n�o foi encontrado no sistema.\n\n");
		system("pause");
	}
}

int main()  // Fun��o principal, o progrma sempre retornar� nesta fun��o
{
	int opcao=0;  // Vari�vel de escolha do usu�rio para op��o
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");  // Comando para limpar a tela de prompt
		
		setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
		printf("\t### Cart�rio EBAC ### \n\n");  // In�cio do menu
		printf("  Selecione a op��o desejada: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\t4 - Sair do programa\n\n");
		printf("\tOp��o: ");  // Final da informa��o do menu
	
		scanf("%d", &opcao);  //Sele��o da op��o por parte do usu�rio  // "%d" � utilizado para armazenar uma vari�vel de valor inteiro
	
		system("cls");  // Comando para limpar a tela de prompt
		
		switch(opcao)  // In�cio da sele��o de menus
		{
			case 1:
			registro();  // Chamada da fun��o registro();
			break;
			
			case 2:
			consulta();  // Chamado da fun��o consulta();
			break;
			
			case 3:
			excluir();  // Chamado da fun��o excluir();
			break;
			
			case 4:
			printf("\tObrigado por utilizar o sistema!\n"); 
			return 0;  // Transforma o valor da vari�vel 'la�o' = 0 e quebra o loop do for, encerrando o programa
			break;
			
			default:
			printf("\tEssa op��o n�o existe\n\n");  
			system("pause");  //Pausa o programa at�  sele��o de uma nova op��o pelo usu�rio
			break;	
		} // Final da sele��o de menus
	
	
	}
	
	printf("Esse software foi desenvolvido por Francisco Wanderer");
}
