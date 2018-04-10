#include "Food.cpp"
#include <iostream>
using namespace std;

int main(){
	Food a;
	a.setX(100);
	a.setY(200);
	a.setIsReachBottom(false);
	a.setStateGambar(0);
	//a.printCoin();   -> hanya dapat di implementasikan ke dalam main.cpp
	
	Food b;
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
	
	Food c;
	c.setX(a.getX() + b.getX()); // c.X = a.X + b.X
	c.setY(b.getY() - a.getX()); // c.Y = b.Y - a.Y
	c.setIsReachBottom(a.getIsReachBottom());  //-> Value c = Value a = GOLD = 55
	c.setStateGambar(0);  // -> cuma pengaturan state gambar untuk animasi
	
	cout<<endl;
	cout<<"Posisi Food a : ( "<<a.getX()<<","<<a.getY()<<endl;
	cout<<"Posisi Food b : ( "<<c.getX()<<","<<b.getY()<<endl;
	cout<<"Posisi Food c : ( "<<c.getX()<<","<<c.getY()<<endl;
	
	
	
	return 0;
}
