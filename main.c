#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NEO_STRUCT 77
typedef struct {
    char nome[NEO_STRUCT];
    char isbn[NEO_STRUCT];
    float preco;
    int score;
    char editora[NEO_STRUCT];
} Livro;
typedef Livro* pLivro;
pLivro livro_aloc(int qtde) {
    return (pLivro)malloc(qtde * sizeof(Livro));
}
void livro_ler(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        printf("\n>>%d:\n", i + 1);
        printf("Nome: ");
        fgets(livros[i].nome, NEO_STRUCT, stdin);
        livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0';
        printf("ISBN: ");
        fgets(livros[i].isbn, NEO_STRUCT, stdin);
        livros[i].isbn[strcspn(livros[i].isbn, "\n")] = '\0';
        printf("Preço: ");
        scanf("%f", &livros[i].preco);
        printf("Avaliação (0 a 10): ");
        scanf("%d", &livros[i].score);
        getchar();
        printf("Editora: ");
        fgets(livros[i].editora, NEO_STRUCT, stdin);
        livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0';
    }
}
void livro_exibe(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
    }
}
void livro_desaloca(pLivro livros) {
    free(livros);
}
int main() {
    int qtde;
    printf("QTDE LIVRO>> ");
    scanf("%d", &qtde);
    getchar();
    pLivro livros = livro_aloc(qtde);
    if (livros == NULL) {
    printf("Erro ao alocar memória!\n");
    return 1;
}
    livro_ler(livros, qtde);
    livro_exibe(livros, qtde);
    livro_desaloca(livros);
    return 0;
}
