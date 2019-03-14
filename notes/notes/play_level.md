---
title: play_level
created: '2019-03-08T14:42:11.300Z'
modified: '2019-03-08T17:40:22.663Z'
tags: [play.c]
---

# play_level

From play.c.

It runs a loop that:

- Finds out if there is a message about hitting queued, and if there is, it shows it with [[message]].
- Resets the trap_door flag
- `move`s (via ncurses, an external library) the rogue to its currently set row and column.
- `refresh`es (via ncurses) to rerender the screen.
- Uses `rgetchar` to see what key is pressed.
- Clears the message
  - But doesn't that mean the hit message shown above gets cleared before it could be read?
