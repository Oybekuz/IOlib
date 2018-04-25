#include <iostream>
#include <string.h>
#include <IOlib.h>

using namespace std;

bool server = true;

int main()
{
	   	 //server ishga tushirish
		   //obekt hosil qilish
       IO sock, io_new;
       sock.bind(8080); // portni tanlash (bir vaqtda bitta portdan 2 ta server foydalana olmaydi)
       sock.listen(1); // bittada nechta clientlar qabul qilinishi
		   io_new = sock.accept(); // client ulanishini kutish va ulangan klient bilan yangi bog'lanish hosil qilish
		   while(io_new.connected) // chekksiz loop
		   {
			    cout<<io_new.recv(1024)<<endl; // clientdan kelgan habarlarni ekranga yozib turish
          
		   }
 }
