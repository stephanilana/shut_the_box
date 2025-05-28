#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numerosJog[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // 0 = disponível, 1 = riscado
    int somaJogadas, jogada;
    int dado1, dado2, somaDados;
    int terminou = 0;
    char sair;
    srand(time(NULL)); // inicia o gerador de números aleatórios do C - quando não utilizada ele sempre vai assumir o número anterior como inicial e gerar sempre a mesma sequencia

    printf("=== JOGO DE RISCAR NUMEROS ===\n");

    while (1)
    {
        // Verificar se todos os números foram riscados
        terminou = 1;
        // vai passar por todas as posições ue existem dentro da variável controladora validando se ainda tem-se o número 0 em alguma posição
        for (int i = 0; i < 9; i++)
        {
            if (numerosJog[i] == 0)
            {
                // se o número 0 ainda existir dentro de numerosJog ele continua setado a variável terminou como 0
                terminou = 0;
                break;
            }
        }
        if (terminou)
        {
            printf("\n🎉 Parabens!! Voce ganhou o jogo!! 🎉\n");
            break;
        }

        // Jogar os dados
        dado1 = (rand() % 6) + 1;
        dado2 = (rand() % 6) + 1;
        somaDados = dado1 + dado2;

        printf("\n==============================\n");
        printf("Dado 1: %d | Dado 2: %d | Soma: %d\n", dado1, dado2, somaDados);
        printf("Numeros disponiveis no tabuleiro: ");
        for (int i = 0; i < 9; i++)
        {
            // mostra cada uma das POSIÇÕES da variável numerosJog somando sempre + 1 se o registro dessa posição for iugual a 0
            if (numerosJog[i] == 0)
            {
                printf("%d ", i + 1);
            }
        }
        printf("\n");

        // Soma dos números disponíveis
        int somaDisponiveis = 0;
        for (int i = 0; i < 9; i++)
        {
            if (numerosJog[i] == 0)
            {
                somaDisponiveis += (i + 1);
            }
        }

        // Verificar se existe alguma combinação possível
        // int existeCombinacao = 0;
        // int totalCombinacoes = 1 << 9; // 2^9 combinações possíveis
        // for (int mask = 1; mask < totalCombinacoes; mask++)
        // {
        //     int somaAtual = 0;
        //     for (int i = 0; i < 9; i++)
        //     {
        //         if ((mask & (1 << i)) && numerosJog[i] == 0)
        //         {
        //             somaAtual += (i + 1);
        //         }
        //     }
        //     if (somaAtual == somaDados)
        //     {
        //         existeCombinacao = 1;
        //         break;
        //     }
        // }

        if (somaDados <= somaDisponiveis) // if (somaDados <= somaDisponiveis && existeCombinacao)
        {
            somaJogadas = 0;
            printf("Deseja contuniar jogango?\nDigite S para sair ou N para continuar jogando: ");
            scanf(" %c", &sair);

            if (sair != 'S' || sair != 's')
            {
                printf("\nFim de jogo. Voce decidiu sair!\n");
                break;
            }

            while (somaJogadas < somaDados)
            {
                printf("Digite um numero para riscar: ");
                scanf("%d", &jogada);

                if (jogada < 1 || jogada > 9)
                {
                    printf("Numero invalido! Digite um numero entre 1 e 9.\n");
                    continue;
                }

                if (numerosJog[jogada - 1] == 0)
                {
                    somaJogadas += jogada;
                    numerosJog[jogada - 1] = 1;

                    if (somaJogadas == somaDados)
                    {
                        printf("Muito bem! Proxima rodada!\n");
                    }
                    else if (somaJogadas > somaDados)
                    {
                        printf("Numero invalido! A soma ultrapassou a dos dados. Repita a jogada.\n");
                        somaJogadas -= jogada;
                        numerosJog[jogada - 1] = 0;
                    }
                }
                else
                {
                    printf("Numero ja riscado! Digite outro.\n");
                }
            }
        }
        else
        {
            printf("\nNao ha mais combinacoes possiveis. Fim de jogo. Voce perdeu!\n");
            break;
        }
    }

    return 0;
}
