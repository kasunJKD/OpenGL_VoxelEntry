#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"

const unsigned int height = 800;
const unsigned int width = 800;

// Vertices coordinates
//GLfloat vertices[] =
//{ //     COORDINATES     /        COLORS      /   TexCoord  //
//	-0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,
//	-0.5f, 0.5f, -0.5f,     0.83f, 0.70f, 0.44f,
//	 0.5f, 0.5f, -0.5f,     0.83f, 0.70f, 0.44f,
//	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,
//	 0.5f, 0.5f,  0.5f,     0.92f, 0.86f, 0.76f,
//};

// Indices for vertices order
//GLuint indices[] =
//{
//	0, 1, 2,
//	0, 2, 3,
//	0, 1, 4,
//	1, 2, 4,
//	2, 3, 4,
//	3, 0, 4
//};

GLfloat vertices[] = {
	-1.0f, -1.0f,  1.0,  0.83f, 0.70f, 0.44f,
	1.0f, -1.0f,  1.0,  0.83f, 0.70f, 0.44f,
	-1.0f,  1.0f,  1.0,  0.83f, 0.70f, 0.44f,
	1.0f,  1.0f,  1.0,  0.83f, 0.70f, 0.44f,
	-1.0f, -1.0f, -1.0,  0.83f, 0.70f, 0.44f,
	1.0f, -1.0f, -1.0,  0.83f, 0.70f, 0.44f,
	 -1.0f,  1.0f, -1.0,  0.83f, 0.70f, 0.44f,
	1.0f,  1.0f, -1.0 ,  0.83f, 0.70f, 0.44f,
};
//
GLuint indices[] = {
	//Top
	   2, 6, 7,
	   2, 3, 7,

	   //Bottom
	   0, 4, 5,
	   0, 1, 5,

	   //Left
	   0, 2, 6,
	   0, 4, 6,

	   //Right
	   1, 3, 7,
	   1, 5, 7,

	   //Front
	   0, 2, 3,
	   0, 1, 3,

	   //Back
	   4, 6, 7,
	   4, 5, 7
};


int main() 
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(height, width, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, height, width);

	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	//// Create Vertex Shader Object and get its reference
	//GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//// Attach Vertex Shader source to the Vertex Shader Object
	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//// Compile the Vertex Shader into machine code
	//glCompileShader(vertexShader);

	//// Create Fragment Shader Object and get its reference
	//GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//// Attach Fragment Shader source to the Fragment Shader Object
	//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//// Compile the Vertex Shader into machine code
	//glCompileShader(fragmentShader);

	//// Create Shader Program Object and get its reference
	//GLuint shaderProgram = glCreateProgram();
	//// Attach the Vertex and Fragment Shaders to the Shader Program
	//glAttachShader(shaderProgram, vertexShader);
	//glAttachShader(shaderProgram, fragmentShader);
	//// Wrap-up/Link all the shaders together into the Shader Program
	//glLinkProgram(shaderProgram);

	//// Delete the now useless Vertex and Fragment Shader objects
	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);


	// Create reference containers for the Vartex Array Object and the Vertex Buffer Object
	//GLuint VAO, VBO, EBO;

	// Generate the VAO and VBO with only 1 object each
	/*glGenVertexArrays(1, &VAO);*/
	//glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Make the VAO the current Vertex Array Object by binding it
	//glBindVertexArray(VAO);

	//// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//// Introduce the vertices into the VBO
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//// Enable the Vertex Attribute so that OpenGL knows to use it
	//glEnableVertexAttribArray(0);

	// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glEnable(GL_DEPTH_TEST);


	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		//glUseProgram(shaderProgram);
		shaderProgram.Activate();

		camera.Inputs(window);
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		/*double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60)
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)(height / width), 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));*/

		//glUniform1f(uniID, 0.5f);
		// Bind the VAO so OpenGL knows to use it
		//glBindVertexArray(VAO);
		VAO1.Bind();
		// Draw the triangle using the GL_TRIANGLES primitive
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	// Delete all the objects we've created
	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	//glDeleteBuffers(1, &EBO);
	//glDeleteProgram(shaderProgram);
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}