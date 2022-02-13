#  Rendu de test technique embarqué LISA

le rendu contient deux fichiers essentiels "gpio_manip.c et gpio_tests.c"

## fichier gpio_manip.c

Ce fichier consiste à définir principalement 3 fonctions "set_gpio_output(int gpio_index), set_gpio_input(int gpio_index) et write_gpio(int gpio_index, bool value)" permettant de définir le sens d'un GPIO et d'affecter une valeur à un GPIO. 

### set_gpio_output(int gpio_index)

Cette fonction consiste à définir un GPIO d'indice 'gpio_index' comme une sortie; en forçant la valeur de la variable (ou du registre) "direction_gpio_bank1" d'indice 'gpio_index' à 1.
Avant de réaliser cette définition, il faut vérifier que l'indice appartient à [0..31].  Si c'est le cas, la fonction retourne l'entier 1 pour indiquer que l'opération était bien effectuée. Dans le cas contraire, elle retourne l'entier 0 pour définition impossible.  

### set_gpio_input(int gpio_index)
Cette fonction consiste à définir un GPIO d'indice "gpio_index" comme une entrée; on procède exactement de la même façon qu'avec la fonction "set_gpio_output" sauf que le forçage doit être à 0. 

### write_gpio(int gpio_index, bool value)

Cette fonction sert à l'affectation d'une valeur booléenne à un GPIO d'indice "gpio_index".
Puisque l'affectation d'une valeur ne peut être réaliser que pour GPIO définie comme Output, la présente fonction fait appel à la fonction "test_direction_out(int gpio_index") qui permet de vérifier cette condition. Si la condition est bien validée l'affectation sera réalisée et la fonction retourne l'entier 1 pour indiquer que l'opération était bien effectuée. Sinon elle retourne l'entier 0 pour affectation impossible.    

## fichier gpio_tests.c

Ce fichier comporte un main exécutant un ensemble de tests permettant de vérifier le bon fonctionnement des fonctions de manipulation des GPIO développées dans le fichier "gpio_manip.c".
Notre main, effectue les tests en appelant les fonctions suivantes: 

### test_def_GPIO_as_Output(int a, int b) 

Cette fonction permet de tester le bon fonctionnement de "set_gpio_output(int gpio_index)", ceci pour un exemple de fonctionnement classique (où gpio_index appartient [0..31] ; valeur de "a") ainsi qu'en fonctionnement limite (où gpio_index en dehors de cet intervalle ; valeur de "b"). 
Cette fonction nous permet d'un affichage du retour de la fonction "set_gpio_output(int gpio_index)" et du contenu de la variable "direction_gpio_bank1" après chaque test, ce qui nous permet débugger les erreurs s'ils se présenetent.
Pour mener à bien ce test, il faut tout d'abord initialiser la variable "direction_gpio_bank1" à zéro (ce qui est réalisé par la fonction "reset_gpios(void)"). Ceci nous aide dans la gestion des erreurs puisque "set_gpio_output(int gpio_index)" va associer un niveau haut à un des bits (le bit d'indice "gpio_index")  de la variable "direction_gpio_bank1" si la définition d'un GPIO en tant que output était bien réalisée.

### test_def_GPIO_as_Input(int a, int b)

Cette fonction permet de tester le bon fonctionnement de "set_gpio_input(int gpio_index)", ceci pour un exemple de fonctionnement classique (où gpio_index appartient [0..31] ; valeur de "a") ainsi qu'en fonctionnement limite (où gpio_index en dehors de cet intervalle ; valeur de "b"). 
Cette fonction nous permet d'un affichage du retour de la fonction "set_gpio_input(int gpio_index)" et du contenu de la variable "direction_gpio_bank1" après chaque test, ce qui nous permet débugger les erreurs s'ils se présenetent.
Pour mener à bien ce test, il faut tout d'abord initialiser la variable "direction_gpio_bank1" à  0xFFFFFFFF (ce qui est réalisé par la fonction "all_gpios_output(void) "). Ceci nous aide dans la gestion des erreurs puisque "set_gpio_input(int gpio_index)" va associer un niveau bas à un des bits (bit d'indice "gpio_index") de la variable "direction_gpio_bank1" si la définition d'un GPIO en tant que input était bien réalisée.

### test_assignment_Output_H(int a, int b)

Cette fonction permet de tester le bon fonctionnement de "write_gpio(int gpio_index, bool value)", en effet, elle nous permet de vérifier l'affectation d'un niveau haut à un GPIO après avoir le définir en tant que output. 
Ce test sera réalisé pour un exemple de fonctionnement classique (où gpio_index appartient [0..31] ; valeur de "a") ainsi qu'en fonctionnement limite (où gpio_index en dehors de cet intervalle ; valeur de "b"). Comme elle nous permet d'un affichage des retours des fonctions de la définition et d'affectation du GPIO ainsi que des variables "value_gpio_bank1" et "direction_gpio_bank1". Ces variable doivent être initialisées à zéro, puisque la définition et l'affectation de GPIO dans ce cas vont associer des 1 logique à un des bits (bits d'indice "gpio_index") pour les deux variables. Cela en cas de la réussite de l'affectation.   

### test_assignment_Output_L(int a)

Cette fonction permet de tester le bon fonctionnement de "write_gpio(int gpio_index, bool value)", en effet, elle nous permet de vérifier l'affectation d'un niveau bas à un GPIO après avoir le définir en tant que output. Ce test sera réalisé uniquement pour un exemple de fonctionnement classique (où gpio_index appartient [0..31] ; valeur de "a") (fonctionnement limite est bien tester avec les fonctions précédentes).
Pour mener à bien ce test, il faut tout d'abord initialiser la variable "direction_gpio_bank1" à zéro et "value_gpio_bank1" à 0xFFFFFFFF (ce qui est réalisé par la fonction "all_value_gpio_bank1_H(void)"). Si l'affectation se réalise  le bit d'indice gpio_index de "value_gpio_bank1" passera à 0.   
Un affichage permettant de visualiser les modifications entrainées sur les variables et d'indiquer la réussite ou l'échec de l'affectation, est nécessaire pour le débogage.  

### test_assignment_Input_H(int a)

Cette fonction permet de tester le bon fonctionnement de "write_gpio(int gpio_index, bool value)", en effet, elle nous permet de nous assurer de l'impossibilité d'affectation d'une valeur à un GPIO défini comme input.  
Pour ce test, on initialise "direction_gpio_bank1" à 0xFFFFFFFF (en appelant la fonction "all_gpios_output(void)") et "value_gpio_bank1" à zéro (en appelant la fonction "reset_value_gpio_bank1(void)"). Si, "value_gpio_bank1" change de valeur à la fin de test cela implique qu'il s'agit d'un erreur.

## Remarques:
Selon la logique que j'ai abordé au dévéloppement des fonctions de manipulation des GPIO, ces tests sont suffisants pour vérifier le bon fonctionnement. 

Les deux fichiers sont commentés. il y'aura des commentaires :
qui précisent les valeurs d'initialisations des différents tests.
qui indiquent les retours attendus pour chaque affichage.



