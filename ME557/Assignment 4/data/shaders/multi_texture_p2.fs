#version 410 core                                                 

uniform sampler2D texture_background; //this is the texture
uniform sampler2D texture_foreground; //this is the texture

in vec2 pass_TexCoord; //this is the texture coord
in vec4 pass_Color;
out vec4 color;


uniform int texture_blend;

void main(void)                                                   
{
    // This function finds the color component for each texture coordinate.
    vec4 noiseVec0;
    vec2 noiseVec;
    
    noiseVec0 = normalize(texture(texture_foreground,pass_TexCoord));
    
    noiseVec[0] = noiseVec0[1];
    noiseVec[1] = noiseVec0[2];
    

    
    noiseVec = (noiseVec * 1.0 +1) * 1000;
    
    color = texture(texture_background, (pass_TexCoord + noiseVec));
    
//    vec4 tex_color =  texture(texture_background, pass_TexCoord);
//    
//    vec4 tex_color_light =  texture(texture_foreground, pass_TexCoord);
//    
//    if(texture_blend ==0)
//    color = 0.1 * pass_Color + tex_color + tex_color_light;
    
}