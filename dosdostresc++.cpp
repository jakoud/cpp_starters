#include <iostream>
#include <string>

using namespace std;

/*ludzie:wiek(lata), plec(m/k), wyksztalcenie(standard), zarobki(PLN), wzrost(m)
metody: bool zmiana_plci(); void rozwoj(string&); */

class ludzie{
private:
	int wiek;
	char plec;
	string wyksztalcenie;
	float zarobki;
	float wzrost;
public:
	bool zmiana_plci();
	void rozwoj(string&);
	void info();

	ludzie(int w=0, char p='k', string wy="-", float z=0, float wz=0):wiek(w), plec(p), wyksztalcenie(wy), zarobki(z), wzrost(wz){}
};


int main()
{
ludzie pierwszy;
pierwszy.info();
	return 0;
}

bool ludzie::zmiana_plci(){
if(zarobki>4000 && wiek>=18 && wiek<50){
	plec=(plec=='m')?('k'):('m');
	return true;

}
return false;
}

void ludzie::rozwoj(string &na_co_zmieniamy){
	wyksztalcenie=na_co_zmieniamy;
	zarobki*=1.1;
}

void ludzie::info(){
	std::cout<<"wiek to: "<<wiek<<endl;
	std::cout<<"plec to: "<<plec<<endl;
	std::cout<<"wyksztalcenie to: "<<wyksztalcenie<<endl;
	std::cout<<"zarobki to: "<<zarobki<<endl;
	std::cout<<"wzrost to: "<<wzrost<<endl;
}
