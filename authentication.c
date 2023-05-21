
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "authentication.h"

void authentication_printf(authentication_t *auth)
{
  printf("==> auth: %p\n", auth);
  printf("use_passcode: %d\n", auth->use_passcode);
  printf("passcode: %d\n", auth->passcode);
  printf("use_passphrasee: %d\n", auth->use_passphrase);
  printf("passphrase: %s\n", auth->passphrase);
}

authentication_t *authentication_new(
bool use_passcode, int passcode,
bool use_passphrase, char passphrase[])
{
  authentication_t *p = calloc(1, sizeof(authentication_t));
  if (NULL == p) return p;

  p->use_passcode = use_passcode;
  p->passcode = passcode;
  p->use_passphrase = use_passphrase;
  strncpy(p->passphrase, passphrase, strlen(passphrase));

  return p;
}