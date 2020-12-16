#include <stdio.h>
#include <ctype.h>
#include "proto.h"
#include <string.h>

void crypter(const char *message , short key , char *ciptext)
{
	unsigned int i = 0;
	short rang;

	while(message[i] != '\0'){
		if(message[i] >= ' ' && message[i] <= '~'){
			rang = (message[i] - ' ' + key) % 126;
			rang = (rang + key) % 126;

			if(rang < 0)
				rang += 126;

			ciptext[i] = ' ' + rang;
		}

		else
			ciptext[i] = message[i];

		i++;
	}

	ciptext[i] = '\0';
}

/*------------------------------------------------------------------------------------------*/

void decrypter(const char *message , short key , char *ciptext){
	crypter(message , -key , ciptext);
}

/*------------------------------------------------------------------------------------------*/

int lire(char *chaine, int longeur){
	char *position = NULL;

	if(fgets(chaine,longeur,stdin) != NULL){
		position = strchr(chaine, '\0');

		if(position != NULL){
			*position = '\0';
		}
		else{
			vider_buffer();
		}
		return 1;
	}
	else{
		vider_buffer();
		return 0;
	}
}

/*------------------------------------------------------------------------------------------*/

void vider_buffer(){

	int c = 0;

	while (c != '\n' && c != EOF){
		c = getchar();
	}
}