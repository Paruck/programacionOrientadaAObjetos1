#include "Application.h"

Application app;

void setup() {
	app.setup();
}

void display() {
	app.display();
}

void update() {
	app.update();
}


void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	app.cursor_position(xpos, ypos);

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	app.keyboardInput(key, scancode, action, mods);
}


int main(int argv, char ** argc) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(920, 640, "PAC-MAN", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();
	app.setup();

	// get version info 
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf(" Renderer: %s\ n", renderer);
	printf(" OpenGL version supported %s\ n", version);

	// tell GL to only draw onto a pixel if the shape is closer to the viewer 
	//glEnable (GL_DEPTH_TEST); // enable depth-testing 	
	//glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer" 

	

	glEnable(GL_DEPTH_TEST); //Z-buffer

	glfwSetKeyCallback(window, key_callback);

	glfwSetCursorPosCallback(window, cursor_position_callback);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, (GLsizei)920, (GLsizei)640);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 920, 640, 0);
		/* update other events like input handling */
		glfwPollEvents();

		app.update();
		/* put the stuff we've been drawing onto the display */
		app.display();

		glViewport(0, 0, (GLsizei)920/4, (GLsizei)640/4);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 920/4, 640/4, 0);

		app.display2();

		glfwSwapBuffers(window);
	}

	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;
}
