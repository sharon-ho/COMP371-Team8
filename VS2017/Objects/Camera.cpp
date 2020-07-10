#include "Camera.h"
#include <iostream>

Camera::Camera(GLFWwindow* window)
{
	this->window = window;
	
	this->cameraPos = glm::vec3(0.0f, 0.5f, 3.0f);
	this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->cameraX = glm::vec3(1.0f, 0.0f, 0.0f);
	this->cameraDirection = glm::vec3(0.0f, 0.0f, .0f);

	
	this->pan = -90.0f;
	this->tilt = -9.48f;
	this->fov = 45.0f;

<<<<<<< HEAD:VS2017/Objects/Camera.cpp
	this->lastX = 512.0f;
	this->lastY = 384.0f;
=======
	this->xzPosition = 90.0f;
	this->yzPosition = 9.48f;

	this->lastX = 400.0f;
	this->lastY = 300.0f;
>>>>>>> added most changes to world orientation, edge case to be fixed:VS2017/Camera.cpp
	
	this->lastFrameTime = glfwGetTime();
}

void Camera::handleFrameData()
{
	this->dt = glfwGetTime() - this->lastFrameTime;
	this->lastFrameTime += this->dt;
	this->cameraSpeed = 2.5f * this->dt;
}

void Camera::handleKeyboardInputs()
{
	// Close the window
	if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(this->window, true);
<<<<<<< HEAD:VS2017/Objects/Camera.cpp
	
	// Home button
	if (glfwGetKey(this->window, GLFW_KEY_0) == GLFW_PRESS)
	{
		this->cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	}

	// forward, backward, left and right
	if (glfwGetKey(this->window, GLFW_KEY_UP) == GLFW_PRESS)
=======


	// World rotation
	if (glfwGetKey(this->window, GLFW_KEY_F) == GLFW_PRESS)
>>>>>>> added most changes to world orientation, edge case to be fixed:VS2017/Camera.cpp
	{
		this->cameraDirection = glm::vec3(0.0f, 0.0f, .0f);
		// rotate left
		this->xzPosition -= this->cameraPanSpeed;
		this->pan -= this->cameraPanSpeed;
		
		glm::vec3 zeroVector(0, 0 ,0);
		float radius = glm::distance<3, float, glm::qualifier::highp>(this->cameraPos, zeroVector);

		std::cout << "xzPosition: " << this->xzPosition << std::endl;
		std::cout << "pan: " << this->pan << std::endl;
		
		this->cameraPos.x = cos(glm::radians(this->xzPosition)) * cos(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
		this->cameraPos.y = sin(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
		this->cameraPos.z = (sin(glm::radians(this->xzPosition))) * cos(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
	}

	if (glfwGetKey(this->window, GLFW_KEY_H) == GLFW_PRESS)
	{
		this->cameraDirection = glm::vec3(0.0f, 0.0f, .0f);
		// rotate right
		this->xzPosition += this->cameraPanSpeed;
		this->pan += this->cameraPanSpeed;

		glm::vec3 zeroVector(0, 0, 0);
		float radius = glm::distance<3, float, glm::qualifier::highp>(this->cameraPos, zeroVector);

		std::cout << "xzPosition: " << this->xzPosition << std::endl;
		std::cout << "pan: " << this->pan << std::endl;

		this->cameraPos.x = cos(glm::radians(this->xzPosition)) * cos(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
		this->cameraPos.y = sin(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
		this->cameraPos.z = (sin(glm::radians(this->xzPosition))) * cos(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
	}

	if (glfwGetKey(this->window, GLFW_KEY_T) == GLFW_PRESS)
	{
		this->cameraDirection = glm::vec3(0.0f, 0.0f, .0f);
		// rotate up
		this->yzPosition += this->cameraPanSpeed;
		
		this->tilt -= this->cameraPanSpeed;
			if (this->tilt > 89.0f) {
				this->tilt = 89.0f;
			}
			if (this->tilt < -89.0f) {
				this->tilt = -89.0f;
			}

		glm::vec3 zeroVector(0, 0, 0);
		float radius = glm::distance<3, float, glm::qualifier::highp>(this->cameraPos, zeroVector);

		std::cout << "yzPosition: " << this->yzPosition << std::endl;
		std::cout << "tilt: " << this->tilt << std::endl;

		this->cameraPos.x = cos(glm::radians(this->xzPosition)) * cos(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
		this->cameraPos.y = sin(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
		this->cameraPos.z = (sin(glm::radians(this->xzPosition))) * cos(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
	}

	if (glfwGetKey(this->window, GLFW_KEY_G) == GLFW_PRESS)
	{
		this->cameraDirection = glm::vec3(0.0f, 0.0f, .0f);
		// rotate down
		this->yzPosition -= this->cameraPanSpeed;
			if (this->yzPosition > 89.0f) {
				this->yzPosition = 89.0f;
			}
			if (this->yzPosition < -89.0f) {
				this->yzPosition = -89.0f;
			}
		
		this->tilt += this->cameraPanSpeed;
			if (this->tilt > 89.0f) {
				this->tilt = 89.0f;
			}
			if (this->tilt < -89.0f) {
				this->tilt = -89.0f;
			}

		glm::vec3 zeroVector(0, 0, 0);
		float radius = glm::distance<3, float, glm::qualifier::highp>(this->cameraPos, zeroVector);

<<<<<<< HEAD:VS2017/Objects/Camera.cpp
	// Up and down
	if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		//this->cameraPos -= glm::normalize(glm::cross(this->cameraFront, this->cameraX)) * this->cameraSpeed;
		//this->cameraPos += this->cameraUp;
=======
		std::cout << "yzPosition: " << this->yzPosition << std::endl;
		std::cout << "tilt: " << this->tilt << std::endl;

		this->cameraPos.x = cos(glm::radians(this->xzPosition)) * cos(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
		this->cameraPos.y = sin(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
		this->cameraPos.z = (sin(glm::radians(this->xzPosition))) * cos(glm::radians(this->yzPosition)) * this->distanceFromWorldOrigin;
>>>>>>> added most changes to world orientation, edge case to be fixed:VS2017/Camera.cpp
	}

	if (glfwGetKey(this->window, GLFW_KEY_P) == GLFW_PRESS)
	{
		this->cameraPos -= this->cameraSpeed * this->cameraFront;
	}

	// 5 degrees left and right
	if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS)
	{
		this->pan -= this->cameraPanSpeed;
		this->xzPosition -= this->cameraPanSpeed;
		glm::vec3 front;
		front.x = cos(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		front.y = sin(glm::radians(this->tilt));
		front.z = sin(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		
		this->cameraFront = glm::normalize(front);
		this->cameraDirection = this-> cameraPos + this->cameraFront;

		std::cout << "pan: " << this->pan << std::endl;
		std::cout << "xzPosition: " << this->xzPosition << std::endl;
	}

	if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS)
	{
		this->pan += this->cameraPanSpeed;
		this->xzPosition += this->cameraPanSpeed;

		glm::vec3 front;
		front.x = cos(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		front.y = sin(glm::radians(this->tilt));
		front.z = sin(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		this->cameraFront = glm::normalize(front);
		this->cameraDirection = this->cameraPos + this->cameraFront;


		std::cout << "pan: " << this->pan << std::endl;
		std::cout << "xzPosition: " << this->xzPosition << std::endl;
	}

	// 5 degrees top and down
	if (glfwGetKey(this->window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		this->tilt += this->cameraPanSpeed;
			if (this->tilt > 89.0f) {
				this->tilt = 89.0f;
			}
			if (this->tilt < -89.0f) {
				this->tilt = -89.0f;
			}
		
		this->yzPosition += this->cameraPanSpeed;
			if (this->yzPosition > 89.0f) {
				this->yzPosition = 89.0f;
			}
			if (this->yzPosition < -89.0f) {
				this->yzPosition = -89.0f;
			}
		glm::vec3 front;
		front.x = -cos(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		front.y = -sin(glm::radians(this->tilt));
		front.z = -sin(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		this->cameraFront = glm::normalize(front);
		this->cameraDirection = this->cameraPos - this->cameraFront;

		std::cout << "tilt: " << this->tilt << std::endl;
		std::cout << "yzPosition: " << this->yzPosition << std::endl;
	}

	if (glfwGetKey(this->window, GLFW_KEY_Z) == GLFW_PRESS)
	{
		this->tilt -= this->cameraPanSpeed;
			if (this->tilt > 89.0f) {
				this->tilt = 89.0f;
			}
			if (this->tilt < -89.0f) {
				this->tilt = -89.0f;
			}
		
		this->yzPosition -= this->cameraPanSpeed;
			if (this->yzPosition > 89.0f) {
				this->yzPosition = 89.0f;
			}
			if (this->yzPosition < -89.0f) {
				this->yzPosition = -89.0f;
			}
		
		glm::vec3 front;
		front.x = -cos(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		front.y = -sin(glm::radians(this->tilt));
		front.z = -sin(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		this->cameraFront = glm::normalize(front);
		this->cameraDirection = this->cameraPos - this->cameraFront;

		std::cout << "tilt: " << this->tilt << std::endl;
		std::cout << "yzPosition: " << this->yzPosition << std::endl;
	}
}

void Camera::mouseCallbackHandler(GLFWwindow* window, double xpos, double ypos)
{
	// Handle mouse camera panning
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT))
	{
		float xoffset = xpos - this->lastX;
		this->lastX = xpos;
		xoffset *= this->mouseSensitivity;
		this->pan += xoffset;
		this->xzPosition += xoffset;

		glm::vec3 front;
		front.x = cos(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		front.y = sin(glm::radians(this->tilt));
		front.z = sin(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		this->cameraFront = glm::normalize(front);
		this->cameraDirection = this->cameraPos + this->cameraFront;
	}
	// Handle mouse camera tilting
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE))
	{
		float yoffset = ypos - this->lastY;
		this->lastY = ypos;
		yoffset *= this->mouseSensitivity;
		this->tilt += yoffset;
		this->yzPosition += this->cameraPanSpeed;

		if (this->tilt > 89.0f) {
			this->tilt = 89.0f;
		}
		if (this->tilt < -89.0f) {
			this->tilt = -89.0f;
		}

		glm::vec3 front;
		front.x = -cos(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		front.y = -sin(glm::radians(this->tilt));
		front.z = -sin(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		this->cameraFront = glm::normalize(front);
		this->cameraDirection = this->cameraPos - this->cameraFront;
	}
	// Handle mouse zooming
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
	{
		float yoffset = ypos - this->lastY;
		this->lastY = ypos;
		yoffset *= this->mouseSensitivity;
		
		this->fov -= (float)yoffset;
		
		if (fov < 1.0f)
		{
			fov = 1.0f;
		}
		if (fov > 45.0f)
		{
			fov = 45.0f;
		}
	}
}


void Camera::mouseScrollHandler(GLFWwindow* window, double xOffset, double yOffset)
{
	this->fov -= (float)yOffset;
	if (fov < 1.0f)
	{
		fov = 1.0f;
	}
	if (fov > 45.0f)
	{
		fov = 45.0f;
	}
}


