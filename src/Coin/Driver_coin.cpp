#include "Coin.cpp"
#include <iostream>
using namespace std;

int main(){
	Coin a;
	a.setX(100);
	a.setY(200);
	a.setValue(SILVER);
	a.setStateGambar(0);
	//a.printCoin();   -> hanya dapat di implementasikan ke dalam main.cpp
	
	Coin b;
	b.operator =(a);
	if(b.operator !=(a)){
		cout<<"Coin b tidak sama dengan b"<<endl;
	}
	else{
		cout<<"Coin b sama dengan a"<<endl;
	}
	b.Move(1000);  // -> Mengecek apakah movenya berhasil memindahkan coin b selama 1000 milisecond
	if(b.operator !=(a)){
		cout<<"Coin b tidak sama dengan b"<<endl;
	}
	else{
		cout<<"Coin b sama dengan a"<<endl;
	}
	a.setValue(GOLD);
	
	Coin c;
	c.setX(a.getX() + b.getX()); // c.X = a.X + b.X
	c.setY(b.getY() - a.getX()); // c.Y = b.Y - a.Y
	c.setValue(a.getValue());  //-> Value c = Value a = GOLD = 55
	c.setStateGambar(0);  // -> cuma pengaturan state gambar untuk animasi
	
	cout<<endl;
	cout<<"Posisi Koin a : ( "<<a.getX()<<","<<a.getY()<<endl;
	cout<<"Posisi Koin b : ( "<<c.getX()<<","<<b.getY()<<endl;
	cout<<"Posisi Koin c : ( "<<c.getX()<<","<<c.getY()<<endl;
	
	
	
	return 0;
}
