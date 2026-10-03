## Anatomy of SDL2 Program

An SDL2 Program consists of
* initialisation phase
* main loop
* clean-up

The Initialisation Phase
* Initialises the SDL2 subsystem
* Creates all SDL2 objects

The Main Loop consists of
* Event Loop
    * Poll event queue and assign event handler
* Update Phase
    * Update the state of each graphic object
* Render Phase
    * Fill Background
    * Render each Graphic Object

The Clean-up
* Destroy/Free all Graphic Objects
* Quit the SDL2 subsystems
s