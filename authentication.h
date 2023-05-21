//authentication.h

#include <stdbool.h>

#ifndef _AUTHENTICATION_H_
#define _AUTHENTICATION_H_

typedef struct
{
  bool use_passcode;
  int passcode;

  bool use_passphrase;
  char passphrase[32];

} authentication_t;

void authentication_printf(authentication_t *auth);

authentication_t *authentication_new(
  bool use_passcode, int passcode,
  bool use_passphrase, char passphrase[]);

#endif
