/* main.c */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "rogue.h"
#include "init.h"
#include "level.h"
#include "main.h"
#include "message.h"
#include "monster.h"
#include "object.h"
#include "play.h"
#include "trap.h"

extern short party_room;
extern object level_objects;
extern object level_monsters;

/*int saved_uid;
int true_uid;*/

/*void turn_into_games(void)
{
	if(setuid(saved_uid) == -1)
	{
		perror("setuid restore failed!");
		clean_up("");
	}
}

void turn_into_user(void)
{
	if(setuid(true_uid)==-1)
	{
		perror("setuid(restore)");
		clean_up("");
	}
}*/
int main(int argc, char *argv[])
{
	/* Save the setuid we have got, then turn back into the player */
//	saved_uid = geteuid();
//	setuid(true_uid = getuid());

	if (init(argc, argv))	/* restored game */
	{
		goto PL;//||{"next": {"line": 62}}
	}

  //||block||{"note": "We are in main(), the first function that runs in all C programs. Rogue uses its main() to do some housekeeping and then set up its main outer loop, which sets up a level and everything that goes with it, lets the player play that level (another loop)."}
	for (;;)
	{
		clear_level();
		make_level();
		put_objects();
		put_stairs();
		add_traps();
		put_mons();
		put_player(party_room);
		print_stats(STAT_ALL);
PL:		
		play_level(); //||{"expand": {"file": "play.c", "lines": [152, 406]}, "note": "This is the inner loop that handles interaction with the level."}
    //||block
		free_stuff(&level_objects);
		free_stuff(&level_monsters);
	}//||{"next": {"line": 51}}

	return 0;
}

