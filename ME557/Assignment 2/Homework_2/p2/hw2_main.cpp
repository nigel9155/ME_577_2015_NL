//
//  main.cpp
//  OpenGL4Test
//
//  Created by Rafael Radkowski on 5/28/15.
//  Copyright (c) 2015 -. All rights reserved.
//  %ME 557 Assignment 2
//  %Nigel Lee & Hsiang Sing Naik

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
#include "HCI557Common.h"


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




/// Camera control matrices
glm::mat4 projectionMatrix; // Store the projection matrix
glm::mat4 viewMatrix; // Store the view matrix
glm::mat4 modelMatrix; // Store the model matrix




// The handle to the window object
GLFWwindow*         window;


// Define some of the global variables we're using for this sample
GLuint program;
GLuint vao;






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Fill this functions with your model code.

// USE THESE vertex array objects to define your objects
unsigned int vaoID[2];
unsigned int vboID[2];



/*!
 ADD YOUR CODE TO CREATE THE TRIANGLE STRIP MODEL TO THIS FUNCTION
 */
unsigned int createTriangleStripModel(void)
{
    // use the vertex array object vaoID[0] for this model representation
    float*vertices = new float[183];
    
    //TODO:
    //vaoID[0];
    // Face 1
    // use the vertex array object vaoID[0] for this model representation
    
    // Face 1
    vertices[0] = 0; vertices[1] = 0; vertices[2] = 3;
    vertices[3] = 1, vertices[4] = 0; vertices[5] = 3;
    vertices[6] = 0, vertices[7] = 1; vertices[8] = 3;
    vertices[9] = 1, vertices[10] = 1; vertices[11] = 3;
    
    // Face 2
    vertices[12] = 1, vertices[13] = 0, vertices[14] = 3;
    vertices[15] = 1, vertices[16] = 1, vertices[17] = 3;
    vertices[18] = 1, vertices[19] = 0, vertices[20] = 1;
    vertices[21] = 1, vertices[22] = 1, vertices[23] = 1;
    
    
    // Face 3
    vertices[24] = 0; vertices[25] = 1; vertices[26] = 3;
    vertices[27] = 1; vertices[28] = 1; vertices[29] = 3;
    vertices[30] = 0; vertices[31] = 1; vertices[32] = 1;
    vertices[33] = 1; vertices[34] = 1; vertices[35] = 1;
    
    // Face 4
    vertices[36] = 0; vertices[37] = 0; vertices[38] = 3;
    vertices[39] = 0; vertices[40] = 1; vertices[41] = 3;
    vertices[42] = 0; vertices[43] = 1; vertices[44] = 1;
    vertices[45] = 0; vertices[46] = 0; vertices[47] = 1;
    
    // Face 5
    vertices[48] = 0; vertices[49] = 0; vertices[50] = 3;
    vertices[51] = 1; vertices[52] = 0; vertices[53] = 3;
    vertices[54] = 0; vertices[55] = 0; vertices[56] = 1;
    vertices[57] = 1; vertices[58] = 0; vertices[59] = 1;
    
    // Face 6.1
    vertices[60] = 0; vertices[61] = 1; vertices[62] = 1; // top right
    vertices[69] = 0; vertices[70] = 2; vertices[71] = 1;
    vertices[63] = 1; vertices[64] = 1; vertices[65] = 1; // top right
    vertices[66] = 1; vertices[67] = 2; vertices[68] = 1;
    
    // Face 6.2
    vertices[69] = 1; vertices[70] = 1; vertices[71] = 1; // top right
    vertices[72] = 1; vertices[73] = 2; vertices[74] = 1; // top right
    vertices[75] = 3; vertices[76] = 1; vertices[77] = 1;
    
    // Face 6.3
    vertices[78] = 1; vertices[79] = 0; vertices[80] = 1; // top right
    vertices[81] = 1; vertices[82] = 1; vertices[83] = 1;
    vertices[84] = 3; vertices[85] = 0; vertices[86] = 1; // top right
    vertices[87] = 3; vertices[88] = 1; vertices[89] = 1;
    
    // Face 7
    vertices[90] = 1; vertices[91] = 2; vertices[92] = 1; // bottom right
    vertices[93] = 1; vertices[94] = 2; vertices[95] = 0; // top right
    vertices[96] = 3; vertices[97] = 1; vertices[98] = 1; // top left
    vertices[99] = 3; vertices[100] = 1; vertices[101] = 0;
    
    // Face 8
    vertices[102] = 0; vertices[103] = 2; vertices[104] = 1; // top right
    vertices[105] = 0; vertices[106] = 2; vertices[107] = 0; // top right
    vertices[108] = 1; vertices[109] = 2; vertices[110] = 1; // top left
    vertices[111] = 1; vertices[112] = 2; vertices[113] = 0; // bottom left
    
    // Face 9
    vertices[114] = 3; vertices[115] = 1; vertices[116] = 1; // bottom right
    vertices[117] = 3; vertices[118] = 0; vertices[119] = 1; // top right
    vertices[120] = 3; vertices[121] = 1; vertices[122] = 0; // top left
    vertices[123] = 3; vertices[124] = 0; vertices[127] = 0; // bottom left
    
    // Face 10.1
    vertices[126] = 0; vertices[127] = 1; vertices[130] = 0; // top right
    vertices[129] = 0; vertices[130] = 2; vertices[131] = 0;
    vertices[132] = 1; vertices[133] = 1; vertices[134] = 0; // top right
    vertices[135] = 1; vertices[136] = 2; vertices[137] = 0;
    
    // Face 10.2
    vertices[138] = 1; vertices[139] = 1; vertices[140] = 0; // top right
    vertices[141] = 1; vertices[142] = 2; vertices[143] = 0; // top right
    vertices[144] = 3; vertices[145] = 1; vertices[146] = 0;
    
    // Face 10.3
    vertices[147] = 1; vertices[148] = 0; vertices[149] = 0; // top right
    vertices[150] = 1; vertices[151] = 1; vertices[152] = 0;
    vertices[153] = 3; vertices[154] = 0; vertices[155] = 0; // top right
    vertices[156] = 3; vertices[157] = 1; vertices[158] = 0;
    
    // Face 11
    vertices[159] = 0; vertices[160] = 0; vertices[161] = 1; // top right
    vertices[162] = 0; vertices[163] = 2; vertices[164] = 1;
    vertices[165] = 0; vertices[166] = 0; vertices[167] = 0; // top right
    vertices[168] = 0; vertices[169] = 2; vertices[170] = 0;
    
    // Face 12
    vertices[171] = 0; vertices[172] = 0; vertices[173] = 0; // top right
    vertices[174] = 0; vertices[175] = 0; vertices[176] = 1;
    vertices[177] = 3; vertices[178] = 0; vertices[179] = 0; // top right
    vertices[180] = 3; vertices[181] = 0; vertices[182] = 1;
    
    glGenVertexArrays(2, &vaoID[0]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object so we can use it
    
    
    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object
    
    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 183 * sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object
    
    
    //Color
     float *colors = new float[183]; // Colors for our vertices
    colors[0] = 0; colors[1] = 0; colors[2] = 1;
    colors[3] = 0; colors[4] = 0; colors[5] = 1;
    colors[6] = 0; colors[7] = 0; colors[8] = 1;
    colors[9] = 0; colors[10] = 0; colors[11] = 1;
    colors[12] = 0; colors[13] = 0; colors[14] = 1;
    colors[15] = 0; colors[16] = 0; colors[17] = 1;
    colors[18] = 0; colors[19] = 0; colors[20] = 1;
    colors[21] = 0; colors[22] = 0; colors[23] = 1;
    colors[24] = 0; colors[25] = 0; colors[26] = 1;
    colors[27] = 0; colors[28] = 0; colors[29] = 1;
    colors[30] = 0; colors[31] = 0; colors[32] = 1;
    colors[33] = 0; colors[34] = 0; colors[35] = 1;
    colors[36] = 0; colors[37] = 0; colors[38] = 1;
    colors[39] = 0; colors[40] = 0; colors[41] = 1;
    colors[42] = 0; colors[43] = 0; colors[44] = 1;
    colors[45] = 0; colors[46] = 0; colors[47] = 1;
    colors[48] = 0; colors[49] = 0; colors[50] = 1;
    colors[51] = 0; colors[52] = 0; colors[53] = 1;
    colors[54] = 0; colors[55] = 0; colors[56] = 1;
    colors[57] = 0; colors[58] = 0; colors[59] = 1;
    colors[60] = 0; colors[61] = 0; colors[62] = 1;
    colors[63] = 0; colors[64] = 0; colors[65] = 1;
    colors[66] = 0; colors[67] = 0; colors[68] = 1;
    colors[69] = 0; colors[70] = 0; colors[71] = 1;
    colors[72] = 0; colors[73] = 0; colors[74] = 1;
    colors[75] = 0; colors[76] = 0; colors[77] = 1;
    colors[78] = 0; colors[79] = 0; colors[80] = 1;
    colors[81] = 0; colors[82] = 0; colors[83] = 1;
    colors[84] = 0; colors[85] = 0; colors[86] = 1;
    colors[87] = 0; colors[88] = 0; colors[89] = 1;
    colors[90] = 0; colors[91] = 0; colors[92] = 1;
    colors[93] = 0; colors[94] = 0; colors[95] = 1;
    colors[96] = 0; colors[97] = 0; colors[98] = 1;
    colors[99] = 0; colors[100] = 0; colors[101] = 1;
    colors[102] = 0; colors[103] = 0; colors[104] = 1;
    colors[105] = 0; colors[106] = 0; colors[107] = 1;
    colors[108] = 0; colors[109] = 0; colors[110] = 1;
    colors[111] = 0; colors[112] = 0; colors[113] = 1;
    colors[114] = 0; colors[115] = 0; colors[116] = 1;
    colors[117] = 0; colors[118] = 0; colors[119] = 1;
    colors[120] = 0; colors[121] = 0; colors[122] = 1;
    colors[123] = 0; colors[124] = 0; colors[125] = 1;
    colors[126] = 0; colors[127] = 0; colors[128] = 1;
    colors[129] = 0; colors[130] = 0; colors[131] = 1;
    colors[132] = 0; colors[133] = 0; colors[134] = 1;
    colors[135] = 0; colors[136] = 0; colors[137] = 1;
    colors[138] = 0; colors[139] = 0; colors[140] = 1;
    colors[141] = 0; colors[142] = 0; colors[143] = 1;
    colors[144] = 0; colors[145] = 0; colors[146] = 1;
    colors[147] = 0; colors[148] = 0; colors[149] = 1;
    colors[150] = 0; colors[151] = 0; colors[152] = 1;
    colors[153] = 0; colors[154] = 0; colors[155] = 1;
    colors[156] = 0; colors[157] = 0; colors[158] = 1;
    colors[159] = 0; colors[160] = 0; colors[161] = 1;
    colors[162] = 0; colors[163] = 0; colors[164] = 1;
    colors[165] = 0; colors[166] = 0; colors[167] = 1;
    colors[168] = 0; colors[169] = 0; colors[170] = 1;
    colors[171] = 0; colors[172] = 0; colors[173] = 1;
    colors[174] = 0; colors[175] = 0; colors[176] = 1;
    colors[177] = 0; colors[178] = 0; colors[179] = 1;
    colors[180] = 0; colors[181] = 0; colors[182] = 1;
    
    
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 183 * sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array
    
    glBindVertexArray(0); // Disable our Vertex Buffer Object


    
    
    return 1;
}

/*!
 ADD YOUR CODE TO CREATE A MODEL USING PRIMITIVES OF YOUR CHOISE TO THIS FUNCTION
 */
unsigned int createMyModel(void)
{
    // use the vertex array object vaoID[1] for this model representation
    float*vertices = new float[270];
    //TODO:
    vaoID[1];
    // Face 1
    // Face 1
    vertices[0] = 0; vertices[1] = 0; vertices[2] = 3;
    vertices[3] = 1, vertices[4] = 0; vertices[5] = 3;
    vertices[6] = 0, vertices[7] = 1; vertices[8] = 3;
    vertices[9] = 0, vertices[10] = 1; vertices[11] = 3;
    vertices[12] = 1, vertices[13] = 1, vertices[14] = 3;
    vertices[15] = 1, vertices[16] = 0, vertices[17] = 3;
    
//    // Face 2
    vertices[18] = 1, vertices[19] = 0, vertices[20] = 3;
    vertices[21] = 1, vertices[22] = 1, vertices[23] = 3;
    vertices[24] = 1, vertices[25] = 0, vertices[26] = 1;
    vertices[27] = 1, vertices[28] = 0, vertices[29] = 1;
    vertices[30] = 1, vertices[31] = 1, vertices[32] = 3;
    vertices[33] = 1, vertices[34] = 1, vertices[35] = 1;
    
    
    // Face 3
    vertices[36] = 0; vertices[37] = 1; vertices[38] = 3;
    vertices[39] = 1; vertices[40] = 1; vertices[41] = 3;
    vertices[42] = 0; vertices[43] = 1; vertices[44] = 1;
    vertices[45] = 1; vertices[46] = 1; vertices[47] = 3;
    vertices[48] = 0; vertices[49] = 1; vertices[50] = 1;
    vertices[51] = 1; vertices[52] = 1; vertices[53] = 1;
    
    // Face 4
    vertices[54] = 0; vertices[55] = 0; vertices[56] = 3;
    vertices[57] = 0; vertices[58] = 1; vertices[59] = 3;
    vertices[60] = 0; vertices[61] = 1; vertices[62] = 1;
    vertices[63] = 0; vertices[64] = 0; vertices[65] = 1;
    vertices[66] = 0; vertices[67] = 1; vertices[68] = 1;
    vertices[69] = 0; vertices[70] = 0; vertices[71] = 3;
    
    // Face 5
    vertices[72] = 0; vertices[73] = 0; vertices[74] = 3;
    vertices[75] = 1; vertices[76] = 0; vertices[77] = 3;
    vertices[78] = 0; vertices[79] = 0; vertices[80] = 1;
    vertices[81] = 1; vertices[82] = 0; vertices[83] = 3;
    vertices[84] = 0; vertices[85] = 0; vertices[86] = 1;
    vertices[87] = 1; vertices[88] = 0; vertices[89] = 1;
    
    // Face 6.1
    vertices[90] = 0; vertices[91] = 1; vertices[92] = 1; // top right
    vertices[93] = 0; vertices[94] = 2; vertices[95] = 1;
    vertices[96] = 1; vertices[97] = 2; vertices[98] = 1; // top right
    vertices[99] = 1; vertices[100] = 1; vertices[101] = 1; // top right
    vertices[102] = 0; vertices[103] = 1; vertices[104] = 1;
    vertices[105] = 1; vertices[106] = 2; vertices[107] = 1;
    
    //Face 6.2
    vertices[108] = 1; vertices[109] = 1; vertices[110] = 1; // top right
    vertices[111] = 1; vertices[112] = 2; vertices[113] = 1; // top right
    vertices[114] = 3; vertices[115] = 1; vertices[116] = 1;

    // Face 6.3
    vertices[117] = 1; vertices[118] = 0; vertices[119] = 1; // top right
    vertices[120] = 1; vertices[121] = 1; vertices[122] = 1;
    vertices[123] = 3; vertices[124] = 1; vertices[125] = 1; // top right
    vertices[126] = 3; vertices[127] = 1; vertices[128] = 1;
    vertices[129] = 1; vertices[130] = 0; vertices[131] = 1;
    vertices[132] = 3; vertices[133] = 0; vertices[134] = 1;
    
    // Face 7
    vertices[135] = 1; vertices[136] = 2; vertices[137] = 1; // bottom right
    vertices[138] = 1; vertices[139] = 2; vertices[140] = 0; // top right
    vertices[141] = 3; vertices[142] = 1; vertices[143] = 1; // top left
    vertices[144] = 3; vertices[145] = 1; vertices[146] = 1;
    vertices[147] = 1; vertices[148] = 2; vertices[149] = 0;
    vertices[150] = 3; vertices[151] = 1; vertices[152] = 0;
    
    // Face 8
    vertices[153] = 0; vertices[154] = 2; vertices[155] = 1; // top right
    vertices[156] = 0; vertices[157] = 2; vertices[158] = 0; // top right
    vertices[159] = 1; vertices[160] = 2; vertices[161] = 1; // top left
    vertices[162] = 0; vertices[163] = 2; vertices[164] = 0; // top right
    vertices[165] = 1; vertices[166] = 2; vertices[167] = 1;
    vertices[168] = 1; vertices[169] = 2; vertices[170] = 0; // bottom left
    
    // Face 9
    vertices[171] = 3; vertices[172] = 1; vertices[173] = 1; // bottom right
    vertices[174] = 3; vertices[175] = 0; vertices[176] = 1; // top right
    vertices[177] = 3; vertices[178] = 1; vertices[179] = 0; // top left
    vertices[180] = 3; vertices[181] = 0; vertices[182] = 1; // top right
    vertices[183] = 3; vertices[184] = 1; vertices[185] = 0;
    vertices[186] = 3; vertices[187] = 0; vertices[188] = 0; // bottom left
    
    // Face 10.1
    vertices[189] = 0; vertices[190] = 0; vertices[191] = 0; // top right
    vertices[192] = 0; vertices[193] = 2; vertices[194] = 0;
    vertices[195] = 1; vertices[196] = 2; vertices[197] = 0; // top right
    vertices[198] = 1; vertices[199] = 0; vertices[200] = 0; // top right
    vertices[201] = 0; vertices[202] = 0; vertices[203] = 0;
    vertices[204] = 1; vertices[205] = 2; vertices[206] = 0;
    
    //Face 10.2
    vertices[207] = 1; vertices[208] = 1; vertices[209] = 0; // top right
    vertices[210] = 1; vertices[211] = 2; vertices[212] = 0; // top right
    vertices[213] = 3; vertices[214] = 1; vertices[215] = 0;
    
    // Face 10.3
    vertices[216] = 1; vertices[217] = 0; vertices[218] = 0; // top right
    vertices[219] = 1; vertices[220] = 1; vertices[221] = 0;
    vertices[222] = 3; vertices[223] = 1; vertices[224] = 0; // top right
    vertices[225] = 3; vertices[226] = 1; vertices[227] = 0;
    vertices[228] = 1; vertices[229] = 0; vertices[230] = 0;
    vertices[231] = 3; vertices[232] = 0; vertices[233] = 0;
    
    // Face 11
    vertices[234] = 0; vertices[235] = 0; vertices[236] = 1; // top right
    vertices[237] = 0; vertices[238] = 2; vertices[239] = 1;
    vertices[240] = 0; vertices[241] = 0; vertices[242] = 0; // top right
    vertices[243] = 0; vertices[244] = 0; vertices[245] = 0;
    vertices[246] = 0; vertices[247] = 2; vertices[248] = 1;
    vertices[249] = 0; vertices[250] = 2; vertices[251] = 0;
    
//    // Face 12
    vertices[252] = 0; vertices[253] = 0; vertices[253] = 0; // top right
    vertices[255] = 0; vertices[256] = 0; vertices[257] = 1;
    vertices[258] = 3; vertices[259] = 0; vertices[260] = 0; // top right
    vertices[261] = 3; vertices[262] = 0; vertices[263] = 0;
    vertices[264] = 0; vertices[265] = 0; vertices[266] = 1;
    vertices[267] = 3; vertices[268] = 0; vertices[269] = 1;
    
    glGenVertexArrays(2, &vaoID[1]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[1]); // Bind our Vertex Array Object so we can use it
    
    
    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object
    
    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 270 * sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object
    
    
    //Color
    float *colors = new float[270]; // Colors for our vertices
    colors[0] = 0; colors[1] = 0; colors[2] = 1;
    colors[3] = 0; colors[4] = 0; colors[5] = 1;
    colors[6] = 0; colors[7] = 0; colors[8] = 1;
    colors[9] = 0; colors[10] = 0; colors[11] = 1;
    colors[12] = 0; colors[13] = 0; colors[14] = 1;
    colors[15] = 0; colors[16] = 0; colors[17] = 1;
    colors[18] = 0; colors[19] = 0; colors[20] = 1;
    colors[21] = 0; colors[22] = 0; colors[23] = 1;
    colors[24] = 0; colors[25] = 0; colors[26] = 1;
    colors[27] = 0; colors[28] = 0; colors[29] = 1;
    colors[30] = 0; colors[31] = 0; colors[32] = 1;
    colors[33] = 0; colors[34] = 0; colors[35] = 1;
    colors[36] = 0; colors[37] = 0; colors[38] = 1;
    colors[39] = 0; colors[40] = 0; colors[41] = 1;
    colors[42] = 0; colors[43] = 0; colors[44] = 1;
    colors[45] = 0; colors[46] = 0; colors[47] = 1;
    colors[48] = 0; colors[49] = 0; colors[50] = 1;
    colors[51] = 0; colors[52] = 0; colors[53] = 1;
    colors[54] = 0; colors[55] = 0; colors[56] = 1;
    colors[57] = 0; colors[58] = 0; colors[59] = 1;
    colors[60] = 0; colors[61] = 0; colors[62] = 1;
    colors[63] = 0; colors[64] = 0; colors[65] = 1;
    colors[66] = 0; colors[67] = 0; colors[68] = 1;
    colors[69] = 0; colors[70] = 0; colors[71] = 1;
    colors[72] = 0; colors[73] = 0; colors[74] = 1;
    colors[75] = 0; colors[76] = 0; colors[77] = 1;
    colors[78] = 0; colors[79] = 0; colors[80] = 1;
    colors[81] = 0; colors[82] = 0; colors[83] = 1;
    colors[84] = 0; colors[85] = 0; colors[86] = 1;
    colors[87] = 0; colors[88] = 0; colors[89] = 1;
    colors[90] = 0; colors[91] = 0; colors[92] = 1;
    colors[93] = 0; colors[94] = 0; colors[95] = 1;
    colors[96] = 0; colors[97] = 0; colors[98] = 1;
    colors[99] = 0; colors[100] = 0; colors[101] = 1;
    colors[102] = 0; colors[103] = 0; colors[104] = 1;
    colors[105] = 0; colors[106] = 0; colors[107] = 1;
    colors[108] = 0; colors[109] = 0; colors[110] = 1;
    colors[111] = 0; colors[112] = 0; colors[113] = 1;
    colors[114] = 0; colors[115] = 0; colors[116] = 1;
    colors[117] = 0; colors[118] = 0; colors[119] = 1;
    colors[120] = 0; colors[121] = 0; colors[122] = 1;
    colors[123] = 0; colors[124] = 0; colors[125] = 1;
    colors[126] = 0; colors[127] = 0; colors[128] = 1;
    colors[129] = 0; colors[130] = 0; colors[131] = 1;
    colors[132] = 0; colors[133] = 0; colors[134] = 1;
    colors[135] = 0; colors[136] = 0; colors[137] = 1;
    colors[138] = 0; colors[139] = 0; colors[140] = 1;
    colors[141] = 0; colors[142] = 0; colors[143] = 1;
    colors[144] = 0; colors[145] = 0; colors[146] = 1;
    colors[147] = 0; colors[148] = 0; colors[149] = 1;
    colors[150] = 0; colors[151] = 0; colors[152] = 1;
    colors[153] = 0; colors[154] = 0; colors[155] = 1;
    colors[156] = 0; colors[157] = 0; colors[158] = 1;
    colors[159] = 0; colors[160] = 0; colors[161] = 1;
    colors[162] = 0; colors[163] = 0; colors[164] = 1;
    colors[165] = 0; colors[166] = 0; colors[167] = 1;
    colors[168] = 0; colors[169] = 0; colors[170] = 1;
    colors[171] = 0; colors[172] = 0; colors[173] = 1;
    colors[174] = 0; colors[175] = 0; colors[176] = 1;
    colors[177] = 0; colors[178] = 0; colors[179] = 1;
    colors[180] = 0; colors[181] = 0; colors[182] = 1;
    colors[183] = 0; colors[184] = 0; colors[185] = 1;
    colors[186] = 0; colors[187] = 0; colors[188] = 1;
    colors[189] = 0; colors[190] = 0; colors[191] = 1;
    colors[192] = 0; colors[193] = 0; colors[194] = 1;
    colors[195] = 0; colors[196] = 0; colors[197] = 1;
    colors[198] = 0; colors[199] = 0; colors[200] = 1;
    colors[201] = 0; colors[202] = 0; colors[203] = 1;
    colors[204] = 0; colors[205] = 0; colors[206] = 1;
    colors[207] = 0; colors[208] = 0; colors[209] = 1;
    colors[210] = 0; colors[211] = 0; colors[212] = 1;
    colors[213] = 0; colors[214] = 0; colors[215] = 1;
    colors[216] = 0; colors[217] = 0; colors[218] = 1;
    colors[219] = 0; colors[220] = 0; colors[221] = 1;
    colors[222] = 0; colors[223] = 0; colors[224] = 1;
    colors[225] = 0; colors[226] = 0; colors[227] = 1;
    colors[228] = 0; colors[229] = 0; colors[230] = 1;
    colors[231] = 0; colors[232] = 0; colors[233] = 1;
    colors[234] = 0; colors[235] = 0; colors[236] = 1;
    colors[237] = 0; colors[238] = 0; colors[239] = 1;
    colors[240] = 0; colors[241] = 0; colors[242] = 1;
    colors[243] = 0; colors[244] = 0; colors[245] = 1;
    colors[246] = 0; colors[247] = 0; colors[248] = 1;
    colors[249] = 0; colors[250] = 0; colors[251] = 1;
    colors[252] = 0; colors[253] = 0; colors[254] = 1;
    colors[255] = 0; colors[256] = 0; colors[257] = 1;
    colors[258] = 0; colors[259] = 0; colors[260] = 1;
    colors[261] = 0; colors[262] = 0; colors[263] = 1;
    colors[264] = 0; colors[265] = 0; colors[266] = 1;
    colors[267] = 0; colors[268] = 0; colors[269] = 1;
    
    
    
    
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 270 * sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array
    
    glBindVertexArray(0); // Disable our Vertex Buffer Object
    
    
    
    
    return 1;

}



/*!
 ADD YOUR CODE TO RENDER THE TRIANGLE STRIP MODEL TO THIS FUNCTION
 */
void renderTriangleStripModel(void)
{
    // Bind the buffer and switch it to an active buffer
    glBindVertexArray(vaoID[0]);
    
    // Draw the triangles
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 61);
    // Unbind our Vertex Array Object
    glBindVertexArray(0);

    
}

/*!
 ADD YOUR CODE TO RENDER YOUR MODEL TO THIS FUNCTION
 */
void renderMyModel(void)
{
    // Bind the buffer and switch it to an active buffer
    glBindVertexArray(vaoID[1]);
    
    // Draw the triangles
    glDrawArrays(GL_TRIANGLES, 0, 90);
    // Unbind our Vertex Array Object
    glBindVertexArray(0);


    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*!
 This function creates the two models
 */
void setupScene(void) {
    
    createTriangleStripModel();
    createMyModel();
    
}


/*!
 This function updates the virtual camera
 */
bool updateCamera()
{
    // Compute the MVP matrix from keyboard and mouse input
    computeMatricesFromInputs();
    viewMatrix =  getViewMatrix(); // get the current view matrix
    
    return true;
}





int main(int argc, const char * argv[])
{
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Init glfw, create a window, and init glew
    
    // Init the GLFW Window
    window = initWindow();
    
    
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
    /// IGNORE THE NEXT PART OF THIS CODE
    /// IGNORE THE NEXT PART OF THIS CODE
    // It controls the virtual camera
    
    // Set up our green background color
    static const GLfloat clear_color[] = { 0.6f, 0.7f, 1.0f, 1.0f };
    static const GLfloat clear_depth[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
    
    projectionMatrix = glm::perspective(1.1f, (float)800 / (float)600, 0.1f, 100.f);
    modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)); // Create our model matrix which will halve the size of our model
    viewMatrix = glm::lookAt(glm::vec3(1.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    
    int projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix"); // Get the location of our projection matrix in the shader
    int viewMatrixLocation = glGetUniformLocation(program, "viewMatrix"); // Get the location of our view matrix in the shader
    int modelMatrixLocation = glGetUniformLocation(program, "modelMatrix"); // Get the location of our model matrix in the shader
    
    
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]); // Send our projection matrix to the shader
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader
    
    
    glBindAttribLocation(program, 0, "in_Position");
    glBindAttribLocation(program, 1, "in_Color");
    
    //// The Shader Program ends here
    //// START TO READ AGAIN
    //// START TO READ AGAIN
    //// START TO READ AGAIN
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    // this creates the scene
    setupScene();
    
    
    

    // Enable depth test
    // ignore this line, it allows us to keep the distance value after we proejct each object to a 2d canvas.
    glEnable(GL_DEPTH_TEST);
    
    // This is our render loop. As long as our window remains open (ESC is not pressed), we'll continue to render things.
    while(!glfwWindowShouldClose(window))
    {
        
        // Clear the entire buffer with our green color (sets the background to be green).
        glClearBufferfv(GL_COLOR , 0, clear_color);
        glClearBufferfv(GL_DEPTH , 0, clear_depth);
        
        
        // update the virtual camera
        // ignore this line since we did not introduced cameras.
        updateCamera();
        
        
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //// This generate the object
        // Enable the shader program
        glUseProgram(program);
        
        // this changes the camera location
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // send the view matrix to our shader
        
        // This moves the model to the right
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader
        
        renderTriangleStripModel();
        

        
        
        // This moves the model to the left
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-2.0f, -0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader
    
        renderMyModel();
        
        
        glUseProgram(0);
        //// This generate the object
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
        // Swap the buffers so that what we drew will appear on the screen.
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    
    // Program clean up when the window gets closed.
    glDeleteVertexArrays(2, vaoID);
    glDeleteProgram(program);
}

