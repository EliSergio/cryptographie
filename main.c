#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include <string.h>


int main(int argc , char **argv)
{
	char message[100];
	char cpt[100];
	char decpt[100];


	printf("entrer votre message\n");
	lire(message , 100);
	crypter(message , 4 , cpt);

	printf("msg crypter : %s\n", cpt);

	decrypter(cpt , 4, decpt);

	printf("msg decripter : %s\n", decpt);

	return 0;
}