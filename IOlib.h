#include <iostream>
#include <string.h>
#include <winsock2.h>

using namespace std;

#pragma comment(lib,"ws2_32.lib")

class IO
{
	public:
		string error_message;
		bool error, connected, bound;
		WSADATA wsaData;
	    SOCKET Socket;
	    SOCKADDR_IN SockAddr, server;
	    struct hostent *host;
	    int c;
		IO()
		{
			error = 0;
    		connected = 0;
    		bound = 0;
    		error_message = "No errors";
    	    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
    	    	error = 1;
        		error_message = "WSAStartup failed.";
        		return;
    		}
    		
			Socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
			
    		
		}
		
		IO(SOCKET _n)
		{
			error = 0;
    		connected = 1;
    		bound = 0;
    		error_message = "No errors";
			Socket=_n;
			
		}
		
		bool connect(string ip, unsigned short port)
		{
			host = gethostbyname(ip.c_str());
            SockAddr.sin_port=htons(port);
    		SockAddr.sin_family=AF_INET;
    		SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
	    	
			if(::connect(Socket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr)) != 0){
				error = 1;
		        error_message = "Could not connect";
		        return 0;
		    }
		    connected = 1;
		    return 1;
		}
		
		bool bind(unsigned short port)
		{
			server.sin_family = AF_INET;
	    	server.sin_addr.s_addr = INADDR_ANY;
		    server.sin_port = htons( port );
		      
		    //Bind
		    if( ::bind(Socket ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
		    {
		        error_message = "Bind failed with error code : " + WSAGetLastError();
		        error = 1;
		        return 0;
		    }
		    bound = 1;
		    return 1;
		}
		
		void listen(int num)
		{
			::listen(Socket, num);
		}
		
		IO accept()
		{
			c = sizeof(struct sockaddr_in);
    		SOCKET new_socket = ::accept(Socket , (struct sockaddr *)&SockAddr, &c);
    		return IO(new_socket);
		}
		
		int send(string data)
		{
			return ::send(Socket, data.c_str(), strlen(data.c_str()),0);
		}
		
		string recv(int len)
		{
			string res = "";
			char buff[len];
			int l = ::recv(Socket, buff,len,0);
			if(l==0)
			    connected = 0;
			for(int i=0; i<len; i++)
			{
				res+=buff[i];
			}
			return res;
		}
};
