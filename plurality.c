#include <cs50.h>
#include <stdio.h>
#include <string.h>


#define MAX 9

// Estrutura que vai armazenar os nomes e votos dos candadidatos.
typedef struct
{
    string name;
    int votes;
}
candidate; // nome dessa gaveta/estrutura

// vetor de estrutura com tamanho definido.
candidate candidates[MAX];

// numeros de candidatos vindo de argv1++++
int candidate_count;

// prototypes das funções 
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check de uso errado
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Quantidade de candidatos no argc, tirando a posição correspondente ao nome do file.
    candidate_count = argc - 1;
    if (candidate_count > MAX) // check de que o numero de candidato nao vai ultrapassar a quantidade máxima.
    {
        printf("Número máximo de candidato é: %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) 
    {
        candidates[i].name = argv[i + 1];  // Operação para ingnorar a posição 0, pois corresponde ao nome do file.
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Vai repetir até o user ter colocado a quantidade de votos de acordo com a contagem dos eleitores.
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Se o voto for diferente dos nomes passado em argv
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
        
      
    }

  
    // Mostrar vencedor da eleição 
    print_winner();
}

// Atualização total de votos dada a uma nova votação 
bool vote(string name)
{
    for(int i = 0; i < candidate_count; i++) 
    {
        if(strcmp(candidates[i].name, name) == 0) // verificar se o valor da ESTRUTURA candidate corresponde a name, que é o nome que foi tentado votar.
        {
            candidates[i].votes++; // Se corresponder ele vai adicionando em uma n posição do vetor no int votes localizado na estrutura 
            return true;
        }
    }
    
    return false;
}

// Imprimir o vencedor 
void print_winner(void)
{
    int max_votes = 0; 
    
    for(int i =0; i< candidate_count; i++) 
    {
        if(candidates[i].votes > max_votes) // Enquanto os votos forem maior que o numero max_votes, ele vai adicionando ao índice de uma posiçao do array que corresponde a var int votes
        {
             max_votes = candidates[i].votes;
        }
    }
    
    for( int i =0; i <candidate_count; i++)
    {
        if(candidates[i].votes == max_votes) // Se alguma posição do array for igual ao número max_votes, ele vai imprimir ao nome do candidato correspondente aquela certa posição do votes 
        {
            printf("Vencedo(a)(s): %s\n", candidates[i].name);
        }
    }
    return;
}

29/06/2022
