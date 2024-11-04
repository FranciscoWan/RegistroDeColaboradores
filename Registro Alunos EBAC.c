#include <stdio.h> // Biblioteca respons�vel por mostrar texto ao usu�rio.
#include <stdlib.h> // Biblioteca respons�vel por alocar espa�o na mem�ria.
#include <locale.h> // Biblioteca respons�vel por identificar texto por regi�o.
#include <string.h> // Biblioteca respons�vel por cuidar das strings.

//int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
//{
//	int laco=1;
//	for (laco=1;laco=1;)
//	{
//		//In�cio da cria��o de vari�veis/strings
//		char arquivo[40];
//		char cpf[40];
//		char nome[40];
//		char sobrenome[40];
//		char cargo[40];
//		//Final da cria��o de vari�veis/strings
//		
//		printf("\tVoc� selecionou registro.\n\n\tDigite o cpf a ser cadastrado: ");  // Coletando a informa��o do usu�rio para definir o cpf
//		scanf("%s", cpf);  // "%s" serve para armazenar uma string
//		
//		strcpy(arquivo, cpf);  // strcpy() serve para copiar o valor de uma vari�vel de string para outra vari�vel
//	
//		FILE *file;  // FILE cria o arquivo
//		file = fopen(arquivo,"w"); // fopen abre o arquivo e "w" escreve os dados da vari�vel.
//		fprintf(file,cpf);  // fprintf serve para salvar a vari�vel.
//		fclose(file);  // fclose fecha o arquivo.
//	
//		file = fopen(arquivo,"a");  // "a" server para atualizar o arquivo existente
//		fprintf(file, ",");
//		fclose(file);
//	
//		printf("\tDigite o nome a ser cadastrado: ");
//		scanf("%s", nome);
//	
//		file = fopen(arquivo,"a");
//		fprintf(file, nome);
//		fclose(file);
//	
//		file = fopen(arquivo, "a");  // "a" server para atualizar o arquivo existente
//		fprintf(file, ",");
//		fclose(file);
//	
//		printf("\tDigite o sobrenome a ser cadastrado: ");
//		scanf("%s", sobrenome);
//		
//		file = fopen(arquivo, "a");
//		fprintf(file, sobrenome);
//		fclose(file);
//	
//		file = fopen(arquivo, "a");  // "a" server para atualizar o arquivo existente
//		fprintf(file, ",");
//		fclose(file);
//	
//		printf("\tDigite o cargo da pessoa cadastrada: ");
//		scanf("%s", cargo);
//	
//		file = fopen(arquivo, "a");
//		fprintf(file, cargo);
//		fclose(file);
//	
//		// Cria��o da vari�vel que ir� defiir se os dado ser�o salvos ou excluidos
//		int salvar=0;
//		
//		printf("\n\n\tOs dados cadastrados est�o corretos?\n");
//		printf("\t1 - Sim, os dados est�o corretos.\n");  //Op��o 1 mant�m os dados salvos
//		printf("\t2 - N�o, escrever novamente os dados.\n");  // Op��o 2 exclui os dados rec�m escritos e pede novamente para escrever os dados
//		printf("\tSelecione uma op��o: ");
//		scanf("%d", &salvar);  // Define o valor da vari�vel inteira salvar
//		if (salvar==1)  
//		{
//			printf("\n\tOs dados foram salvados com sucesso.\n");
//			printf("\tRetornando ao menu inicial.\n\t");
//			system("pause");
//			break; // Sai do loop e retorna ao menu inicial
//		}
//		else if (salvar==2)
//		{
//			remove(arquivo);
//			printf("\n\tOs dados n�o foram salvos.\n\tReiniciando o registro.\n\t");
//			system("pause");
//			system("cls");
//		}
//		else
//		{
//			printf("\n\tOp��o inv�lida, cadastro reiniciado.\n\n");
//			system("pause");
//		}
//	}
//}
void exibirDados(const char *cpf) 
{
    FILE *file = fopen(cpf, "r"); // Abre o arquivo para leitura
    if (file == NULL) 
    {
        printf("\tErro: N�o foi poss�vel abrir o arquivo. Verifique se o CPF est� cadastrado.\n");
        return;
    }

    // Vari�veis tempor�rias para armazenar os dados do arquivo
    char cpfAtual[40], nome[40], sobrenome[40], cargo[40];

    // L� os dados do arquivo
    fscanf(file, "%[^,],%[^,],%[^,],%s", cpfAtual, nome, sobrenome, cargo);
    fclose(file); // Fecha o arquivo ap�s a leitura

    // Exibe os dados no console
    printf("\n\tDados atuais do cadastro:\n");
    printf("\tCPF: %s\n", cpfAtual);
    printf("\tNome: %s\n", nome);
    printf("\tSobrenome: %s\n", sobrenome);
    printf("\tCargo: %s\n", cargo);
}

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
    int laco = 1;
    while (laco == 1)
    {
        // Cria��o de vari�veis/strings
        char arquivo[40];
        char cpf[40];
        char nome[40];
        char sobrenome[40];
        char cargo[40];

        printf("\tVoc� selecionou registro.\n\n\tDigite o CPF a ser cadastrado: ");
        scanf("%s", cpf);  // Coleta o CPF

        strcpy(arquivo, cpf);  // Cria o nome do arquivo com base no CPF

        // Verifica se o arquivo j� existe
        FILE *file = fopen(arquivo, "r");  // Tenta abrir o arquivo no modo de leitura
        if (file != NULL) // Se o arquivo existir
        {  
            printf("\tO CPF j� se encontra cadastrado.\n");

            // Exibe os dados atuais antes de atualizar
            exibirDados(arquivo);

            // Op��o para retornar ao menu inicial ou atualizar cadastro
            int sequencia = 0;
            printf("\tDeseja atualizar cadastro ou retornar ao menu inicial?\n\n");
            printf("\t1 - Atualizar cadastro.\n");
            printf("\t2 - Retornar ao menu inicial.\n\tOp��o: ");
            scanf("%d", &sequencia);
            
            if (sequencia == 1)
            {
                // C�digo para atualizar cadastro
                printf("\n\tAtualizando cadastro...\n\n");
                fclose(file); // Fecha o arquivo aberto para leitura

                // L� os dados atuais do cadastro
                char nomeAtual[40], sobrenomeAtual[40], cargoAtual[40];
                file = fopen(arquivo, "r");
                if (file == NULL) 
                {
                    printf("\tErro ao abrir o arquivo para leitura.\n");
                    return 1;
                }
                fscanf(file, "%[^,],%[^,],%[^,],%s", cpf, nomeAtual, sobrenomeAtual, cargoAtual); // L� os dados
                fclose(file); // Fecha o arquivo ap�s leitura

                // Solicita o novo cargo
                printf("\tDigite o novo cargo: ");
                scanf("%s", cargoAtual);
                // Abre o arquivo no modo de escrita para atualizar o cargo
                file = fopen(arquivo, "w");
                if (file == NULL) 
                {
                    printf("\tErro ao abrir o arquivo para atualizar.\n");
                    return 1;
                }    

                // Grava os dados atualizados no arquivo, mantendo CPF, nome e sobrenome
                fprintf(file, "%s,%s,%s,%s", cpf, nomeAtual, sobrenomeAtual, cargoAtual);
                fclose(file); // Fecha o arquivo ap�s a atualiza��o

                printf("\tCadastro atualizado com sucesso!\n\n");
                system("pause");
            }
            else if (sequencia == 2)
            {
                printf("\tRetornando ao menu inicial.\n");
                fclose(file);  // Fecha o arquivo e sai da fun��o
            }
            else
            {
                printf("\n\tOp��o selecionada inv�lida.\n");
                printf("\tRetornando ao menu inicial.\n\n");
                system("pause");
            }
            return 1;  // Indica que j� existe um cadastro com esse CPF
        }

        // Abre o arquivo para escrita
        file = fopen(arquivo, "w");
        if (file == NULL) 
        {
            printf("\tErro ao criar o arquivo.\n");
            system("pause");
            return 1;
        }

        // Grava o CPF no arquivo
        fprintf(file, "%s", cpf);
        fclose(file);

        // Abre o arquivo no modo append para adicionar dados
        file = fopen(arquivo, "a");
        fprintf(file, ",");

        printf("\tDigite o nome a ser cadastrado: ");
        scanf("%s", nome);
        fprintf(file, "%s", nome);
        fprintf(file, ",");

        printf("\tDigite o sobrenome a ser cadastrado: ");
        scanf("%s", sobrenome);
        fprintf(file, "%s", sobrenome);
        fprintf(file, ",");

        printf("\tDigite o cargo da pessoa cadastrada: ");
        scanf("%s", cargo);
        fprintf(file, "%s", cargo);
        fclose(file);

        // Confirma��o para salvar ou refazer o cadastro
        int salvar = 0;

        printf("\n\tOs dados cadastrados est�o corretos?\n");
        printf("\t1 - Salvar dados cadastrados\n");
        printf("\t2 - Escrever novamente os dados\n");
        printf("\tSelecione uma op��o: ");
        scanf("%d", &salvar);

        if (salvar == 1) 
        {
            printf("\tOs dados foram salvos com sucesso.\n\n");
            break; // Sai do loop quando os dados s�o salvos
        } 
        else if (salvar == 2) 
        {
            remove(arquivo);  // Apaga o arquivo e recome�a o cadastro
            printf("\tCadastro reiniciado.\n\n");
        } 
        else 
        {
            printf("\tOp��o inv�lida, cadastro reiniciado.\n\n");
        }
    }

    return 0;
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
	char senha[] = "a";  // Cria a vari�vel senha com valor predefinido de "a"
	int comparacao;  // Cria uma vari�vel para que seja poss�vel a compara��o da senha
	
	setlocale(LC_ALL, "Portuguese");  // Define a loclaiza��o para utilizar acentos e letras locais.
	printf("\tBem vindo ao login do cart�rio EBAC.\n");
	printf("\tDigite a senha: ");
	scanf("%s", senha);  // Aloca o que o usu�rio digitou para a vari�vel senha
	
	comparacao = strcmp(senha,"admin");
	
	if (comparacao == 0)
	{
		for(laco=1;laco=1;)
		{
			system("cls");  // Comando para limpar a tela de prompt
		
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
	}
	else  // Caso a senha digitada seja diferente de "admin"
	{
		printf("\n\tSenha incorreta!\n");
		printf("\tEncerrando o programa\n\n");  
	}
	
	printf("Esse software foi desenvolvido por Francisco Wanderer");  // Ultima linha de c�digo do programa
}
