
#include <stdint.h>
#include <stdbool.h>
#include "gpio_manip.h"

uint32_t direction_gpio_bank1 = 0;
uint32_t value_gpio_bank1 = 0;


/* définition du sens de GPIO comme une sortie */
// la fonction retourne 1 si la définition est possible sinon 0 //


int set_gpio_output(int gpio_index) {

	if ((gpio_index >= 0) && (gpio_index <= 31))                    

	{
		direction_gpio_bank1 = direction_gpio_bank1 | (1 << gpio_index);
		return 1;
	}

	else
		return 0;
}


/* definition du sens de GPIO comme une entrée */
// la fonction retourne 1 si la définition est possible sinon 0 //

}

int set_gpio_input(int gpio_index) {

	if ((gpio_index >= 0) && (gpio_index <= 31))

	{
		direction_gpio_bank1 = direction_gpio_bank1 & ~(1 << gpio_index);
		return 1;
	}

	else
		return 0;

}

/* fonction de test de sens de GPIO  */
//permet de vérifier si l'indice correspend à un GPIO défini comme une sortie//  

bool test_direction_out(int gpio_index) {

	if ((gpio_index >= 0) && (gpio_index <= 31))

	{
		if (direction_gpio_bank1 & (1 << gpio_index))
			return 1;
		else
			return 0;
	}

	else
		return 0;  
}

/*   fonction d'affectation des sorties  */
// retourne 1 si l'affectation etait bien réalisée et 0 en cas de l'impossibilité  // 

int write_gpio(int gpio_index, bool value) {


	if (test_direction_out(int gpio_index))
	{
		if (value == 0)
		{
			value_gpio_bank1 = value_gpio_bank1 & ~(1 << gpio_index);
			return 1;
		}
		else
		{
			value_gpio_bank1 = value_gpio_bank1 | (1 << gpio_index);
			return 1;
		}
	}

	else
		return 0;



}
