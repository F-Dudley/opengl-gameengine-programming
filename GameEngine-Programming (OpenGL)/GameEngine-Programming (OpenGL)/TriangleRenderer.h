#pragma once

#include <glm/gtc/type_ptr.hpp>

#include "Camera.h"
#include "GameObject.h"
#include "Utils.h"

class TriangleRenderer : public GameObject {
public:

private:
	GLuint programID;

	GLint vertexPos2DLocation;

	GLuint vboTriangle;


public:
	TriangleRenderer() {
		
	}

	virtual ~TriangleRenderer() {

	}

	bool init() {
		GLfloat vertexData[] = {
			-1.0f, 0.0f,
			1.0f, 0.0f,
			0.0f, 1.0f
		};

		// Creating the Vertex Shader.
		GLuint _vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Shader Code
		const GLchar* _p_V_ShaderCode[] = {
			"#version 140\n"
			"in vec2 vertexPos2D\n"
			"uniform mat4 transform;\n"
			"uniform mat4 view;\n"
			"uniform mat4 projection;\n"
			"void main() {\n"
			"vec4 v4 = vec4(vertexPos2D.x, vertexPos2D.y, 0, 1);\n"
			"gl_Position = v4;\n"
			"}\n"
		};

		// Copying Shader Source to OpenGL.
		glShaderSource(_vertexShader, 1, _p_V_ShaderCode, NULL);

		// Compiling Shader.
		glCompileShader(_vertexShader);

		// Check for Shader Compile Errors.
		GLint _isShaderCompiledOK = GL_FALSE;

		glGetShaderiv(_vertexShader, GL_COMPILE_STATUS, &_isShaderCompiledOK);
		if (_isShaderCompiledOK != GL_TRUE) {
			std::cerr << "Unable to Compile Vertex Shader" << std::endl;

			Utils::displayShaderError(_vertexShader);

			return false;
		}

		GLuint _fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		const GLchar* _p_F_ShaderCode[] = {
			"#version 140\n"
			"out vec4 fragmentColour;\n"
			"void main()\n"
			"{ fragmentColour = vec4(1.0, 0.0, 0.0, 1.0); }\n"

		};

		glShaderSource(_fragmentShader, 1, _p_F_ShaderCode, NULL);

		glCompileShader(_fragmentShader);

		_isShaderCompiledOK = GL_FALSE;
		glGetShaderiv(_fragmentShader, GL_COMPILE_STATUS, &_isShaderCompiledOK);

		if (_isShaderCompiledOK != GL_TRUE) {
			std::cerr << "Unable to Compile Fragment Shader" << std::endl;

			Utils::displayShaderError(_fragmentShader);

			return false;
		}

		programID = glCreateProgram();

		glAttachShader(programID, _vertexShader);
		glAttachShader(programID, _fragmentShader);

		glLinkProgram(programID);

		GLint _isProgramLinked = GL_FALSE;

		glGetProgramiv(programID, GL_LINK_STATUS, &_isProgramLinked);
		if (_isProgramLinked != GL_TRUE) {
			std::cerr << "Failed to Link Program" << std::endl;

			return false;
		}

		vertexPos2DLocation = glGetAttribLocation(programID, "vertexPos2D");
		if (vertexPos2DLocation == -1) {
			std::cerr << "Problem getting vertex2DPos" << std::endl;

			return false;
		}

		transformUniformId = glGetUniformLocation(programID, "transform");
		viewUniformId = glGetUniformLocation(programID, "view");
		projectionUniformId = glGetUniformLocation(programID, "projection");

		glGenBuffers(1, &vboTriangle);
		glBindBuffer(GL_ARRAY_BUFFER, vboTriangle);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		
		return true;
	}

	void processInput() {

	}

	void update() {
		transformationMatrix = glm::mat4(1.0f);

		transformationMatrix = glm::translate(transformationMatrix, position);
		transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		transformationMatrix = glm::scale(transformationMatrix, scale);
	}

	void draw(Camera *_p_camera) {
		glUseProgram(programID);

		glUniformMatrix4fv(transformUniformId, 1, GL_FALSE, glm::value_ptr(transformationMatrix));
		glUniformMatrix4fv(viewUniformId, 1, GL_FALSE, glm::value_ptr(_p_camera->getViewMatrix()));
		glUniformMatrix4fv(projectionUniformId, 1, GL_FALSE, glm::value_ptr(_p_camera->getProjectionMatrix()));

		glVertexAttribPointer(vertexPos2DLocation, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), nullptr);

		glEnableVertexAttribArray(vertexPos2DLocation);

		glBindBuffer(GL_ARRAY_BUFFER, vboTriangle);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(vertexPos2DLocation);

		glUseProgram(0);
	}

	void clean() {
		glDeleteProgram(programID);

		glDeleteBuffers(1, &vboTriangle);
	}

private:

};