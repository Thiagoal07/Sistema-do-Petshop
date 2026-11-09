#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerInteiro() {
    char entrada[50];
    fgets(entrada, 50, stdin);
    return atoi(entrada);
}

int login() {
    char senha[30];
    char usuario[50];
    int tentativas = 3;

    do {
        printf("============= LOGIN =============\n");
        printf("Você tem %d tentativas.\n", tentativas);

        printf("Usuário: ");
        fgets(usuario, 50, stdin);
        usuario[strcspn(usuario, "\n")] = '\0';

        printf("Senha: ");
        fgets(senha, 30, stdin);
        senha[strcspn(senha, "\n")] = '\0';

        if (strcmp(usuario, "Miguel Thiago") == 0 &&
            strcmp(senha, "1234") == 0) {
            return 1;
        } else {
            tentativas--;
            system("clear");
            printf("Usuário ou senha incorretos!\n\n");
        }

    } while (tentativas > 0);

    return 0;
}

int selecionarPet(int codigoCliente[5], char cliente[5][50],
                  char pet[10][100], int nrPet[5],
                  int totalClientes) {

    int codigoBusca;
    int inicio = 0;
    int escolha;

    printf("Digite o código do cliente: ");
    codigoBusca = lerInteiro();

    for (int c = 0; c < totalClientes; c++) {

        if (codigoBusca == codigoCliente[c]) {

            for (int j = 0; j < c; j++) {
                inicio += nrPet[j];
            }

            printf("\nCliente: %s\n", cliente[c]);
            printf("\n========== ESCOLHA O PET ==========\n");

            for (int i = 0; i < nrPet[c]; i++) {
                printf("[%d] %s\n", i + 1, pet[inicio + i]);
            }

            do {
                printf("Digite o número do PET: ");
                escolha = lerInteiro();

                if (escolha < 1 || escolha > nrPet[c]) {
                    printf("Digite um número válido!\n");
                }

            } while (escolha < 1 || escolha > nrPet[c]);

            return inicio + escolha - 1;
        }
    }

    printf("Código do cliente não encontrado!\n");
    return -1;
}

void adicionarItem(char itemNome[10][50][100],
                   float itemValor[10][50],
                   int totalItens[10], float total[10],
                   int petSelecionado, const char *nome, float valor) {

    if (totalItens[petSelecionado] < 50) {

        snprintf(itemNome[petSelecionado][totalItens[petSelecionado]],
                 100, "%s", nome);

        itemValor[petSelecionado][totalItens[petSelecionado]] = valor;

        totalItens[petSelecionado]++;
        total[petSelecionado] += valor;

        printf("Item adicionado com sucesso!\n");

    } else {
        printf("Limite de itens atingido!\n");
    }
}

void funcBanho(int portePet[10], char itemNome[10][50][100],
               float itemValor[10][50], int totalItens[10],
               float total[10], int somaBusca) {

    if (portePet[somaBusca] == 1) {
        adicionarItem(itemNome, itemValor, totalItens, total,
                      somaBusca, "Banho para PET pequeno", 20);

    } else if (portePet[somaBusca] == 2) {
        adicionarItem(itemNome, itemValor, totalItens, total,
                      somaBusca, "Banho para PET médio", 30);

    } else if (portePet[somaBusca] == 3) {
        adicionarItem(itemNome, itemValor, totalItens, total,
                      somaBusca, "Banho para PET grande", 40);

    } else {
        printf("Porte do PET inválido!\n");
    }
}

void funcTosa(char itemNome[10][50][100],
              float itemValor[10][50], int totalItens[10],
              float total[10], int somaBusca) {

    int opcao;
    const char *nome;
    float valor;

    if (totalItens[somaBusca] >= 50) {
        printf("Limite de itens do comprovante atingido!\n");
        return;
    }

    printf("Qual tipo de tosa você deseja realizar?\n");
    printf("1 - Tosa higiênica = R$ 20,00\n");
    printf("2 - Tosa completa = R$ 30,00\n");
    printf("3 - Tosa na tesoura = R$ 20,00\n");
    printf("Digite a opção desejada: ");
    opcao = lerInteiro();

    if (opcao == 1) {
        nome = "Tosa higiênica";
        valor = 20;

    } else if (opcao == 2) {
        nome = "Tosa completa";
        valor = 30;

    } else if (opcao == 3) {
        nome = "Tosa na tesoura";
        valor = 20;

    } else {
        printf("Opção inválida!\n");
        return;
    }

    adicionarItem(itemNome, itemValor, totalItens, total,
                  somaBusca, nome, valor);
}

void funcVeterinaria(char itemNome[10][50][100],
                     float itemValor[10][50], int totalItens[10],
                     float total[10], int somaBusca) {

    int opcao;
    const char *nome;
    float valor;

    if (totalItens[somaBusca] >= 50) {
        printf("Limite de itens do comprovante atingido!\n");
        return;
    }

    printf("Qual procedimento veterinário você deseja realizar?\n");
    printf("1 - Consulta = R$ 30,00\n");
    printf("2 - Vacina = R$ 50,00\n");
    printf("3 - Exame = R$ 30,00\n");
    printf("Digite a opção desejada: ");
    opcao = lerInteiro();

    if (opcao == 1) {
        nome = "Consulta";
        valor = 30;

    } else if (opcao == 2) {
        nome = "Vacina";
        valor = 50;

    } else if (opcao == 3) {
        nome = "Exame";
        valor = 30;

    } else {
        printf("Opção inválida!\n");
        return;
    }

    adicionarItem(itemNome, itemValor, totalItens, total,
                  somaBusca, nome, valor);
}

int main() {

    if (login() == 0) {
        printf("Limite de tentativas atingido. Encerrando o sistema!\n");
        return 0;
    }

    system("clear");

    char cliente[5][50] = {0};
    char telefone[5][50] = {0};

    char pet[10][100] = {0};
    char especie[10][100] = {0};
    char raca[10][100] = {0};

    int codigoCliente[5] = {0};
    int portePet[10] = {0};
    int nrPet[5] = {0};

    int totalClientes = 0;
    int totalPet = 0;

    char itemNome[10][50][100] = {0};
    float itemValor[10][50] = {0};
    int totalItens[10] = {0};
    float total[10] = {0};

    char produtos[3][3][100] = {
        {"Golden Special - Frango", "Pedigree - Carne", "GranPlus - Frango e Arroz"},
        {"Coleira de nylon", "Pote duplo", "Bola de borracha"},
        {"Pet Society - Shampoo", "Sanol Dog - Condicionador", "Tapete higiênico"}
    };

    float precoProdutos[3][3] = {
        {89.90, 79.90, 99.90},
        {25.00, 35.00, 15.00},
        {32.00, 24.00, 45.00}
    };

    int estoque[3][3] = {
        {10, 10, 10},
        {10, 10, 10},
        {10, 10, 10}
    };

    int opcao;
    int x, z;
    int somaBusca;

    do {
        printf("\n=================================\n");
        printf("====== PETSHOP AMIGO FIEL =======\n");
        printf("=================================\n");

        printf("[1] Cadastros\n");
        printf("[2] Serviços\n");
        printf("[3] Produtos\n");
        printf("[4] Comprovante final\n");
        printf("[5] Sair\n");

        printf("Digite a opção desejada: ");
        opcao = lerInteiro();

        if (opcao >= 1 && opcao <= 5) {
            system("clear");
        }

        switch (opcao) {

        case 1: {
            int opcaoCadastro;

            do {
                printf("\n=========== CADASTROS ===========\n");
                printf("CADA CLIENTE CADASTRADO DEVE TER UM PET.\n");
                printf("[1] Cadastrar\n");
                printf("[2] Voltar ao menu\n");
                printf("Digite a opção desejada: ");

                opcaoCadastro = lerInteiro();

                if (opcaoCadastro == 1 || opcaoCadastro == 2) {
                    system("clear");
                }

                switch (opcaoCadastro) {

                case 1: {
                    printf("Digite a quantidade de clientes que deseja cadastrar: ");
                    x = lerInteiro();

                    if (x > 0 && totalClientes + x <= 5) {

                        for (int c = totalClientes; c < totalClientes + x; c++) {

                            codigoCliente[c] = c + 1;

                            printf("\nCódigo do cliente: %03d\n", codigoCliente[c]);

                            printf("Digite o nome: ");
                            fgets(cliente[c], 50, stdin);
                            cliente[c][strcspn(cliente[c], "\n")] = '\0';

                            printf("Digite o telefone: ");
                            fgets(telefone[c], 50, stdin);
                            telefone[c][strcspn(telefone[c], "\n")] = '\0';

                            do {
                                printf("Digite a quantidade de PETs do cliente (1 ou 2): ");
                                z = lerInteiro();

                                if (z < 1 || z > 2) {
                                    printf("Digite um valor válido!\n");
                                }

                            } while (z < 1 || z > 2);

                            nrPet[c] = z;

                            for (int i = 0; i < z; i++) {

                                printf("Digite o nome do %dº PET: ", i + 1);
                                fgets(pet[totalPet], 100, stdin);
                                pet[totalPet][strcspn(pet[totalPet], "\n")] = '\0';

                                printf("Digite a espécie do PET: ");
                                fgets(especie[totalPet], 100, stdin);
                                especie[totalPet][strcspn(especie[totalPet], "\n")] = '\0';

                                printf("Digite a raça do PET: ");
                                fgets(raca[totalPet], 100, stdin);
                                raca[totalPet][strcspn(raca[totalPet], "\n")] = '\0';

                                do {
                                    printf("Digite o porte do PET:\n");
                                    printf("[1 - Pequeno / 2 - Médio / 3 - Grande]: ");

                                    portePet[totalPet] = lerInteiro();

                                    if (portePet[totalPet] < 1 ||
                                        portePet[totalPet] > 3) {
                                        printf("Digite um valor válido!\n");
                                    }

                                } while (portePet[totalPet] < 1 ||
                                         portePet[totalPet] > 3);

                                totalPet++;
                            }
                        }

                        totalClientes += x;

                        printf("Cadastro realizado com sucesso!\n");

                    } else {
                        printf("Quantidade inválida ou limite de cadastros atingido!\n");
                    }

                    break;
                }

                case 2:
                    break;

                default:
                    printf("Digite uma opção válida!\n");
                }

            } while (opcaoCadastro != 2);

            break;
        }

        case 2: {
            int opcaoServico;

            do {
                printf("\n=========== SERVIÇOS ============\n");
                printf("[1] Banho\n");
                printf("[2] Tosa\n");
                printf("[3] Veterinária\n");
                printf("[4] Voltar\n");
                printf("Digite a opção desejada: ");

                opcaoServico = lerInteiro();

                if (opcaoServico >= 1 && opcaoServico <= 4) {
                    system("clear");
                }

                switch (opcaoServico) {

                case 1:
                case 2:
                case 3: {

                    if (totalClientes == 0) {
                        printf("Nenhum cliente cadastrado!\n");
                        break;
                    }

                    somaBusca = selecionarPet(codigoCliente, cliente, pet,
                                              nrPet, totalClientes);

                    if (somaBusca == -1) {
                        break;
                    }

                    if (opcaoServico == 1) {
                        funcBanho(portePet, itemNome, itemValor,
                                  totalItens, total, somaBusca);

                    } else if (opcaoServico == 2) {
                        funcTosa(itemNome, itemValor, totalItens,
                                 total, somaBusca);

                    } else {
                        funcVeterinaria(itemNome, itemValor, totalItens,
                                        total, somaBusca);
                    }

                    break;
                }

                case 4:
                    break;

                default:
                    printf("Digite uma opção válida!\n");
                }

            } while (opcaoServico != 4);

            break;
        }

        case 3: {
            int categoria, produto, quantidade;
            char nomeVenda[100];

            if (totalClientes == 0) {
                printf("Nenhum cliente cadastrado!\n");
                break;
            }

            printf("\n=========== PRODUTOS ===========\n");

            somaBusca = selecionarPet(codigoCliente, cliente, pet,
                                      nrPet, totalClientes);

            if (somaBusca == -1) {
                break;
            }

            system("clear");

            printf("\nEscolha a categoria:\n");
            printf("[1] Alimentos\n");
            printf("[2] Acessórios\n");
            printf("[3] Higiene\n");
            printf("Digite a opção desejada: ");

            categoria = lerInteiro();

            if (categoria < 1 || categoria > 3) {
                printf("Categoria inválida!\n");
                break;
            }

            system("clear");

            printf("\n======= LISTA DE PRODUTOS =======\n");

            for (int i = 0; i < 3; i++) {
                printf("\n[%d] %s\n", i + 1, produtos[categoria - 1][i]);
                printf("Preço: R$ %.2f\n", precoProdutos[categoria - 1][i]);
                printf("Estoque: %d unidades\n", estoque[categoria - 1][i]);
            }

            printf("\nDigite o número do produto desejado: ");
            produto = lerInteiro();

            if (produto < 1 || produto > 3) {
                printf("Produto inválido!\n");
                break;
            }

            if (estoque[categoria - 1][produto - 1] == 0) {
                printf("Produto sem estoque!\n");
                break;
            }

            printf("Digite a quantidade desejada: ");
            quantidade = lerInteiro();

            if (quantidade <= 0 ||
                quantidade > estoque[categoria - 1][produto - 1]) {
                printf("Quantidade indisponível no estoque!\n");
                break;
            }

            if (totalItens[somaBusca] >= 50) {
                printf("Limite de itens do comprovante atingido!\n");
                break;
            }

            system("clear");

            snprintf(nomeVenda, sizeof(nomeVenda), "%s (Quantidade: %d)",
                     produtos[categoria - 1][produto - 1], quantidade);

            adicionarItem(itemNome, itemValor, totalItens, total,
                          somaBusca, nomeVenda,
                          precoProdutos[categoria - 1][produto - 1] * quantidade);

            estoque[categoria - 1][produto - 1] -= quantidade;

            printf("\nVenda realizada com sucesso!\n");
            printf("Valor da compra: R$ %.2f\n",
                   precoProdutos[categoria - 1][produto - 1] * quantidade);

            printf("Estoque restante: %d unidades\n",
                   estoque[categoria - 1][produto - 1]);

            break;
        }

        case 4: {

            printf("\n======= COMPROVANTE FINAL =======\n");

            if (totalPet == 0) {
                printf("Nenhum PET cadastrado!\n");
                break;
            }

            int inicio = 0;

            for (int c = 0; c < totalClientes; c++) {

                for (int i = 0; i < nrPet[c]; i++) {

                    printf("\n=================================\n");
                    printf("Código do cliente: %03d\n", codigoCliente[c]);
                    printf("Dono: %s\n", cliente[c]);
                    printf("Telefone: %s\n", telefone[c]);
                    printf("PET: %s\n", pet[inicio + i]);

                    if (totalItens[inicio + i] == 0) {
                        printf("Nenhum item registrado.\n");
                    } else {

                        for (int j = 0; j < totalItens[inicio + i]; j++) {
                            printf("%s - R$ %.2f\n",
                                   itemNome[inicio + i][j],
                                   itemValor[inicio + i][j]);
                        }

                        printf("Total: R$ %.2f\n", total[inicio + i]);
                    }

                    printf("=================================\n");
                }

                inicio += nrPet[c];
            }

            break;
        }

        case 5:
            printf("Encerrando o sistema...\n");
            break;

        default:
            printf("Digite uma opção válida!\n");
        }

    } while (opcao != 5);

    return 0;
}
