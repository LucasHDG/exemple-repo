/*
** EPITECH PROJECT, 2018
** calendar
** File description:
** invite to a meeting
*/

#include "calendar.h"

int get_new_len(char **command, int *employees)
{
	int len = 0;

	for (int x = 0; employees[x] != -42; x++)
		len++;
	for (int y = 2; command[y] != NULL; y++)
		len++;
	return (len);
}

int *change_my_employees(int *employees, char **command)
{
	int x = 0;
	int len = get_new_len(command, employees);
	int *new = malloc(sizeof(int) * (len + 1));

	if (new == NULL)
		return (NULL);
	for (; employees[x] != -42; x++)
		new[x] = employees[x];
	for (int y = 2; command[y] != NULL; y++) {
		new[x] = atoi(command[y]);
		x++;
	}
	new[x] = -42;
	free(employees);
	return (new);
}

void invite_to_meeting(char **command, meeting_t *meeting)
{
	int id = 0;

	if (len_double_array(command) < 3)
		return;
	id = atoi(command[1]);
	while (meeting != NULL) {
		if (meeting->id == id)
			meeting->employees = change_my_employees	\
			(meeting->employees, command);
		meeting = meeting->next;
	}
}
