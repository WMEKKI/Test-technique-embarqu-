
#include "gpio_manip.h"

uint32_t direction_gpio_bank1 = 0;
uint32_t value_gpio_bank1 = 0;


/* d�finition du sens de GPIO comme une sortie */
// la fonction retourne 1 si la d�finition est possible sinon 0 //


int set_gpio_output(int gpio_index) {

	if ((gpio_index >= 0) && (gpio_index <= 31))                    

	{
		direction_gpio_bank1 = direction_gpio_bank1 | (1 << gpio_index);
		return 1;
	}

	else
		return 0;
}


/* definition du sens de GPIO comme une entr�e */
// la fonction retourne 1 si la d�finition est possible sinon 0 //

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
//permet de v�rifier si l'indice correspend � un GPIO d�fini comme une sortie//  

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
// retourne 1 si l'affectation etait bien r�alis�e et 0 en cas de l'impossibilit�  // 

int write_gpio(int gpio_index, bool value) {


	if (test_direction_out(gpio_index))
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
