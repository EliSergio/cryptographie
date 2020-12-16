#ifndef ___PROTO_H___
#define ___PROTO_H___

void crypter(const char *message , short key , char *ciptext);
void decrypter(const char *message , short key , char *ciptext);
int lire(char *chaine, int longeur);
void vider_buffer();

#endif