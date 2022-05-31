struct Item{
    int codigo;
    char descricao[51];
    double valorUnitario;
    int quantidade;
    double valorTotal;
};
typedef struct Item item;

void inicializar(item* p_carrinho[], int tam);

int adicionar(item* p_carrinho[], int pos);

void fecharCompra(item *p_carrinho[], int tam, char * arquivo);
