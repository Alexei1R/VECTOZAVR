#pragma once
#include "Window.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"



Core::Window& window = Core::Window::getInstanse();
			
		


		void Init() {
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			ImGui::StyleColorsDark();
			ImGui_ImplGlfw_InitForOpenGL(window.getGLFWwindow(), true);
			ImGui_ImplOpenGL3_Init("#version 330");
		};

		void NewFramw() {
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
		};
		void ImguiRenderScene() {
			ImGui::Render();
			int display_w, display_h;
			glfwGetFramebufferSize(window.getGLFWwindow(), &display_w, &display_h);
			glViewport(0, 0, display_w, display_h);
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		};
		void ImguiDestroi() {
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		}