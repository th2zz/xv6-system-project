//this is a test file for getopenedcount
#include "types.h"
#include "user.h"
int main(int argc, char* argv[]) {
	uint opened_count = getopenedcount();
	printf(1, "initial value: %d\n", opened_count);
	for (int i = 0; i < 100; i++) {
		open("./testfile",0);
		open("no", 0);
	}
	opened_count = getopenedcount();
	printf(1, "after open 200 times, the count is: %d\n", opened_count);
	exit();
}
