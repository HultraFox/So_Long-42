# 42 So_Long, aka Escape into the Dungeon
 
## My So_Long project for 42, this is technically a demo for a fully built game that will contain way much more content. Once finished i'll link the steam page here.

In this game you play a little slime trying to escape the harsh outside world by entering a dungeon, but it won't take long untill this little slime start hearing some humans. Maybe going deeper in this dungeon will be less dangerous ?

## Some things to note before trying to play this game:
* This game will only work on Linux;
* This game was made using the MacroLibX 2.0.1, it's possible that some dependencies for the MacroLibX are missing on your machine when installing the game such as libvulkan.so, installing what it's telling you to install will fix it;
* In the bonus story-mode, dialogues are written in French.

## How to install the game
* Two version of the game can be installed, the first is what the 42 project calls the "mandatory" version, the second one is the "bonus" version;
* You do not need to install both versions of the game to play it, they are fully independant;
* Installing any of those version need you to do so from the console (shell);
* To install the mandotory version, just write "make" and press enter;
* To install the bonus version, just write "make bonus" and press enter;
* Both installations will also install any of the libraries neede, you do not need to navigate into any of the folders to install them manually !
* Those libraries are present in the game folder and installed in it too, if you remove the game for your machine they will also be removed.

## What to be aware of and how to launch the game
* Each version of the game can be started independantly, they're called "so_long" and "so_long_bonus"
* To play the mandatory version ("so_long"), you will need to open the console and write in it "./so_long \**map.ber*\*" were map.ber is the map file you want to play and press enter (can also be in a folder, like Maps/test.ber);
* To play the bonus version, lauching the executable called "so_long_bonus" will launch the game in "story mode" (can also be launched from the console);
* You can also launch the game the same way as the mandatory version, but using "so_long_bonus" in place of "so_long", this will launch it in "strich mode"
* Launching the games can take up to multiple seconds and will then be faster than should be for the same amount of time, it should only impact you when playing in "strict mode";


# The game content:

## The mandatory version:
* Start and play a map from the console;
* Press buttons to open a trapdoor to finish the map;
* The game write in the console the number of mevements made;

## Story mode:
* All of the stuff above;
* Enemies can be encountered in every level;
* In game UI;
* Touching an enemy will kill you, resulting in you losing a life;
* You can retry a level as long as you have lives;
* Losing all of you lifes mean losing all your progress;
* The player, as well as the enemies and the trap door, when opening, are now animated;
* Sound plays in game;
* You can navigate menus;
* You can customize the game (changes made are saved automatically);
* You can play the story of the game (with multiples level back to back);
* You will see dialogues play in the story (when starting the levels);
* The game create and edit a config file during gameplay;
* There is an hidden map customizer;

## Strict mode is basically the mandatory version, with only some of the bonus features, you can see it as a way to test maps quickly and play maps not in the story, differences with story mode are:
* You only have one life (doesn't affect your config file);
* Touching an enemy will kill you, resulting in the game closing;
* Finishing a map will result in the game closing;
* There is no menus, so no way to customize the game either;
* There is no dialogues, as there is no story;
* The game does not edit you config file, but if you customized the game then it will read those changes correctly;


# Controls

## Mandatory:
* You can use WASD or the directional arrows to move.

## Bonus:
* You can use WASD or the directional arrows to move in a map;
* You can use W & S or the up and down arrows to move in menus;
* You can use A & D or the left and right arrows to select an option in a menu when possible;
* You can press space or enter to continue / select an option in a menu and in dialogue;
* You can press M in the main menu to open the map customization;
* If you opened the game from the console, pressing P print a debug log in said console, if not it just make a funny noise.
* In the map customizer, pressing WASD or the directional arrows will move the cursor;
* In the map customizer, pressing 4 & 6 on the numpad will change the tile type;
* In the map customizer, pressing enter or space will place the selected tile type;


# Editing and creating maps

## You can always edit and create custom maps either with a text editor or with the map customizer in the bonus version. But to do so you have to follow some rules (if not, the game will not be able to use your maps):
* A map can be as large or long as you want, as long as there is no more than 975 characters (without counting the \n to add a new line), it is recommended to use the "custom.ber" map file if you need a big map;
* The mandatory version maps can only contain specific characters:
	* 1 (wall);
	* 0 (ground);
	* C (button);
	* E (exit);
	* P (player);
* The bonus version maps can also contain a N character for enemies;
* A map file is not valid if:
	* The whole map is not surrounded by walls;
	* There is no buttons, player or exit;
	* There is 2 or more player or exit;
	* You can't reach the exit or every buttons;
	* The map is not rectangular;
	* The map file doesn't end in .ber;
	* A map can not have more than 15 buttons;
	* A map can not have more than 9 enemies;

Note that the customizer will tell you if most of those cases are not respected while you are working on your map, and that it saves every changes the moment they are made. That said the customizer will only edit the "custom.ber" map file.