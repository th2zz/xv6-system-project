#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
        void* addr = (void*)shmget(1);
	printf(1,"shmget(1)| addr is: %x\n",addr);
	void* addr2 = (void*)shmget(-1);
	printf(1, "shmget(0)| addr is: %x\n",addr2);
	void* addr3 = (void*)shmget(3);
        printf(1, "shmget(3)| addr is: %x\n",addr3);
	char* ptr = addr3;
	printf(1, "derefencing addr3: %x\n", *ptr);
	exit();
}

