#include <iostream>
#include <string>
using namespace std;

class ContaCorrente{
	private:
		string titular_;
		float saldo_;
		float limite_;
		bool validar(float valor){
			return valor <= (saldo_+limite_);
		}
		
		
		
	public:
		ContaCorrente(string titular, float saldo, float limite);
		ContaCorrente(string titular, float saldo);
		ContaCorrente();
		void exibirInfo();
		bool saque(float valor);
		bool transferencia(float valor, ContaCorrente&destino);
		void depositar(float valor);
};
	
	int main(){
		setlocale(LC_ALL,"portuguese");
		
		ContaCorrente minhaConta1 ("Rafael", 300, 1000);
		
		ContaCorrente minhaConta2 ("Gabriel", 100);
		
	
		
		minhaConta1.exibirInfo();
		minhaConta1.transferencia(1200,minhaConta2);
		minhaConta1.exibirInfo();
		
		minhaConta2.exibirInfo();
		
		return 0;
	}
	

		ContaCorrente::ContaCorrente(string titular, float saldo, float limite):
								titular_(titular),saldo_(saldo), limite_(limite){}
			
		ContaCorrente::ContaCorrente(string titular, float saldo):
					titular_(titular), saldo_(saldo), limite_(1000){}
					
		ContaCorrente::ContaCorrente():
					titular_("Não informado"),saldo_(0),limite_(0){}
					
		
		bool ContaCorrente::saque(float valor){
			if (validar (valor)== true){
				saldo_ = valor - saldo_;
				cout << "Saque no valor:" << valor << " feito com sucesso!" << endl;
				return true;
			}
			else{
				cout <<"Saque negado! "<< endl;
				return false;
			}
		}
		
		bool ContaCorrente::transferencia(float valor, ContaCorrente&destino){
			if (saque(valor)){
				destino.depositar(valor);
				return true;
			}
			else{
				cout << "Transferencia negada, saldo insuficiente!" << endl;
				return false;
			}
			
			
			
		}
			
		void ContaCorrente::depositar(float valor){
			saldo_+=valor;
			cout << "Deposito no valor: " << valor << " com sucesso!"<< endl;
		
		}
			
		void ContaCorrente::exibirInfo(){
			cout << "Titular é:" << titular_ << endl;
			cout << "Saldo de:" << saldo_ << endl;
			cout << "Limite de: " << limite_ << endl;
			cout << "Disponivel para saque: " << saldo_ + limite_ << endl;
		}
	

