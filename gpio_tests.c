
#include "gpio_manip.h"

void reset_gpios(void){                                                               // fonction d'initialisation 
  direction_gpio_bank1 = 0;
  value_gpio_bank1 = 0;
}

void all_value_gpio_bank1_H(void) {                                                   // fonction d'initialisation
	value_gpio_bank1 = 0xFFFFFFFF;
}

void all_gpios_output(void) {                                                         // fonction d'initialisation
	direction_gpio_bank1 = 0xFFFFFFFF;
}

void reset_value_gpio_bank1(void) {                                                   // fonction d'initialisation
	direction_gpio_bank1 = 0;                                            
}

void test_def_GPIO_as_Output(int a, int b) {                                          // avec  ( a >= 0  et a <= 31 )  et  ( 0 < a ou > 31 ) 
	printf(" test : definition of direction GPIO as output \n");
	printf("\n");

	//Exemple de fonctionnement classique
	printf(" classic example  \n");
	reset_gpios(void);                                                                // direction_gpio_bank1 = value_gpio_bank1 = 0
	printf("result definition of direction output ==> %d\n", set_gpio_output(a));     // doit renvoyer 1
	printf("readback direction_gpio_bank1 = %04x\n", direction_gpio_bank1);           // tous les bits à 0 sauf le a eme bit à 1 
	printf("\n");

	//Exemple de fonctionnement limite
	printf(" Example of operating limit \n");
	reset_gpios(void);                                                                // direction_gpio_bank1 = value_gpio_bank1 = 0 
	printf("result definition of direction output ==> %d\n", set_gpio_output(b));     // doit renvoyer 0
	printf("readback  direction_gpio_bank1 = %04x\n", direction_gpio_bank1);          // doit renvoyer 0x00

}

void test_def_GPIO_as_Input(int a, int b) {                                           // avec  ( a >= 0  et a <= 31 )  et  ( 0 < a ou > 31 )
	printf(" Test : definition of direction GPIO as input \n");
	printf("\n");

	//Exemple de fonctionnement classique
	printf(" classic example  \n");
	all_gpios_output(void);															  // direction_gpio_bank1 = 0xFFFFFFFF
	printf("result definition of direction input ==> %d\n", set_gpio_input(a));       // doit renvoyer 1
	printf("readback direction_gpio_bank1  = %04x\n", direction_gpio_bank1);          // tous les bits à 1 sauf le a eme bit à 0
	printf("\n");

	//Exemple de fonctionnement limite
	printf(" Example of operating limit \n");
	all_gpios_output(void);                                                           // direction_gpio_bank1 = 0xFFFFFFFF
	printf("result definition of direction input ==> %d\n", set_gpio_input(b));       // doit renvoyer 0
	printf("readback direction_gpio_bank1  = %04x\n", direction_gpio_bank1);          // doit renvoyer 0xFFFFFFFF
}

void test_assignment_Output_H(int a, int b){                                          // avec  ( a >= 0  et a <= 31 )  et  ( 0 < a ou > 31 )
	printf(" Test : assignment of output to high \n");
	printf("\n");

	//Exemple de fonctionnement classique
	printf(" classic example  \n");
	reset_gpios(void);																  // direction_gpio_bank1 = value_gpio_bank1 = 0 
	printf("result definition of direction output ==> %d\n", set_gpio_output(a));     // doit renvoyer 1
	printf("readback direction_gpio_bank1 = %04x\n", direction_gpio_bank1);           // tous les bits à 0 sauf le a eme bit à 1
	printf("result assignment of output ==> %d\n", write_gpio(a, 1));                 // doit renvoyer 1
	printf("readback value_gpio_bank1 =  %04x\n", value_gpio_bank1);                  // tous les bits à 0 sauf le a eme bit à 1
	printf("\n");

	 //Exemple de fonctionnement limite
	printf(" Example of operating limit \n");
	reset_gpios(void);													         	 // direction_gpio_bank1 = value_gpio_bank1 = 0
	printf("result definition of direction output ==> %d\n", set_gpio_output(b));    // doit renvoyer 0
	printf("readback direction_gpio_bank1 = %04x\n", direction_gpio_bank1);          // doit renvoyer 0x00
	printf("result assignment of output ==> %d\n", write_gpio(b, 1));                // doit renvoyer 0
	printf("readback value_gpio_bank1 =  %04x\n", value_gpio_bank1);                 // doit renvoyer 0x00
}
 

void test_assignment_Output_L(int a) {                                               // avec  ( a >= 0  et a <= 31 )  
	printf(" Test : assignment of output to low \n");
	printf("\n");

	//Exemple de fonctionnement classique
	printf(" classic example  \n");
	reset_gpios(void);                                                               // direction_gpio_bank1 = value_gpio_bank1 = 0
	all_value_gpio_bank1_H(void);                                                    // value_gpio_bank1 = 0xFFFFFFFF
	printf("result definition of direction output ==> %d\n", set_gpio_output(a));    // doit renvoyer 1
	printf("readback direction_gpio_bank1 = %04x\n", direction_gpio_bank1);          // tous les bits à 0 sauf le a eme bit à 1
	printf("result assignment of output ==> %d\n", write_gpio(a, 0));                // doit renvoyer 1
	printf("readback value_gpio_bank1 =  %04x\n", value_gpio_bank1);                 // tous les bits à 1 sauf le a eme bit à 0
	printf("\n");
}

void test_assignment_Input_H(int a) {											    // avec  ( a >= 0  et a <= 31 ) 
	printf(" Test of the impossibility of assigning a value to an input \n");
	printf(" \n ");
	all_gpios_output(void);														    // direction_gpio_bank1 = 0xFFFFFFFF
	reset_value_gpio_bank1(void);												    // value_gpio_bank1 = 0
	printf("result definition of direction input ==> %d\n", set_gpio_input(a));     // doit renvoyer 1
	printf("readback direction_gpio_bank1 %04x\n", direction_gpio_bank1);           // tous les bits à 1 sauf le a eme bit à 0 
	printf("result assignment of output ==> %d\n", write_gpio(a, 1));               // doit renvoyer 0
	printf("readback %04x\n", value_gpio_bank1);                                    // doit renvoyer 0x00
}


int main(int argc, char argv[]){

	int index0 = 0;
	int index1 = 1;
	int index2 = 2;
	int index50 = 50;	
	int index_1 = -1; 

  printf(" \n                       beginning of the tests \n ");
  printf(" \n _____________________________________________________________________________________________\n");

  /*Test définition de la direcction GPIO comme sortie*/
  test_def_GPIO_as_Output(index0, index50);
  printf(" \n _____________________________________________________________________________________________\n");

  /*Test définition de la direction GPIO comme entrée*/
  test_def_GPIO_as_Input(index0, index50);
  printf(" \n _____________________________________________________________________________________________\n");

  /* Test d'affectation d'une sortie à 1 */
  test_assignment_Output_H(index2, index50);
  printf(" \n _____________________________________________________________________________________________\n");

  /* Test d'affectation d'une sortie à 0 */
  test_assignment_Output_L(index1);
  printf(" \n _____________________________________________________________________________________________\n");

  /* Test de l'impossibilté d'affectation d'une valeur = 1 à une entrée */
  test_assignment_Input_H(index1);
  printf(" \n _____________________________________________________________________________________________\n");
  printf(" \n                               End of tests \n ");

}
