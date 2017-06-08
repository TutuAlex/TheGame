#include "functions.h"
#include "objloader.h"


#include "vector3d.h"

#include"camera.h"
#include"collision.h"
#include<SDL_mixer.h>


//necesairy file 
FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
return _iob;
}







//camera 
camera cam;

//cube object loaded
int cube;
objloader obj;

//bool that checks if mouse is in the window
bool mousein = false;

//music 
Mix_Music *gMusic = NULL;


//initialize 
void init()
{

	//sets camera aka the player in a position in the world
	cam.setLocation(vector3d(0, 0, 10));

	//sets color
	glClearColor(0.5, 0.5, 0.5, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 640.0 / 480.0, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);

	//loads cube
	cube = obj.load("therealone.obj");

	//lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	float col[] = { 0.0,0.0,0.0,0.0 };
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, col);
	
}





void init1()
{
	bool success = true;

	glClearColor(1.0, 0.0, 0.0, 1.0);  //background color and alpha
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 640.0 / 480.0, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_FLAT);          // no color interpolation
    glShadeModel(GL_SMOOTH);        // color interpolation (default)
	glColor3f(0.0,1.0,0.0);

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
}





void display1()
{

	//creates simple triengle
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 2.0, -5.0);	
	glVertex3f(-2.0, -2.0, -5.0);
	glVertex3f(2.0, -2.0, -5.0);
	glEnd();
	
}








void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	cam.control();
	
	//draw the skybox, very important to initialise it after cam.control and before cam.update, so it doesnt moove
    drawSkybox(50.0);
	
	cam.update();

	
	glDisable(GL_LIGHTING);

	//makes object (cube)
	glCallList(cube);
	glColor3f(1.0, 1.0, 1.0);
}










void display2()
{
	//create simple lighting
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	float pos[] = { -1.0,1.0,-2.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
}






bool unitTest1()
{
	bool success = true;

	//initialize everything

	SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_OPENGL);
bool running = true;
Uint32 start;
SDL_Event event;
init1();

//Load music
gMusic = Mix_LoadMUS("CBTank.wav");
if (gMusic == NULL)
{
	printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	success = false;
}


while (running)
{
	start = SDL_GetTicks();
	

	while (SDL_PollEvent(&event))
	{


		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			Mix_PlayMusic(gMusic, -1);
		}


		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		
			//stop the program
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				running = false;
				break;
			}
			break;

		}
	}

	display1();
	SDL_GL_SwapBuffers();
	
	if (1000 / 30>(SDL_GetTicks() - start))
		SDL_Delay(1000 / 30 - (SDL_GetTicks() - start));
}

//deconstruct
SDL_Quit();


return true;

}






bool unitTest2()
{

	//initialize everything
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_OPENGL);
	bool running = true;
	Uint32 start;
	SDL_Event event;
	init();

	while (running)
	{
		start = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:

				
				SDL_ShowCursor(SDL_DISABLE);
				break;
			
				//stop the program
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
					break;
				}
				break;

			}
		}

		display();
		SDL_GL_SwapBuffers();

		if (1000 / 30>(SDL_GetTicks() - start))
			SDL_Delay(1000 / 30 - (SDL_GetTicks() - start));
	}

	//deconstruct
	SDL_Quit();
	

	return true;


}





bool unitTest3()
{

	//initialize everything
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_OPENGL);
	bool running = true;
	Uint32 start;
	SDL_Event event;
	init();
	initskybox();

	while (running)
	{
		start = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:

				cam.mouseIn();
				SDL_ShowCursor(SDL_DISABLE);
				break;
			case SDL_KEYDOWN:
				//pause the game
				if (event.key.keysym.sym == SDLK_p)
				{

					cam.mouseOut();
					SDL_ShowCursor(SDL_ENABLE);
					break;
				}
				//stop the program
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
					break;
				}
				break;

			}
		}

		display();
		SDL_GL_SwapBuffers();

	
		if (1000 / 30>(SDL_GetTicks() - start))
			SDL_Delay(1000 / 30 - (SDL_GetTicks() - start));
	}

	//deconstruct
	SDL_Quit();
	killskybox();

	return true;


}












bool unitTest4()
{

	//initialize everything
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_OPENGL);
	bool running = true;
	Uint32 start;
	SDL_Event event;
	init();
	initskybox();

	while (running)
	{
		start = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:

				cam.mouseIn();
				SDL_ShowCursor(SDL_DISABLE);
				break;
			case SDL_KEYDOWN:
				//pause the game
				if (event.key.keysym.sym == SDLK_p)
				{

					cam.mouseOut();
					SDL_ShowCursor(SDL_ENABLE);
					break;
				}
				//stop the program
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
					break;
				}
				break;

			}
		}

		display();
		SDL_GL_SwapBuffers();
		//checks for collision
		vector3d cameraPos = cam.getLocation();
		if (collision::spheresphere(cameraPos, 2.0, vector3d(0, 0, 0), 1.0))
			std::cout << "collision\n";

		cam.setLocation(vector3d(cameraPos));
		cam.setLocation(cameraPos);
		if (1000 / 30>(SDL_GetTicks() - start))
			SDL_Delay(1000 / 30 - (SDL_GetTicks() - start));
	}

	//deconstruct
	SDL_Quit();
	killskybox();

	return true;


}




int main(int argc, char **argv)
{

	//UNIT TESTING
	//display red screen with green triangle and loads musical piece
	try {
		bool a = false;
         a = unitTest1();
		 if (a == false)
		 {
			 throw a;
		 }
		 std::cout << "unit test 1 succeeded" << std::endl;
	     }
	catch (bool a) 
	{

		std::cout << "unit test 1 failed" << std::endl;
		return -1;
	}




	//checks the object loader, loads an object

	try {
		bool a = false;
		a = unitTest2();
		if (a == false)
		{
			throw a;
		}
		std::cout << "unit test 2 succeeded" << std::endl;
	}
	catch (bool a)
	{

		std::cout << "unit test 2 failed" << std::endl;
		return -1;
	}



	//chacks the camera
	try {
		bool a = false;
		a = unitTest3();
		if (a == false)
		{
			throw a;
		}
		std::cout << "unit test 3 succeeded" << std::endl;
	}
	catch (bool a)
	{

		std::cout << "unit test 3 failed" << std::endl;
		return -1;
	}





	//checks the collision

	try {
		bool a = false;
		a = unitTest4();
		if (a == false)
		{
			throw a;
		}
		std::cout << "unit test 4 succeeded" << std::endl;
	}
	catch (bool a)
	{

		std::cout << "unit test 4 failed" << std::endl;
		return -1;
	}










	return 0;


}