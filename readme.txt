The Mana Framework

Create a new empty project and C++ file and name it like "AppMain" or whatever and then import "ManaApplication.h"

Then create your main function something like this

```
int main(int argc, char *argv[]) {
	ManaApplication app = ManaApplication();
	
	app.Init("Mana Test App", 800, 600, false, 60);
	app.Run();

	return 0;
}
```

Mana Application is the entry point of the framework and where the main loop happens. In init
just pass in the name of the window, the width, height, whether it's fullscreen, and your fps cap.

The ManaFramework is organized in GameStates. GameStates can be thought of as like your title screen,
menu screen, play screen, and game over screen. Or whatever you want really. To create your own just
extend "GameState.h" and implement the virtual functions "OnEnter()" and "OnExit()" that return void.

Now you may be wondering what to put in OnEnter() and OnExit()? Well OnEnter() is generally where you'll
add your GameObjects, which can also and probably should be extended "GameObject.h" or "Sprite.h"

GameObjects are what represent pretty much anything in your game from your player to your enemies to your
backgrounds and whatnot. To add your own just create your own just extend "GameObject.h" or "Sprite.h"
The difference being that Sprites have a few more virtual functions that you can override such as more
control over drawing them whereas you cannot control how you draw a regular GameObject other than
drawing from a regular texture or drawing a TextureRegion from it.