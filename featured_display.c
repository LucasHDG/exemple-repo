/*
** EPITECH PROJECT, 2018
** featured_display.c
** File description:
** display function for features
*/

#include "rpg.h"

void	set_scale_pause(s_game *game)
{
	sfVector2f vec;

	vec.x = 2;
	vec.y = 2;
	sfSprite_setScale(game->pause.menu.sprite, vec);
	sfSprite_setScale(game->pause.main.sprite, vec);
	sfSprite_setScale(game->pause.quit.sprite, vec);
	sfSprite_setScale(game->pause.res.sprite, vec);
}

int	set_featured_display(s_game *game)
{
	int a = set_sprite("rsc/mini_map.png", &game->m_map, 200, 120);
	int b = set_sprite("rsc/status.jpg", &game->i_inventory, 250, 230);
	int c = set_sprite("rsc/head.png", &game->h_head, 807, 476);
	int d = set_sprite("rsc/MAP/ark.png", &game->ark1, 857, 766);
	int e = set_sprite("rsc/MAP/ark.png", &game->ark2, 618, 799);
	int f = set_sprite("rsc/MAP/c_ark.png", &game->c_ark1, 1191, 129);
	int g = set_sprite("rsc/MAP/c_ark.png", &game->c_ark2, -16, 130);
	int h = set_carac("rsc/menu/p_m.png", &game->pause.menu, 390, 300);
	int i = set_carac("rsc/menu/m_m.png", &game->pause.main, 520, 430);
	int j = set_carac("rsc/menu/quit.png", &game->pause.quit, 520, 530);
	int k = set_carac("rsc/menu/res.png", &game->pause.res, 520, 330);

	if ((a + b + c + d + e + f + g + h + i + j + k) != 0)
		return (84);
	set_scale_pause(game);
	game->story.quest = 1;
	game->show_map = 0;
	game->inventory = 0;
	if (set_item_inv(game) == 84)
		return (84);
	return (0);
}

int	set_featured_display2(s_game *game)
{
	int a = set_sprite("rsc/story/cadre.png", \
&game->story.cadre, 1000, 620);
	int b = set_sprite("rsc/story/cadre_dialogue.png", \
&game->story.cadre_dialogue, 20, 757);
	int c = set_sprite("rsc/MAP/back_castle.png",	\
&game->castle, 0, 0);
	int d = set_sprite("rsc/MAP/back_castle2.png",	\
&game->castle2, 0, 0);

	if ((a + b + c + d)!= 0) {
		write(2, "Error: missing file\n", 20);
		return (84);
	}
	return (0);
}

void	draw_inventory(sfRenderWindow *window, s_game *game)
{
	sfRenderWindow_drawSprite(window, game->i_inventory.sprite, NULL);
	sfRenderWindow_drawText(window, game->stat.text_hp, NULL);
	sfRenderWindow_drawText(window, game->stat.text_hp_max, NULL);
	sfRenderWindow_drawText(window, game->stat.text_stam, NULL);
	sfRenderWindow_drawText(window, game->stat.text_stam_max, NULL);
	sfRenderWindow_drawText(window, game->stat.text_att, NULL);
	sfRenderWindow_drawText(window, game->stat.text_lvl, NULL);
	sfRenderWindow_drawText(window, game->stat.text_xp, NULL);
	sfRenderWindow_drawText(window, game->stat.text_xp_max, NULL);
	draw_item(window, game);
}

void	display_featured(sfRenderWindow *window, s_game *game, s_map *map)
{
	if (map->disp != 0 && map->disp != 1 && \
map->disp != 6 && map->disp != 7 && map->disp != 12 && game->check_castle == 0)
		wind(window, game->wind);
	if (game->story.quest == 1) {
		sfRenderWindow_drawSprite(window,	\
		game->story.cadre.sprite, NULL);
		sfRenderWindow_drawSprite(window,		\
		game->story.cadre_dialogue.sprite, NULL);
	}
	if (game->show_map == 1) {
		sfRenderWindow_drawSprite(window, game->m_map.sprite, NULL);
		sfRenderWindow_drawSprite(window, game->h_head.sprite, NULL);
	}
	if (game->inventory == 1)
		draw_inventory(window, game);
	if (game->level == 1)
		animation_level_up(window, game, 100);
	ark(window, game, map);
}
