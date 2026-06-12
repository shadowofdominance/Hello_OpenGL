#include <glad/glad.h>   // GLAD first
#include <GLFW/glfw3.h>  // then GLFW
#include <iostream>

int main() {
	if (!glfwInit()) return -1;

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello OpenGL", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Initialize GLAD after creating the context
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Set background color to blue
	glClearColor(1, 1, 1, 1);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
