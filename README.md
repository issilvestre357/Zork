# Zork

## Game Information

**Zork** is a C++ text adventure game created in Visual Studio 2019 Community.

The player wakes up trapped inside a pizzeria and must explore the building, collect useful items, restore power, unlock restricted rooms, and find a way out.

## Author

Ian Silvestre

## Repository

https://github.com/issilvestre357/Zork

## How to Play

The game is played through the console by typing commands.

Player input is converted to lowercase, so capitalization does not matter.

### Movement

You can move using the directions:

- `north`
- `south`
- `east`
- `west`

The game can also recognize those direction words inside longer sentences.

### Looking Around

Use commands such as:

- `look`
- `see`

to view the current room and any visible items.

### Picking Up Items

You can use commands such as:

- `pick up fuse`
- `grab fuse`
- `take fuse`

If you enter a pickup command without naming an item, the game will ask which item you want to pick up.

The **Tool Belt** must be collected before most other items can be carried. Other items are stored inside the Tool Belt.

### Dropping Items

Use commands such as:

- `drop fuse`
- `leave fuse`

The Tool Belt cannot be dropped while it still contains other items.

### Inventory

Type:

`inventory`

to view what you are currently carrying and what is stored inside the Tool Belt.

### Restarting and Quitting

Type:

- `restart` to restart the game
- `quit` to exit the game

The game will ask for confirmation before restarting.

## How to Finish the Game

1. Start in the **Eating Area**.
2. Travel north to the **Bathroom** and pick up the **Tool Belt**.
3. Return to the Eating Area and pick up the **Fuse**.
4. Travel west through the dark **Kitchen**.
5. Travel south into the **Supply Closet**.
6. Use the Fuse when prompted to restore power.
7. Return to the Kitchen. The lights will now be on and the **Guardroom Key** can be found.
8. Pick up the Guardroom Key.
9. Return to the Eating Area and travel east to unlock the **Guard Room**.
10. Pick up the **Exit Key** inside the Guard Room.
11. Return to the Eating Area and travel south to unlock the **Exit**.
12. Enter the Exit to complete the game.

## Main Features

- Six connected rooms
- Items that can be picked up and dropped
- Items stored inside another item
- Locked rooms that require keys
- Fuse and power-restoration puzzle
- Dark-room visibility mechanic
- Flexible keyword-based command input
- Restart and replay support


## License

This project is licensed under the MIT License.

Copyright (c) 2026 Ian Silvestre

See the LICENSE file for details.