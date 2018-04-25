#include <iostream>
#include <string.h>
#include <IOlib.h>

using namespace std;

int main()
{
    	IO sock;
		  // client bo'lib ulanish
      string ip_addr;
      cout<<"IP: ";
      cin>>ip_addr;
      int port;
      cout<<"port: ";
      cin>>port;
	    sock.connect(ip_addr, port); // ip:port ga client bo'lib ulanish 
  		string se; // shunchaki tajriba uchun
	  	while(1){
			    getline(cin, se);
			    sock.send(se); // kiritilgan so'zni TCP bog'lanish orqali jo'natib yuborish
		    }
    }
}
