
#include "gpio_manip.h"

void reset_gpios(void){
  direction_gpio_bank1 = 0;
  value_gpio_bank1 = 0;
}

int main(int argc, char argv[]){
  //Exemple de fonctionnement classique
  reset_gpios(void);
  printf("result %d\n", set_gpio_output(0));
  printf("readback %04x\n", direction_gpio_bank1);

  //Exemple de fonctionnement limite
  reset_gpios(void);
  printf("result %d\n", set_gpio_output(-1));
  printf("readback %04x\n", direction_gpio_bank1);
}
