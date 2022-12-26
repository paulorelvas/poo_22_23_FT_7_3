#include "Livro.h"
#include "Biblioteca.h"

Livro::Livro(string titulo, string autor, string ISBN):titulo(titulo), autor(autor), ISBN(ISBN){}
Livro::~Livro(){
    //todo:
    delete biblioteca;
}
void Livro::alteraTitulo(string titulo){
    this->titulo = titulo;
}

string Livro::obtemTitulo() const{
    return titulo;
}
string Livro::obtemAutor() const{
    return autor;
}
string Livro::obtemISBN() const{
    return ISBN;
}

bool Livro::estaBiblioteca(Biblioteca *obj){                  // função que permite associar livro à biblioteca
    if (biblioteca != nullptr || obj == nullptr)              // caso o biblioteca seja != nullptr ou obj = nullptr - sai
        return false;

    biblioteca = obj;
    cout << "----------------- :: associado à biblioteca :: ---------------------" << this->titulo << endl;
    return true;
}

bool Livro::deixaBiblioteca(Biblioteca *obj){                  // função que permite associar livro à biblioteca
    if (biblioteca != obj)              // caso o biblioteca seja != nullptr ou obj = nullptr - sai
        return false;

    biblioteca = nullptr;
    cout << "----------------- :: desassociado da biblioteca :: ---------------------" << this->titulo << endl;
    return true;
}

string Livro::getAsString() const{
    ostringstream os;
    os << "Título: " << titulo <<
    " | Autor: " << autor <<
    " | ISBN: " << ISBN << endl;
    return os.str();
}

void Livro::imprime(ostream & os) const{
    os << "Título: " << titulo << " | Autor: " << autor << " | ISBN: " << ISBN << endl;
}
ostream &operator<<(ostream &os, const Livro &p){
    p.imprime(os);
    return os;
}

bool operator== (const Livro& l1, const Livro& l2){
    return l1.ISBN == l2.ISBN;
}

Livro::Livro(const Livro & obj): titulo(obj.titulo), autor(obj.autor), ISBN(obj.ISBN){
    // cout << endl << "--- construtor por cópia Livro ---" << endl;
    biblioteca= nullptr;
}

Livro &Livro::operator=(const Livro & obj){
    // cout << endl << "--- Operador atribuição Livro ---" << endl;
    titulo = obj.titulo;
    autor = obj.autor;
    ISBN = obj.ISBN;

    biblioteca= nullptr;

    return *this;
}