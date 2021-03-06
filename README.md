<br />
<p align="center">
	<img src="https://raw.githubusercontent.com/Mars073/groupeA05/master/pgroupeA05/data/images/logo.png" />
	<p align="center">Project carried out as part of the video game development course at HELHa
		<br />
		<br />
		<a href="https://helha.be/" target="_blank">HELHa Website</a>
		.
		<a href="https://github.com/Mars073/groupeA05/issues">Report Bug</a>
		.
		<a href="https://github.com/Mars073/groupeA05/issues">Request Feature</a>
	</p>
</p>

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Team](#team)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Configure Code::Blocks](#configure)
  * [How to play](#how-to-play)
* [License](#license)

<!-- ABOUT THE PROJECT -->
## About The Project
The playable character will move on a "map" where he will randomly meet monsters he will have to fight. It will have a starting level of 1 and characteristics such as :
* Attack
* Defense
* Magic
* ...

The more monsters he beats, the more experience he will gain and the more he will increase his level and characteristics.

### Team
| ![avatar](https://image.noelshack.com/fichiers/2019/44/1/1572255557-10551879-816797391685674-1509560817-n.jpg) | ![avatar](https://image.noelshack.com/fichiers/2019/44/1/1572255557-10304438-354222028072916-5132253780138011790-n.jpg) | ![avatar](https://image.noelshack.com/fichiers/2019/44/1/1572255557-3de4c0e02f5f238610de9062ec468aad8ddd38dfd825fdce632fe47116791901.jpg) |
| :---: | :---: | :---: |
| Kevin "[Nevo067](//github.com/nevo067)" Opese | Corentin "[TigrouSimba](//github.com/TigrouSimba)" Nya | Martin "[mars073](//github.com/mars073)" Leroy |
| _UI Design and combat/loot system_ | _Monster, character and inventory system_ | _Basic systems, game map and animations_ |


### Built With

* [Code::Blocks](http://www.codeblocks.org/)
* [SFML](https://www.sfml-dev.org/)

<!-- GETTING STARTED -->
## Getting Started
Obviously, clone or download the project:
```sh
git clone https://github.com/Mars073/groupeA05.git
```

### Configure
* On Window
	1. Open the `pgroupeA05\pgroupeA05.cbp` file with Code::Blocks
	2. Include <a href="https://www.sfml-dev.org/tutorials/2.5/start-cb.php" target="_blank" title="SFML and Code::Blocks (MinGW)">SFML libraries</a>, the default folder in the project is `C:\libs\SFML`. You can also add all DLL files to the `bin\Debug\` folder.
	3. Build <kbd>F9</kbd> & Enjoy.
* On Linux 
	1. Open the `pgroupeA05\pgroupeA05_linux.cbp` file with Code::Blocks
	2. Everything is ready, you can Build and run <kbd>F9</kbd> σ(≧ε≦ｏ)

> ** NOTE **: it is necessary to install the `openal` devel on some linux  

Fedora:
```sh
sudo dnf install openal
```

### How to play
* On map
	You can use the <kbd>Z</kbd><kbd>↑</kbd>, <kbd>D</kbd><kbd>→</kbd>, <kbd>S</kbd><kbd>↓</kbd> or <kbd>Q</kbd><kbd>←</kbd> key to move your character on the map.

## Resources
_All elements of the game remain the property of their intellectual author(s) and can be deleted upon request._
* Graphics:
	* Game sprites: [RPG Maker](https://www.rpgmakerweb.com/)
	* Title bg: [Goblin Slayer](https://www.trzcacak.rs/imgb/iwwxxwR/) + [Dofus](https://www.dofus.com/en/mmorpg/media/wallpapers/579152-dofus-2016-login-screen)
* Musics:
	* Title music: [Main Theme 04](https://wingless-seraph.net/en/material-music_title.html)
	* World 0 : [Voyage of Mystic Sea](https://wingless-seraph.net/en/material-music_field.html)
	* World 1 : [Shopping District](https://wingless-seraph.net/en/material-music_town_field.html)
	* World 2 : [Caos and Despair](https://wingless-seraph.net/en/material-music_dangeon.html)


<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.
