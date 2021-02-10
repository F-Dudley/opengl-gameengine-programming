#pragma once

#include <iostream>
#include <GL\glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include "GameObject.h"
#include "Utils.h"



class TriangleRenderer {
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

		GLuint _vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* _p_V_ShaderCode[] = {
			"#version 140\n"
			"in vec2 vertexPos2D;\n"
			"void main() {\n"
			"gl_Position = vec4(vertexPos2D.x, vertexPos2D.y, 0, 1);\n"
			"}\n"
		};

		glShaderSource(_vertexShader, 1, _p_V_ShaderCode, NULL);

		glCompileShader(_vertexShader);

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

		vertexPos2DLocation = glGetAttribLocation(programID, "vertesPos2D");

		if (vertexPos2DLocation == -1) {
			std::cerr << "Problem getting vertex2DPos" << std::endl;

			return false;
		}

		glGenBuffers(1, &vboTriangle);
		glBindBuffer(GL_ARRAY_BUFFER, vboTriangle);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		
		return true;
	}

	void processInput() {

	}

	void update() {

	}

	void draw() {
		glUseProgram(programID);

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