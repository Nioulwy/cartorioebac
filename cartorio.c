#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de alocar espa�o em mem�ria
#include <locale.h>//biblioteca para definir linguagem
#include <string.h>//biblioteca das strings

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	
	//criando as vari�veis, strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF: ");
	scanf("%s", cpf); // salvando o valor dentro da string(%s) cpf
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores.
	
	FILE *file;
	file = fopen(arquivo, "w"); //criar arquivo, escrevendo arquivo("w").
	fprintf(file,"CPF: ");
	fclose(file);
	
	file = fopen(arquivo, "a"); // atualizando o arquivo("a").
	fprintf(file,cpf); //salvando o conte�do da vari�vel
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

    //criando as vari�veis (strings).
    char cpf[40];
    char conteudo[200];

    printf("Qual CPF deseja consultar? ");
    scanf("%s",cpf); //salvando a resposta do usu�rio na string(%s) cpf.

    FILE *file; //abrindo o arquivo
    file = fopen(cpf,"r"); //lendo o arquivo (r)

    if(file == NULL) //Definindo resposta para um arquivo inexistente
    {
    	system("cls");
        printf("Este arquivo n�o foi localizado!");
        printf("\n\n");
        system("pause");
    }

	if(file != NULL)
	{
    	printf("\n");
    	
    	system("cls");
	
    	printf("Informa��es do Usu�rio: ");
    
    	printf("\n");
		
    	while(fgets(conteudo, 200, file) != NULL) //Checando e salvando os 200 caract�res dentro da pasta
    	{	
        printf("%s", conteudo); //Trazendo as informa��es dentro do arquivo.
    	}
		
    	printf("\n\n");
		
		system("pause");	
	}
	
    fclose(file);//fechando o arquivo
    
}

int deletar()
{
	//criando as vari�veis(strings).
	char cpf[40];
	
	printf("Digite o CPF que deseja Deletar: ");
	scanf("%s",cpf); //salvando a resposta dentro da string(%s) cpf
	
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo o arquivo (r = read)
	fclose(file);
	
	
	if(file == NULL) //verifica se existe o cpf no arquivo.
	{
		system("cls");
		printf("Usu�rio n�o encontrado no sistema.\n\n");
		system("pause");
	}
	if(file != NULL)
	{
		remove(cpf);//respons�vel por deletar o arquivo desejado.
		system("cls");
		printf("Usu�rio Deletado com Sucesso! \n\n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao=0; //definindo vari�veis
	int xd=1;
	
	for(xd=1;xd=1;)//*come�o da repeti��o
	{
	
	system("cls");
	
		setlocale(LC_ALL, "Portuguese");//definindo linguagem
//	Definindo o Titulo
		printf("	Cart�rio EBAC	\n\n");
//	Come�ando o Menu
		printf("Selecione a op��o desejada:\n\n\t1 - Registrar Nomes\n\t2 - Consultar Nomes\n\t3 - Deletar Nomes\n\t4 - Sair do Menu\n\nOp��o: ");
//	Fim do Menu

		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls"); //apagar os textos anteriores.
		
		switch(opcao)//inicio das op��es
		{
			case 1:
			registrar(); //chama a fun��o
			break;
		
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Voc� saiu do Menu!\n");
			return 0;
			break;
		
			default:
			printf("Esta op��o n�o existe.\n");
			system("pause");
			break;//fim das op��es
		}
	}//*t�rmino da repeti��o
}
