#! /bin/bash
gcc -o bin/a main.c libs/ggame_utils.c libs/player.c libs/enemy.c -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image -lm
bin/a

