#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>
#include <gl\glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include <string>
#include "Shader.h"
#include <imgui.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"


float position[] = {
        -0.5f,-0.5f,-0.25f,     0.0,0.0,  // 0.0f,0.0f,
         0.5f,-0.5f,-0.25f,     1.0,0.0,  // 1.0f,0.0f,
         0.5f, 0.5f,-0.25f,     1.0,1.0,  // 1.0f,1.0f,
        -0.5f, 0.5f,-0.25f,     0.0,1.0,  // 0.0f,1.0f,

         /*0.5f,-0.5f,0.25f,
         0.5f, 0.5f,0.25f,
        -0.5f, 0.5f,0.25f,
        -0.5f,-0.5f,0.25f*/

};
GLuint indices[] = {
    0,1,2,
    0,2,3,

     /*1,4,5,
     1,5,2,

     3,2,5,
     3,5,6,

     4,5,6,
     4,6,7,

     7,6,3,
     7,0,3,

     0,1,4,
     0,4,7*/
};




int main() {

    Core::Window& window = Core::Window::getInstanse();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

    Shader shader("C:/Users/alexe/OneDrive/Desktop/PROIECT/VECTOZAVR/VECTOZAVR/basic.shader");
    shader.Bind();
    shader.SetUniform4f("u_color",0.0,1.0,0.0,1.0);

    VertexArray va;
    VertexBuffer vb(position,sizeof(position));
    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    
    IndexBuffer ib(indices,sizeof(indices)/4);
    ib.Bind();
    Renderer renderer;

    Texture texture("C:/Users/alexe/OneDrive/Desktop/mem.png");
    texture.Bind();
    shader.SetUniform1i("u_Texture",0);
    

    
    while (!glfwWindowShouldClose(window.getGLFWwindow()))
    {
        int display_w, display_h;
        glfwGetFramebufferSize(window.getGLFWwindow(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        renderer.Clear();

        va.Bind();
        ib.Bind();

        
        renderer.Draw(va,ib,shader);
        
        

        
        
        


        glfwSwapBuffers(window.getGLFWwindow());
        glfwPollEvents();
    }


    glfwTerminate();




    return 0;
}

