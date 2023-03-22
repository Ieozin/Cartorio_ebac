#include <stdio.h> //Biblioteca de comuni��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o Respons�vel por cadastrar os usu�rios no sistema
{
	
	//Inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se � string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //Cria o arquivo no banco de dados e o "w" significa escrever
	fprintf(file, cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file,","); //Imprime uma virgula para separar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //Coletando informa��o do usu�rio
	scanf("%s", nome); //Salva a vari�vel nome no "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, nome); //Imprime as vari�veis do "nome"
	fclose(file); //Fecha o arquivo 
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, ","); //Imprime uma virgula para separar
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: \n"); //Coletando informa��es do usu�rio
	scanf("%s", sobrenome); //Salva a vari�vel sobrenome no "%s"
	
	file= fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, sobrenome); //Imprime as vari�veis do "sobrenome"
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, ","); //Imprime uma virgula para separar 
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: \n"); //Coletando informa��es do usu�rio
	scanf("%s", cargo); //Salva a vari�vel cargo no "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, cargo); //Imprime as vari�veis do "Cargo"
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o sistema para o usu�rio ler
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	//Inicio da cria��o de vari�veis
	char cpf[40];  
	char conteudo[200];
	//Fim da cria��o de veri�veis
	
	printf("Digite o cpf a ser consultado: \n"); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //Salvando a vari�vel no "%s"
	
	FILE *file; //Cria o arquivo do banco de dados
	file = fopen(cpf,"r"); //Abre o arquivo e consulta-se, "r" significa ler
	
	if(file == NULL) //Se a vari�vel n�o existir, exibe mensagem de erro
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Faz uma checagem na vari�vel, se ela existe exibe a mensagem
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Imprime um guia para o usu�rio entender a informa��o
		printf("%s", conteudo); //Imprime a vari�vel consultada
		printf("\n\n"); //Imprime espa�os de linha para separar
	}
	
	system("pause"); //Sistema pausa para usu�rio ler
	
}


int deletar()
{
	
	char cpf[40]; //Cria vari�vel 
	
	printf("Digite o cpf a ser deletado: "); //Coleta informa��o do usu�rio
	scanf("%s",cpf); //Salva a vari�vel no "%s"
	
	remove(cpf); //Se a vari�vel existir, remova ela 
	
	FILE *file; //Cria o arquivo do banco de dados
	file = fopen(cpf,"r"); //Consulta o arquivo do banco de dados, "r" significa ler
	
	if(file == NULL) //Faz uma checagem
	{
		printf("O Usu�rio n�o se encontra no sistema!.\n"); //Passa a informa��o que a vari�vel n�o existe
		system("pause"); //Pausa no sistema para usu�rio ler
	}
	    
	
}


int main()
{
	int opcao =0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	
        
        system("cls"); //Respons�vel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	    //Inicio do Menu
      	printf("###__ Cart�rio da EBAC __###\n\n"); 
    	printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1- Registar Nomes\n");
    	printf("\t2- Consultar Nomes\n");
	    printf("\t3- Apagar Nomes\n\n\n"); 
	    printf("\t4- Sair do sistema\n\n");
    	printf("Op��o: "); 
		//Fim do Menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls"); //Respons�vel por limpar a tela
    	
    	switch(opcao) //Inicio da sele��o do menu
    	{
    		case 1:
    		registro(); //Chamada de fun��es, chama a fun��o "registro"
 	    	break;
 	    	
 	    	case 2:
 	    	consulta(); //Chamada de fun��es, chama a fun��o "consulta"
		    break;
		    
		    case 3:
		   	deletar(); //Chamada de fun��es, chama a fun��o "deletar"
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
	    	return 0;
	    	break;
	    
	    	default:
	    	printf("Essa op��o n�o est� disponivel, tente novamente\n");
		    system("pause");
		    break; //Fim da Sele��o
        }
        
        
        
    }
    
        
}
    
    

