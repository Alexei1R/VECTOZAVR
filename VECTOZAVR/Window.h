#pragma once
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include "event.h"

namespace Core {


	class Window final {

	private:
		std::string name;
		int width = 0;
		int height = 0;
		GLFWwindow* window = nullptr;
		std::function<void(Event&)> fnCallback;
	public:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

	private:
		Window(const std::string& name, int width, int height);
	private:
		~Window();
	public:
		static Window& getInstanse() { static Window instanse("Window", 800, 800); return instanse; }
	public:
		void init(const std::string& name, int width, int height);
		__forceinline GLFWwindow* getGLFWwindow() const { return window; }
		void setfnCallback(const std::function<void(Event&)>& fn) { fnCallback = fn; }
	public:
		static void mouseMovedCallback(GLFWwindow* window, double x, double y);
		/*static void mouseScrollCallback(GLFWwindow* window, double x, double y);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void keyCallback(GLFWwindow*, int key, int scancode, int action, int mods);
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
		static void windowCloseCallback(GLFWwindow* window);*/
	};



}
