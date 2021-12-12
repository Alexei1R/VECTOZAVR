#shader vertex


#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_texCoord;

void main()
{	

	v_texCoord = texCoord;
	//gl_Position = u_projection * u_view * u_model * position;
	gl_Position = position;
};



#shader fragment

#version 330 core

layout(location = 0) out vec4 color;
uniform sampler2D u_Texture;
in vec2 v_texCoord;


uniform vec4 u_color;
void main()
{
	vec4 texColor = texture(u_Texture, v_texCoord);
	color = texColor * u_color;
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
};