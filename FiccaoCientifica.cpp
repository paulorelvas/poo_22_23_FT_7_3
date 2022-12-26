#include "FiccaoCientifica.h"

FiccaoCientifica::FiccaoCientifica(string titulo, string autor, string ISBN, string planeta, int ano, bool isRealista)
        :Livro(titulo,autor,ISBN), planeta(planeta), ano(ano), isRealist(isRealista){
}
FiccaoCientifica::FiccaoCientifica(const FiccaoCientifica & obj):Livro(obj), planeta(obj.planeta), ano(obj.ano), isRealist(obj.isRealist){
    cout << endl << "--- construtor por cópia FiccaoCientifica ---" << endl;
}

FiccaoCientifica::~FiccaoCientifica(){
    cout << "---- Destruir livro Ficção Científica ----" << endl;
}
string FiccaoCientifica::getAsString() const{
    ostringstream os;
    Livro::getAsString();
    os << " | Planeta: " << planeta <<
          " | Ano: " << ano <<
          " | Realista: " << isRealist << endl;

    return os.str();
}

void FiccaoCientifica::imprime( ostream & os ) const{
    Livro::imprime(os);
    os << " | Planeta: " << planeta <<
          " | Ano: " << ano <<
          " | Realista: " << isRealist << endl;
}
ostream &operator<<(ostream &os, const FiccaoCientifica &obj) {
    obj.imprime(os);
    return os;
}

FiccaoCientifica &FiccaoCientifica::operator=(const FiccaoCientifica & obj){
    Livro::operator=(obj);
    planeta = obj.planeta;
    ano = obj.ano;
    isRealist = obj.isRealist;

    return *this;
}

