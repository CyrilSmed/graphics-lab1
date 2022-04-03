#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>

GLuint VBO;

static void renderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);



    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab 1");

    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glutDisplayFunc(renderSceneCB);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glm::vec3 vecs[6] = {
        {0.3f, 0.3f, 0.0f},
        {0.5f, 0.5f, 0.0f},
        {-0.1f, 0.5f, 0.0f},

        {-0.3f, -0.3f, 0.0f},
        {-0.5f, -0.5f, 0.0f},
        {0.1f, -0.5f, 0.0f}
    };


    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vecs), vecs, GL_STATIC_DRAW);

    glutMainLoop();

    return 0;
}