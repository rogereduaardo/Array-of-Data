#include <stdio.h>
#include <stdlib.h>

#include "single-data-item-demo.h"
#include "authentication.h"

void single_data_item_demo()
{
  puts("== Single Data Item Demo ===");

  int passcode = 123;
  printf("passcode: %d\n", passcode);

  char passphrase[] = "abc";
  printf("passphrase: %s\n", passphrase);

  authentication_t auth_with_passcode ={
  .use_passcode = true,
  .passcode = 123,
  .use_passphrase = false,
  .passphrase = ""
  };
  authentication_printf(&auth_with_passcode);

  authentication_t *ptr_auth_with_passphrase =
    authentication_new(false,0,true,"abc");

  if (NULL == ptr_auth_with_passphrase)
  {
    fprintf(stderr, "authentication_new() failed");
    return;
  }
  authentication_printf(ptr_auth_with_passphrase);

}