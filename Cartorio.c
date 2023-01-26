#include <stdio.h> // biblioteca de comunicacao com o usuario
#include <stdlib.h> // biblioteca de alocacao de espaco na memoria 
#include <locale.h> //biblioteca de alocacoes de texto
#include <string.h> //biblioteca de strings 

// INICIO DAS FUNCOES

char logincheckglb[100];


int registrar()
{
   // inicio declaracao de variaveis
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   // fim declaracao de variaveis 
   
   FILE *file; // criando o comando para usar arquivos
   
   // inicio tela 03
   printf("To create a profile, please answer the following questions: \n\n");
   printf("Insert the user's CPF: ");
   scanf("%s", cpf); // Armazenando o CPF como chave mestra para nomeacao de arquivo. 
   
   file = fopen (cpf, "r"); // Lendo o dado da chave mestra no arquivo
   
   if (file != NULL ) // verificar se o arquivo ja esta cadastrado 
   {    
        // Inicio tela 04
        printf("\nA profile with this CPF already exists, please try again! \n");
        printf("To update this profile query it on the second option a the menu. \n\n");
   	  
   	  	system("pause");
   	  	// Fim tela 04
   	
   } 
   else // Procedimento caso nao esteja.
   {	
    	strcpy(arquivo, cpf); //resposavel por copiar o valor da string.
        
   		file = fopen(arquivo, "w"); // Criando um arquivo com o nome da chave mestra.
    	   fprintf(file, "CPF: ");
 	    fclose(file);
   
	    file = fopen(arquivo, "a");
  	       fprintf(file, cpf); // inserindo o a chave mestra no arquivo.
 	    fclose(file);
   
 	    file = fopen(arquivo, "a");
   	   	   fprintf (file, "; Name: "); // Nomeando o proximo dado no arquivo.
  	    fclose(file);
   
   
 	    printf("Insert the first name: ");
   	    scanf("%s", nome); // Armazenando dado 2.
   
        file = fopen (arquivo, "a");
   		   fprintf(file, nome); // Inserindo dado 2 ao arquivo.
        fclose(file);
   
        file = fopen(arquivo, "a");
   		   fprintf (file, " ");
        fclose(file);
   
   
        printf("Insert the surname: ");
        scanf("%s", sobrenome); // Armazenando dado 3.
   
        file = fopen(arquivo, "a");
   		   fprintf(file, sobrenome); // Inserindo dado 3 no arquivo.
        fclose(file);
   
        file = fopen(arquivo, "a");
   		   fprintf (file, "; Corporate Position: "); // Nomeando o nome do proximo dado no arquivo.
        fclose(file);
   
   
        printf("Insert corporate position: ");
        scanf("%s", cargo); // Armazenando dado 4.
   
        file = fopen(arquivo, "a");
   		   fprintf(file, cargo); // Inserindo dado 4 no arquivo.
        fclose(file);
   
        file = fopen(arquivo, "a");
   		   fprintf (file, ". ");
        fclose(file);
   
        printf("\n\nUSER CREATED SUCCESFULLY! \n\n");
        
        system("pause");
        // Fim tela 03.
   }
}

int consultar()
{
	
	// Inicio declaracao variaveis.
	char consulta[40];
	char conteudo[200];
	int opcao = 0;
	int comparacao = 0;
	
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Fim declaracao variaveis.
	
	// Inicio tela 05.
	printf("Insert the CPF you wish to query: ");
	scanf("%s", consulta); // Armazenando chave mestra.
	
	FILE *file;
	
	comparacao = strcmp (logincheckglb, consulta);
	
	if (comparacao == 0)
	{
		printf("\n\n---- ERROR ----\n\n. ");
		system ("pause");
		return 0;
	}
	
	file = fopen(consulta, "r"); // Lendo a chave no arquivo para consulta.
	
	if (file == NULL) // Caso o aqruivo nao exista.
	{
		// Inicio tela 06.
		printf("\nThis user is not registered.\n");
		system("pause");
		// Fim tela 06.
	}
	else // Caso exista.
	{

		while (fgets(conteudo, 200, file) != NULL) // Colocando todo o conteudo do arquivo dentro de uma variavel.
		{
			printf("\nThe user profile is: \n\n");
			printf("%s", conteudo); // Apresentando a variavel com todo o conteudo do arquivo.
			printf("\n\n");
		}
	
		printf("1. Yes \n2. No \n\nDo you wish to update this profile's data? ");
		scanf("%d", &opcao); // Armazenando resposta para alteracao de arquivo.
	
		switch (opcao)
		{
			case 1: 
			
			fclose(file); // fechando o arquivo.
			
			printf("\nInsert the CPF: "); 
			scanf("%s", cpf); // Armazenando novo dado de chave mestra. (que pode ser o mesmo).
			
			strcpy(arquivo, consulta); // Copiando duas strings.
    
	   		file = fopen(arquivo, "w");
	    	   fprintf(file, "CPF: ");
	 	    fclose(file);
   
		    file = fopen(arquivo, "a");
	  	       fprintf(file, cpf); // Inserindo novo arquivo de chave mestra. (que pode ser o mesmo).
	 	    fclose(file);
   
 		    file = fopen(arquivo, "a");
	   	   	   fprintf (file, "; Name: ");
	  	    fclose(file);
   
            
	 	    printf("Insert the first name: ");
	   	    scanf("%s", nome); // Armazenando novo dado.
   
	        file = fopen (arquivo, "a");
	   		   fprintf(file, nome); // Inserindo novo dado.
	        fclose(file);
   
	        file = fopen(arquivo, "a");
	   		   fprintf (file, " ");
	        fclose(file);
   
   
	        printf("Insert the surname: ");
	        scanf("%s", sobrenome); // Armazenando novo dado.
   
	        file = fopen(arquivo, "a");
	   		   fprintf(file, sobrenome); // Inserindo novo dado.
	        fclose(file);
   
	        file = fopen(arquivo, "a");
	   		   fprintf (file, "; Corporate Position: ");
	        fclose(file);
   
   
	        printf("Insert the corporate position: ");
	        scanf("%s", cargo); // Armazenando novo dado.
   
	        file = fopen(arquivo, "a");
	   		   fprintf(file, cargo); // Inserindo novo dado.
	        fclose(file);
   
	        file = fopen(arquivo, "a");
	   		   fprintf (file, ". ");
	        fclose(file);
	        
	        rename(consulta, cpf); // Renomeando o arquivo com a nova chave mestra inserida.
		
		    printf("\n\n USER SUCCEFULLY UPDATED! \n\n");
		    
			break;
		    // Fim tela 05
		    
			case 2: // Caso a segundo opcao seja selecionada.
			
			// Incio tela 07.
			system("cls");
			printf("\n\n OK! Press any key to go back to menu. \n\n");
			break;
			// Fim tela 07.
		
			default:
			// Inicio tela 08.
			system("cls"); // Caso nenhuma opcao seja selecionada.
			printf("\n\nThis option is not available! Please try again. \n\n");
		    // Fim tela 08.
		}
		
	fclose(file); // Fechando o arquivo para as proximas funcoes.
	system("pause");
    }

}

int deletar()
{
	// Inicio declaracao variaveis 
	char cpf[40];
	int opcao = 0;
	int comparacao = 0;
	// Fim declaracao variaveis 
	
	// Inicio tela 09.
	printf("Please insert the profile's CPF you wish to delete: "); // armazenando a chave mestra
	scanf("%s", cpf); // armazenando a chave mestra 
	
	FILE *file;
	
	comparacao = strcmp (logincheckglb, cpf);
	
	if (comparacao == 0)
	{
		printf("\n\n---- ERROR ----\n\n. ");
		system ("pause");
		return 0;
	}
	
	file = fopen(cpf, "r"); // Lendo a chave mestra no arquivo para consulta.
	
	if (file == NULL) // verificando a existencia do arquivo 
	{
		printf("\nThis profile does not exist. \n\n");
		fclose(file); // Fechando o arquivo para as proximas funcoes.
		
	} else // Caso exista.
	{
		fclose(file); // Fechando o arquivo.
		
		printf("\nAre you sure? PRESS [1] for 'YES' or [2] for 'NO'. "); // Certificando a resposta.
		scanf("%d", &opcao); // Armazenando opcao.
		
		switch (opcao)
		{
		case (1):	
		remove(cpf); // Excluindo o arquivo.
		printf("\nThe profile has been succesfully deleted!\n\n");
		break; 
		
		case (2): // Caso o cliente mude de ideia.
		printf("\nOK! Press any key to get back to menu.\n\n");
		break;
		
		default: // caso opcao nao exista.
		printf("\nThis option is not available, try again at the menu. \n\n");
		
	    }
	}
	
	system("pause");
	
	// Fim tela 09.
}

int alterardados()
{
	//inicio variaveis
	char checar[100];
	char email[100];
	char senha[40];
	char email2[100];
	char senha2[40];
	char checar2[100];
	char conteudo[120];
	int comparacao=0;
	
	//fim variaveis
	
	// Inicio tela 10.
	printf("Insert old Email and Passwords: ");
	printf("\n\n Old email: ");
	scanf("%s", email); // Guardando chave mestra para alteracao
	printf("\n Old password: ");
	scanf("%s", senha);
	
	FILE *velho; //Criando os comandos FILE
	FILE *novo;
			
	strcpy (checar, email);
				
	velho = fopen (checar, "r"); //Lendo a chave mestra no arquivo para averiguacao.
	
	
				
	if (velho == NULL) // Verificando existencia do arquivo.
	{
		// Inicio tela 11.
		printf("This email is incorrect, please try again.\n\n ");
		// Fim tela 11.
	}
	else // Caso exista.
	{
		while (fgets(conteudo, 120, velho) != NULL )
		{ 
		}
	
		fclose(velho); // fechando arquivo para bom funcionamento.
	
		strcat (checar, senha);
	
		comparacao = strcmp (checar, conteudo);
		
		if (comparacao == 0)
		{
			
			printf("\n\n============================================");
			printf("\nInsert NEW Email and Password: ");
			printf("\n\n New or Same email: ");
			scanf("%s", email2);
			printf("\n New or Same password: ");
			scanf("%s", senha2);
						
			remove(email); // Deletando antigo arquivo para a criacao do novo.
		
			strcpy (checar2, email2);
					
			novo = fopen (checar2, "w"); // Criando novo arquivo com o email como chave mestra.
				fprintf(novo, email2); 
				fprintf(novo, senha2); // Inserindo senha para login posterior.
			fclose(novo);
					
			printf("\n\n Account details updated succesfully! \n\n");
		}
		else 
			printf("\n The password is incorrect. \n\n");
		
	}
	system("pause");
	// Fim tela 10.
}

int menu()
{
	int opcao=0;
	int laco=1;
	
	for (laco=1; laco=1;)
	{
		system("cls");
		
	//inicio tela 1 
		printf("===== EBAC NOTARY OFFICE ===== \n\n"); // Inicio do menu
		printf("Welcome to the Registry's software. \n\n\n");
		printf("\t 1. Register a new name. \n");
		printf("\t 2. Query a name. \n");
		printf("\t 3. Delete a name. \n");
		printf("\t 4. Update account details.\n ");
		printf("\t 5. Exit program. \n\n\n");
	
		printf("Please choose one of the options shown above: "); //fim do menu
		scanf("%d", &opcao); // Armazenando a resposta do usuario 
	
		system("cls");
		// fim da tela 1
		
	    switch (opcao) //inicio da selecao
	    {
	    	case 1:
	    	registrar(); // Acionando a funcao de Deletar.
			break;
			
			case 2:
			consultar(); // Acionando a funcao de consultar.
			break;
			
			case 3:
			deletar(); // Acionando a funcao de deletar.
			break;
			
			case 4:
			alterardados(); // Acionando funcao de alterar dados da conta.
			break;
			
			case 5:
			printf("Exit succesfully done. ");
			return 0;
			break;
			
			//inicio tela 2
			default:
			printf("This option is not available, try again!\n\n");
		    system("pause");
		    // fim tela 2
			
		} //fim da selecao
		 
	}
}

// FIM DAS FUNCOES 


int main()
{
	// inicio variaveis
	int opcao=0; 
	int laco=1;
	char email[40];
	char senha[40];
	int checar=0;
	char conteudo[100];
	char checar2[40];
	char checar3[100];
	// fim variaveis
	
	for (laco=1; laco=1;) // 
	{	
		system ("cls");
		
	    // Inicio tela 12.
	    
	    // Menu inicial
		printf("===== EBAC NOTARY OFFICE ===== \n\n");
		printf("1. LOGIN "); 
		printf("\n2. REGISTER");
		printf("\n3. EXIT. ");
		printf("\n\nOption: ");
		scanf("%d", &opcao); 
		// Menu incial
	
		FILE *login1;
		FILE *login2;
	
		switch (opcao)
		{
			case 1: // .
				
				printf("===========================================");
    			printf("\n\nInsert your details do LOGIN. \n\n");
				printf("Email: ");
				scanf("%s", email); // Guardando email como chave mestra para nomecao de arquivo.
				printf("Password: ");
				scanf("%s", senha); 
				
				strcpy (checar3, email);
				
				login2 = fopen (checar3, "r"); //Lendo a chave no arquivo para averiguacao.
				
				if (login2 != NULL) // Inicio da averiguacao de acesso a conta.
				{
					strcat (checar3, senha);
					
					while (fgets(conteudo, 100, login2) != NULL ) // Lendo as informacoes de acesso para uma variavel de comparacao.
					{
					}
					
					checar = strcmp (checar3, conteudo); // Comparando as informacoes de login.
					fclose(login2);
					
					if (checar == 0) // Verificando se as informacoes de login estao corretas.
					{
						strcpy (logincheckglb, email);
						menu();
					}
	    // Fim tela 12.
					else // Caso estejam incorretas.
					
					    // Inicio tela 13.
						printf("\n\nEither password or email are incorrect, please try again. \n\n");
						system("pause");
						// Fim tela 13.
					
				} else 
				    // Inicio tela 14.
					printf("\n\nThis account does not exist, please try again! \n\n");
					system("pause");
					// Fim tela 14.
					
					// Fim da averiguacao de acesso.
				
			break;
	
			case 2: // Inicio do registro de novas contas.
			
				system("cls");
				
				//inicio tela 15.
				
				printf("=======================================");
				printf("\n\nInsert your details to REGISTER. \n\n");
				printf("Email: ");
				scanf("%s", email); // Guardando email como chave mestra. 
				printf("Password: ");
				scanf("%s", senha); // Guarando senha para averiguacao.
				
				strcpy (checar2, email);
				
				login1 = fopen (checar2, "r"); // Lendon chave mestra no arquivo.
				fclose(login1);
				
				if (login1 == NULL) // Verificando se o arquivo ja existe.
				{	
					login1 = fopen (checar2,"w"); // Criando conta.
						fprintf(login1, email); // Inserindo dados.
						fprintf(login1, senha);
					fclose(login1);
					
					printf("\nAccount succesfully created.\n\n");
					system("pause");
					
				// Fim tela 15.
				} 
				else 
				{
					// Inicio tela 16.
					printf("This email is already registered, to change password or email please login.\n\n ");
					system("pause");
					// Fim tela 16.
				}
				
				break;
			
			case 3:
				return (0);	
			break;
	
			default:
				printf("This option does not exist.");
				system("pause");
				
		
		 }
	} 
}
