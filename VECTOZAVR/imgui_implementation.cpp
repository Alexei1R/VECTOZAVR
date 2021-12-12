#include "imgui_implementation.h"

namespace Core {


	Imgui::Imgui() {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		ImGui::StyleColorsDark();
		
	}
	


	void Imgui::Init() {
		
		ImGui_ImplGlfw_InitForOpenGL(window.getGLFWwindow(), true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	void Imgui::NewFramw() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void Imgui::ImguiRenderScene() {
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window.getGLFWwindow(), &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}


	Imgui::~Imgui() {
		/*ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();*/
	}


}