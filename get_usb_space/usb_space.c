#include <sys/vfs.h>
#include <stdio.h>

unsigned int GetToalSpaceKB(const char *pathname)
{
	unsigned int iTotalSpace = 0;
	struct statfs diskInfo;
	if(0 == statfs(pathname, &diskInfo))
	{
		iTotalSpace = (diskInfo.f_bsize * diskInfo.f_blocks) >> 10;
		return iTotalSpace;
	}
	return 0;
}

unsigned int GetFreeSpaceKB(const char *pathname)
{
	unsigned int iFreeSpace = 0;
	struct statfs diskInfo;
	if(0 == statfs(pathname, &diskInfo))
	{
		iFreeSpace = (diskInfo.f_bsize * diskInfo.f_bavail) >> 10;
		return iFreeSpace;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	printf("pathname = %s\n",argv[1]);
	printf("Total Space (KB): %d\n",GetToalSpaceKB(argv[1]));
	printf("Free Space (KB): %d\n",GetFreeSpaceKB(argv[1]));
	return 0;
}
