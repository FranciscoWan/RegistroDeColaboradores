#include <stdio.h> // Biblioteca responsável por mostrar texto ao usuário.
#include <stdlib.h> // Biblioteca responsável por alocar espaço na memória.
#include <locale.h> // Biblioteca responsável por identificar texto por região.
#include <string.h> // Biblioteca responsável por cuidar das strings.

//int registro() // Função responsável por cadastrar os usuários no sistema
//{
//	int laco=1;
//	for (laco=1;laco=1;)
//	{
//		//Início da criação de variáveis/strings
//		char arquivo[40];
//		char cpf[40];
//		char nome[40];
//		char sobrenome[40];
//		char cargo[40];
//		//Final da criação de variáveis/strings
//		
//		printf("\tVocê selecionou registro.\n\n\tDigite o cpf a ser cadastrado: ");  // Coletando a informação do usuário para definir o cpf
//		scanf("%s", cpf);  // "%s" serve para armazenar uma string
//		
//		strcpy(arquivo, cpf);  // strcpy() serve para copiar o valor de uma variável de string para outra variável
//	
//		FILE *file;  // FILE cria o arquivo
//		file = fopen(arquivo,"w"); // fopen abre o arquivo e "w" escreve os dados da variável.
//		fprintf(file,cpf);  // fprintf serve para salvar a variável.
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
//		// Criação da variável que irá defiir se os dado serão salvos ou excluidos
//		int salvar=0;
//		
//		printf("\n\n\tOs dados cadastrados estão corretos?\n");
//		printf("\t1 - Sim, os dados estão corretos.\n");  //Opção 1 mantém os dados salvos
//		printf("\t2 - Não, escrever novamente os dados.\n");  // Opção 2 exclui os dados recém escritos e pede novamente para escrever os dados
//		printf("\tSelecione uma opção: ");
//		scanf("%d", &salvar);  // Define o valor da variável inteira salvar
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
//			printf("\n\tOs dados não foram salvos.\n\tReiniciando o registro.\n\t");
//			system("pause");
//			system("cls");
//		}
//		else
//		{
//			printf("\n\tOpção inválida, cadastro reiniciado.\n\n");
//			system("pause");
//		}
//	}
//}
void exibirDados(const char *cpf) 
{
    FILE *file = fopen(cpf, "r"); // Abre o arquivo para leitura
    if (file == NULL) 
    {
        printf("\tErro: Não foi possível abrir o arquivo. Verifique se o CPF está cadastrado.\n");
        return;
    }

    // Variáveis temporárias para armazenar os dados do arquivo
    char cpfAtual[40], nome[40], sobrenome[40], cargo[40];

    // Lê os dados do arquivo
    fscanf(file, "%[^,],%[^,],%[^,],%s", cpfAtual, nome, sobrenome, cargo);
    fclose(file); // Fecha o arquivo após a leitura

    // Exibe os dados no console
    printf("\n\tDados atuais do cadastro:\n");
    printf("\tCPF: %s\n", cpfAtual);
    printf("\tNome: %s\n", nome);
    printf("\tSobrenome: %s\n", sobrenome);
    printf("\tCargo: %s\n", cargo);
}

int registro() // Função responsável por cadastrar os usuários no sistema
{
    int laco = 1;
    while (laco == 1)
    {
        // Criação de variáveis/strings
        char arquivo[40];
        char cpf[40];
        char nome[40];
        char sobrenome[40];
        char cargo[40];

        printf("\tVocê selecionou registro.\n\n\tDigite o CPF a ser cadastrado: ");
        scanf("%s", cpf);  // Coleta o CPF

        strcpy(arquivo, cpf);  // Cria o nome do arquivo com base no CPF

        // Verifica se o arquivo já existe
        FILE *file = fopen(arquivo, "r");  // Tenta abrir o arquivo no modo de leitura
        if (file != NULL) // Se o arquivo existir
        {  
            printf("\tO CPF já se encontra cadastrado.\n");

            // Exibe os dados atuais antes de atualizar
            exibirDados(arquivo);

            // Opção para retornar ao menu inicial ou atualizar cadastro
            int sequencia = 0;
            printf("\tDeseja atualizar cadastro ou retornar ao menu inicial?\n\n");
            printf("\t1 - Atualizar cadastro.\n");
            printf("\t2 - Retornar ao menu inicial.\n\tOpção: ");
            scanf("%d", &sequencia);
            
            if (sequencia == 1)
            {
                // Código para atualizar cadastro
                printf("\n\tAtualizando cadastro...\n\n");
                fclose(file); // Fecha o arquivo aberto para leitura

                // Lê os dados atuais do cadastro
                char nomeAtual[40], sobrenomeAtual[40], cargoAtual[40];
                file = fopen(arquivo, "r");
                if (file == NULL) 
                {
                    printf("\tErro ao abrir o arquivo para leitura.\n");
                    return 1;
                }
                fscanf(file, "%[^,],%[^,],%[^,],%s", cpf, nomeAtual, sobrenomeAtual, cargoAtual); // Lê os dados
                fclose(file); // Fecha o arquivo após leitura

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
                fclose(file); // Fecha o arquivo após a atualização

                printf("\tCadastro atualizado com sucesso!\n\n");
                system("pause");
            }
            else if (sequencia == 2)
            {
                printf("\tRetornando ao menu inicial.\n");
                fclose(file);  // Fecha o arquivo e sai da função
            }
            else
            {
                printf("\n\tOpção selecionada inválida.\n");
                printf("\tRetornando ao menu inicial.\n\n");
                system("pause");
            }
            return 1;  // Indica que já existe um cadastro com esse CPF
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

        // Confirmação para salvar ou refazer o cadastro
        int salvar = 0;

        printf("\n\tOs dados cadastrados estão corretos?\n");
        printf("\t1 - Salvar dados cadastrados\n");
        printf("\t2 - Escrever novamente os dados\n");
        printf("\tSelecione uma opção: ");
        scanf("%d", &salvar);

        if (salvar == 1) 
        {
            printf("\tOs dados foram salvos com sucesso.\n\n");
            break; // Sai do loop quando os dados são salvos
        } 
        else if (salvar == 2) 
        {
            remove(arquivo);  // Apaga o arquivo e recomeça o cadastro
            printf("\tCadastro reiniciado.\n\n");
        } 
        else 
        {
            printf("\tOpção inválida, cadastro reiniciado.\n\n");
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
	char senha[] = "a";  // Cria a variável senha com valor predefinido de "a"
	int comparacao;  // Cria uma variável para que seja possível a comparação da senha
	
	setlocale(LC_ALL, "Portuguese");  // Define a loclaização para utilizar acentos e letras locais.
	printf("\tBem vindo ao login do cartório EBAC.\n");
	printf("\tDigite a senha: ");
	scanf("%s", senha);  // Aloca o que o usuário digitou para a variável senha
	
	comparacao = strcmp(senha,"admin");
	
	if (comparacao == 0)
	{
		for(laco=1;laco=1;)
		{
			system("cls");  // Comando para limpar a tela de prompt
		
			printf("\t### Cartório EBAC ### \n\n");  // Início do menu
			printf("  Selecione a opção desejada: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Excluir nomes\n");
			printf("\t4 - Sair do programa\n\n");
			printf("\tOpção: ");  // Final da informação do menu
	
			scanf("%d", &opcao);  //Seleção da opção por parte do usuário  // "%d" é utilizado para armazenar uma variável de valor inteiro
	
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
				
				case 4:
				printf("\tObrigado por utilizar o sistema!\n"); 
				return 0;  // Transforma o valor da variável 'laço' = 0 e quebra o loop do for, encerrando o programa
				break;
				
				default:
				printf("\tEssa opção não existe\n\n");  
				system("pause");  //Pausa o programa até  seleção de uma nova opção pelo usuário
				break;	
			} // Final da seleção de menus
		}
	}
	else  // Caso a senha digitada seja diferente de "admin"
	{
		printf("\n\tSenha incorreta!\n");
		printf("\tEncerrando o programa\n\n");  
	}
	
	printf("Esse software foi desenvolvido por Francisco Wanderer");  // Ultima linha de código do programa
}
