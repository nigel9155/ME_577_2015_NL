//
//  main.cpp
//  OpenGL4Test
//
//  Created by Rafael Radkowski on 5/28/15.
//  Copyright (c) 2015 -. All rights reserved.
//

// stl include
#include <iostream>
#include <string>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// glfw includes
#include <GLFW/glfw3.h>


// include local files
#include "controls.h"



using namespace std;

static const string vs_string =
    "#version 410 core                                                 \n"
    "                                                                   \n"
    "uniform mat4 projectionMatrix;                                    \n"
    "uniform mat4 viewMatrix;                                           \n"
    "uniform mat4 modelMatrix;                                          \n"
    "in vec3 in_Position;                                               \n"
    "                                                                   \n"
    "in vec3 in_Color;                                                  \n"
    "out vec3 pass_Color;                                               \n"
    "                                                                  \n"
    "void main(void)                                                   \n"
    "{                                                                 \n"
    "    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);  \n"
    "    pass_Color = in_Color;                                         \n"
    "}                                                                 \n";

// Fragment shader source code. This determines the colors in the fragment generated in the shader pipeline. In this case, it colors the inside of our triangle specified by our vertex shader.
static const string fs_string  =
    "#version 410 core                                                 \n"
    "                                                                  \n"
    "in vec3 pass_Color;                                                 \n"
    "out vec4 color;                                                    \n"
    "void main(void)                                                   \n"
    "{                                                                 \n"
    "    color = vec4(pass_Color, 1.0);                               \n"
    "}                                                                 \n";


glm::mat4 projectionMatrix; // Store the projection matrix
glm::mat4 viewMatrix; // Store the view matrix
glm::mat4 modelMatrix; // Store the model matrix


// The handle to the window object
GLFWwindow*         window;


// Define some of the global variables we're using for this sample
GLuint program;
GLuint vao;

unsigned int vaoID[1]; // Our Vertex Array Object

unsigned int vboID[2]; // Our Vertex Buffer Object


// This is the callback we'll be registering with GLFW for errors.
// It'll just print out the error to the STDERR stream.
void error_callback(int error, const char* description) {
    fputs(description, stderr);
}


// This is the callback we'll be registering with GLFW for keyboard handling.
// The only thing we're doing here is setting up the window to close when we press ESC
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}


void createBox(void)
{
    float* vertices = new float[60];  // Vertices for our square
    float *colors = new float[60]; // Colors for our vertices
    
    vertices[0] = 0; vertices[1] = 0; vertices[2] = 0;
    vertices[3] = 0, vertices[4] = 3; vertices[5] = 0;
    vertices[6] = 1, vertices[7] = 3; vertices[8] = 0;
    vertices[9] = 2, vertices[10] = 1; vertices[11] = 0;
    vertices[12] = 2, vertices[13] = 0, vertices[14] = 0;
    vertices[15] = 0, vertices[16] = 1, vertices[17] = 0;
    vertices[18] = 1, vertices[19] = 1, vertices[20] = 0;
    vertices[21] = 1, vertices[22] = 1, vertices[23] = 0;
    
    
    //Second Level
    vertices[24] = 0; vertices[25] = 0; vertices[26] = 1;
    vertices[27] = 0; vertices[28] = 1; vertices[29] = 1;
    vertices[30] = 1; vertices[31] = 0; vertices[32] = 1;
    vertices[33] = 1; vertices[34] = 1; vertices[35] = 1;
    vertices[36] = 0; vertices[37] = 3; vertices[38] = 1;
    vertices[39] = 1; vertices[40] = 3; vertices[41] = 1;
    vertices[42] = 2; vertices[43] = 1; vertices[44] = 1;
    vertices[45] = 2; vertices[46] = 0; vertices[47] = 1;
    
    //Fourth level
    
    vertices[48] = 0; vertices[49] = 0; vertices[50] = 3;
    vertices[51] = 0; vertices[52] = 1; vertices[53] = 3;
    vertices[54] = 1; vertices[55] = 0; vertices[56] = 3;
    vertices[57] = 1; vertices[58] = 1; vertices[59] = 3;
    
    
    glGenVertexArrays(2, &vaoID[0]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object so we can use it
    
    
    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object
    
    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 60 * sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
  
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object
    
    
    //Color
    colors[0] = 0;colors[1] = 0; colors[2] = 1;
    colors[3] = 0;colors[4] = 0; colors[5] = 1;
    colors[6] = 0;colors[7] = 0; colors[8] = 1;
    colors[9] = 0;colors[10] = 0; colors[11] = 1;
    colors[12] = 0;colors[13] = 0; colors[14] = 1;
    colors[15] = 0;colors[16] = 0; colors[17] = 1;
    colors[18] = 0;colors[19] = 0; colors[20] = 1;
    colors[21] = 0;colors[22] = 0; colors[23] = 1;
    colors[24] = 0;colors[25] = 0; colors[26] = 1;
    colors[27] = 0;colors[28] = 0; colors[29] = 1;
    colors[30] = 0;colors[31] = 0; colors[32] = 1;
    colors[33] = 0;colors[34] = 0; colors[35] = 1;
    colors[36] = 0;colors[37] = 0; colors[38] = 1;
    colors[39] = 0;colors[40] = 0; colors[41] = 1;
    colors[42] = 0;colors[43] = 0; colors[44] = 1;
    colors[45] = 0;colors[46] = 0; colors[47] = 1;
    colors[48] = 0;colors[49] = 0; colors[50] = 1;
    colors[51] = 0;colors[52] = 0; colors[53] = 1;
    colors[54] = 0;colors[55] = 0; colors[56] = 1;
    colors[57] = 0;colors[58] = 0; colors[59] = 1;
    
    //Color
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 60 * sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array
    
    glBindVertexArray(0); // Disable our Vertex Buffer Object
    
    
    delete [] vertices; // Delete our vertices from memory
}


void setupScene(void) {
    createBox();
}



/*!
 This function initializes the GLFW window
 */
int initWindow(void)
{
    // Initialize GLFW, and if it fails to initialize for any reason, print it out to STDERR.
    if (!glfwInit()) {
        fprintf(stderr, "Failed initialize GLFW.");
        exit(EXIT_FAILURE);
    }
    
    // Set the error callback, as mentioned above.
    glfwSetErrorCallback(error_callback);
    
    // Set up OpenGL options.
    // Use GLFW verion 3.3,
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    
    // Create a window to put our stuff in.
    window = glfwCreateWindow(800, 600, "Hello OpenGL", NULL, NULL);
    
    // If the window fails to be created, print out the error, clean up GLFW and exit the program.
    if( window == NULL ){
        cout <<  "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible." << endl;
        glfwTerminate();
        system("pause");
        exit(-1);
    }
    
    // Use the window as the current context (everything that's drawn will be place in this window).
    glfwMakeContextCurrent(window);

    return 1;
}


/*!
 This function initializes glew
 */
bool initGlew(void)
{
    
    // Makes sure all extensions will be exposed in GLEW and initialize GLEW.
    glewExperimental = GL_TRUE;
    
    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        cout <<  "Failed to initialize GLEW\n" << endl;
        system("pause");
        return -1;
    }
    
    cout <<  "OpenGL version supported by this platform " << glGetString(GL_VERSION) <<  endl;
    return 1;
}

/*!
 This function updates the virtual camera
 */
bool updateCamera()
{
    // Compute the MVP matrix from keyboard and mouse input
    computeMatricesFromInputs();
    viewMatrix = getViewMatrix(); // get the current view matrix
    
    return true;
}



int main(int argc, const char * argv[])
{
    // Init the GLFW Window
    initWindow();
    
    // Set the keyboard callback so that when we press ESC, it knows what to do.
    glfwSetKeyCallback(window, key_callback);
    
    // Init the glew api
    initGlew();
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// The Shader Program starts here
    
    // Vertex shader source code. This draws the vertices in our window. We have 3 vertices since we're drawing an triangle.
    // Each vertex is represented by a vector of size 4 (x, y, z, w) coordinates.
    static const string vertex_code = vs_string;
    static const char * vs_source = vertex_code.c_str();
    
    // Fragment shader source code. This determines the colors in the fragment generated in the shader pipeline. In this case, it colors the inside of our triangle specified by our vertex shader.
    static const string fragment_code = fs_string;
    static const char * fs_source = fragment_code.c_str();

    // This next section we'll generate the OpenGL program and attach the shaders to it so that we can render our triangle.
    program = glCreateProgram();
    
    // We create a shader with our fragment shader source code and compile it.
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fs_source, NULL);
    glCompileShader(fs);
    
    // We create a shader with our vertex shader source code and compile it.
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vs_source, NULL);
    glCompileShader(vs);
    
    // We'll attach our two compiled shaders to the OpenGL program.
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    
    glLinkProgram(program);
    
    // We'll specify that we want to use this program that we've attached the shaders to.
    glUseProgram(program);
    
     //// The Shader Program ends here
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   
    /// IGNORE THE NEXT PART OF THIS CODE
    
    // Set up our green background color
    static const GLfloat clear_color[] = { 0.6f, 0.7f, 1.0f, 1.0f };
    static const GLfloat clear_depth[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
    
    projectionMatrix = glm::perspective(1.57f, (float)800 / (float)600, 0.1f, 100.f);
    modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)); // Create our model matrix which will halve the size of our model
    viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    
    int projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix"); // Get the location of our projection matrix in the shader
    int viewMatrixLocation = glGetUniformLocation(program, "viewMatrix"); // Get the location of our view matrix in the shader
    int modelMatrixLocation = glGetUniformLocation(program, "modelMatrix"); // Get the location of our model matrix in the shader
    
    
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]); // Send our projection matrix to the shader
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader
    
    
     
    setupScene();
    glBindAttribLocation(program, 0, "in_Position");
    glBindAttribLocation(program, 1, "in_Color");
    
    // Enable depth test
    glEnable(GL_DEPTH_TEST); // ignore this line
    
    // This is our render loop. As long as our window remains open (ESC is not pressed), we'll continue to render things.
    while(!glfwWindowShouldClose(window))
    {
       
        // Clear the entire buffer with our green color (sets the background to be green).
        glClearBufferfv(GL_COLOR , 0, clear_color);
        glClearBufferfv(GL_DEPTH , 0, clear_depth);
        
        // update the virtual camera
        updateCamera();


        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //// This generate the object
        
        // Enable the shader program
        glUseProgram(program);
        
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // send the view matrix to our shader
        
        // Bind the buffer and switch it to an active buffer
        glBindVertexArray(vaoID[0]);
        
        // Draw the triangles
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 16);
        // Unbind our Vertex Array Object
        glBindVertexArray(0);
        
        // Unbind the shader program
        glUseProgram(0);
        
        //// This generate the object
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        
        // Swap the buffers so that what we drew will appear on the screen.
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    
    // Program clean up when the window gets closed.
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(program);
}

