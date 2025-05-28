#include <stdio.h> // Carrefar a função do printf (para exibir mensagens na tela)

int main()
{
    char nome[50];
    printf("Hello World!!!");
    printf("\nAgora que ja nos comprimentamos, me diga o seu nome: ");
    scanf("%s", &nome);
    printf("\nMuito prazer %s", nome);
}
