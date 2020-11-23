#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int opc = 0;
	char usuario[11], senha[11];
	
	//Protótipos
	void cadastrar_paciente();
	void agendar_consulta();
	void cancelar_consulta();
	
	
	do {
		// Tela de login
		printf("------------------------------\n");
		printf("        CADASTRO MED\n");
		printf("------------------------------\n");
		printf("           LOGIN\n");
		printf("------------------------------\n");
		printf("Usuario: ");
		scanf("%s", usuario);
		
		// Validando Usuário
		if (strcmp(usuario, "master")==0) {
			printf("Senha: ");
			scanf("%s", senha);
			if(strcmp(senha, "123123")==0) {
				printf("Validado\n");
				system("cls");
				
				// Tela incial
				printf("-------------------------------\n");
				printf("  REDE DE CLÍNICAS MED-CORPUS\n");
				printf("-------------------------------\n");
				printf("Bem vindo(a)!\nEscolha uma das opcoes abaixo.\n");
				printf("1 - CONSULTAR PACIENTE\n");
				printf("2 - CADASTRAR PACIENTE\n");
				printf("3 - AGENDAR CONSULTA\n");
				printf("4 - CANCELAR CONSULTA\n");
				printf("5 - AGENDAR EXAME\n");
				printf("6 - CANCELAR EXAME\n");
				printf("7 - VISUALIZAR AGENDA\n");
				printf("10 - SAIR DO SISTEMA\n");
				printf("Digite a sua opcao: ");
				scanf("%d", &opc);
				system("cls");
				
				// Validando escolha
				if (opc == 2){
					cadastrar_paciente();
				} else if (opc == 3 ){
					agendar_consulta();
				} else if (opc == 4) {
					cancelar_consulta();
				} else {
					printf("Opção inválida!\n");
				}
				
			} else{
				printf("Senha invalida\n");
				printf("Digite 0 para sair ou qualquer tecla para tentar novamente: ");
				scanf("%d", &opc);
			}
		} else{
			printf("Usuario invalido\n");
			printf("Digite 0 para sair ou qualquer numero para tentar novamente: ");
			scanf("%d", &opc);
		}
	} while (opc != 0 && opc != 10);
	printf("Saindo... Ate logo!");
	
	return 0;
}

// Funções
void cadastrar_paciente() {
	int resp_cadastro;
	int i;

	struct ficha_paciente{
	    char nome[50];
	    char cpf[15];
	    char data_nasc[11];
	    char telefone[15];
  	};
  	struct ficha_paciente paciente[100];

	for (i = 0; i <= 100; i++){
		printf("\n|---------- Cadastro de paciente ----------|\n\n\n");
		fflush(stdin);
		printf("Nome: ");
		fgets(paciente[i].nome, 40, stdin);
		fflush(stdin);
		printf("CPF: ");
		fgets(paciente[i].cpf, 40, stdin);
		fflush(stdin);
		printf("Data de nascimento: ");
		fgets(paciente[i].data_nasc, 40, stdin);
		fflush(stdin);
		printf("Telefone: ");
		fgets(paciente[i].telefone, 40, stdin);
		fflush(stdin);
		printf("CADASTRADO COM SUCESSO!\n");
		printf("Deseja cadastrar outro paciente? (1 para sim / 0 para não): ");
		scanf("%d", &resp_cadastro);
		fflush(stdin);
		if (resp_cadastro == 0){
		  break;
		}
	}
}

void agendar_consulta() {
		int resp = 0;
		int i;
	
	  struct ficha_consulta{
	    char cpf_paciente[15];
	    char tipo_consulta[25];
	    char data[11];
	    char hora[6];
	  };
	  struct ficha_consulta consulta;
	
	  for (i = 0; i < 1; i++){
	    // Entrada
	    printf("\n|------- Agendando consulta -------|\n\n\n");
	    printf("Código da consulta: %d \n", rand() % 1000);
	    fflush(stdin);
	    printf("CPF do paciente: ");
	    fgets(consulta.cpf_paciente, 15, stdin);
	    fflush(stdin);
	    printf("Tipo da consulta: ");
	    fgets(consulta.tipo_consulta, 25, stdin);
	    fflush(stdin);
	    printf("Data: ");
	    fgets(consulta.data, 11, stdin);
	    fflush(stdin);
	    printf("Hora: ");
	    fgets(consulta.hora, 6, stdin);
	    fflush(stdin);
	    // Saída
	    printf("AGENDADO COM SUCESSO! \n");
	    i--;
	    printf("1 para continuar / 0 para sair: ");
	    scanf("%d", &resp);
	    system("cls");
	    if (resp == 0) {
	      break;
	    }
	}
}

void cancelar_consulta(){
	char codigo[5];
	int resp1, resp2;
	for (int i = 0; i < 1; i++){
		while (resp1 != 0) {
			printf("\n|------- Cancelando consulta -------|\n\n\n");
			printf("Código da consulta: ");
			scanf("%s", codigo);
			fflush(stdin);
			printf("Tem certeza que deseja cancelar a consulta %s? (1 para sim / 0 para não): ", codigo);
			scanf("%d", &resp2);
			if (resp2 == 1) {
				break;
			}else if (resp2 == 0){
				system("cls");
				printf("CONSULTA NÃO CANCELADA!\n");
			} else{
				system("cls");
				printf("Opção inválida!\n");
			}
		}
	}
	system("cls");
	printf("CONSULTA %s CANCELADA COM SUCESSO!\n", codigo);
}
