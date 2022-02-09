# Test technique embarqué LISA

Voici les informations nécessaires pour réaliser le test technique

## Matériel

Seul un ordinateur est nécessaire.

## Sujet

Le but est d'évaluer vos connaissances basiques en C embarqué. Voici le sujet :

On va imaginer deux variables globales (etiers non signés 32 bits) direction_gpio_bank1 et value_gpio_bank1. La première variable correspnd au sens des 32 GPIOs du bank1 (0 pour input, 1 pour output) et la deuxième la valeur des 32 GPIOs du bank1 (0 pour GND, 1 pour VCC). Chaque bit de ces variables est allginé de façon à ce que le MSB correponde au GPIO31 et le LSB au GPIO0.

L'idée est de créer au moins 3 fonctions : set_gpio_output(int gpio_index), set_gpio_input(int gpio_index) et write_gpio(int gpio_index, bool value)  (vous pourriez avoir besoin de créer des sous fonctions). gpio_index correspond à l'index du gpio que nous voulons modifier (il peut aller de 0 à 31).

## Rendu

On attend comme rendus un fichier sans main implémentant au moins les 3 fonctions précedants, un deuxième fichier implémentant les tests comprenant un main qui execute et vérifie les tests et un README.md documentant votre code d'un point de vue fonctionnel. On attend un code bien commenté, qui prend en compte de la gestion d'erreurs.

### Pour commencer

Afin de commencer votre code, il faut faire un clone de ce repositiory dans votre espace de travail préféré.
```
git clone [url]
```

Il y a dans ce dossier, des fichiers de code .c contenant une partie du code, servez vous en.
Une fois votre code terminé, faites un repository avec votre rendu et envoyez le lien à la personne qui vous a intervievé.

**Bonne chance**
