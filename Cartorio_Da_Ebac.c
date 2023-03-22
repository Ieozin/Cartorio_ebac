#include <stdio.h> //Biblioteca de comunição com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função Responsável por cadastrar os usuários no sistema
{
	
	//Inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se à string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //Cria o arquivo no banco de dados e o "w" significa escrever
	fprintf(file, cpf); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file,","); //Imprime uma virgula para separar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //Coletando informação do usuário
	scanf("%s", nome); //Salva a variável nome no "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, nome); //Imprime as variáveis do "nome"
	fclose(file); //Fecha o arquivo 
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, ","); //Imprime uma virgula para separar
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: \n"); //Coletando informações do usuário
	scanf("%s", sobrenome); //Salva a variável sobrenome no "%s"
	
	file= fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, sobrenome); //Imprime as variáveis do "sobrenome"
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, ","); //Imprime uma virgula para separar 
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: \n"); //Coletando informações do usuário
	scanf("%s", cargo); //Salva a variável cargo no "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo nomeado de "file"
	fprintf(file, cargo); //Imprime as variáveis do "Cargo"
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o sistema para o usuário ler
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	//Inicio da criação de variáveis
	char cpf[40];  
	char conteudo[200];
	//Fim da criação de veriáveis
	
	printf("Digite o cpf a ser consultado: \n"); //Coletando informações do usuário
	scanf("%s",cpf); //Salvando a variável no "%s"
	
	FILE *file; //Cria o arquivo do banco de dados
	file = fopen(cpf,"r"); //Abre o arquivo e consulta-se, "r" significa ler
	
	if(file == NULL) //Se a variável não existir, exibe mensagem de erro
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Faz uma checagem na variável, se ela existe exibe a mensagem
	{
		printf("\nEssas são as informações do usuário: "); //Imprime um guia para o usuário entender a informação
		printf("%s", conteudo); //Imprime a variável consultada
		printf("\n\n"); //Imprime espaços de linha para separar
	}
	
	system("pause"); //Sistema pausa para usuário ler
	
}


int deletar()
{
	
	char cpf[40]; //Cria variável 
	
	printf("Digite o cpf a ser deletado: "); //Coleta informação do usuário
	scanf("%s",cpf); //Salva a variável no "%s"
	
	remove(cpf); //Se a variável existir, remova ela 
	
	FILE *file; //Cria o arquivo do banco de dados
	file = fopen(cpf,"r"); //Consulta o arquivo do banco de dados, "r" significa ler
	
	if(file == NULL) //Faz uma checagem
	{
		printf("O Usuário não se encontra no sistema!.\n"); //Passa a informação que a variável não existe
		system("pause"); //Pausa no sistema para usuário ler
	}
	    
	
}


int main()
{
	int opcao =0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	
        
        system("cls"); //Responsável por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	    //Inicio do Menu
      	printf("###__ Cartório da EBAC __###\n\n"); 
    	printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1- Registar Nomes\n");
    	printf("\t2- Consultar Nomes\n");
	    printf("\t3- Apagar Nomes\n\n\n"); 
	    printf("\t4- Sair do sistema\n\n");
    	printf("Opção: "); 
		//Fim do Menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    	system("cls"); //Responsável por limpar a tela
    	
    	switch(opcao) //Inicio da seleção do menu
    	{
    		case 1:
    		registro(); //Chamada de funções, chama a função "registro"
 	    	break;
 	    	
 	    	case 2:
 	    	consulta(); //Chamada de funções, chama a função "consulta"
		    break;
		    
		    case 3:
		   	deletar(); //Chamada de funções, chama a função "deletar"
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
	    	return 0;
	    	break;
	    
	    	default:
	    	printf("Essa opção não está disponivel, tente novamente\n");
		    system("pause");
		    break; //Fim da Seleção
        }
        
        
        
    }
    
        
}
    
    

