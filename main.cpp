#include <iostream>
#include "Livro.h"
#include "LivroPolicial.h"
#include "FiccaoCientifica.h"

#include "Biblioteca.h"

using namespace std;

int main() {
    cout << "-------- FT 7_03 --------" << endl;

    Livro * l1 = new Livro{"POO", "Luis Antunes", "123-984-24234"};
    Livro * l2 = new Livro{"JAVA", "Ana Andrade", "125-999-34276"};
    Livro * l3 = new Livro{"SO", "Maria Rita", "129-769-64275"};
    Livro * l4 = new LivroPolicial{"Policia 1", "Joana Silva", "156-764-64299", "Ahmit Robert", 10};
    Livro * l5 = new LivroPolicial{"O ladrão e o policial", "Joana Silva", "178-780-74282", "Rita Bolero", 7};
    Livro * l6 = new FiccaoCientifica{"A sombra em Marte", "Santaria Ruth", "110-230-83452", "Marte", 2022, true};
    Livro * l7 = new FiccaoCientifica{"Calor mas pouco", "Ruth Albanir", "119-237-23456", "Nepturno", 2021, false};

    Biblioteca * b1 = new Biblioteca{"R. Pedro Nunes"};
    Biblioteca * b2 = new Biblioteca{"Coimbra"};

    b1->adicionaLivro(l6);
    b2->adicionaLivro(l1);
    b2->adicionaLivro(l2);
    b2->adicionaLivro(l4);
    b2->adicionaLivro(l7);
    b2->adicionaLivro(l6);

    cout << endl << "---- Lista de livros biblioteca B1 -----" << endl;
    cout << *b1;

    cout << endl << "---- Lista de livros biblioteca B2 -----" << endl;
    cout << *b2;

    cout << endl << "---- Vou remover livros da biblioteca B2 -----" << endl;
    b2->removeLivro("119-237-23456");       // l7
    b2->removeLivro("156-764-64299");       // l4
    cout << endl << "---- Nova Listagem de livros biblioteca após remover livros B2 -----" << endl;
    cout << *b2;

    b1->adicionaLivro(l7);
    b1->adicionaLivro(l4);
    cout << endl << "---- Lista de livros biblioteca B1 -----" << endl;
    cout << *b1;

    cout << endl << "---- Copiar B1 para B3 | construtor por cópia -----" << endl; // implementar construtor por cópia ---> os livros só podem estar numa biblioteca
    Biblioteca b3 (*b2);
    l1->alteraTitulo("Novo título");
    cout << endl << "---- Lista B3 | após construtor por cópia -----" << endl;
    cout << b3;
    cout << endl << "---- Lista B2 | após construtor por cópia -----" << endl;
    cout << *b2;

    cout << endl << "---- Copiar B1 para B3 | operador de atribuição -----" << endl; // implementar operador de atribuição
    b3 = *b1;
    cout << *b2;
    cout << b3;
    // cout << endl << "---- Copiar B1 para B3 -----" << endl;


    cout << endl << "---- Copiar B2 para B4 | construtor por cópia -----" << endl; // implementar construtor por cópia ---> os livros só podem estar numa biblioteca
    Biblioteca * b4 = new Biblioteca("test");
    //Biblioteca * b4;
    *b4 = *b2;
    cout << *b4;

    delete b4;
    delete b2;
    delete b1;

    return 0;
}
