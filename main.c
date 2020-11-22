#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int opc = 0;
	char usuario[11], senha[11];
	
	// Tela de login
	do {
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
