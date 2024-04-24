//Criado por: Felipe S. Hirata e Felipe S. Winter
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char nome[50], cpf[11];
  int digitocpf[11];
  printf("Digite seu primeiro nome:\n");
  scanf("%s", nome);

  int digito1, digito2;
  int soma = 0;
  int i, j;

    printf("Seja bem vindo %s, insira seu CPF para a verificação:\n ", nome);
    scanf("%s", cpf);

  if (strlen(cpf) < 11 || strlen(cpf) > 11) {
    printf("Você deve inserir 11 dígitos do seu CPF.\n");
  }

  for (i = 0; i < strlen(cpf); i++) {
    if (cpf[i] >= '0' || cpf[i] <= '9') {
      digitocpf[i] = cpf[i] - '0';
    }
  }

  for (i = 0, j = 10; i < 9; i++, j--) {
    soma += digitocpf[i] * j;
  }

  int resto = soma % 11;
  digito1 = (resto < 2) ? 0 : (11 - resto);

  soma = 0;

  for (i = 0, j = 11; i < 9; i++, j--) {
    soma += digitocpf[i] * j;
  }

  soma += digito1 * 2;
  resto = soma % 11;
  digito2 = (resto < 2) ? 0 : (11 - resto);

  if (digitocpf[9] == digito1 && digitocpf[10] == digito2) {
    printf("O CPF é válido.\n\n");
  } else {
    printf("O CPF é inválido.\n\n");
  }

  int reiniciar;
  printf("Deseja reiniciar o programa? (1 - Sim, 0 - Não):\n");
  scanf("%d", &reiniciar);

  if(reiniciar == 1){
  main();
  }
  else(
    printf("Programa encerrado. Adeus!\n")
  );
  }