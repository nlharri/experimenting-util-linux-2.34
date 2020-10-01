
#include <stdio.h>
#include <unistd.h>

#include "md5.h"

int main(void)
{
	int i, ret;
	struct UL_MD5Context ctx;
	unsigned char digest[UL_MD5LENGTH];
	unsigned char buf[BUFSIZ];

	ul_MD5Init( &ctx );

	while(!feof(stdin) && !ferror(stdin)) {
		ret = fread(buf, 1, sizeof(buf), stdin);
		if (ret)
			ul_MD5Update( &ctx, buf, ret );
	}

	fclose(stdin);
	ul_MD5Final( digest, &ctx );

	for (i = 0; i < UL_MD5LENGTH; i++)
		printf( "%02x", digest[i] );
	printf("\n");
	return 0;
}
