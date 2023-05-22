#include <stdio.h>
#include <stdlib.h>

#include "array-data-demo.h"
#include "authentication.h"

void array_data_demo()
{
  puts("== Array Data ===");
  int passcode[] = {123, 456, 789};
  for (int i = 0; i < sizeof(passcode)/sizeof(passcode[0]); i++)
  {
     printf("%d\n", passcode[i]);
  }

  char *passphrase[] = { "red", "green", "blue"};
  for (int i = 0; i < sizeof(passphrase)/sizeof(passphrase[0]); i++)
    {
      printf("%s\n", passphrase[i]);
    }

  authentication_t auth_with_passcode[] = {
    { .use_passcode = true, .passcode = 123, .use_passphrase = false, .passphrase = ""},
    { .use_passcode = false, .passcode = 0, .use_passphrase = true, .passphrase = ""},
  };
  for (int i = 0; i < sizeof(auth_with_passcode)/sizeof(auth_with_passcode[0]); i++)
    {
      authentication_printf(&auth_with_passcode[0]);
    }

  authentication_t *ptr_auth_with_passphrase[] = {
    authentication_new(true,123,false,""),
    authentication_new(false,0,true,"abc")
  };
  for (int i = 0; i < sizeof(auth_with_passcode)/sizeof(auth_with_passcode[0]); i++)
    {
      authentication_printf(ptr_auth_with_passphrase[i]);
    }
  
}