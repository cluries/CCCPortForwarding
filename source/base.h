#ifndef __BASE_H__
#define __BASE_H__

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <netdb.h>

#include <net/if.h>
#include <net/if_arp.h>
#include <netinet/in.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/dir.h>
#include <sys/stat.h>

#ifdef __LINUX__
	#include <sys/epoll.h>
	#include <sys/io.h>
#endif

namespace base
{ 

	enum TimeUnitTables { 
		kTimeSEC	= 1000000000 ,
		kTimeMS		= 1000000 ,
		kTimeUS		= 1000 ,
		kTimeNS		= 1
	};

	inline void sleep(unsigned int uins)
	{
		timespec ticks , exticks;
		ticks.tv_sec  = uins / kTimeSEC;
		ticks.tv_nsec = uins % kTimeSEC;
		nanosleep(&ticks,&exticks);
	}

	inline void ipv4addrtostr(unsigned int uiv4addr,unsigned short usport,char *straddr) 
	{
		if(NULL == straddr) {	return ;	}
		in_addr saddr; 
		saddr.s_addr = uiv4addr;
		sprintf(straddr,"%s:%d",inet_ntoa(saddr),ntohs(usport));	
	}
}

#endif
