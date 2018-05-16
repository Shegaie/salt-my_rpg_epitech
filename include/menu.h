/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** menu.h
*/

#include "struct.h"
#include "mob.h"

typedef struct button {
	sfRectangleShape *button_r;
	sfTexture *button_tx;
	sfIntRect rect;
} button_t;

int closing_event(sfEvent *event, rpg_t *, sfRenderWindow *, mobs_t **mob);
int menu(sfRenderWindow *window);
int game_loop_menu(button_t **button_arr, sfRenderWindow *window, sfTime wait,
sfEvent event);
int menu_loop(sfRenderWindow *window, button_t **button_arr, sfTexture *menu_t,
sfSprite *menu_s);
void init_newGame_button(button_t *new_game);
void init_quitGame_button(button_t *quit_game);
int is_mouse_on(sfRectangleShape *rect_shape, sfVector2i mouse_pos, int offset);
int button_state_released(sfVector2i mouse_pos, button_t **button_arr,
sfRenderWindow *window);
int init_buttons(button_t **button_arr);
int free_destroy(button_t **button_arr, sfTexture *menu_t, sfSprite *menu_s,
int bt_nb);
int display_reinit(sfRenderWindow *window, button_t **button_arr, int bt_nb);
int event_handle(sfEvent *event, button_t **button_arr, sfRenderWindow *window);
int mouse_on_button(button_t **button_arr, sfRenderWindow *window, int, int);
int pause_game(sfRenderWindow *window, rpg_t *rpg);

//pause func

int which_button_released(sfVector2i mouse_pos, button_t **button_arr,
sfRenderWindow *window);
int click_on_button(button_t **button_arr, sfRenderWindow *window, int *stat);
int pause_loop(rpg_t *rpg, button_t **button_arr, hud_t bg,
int *stat);
int pause_game(sfRenderWindow *window, rpg_t *rpg);
void init_the_button(button_t *new_game, sfVector2f pos, char *path);
int init_buttons_pause(button_t **button_arr);
int stat_player(sfRenderWindow *window, rpg_t *rpg, sfEvent *event);
