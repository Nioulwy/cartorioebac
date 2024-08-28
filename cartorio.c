#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocar espaço em memória
#include <locale.h>//biblioteca para definir linguagem
#include <string.h>//biblioteca das strings

int registrar() //Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	
	//criando as variáveis, strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF: ");
	scanf("%s", cpf); // salvando o valor dentro da string(%s) cpf
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores.
	
	FILE *file;
	file = fopen(arquivo, "w"); //criar arquivo, escrevendo arquivo("w").
	fprintf(file,"CPF: ");
	fclose(file);
	
	file = fopen(arquivo, "a"); // atualizando o arquivo("a").
	fprintf(file,cpf); //salvando o conteúdo da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o Nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf (file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf (file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o Cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf (file, cargo);
	fclose(file);
	
	
	system("pause");
	
}

int consultar()
{
    setlocale(LC_ALL, "Portuguese");//definindo linguagem

    //criando as variáveis (strings).
    char cpf[40];
    char conteudo[200];

    printf("Qual CPF deseja consultar? ");
    scanf("%s",cpf); //salvando a resposta do usuário na string(%s) cpf.

    FILE *file; //abrindo o arquivo
    file = fopen(cpf,"r"); //lendo o arquivo (r)

    if(file == NULL) //Definindo resposta para um arquivo inexistente
    {
    	system("cls");
        printf("Este arquivo não foi localizado!");
        printf("\n\n");
        system("pause");
    }

	if(file != NULL)
	{
    	printf("\n");
    	
    	system("cls");
	
    	printf("Informações do Usuário: ");
    
    	printf("\n");
		
    	while(fgets(conteudo, 200, file) != NULL) //Checando e salvando os 200 caractéres dentro da pasta
    	{	
        printf("%s", conteudo); //Trazendo as informações dentro do arquivo.
    	}
		
    	printf("\n\n");
		
		system("pause");	
	}
	
    fclose(file);//fechando o arquivo
    
}

int deletar()
{
	//criando as variáveis(strings).
	char cpf[40];
	
	printf("Digite o CPF que deseja Deletar: ");
	scanf("%s",cpf); //salvando a resposta dentro da string(%s) cpf
	
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo o arquivo (r = read)
	fclose(file);
	
	
	if(file == NULL) //verifica se existe o cpf no arquivo.
	{
		system("cls");
		printf("Usuário não encontrado no sistema.\n\n");
		system("pause");
	}
	if(file != NULL)
	{
		remove(cpf);//responsável por deletar o arquivo desejado.
		system("cls");
		printf("Usuário Deletado com Sucesso! \n\n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao=0; //definindo variáveis
	int xd=1;
	
	for(xd=1;xd=1;)//*começo da repetição
	{
	
	system("cls");
	
		setlocale(LC_ALL, "Portuguese");//definindo linguagem
//	Definindo o Titulo
		printf("	Cartório EBAC	\n\n");
//	Começando o Menu
		printf("Selecione a opção desejada:\n\n\t1 - Registrar Nomes\n\t2 - Consultar Nomes\n\t3 - Deletar Nomes\n\t4 - Sair do Menu\n\nOpção: ");
//	Fim do Menu

		scanf("%d", &opcao);//armazenando a escolha do usuário
	
		system("cls"); //apagar os textos anteriores.
		
		switch(opcao)//inicio das opções
		{
			case 1:
			registrar(); //chama a função
			break;
		
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Você saiu do Menu!\n");
			return 0;
			break;
		
			default:
			printf("Esta opção não existe.\n");
			system("pause");
			break;//fim das opções
		}
	}//*término da repetição
}
