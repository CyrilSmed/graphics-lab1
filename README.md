# Computer Graphics Laboratory work 1
USATU Engineering Graphics univecity cource. <br>
Drawing a triangle, square, dots and a line in OpenGL freeglut environment.<br>
Выполнил студент группы ПРО-227 Кузнецов Кирилл.<br><br>

# Initialization
    glutInit(&argc, argv) -
    <br><br>
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA) - 
    <br><br>

    GLenum res = glewInit() - 
    <br><br>
    if (res != GLEW_OK) {...} - 
    <br><br>
    glutDisplayFunc(renderSceneCB);
    <br><br>
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    <br><br>
    glm::vec3 vecs[6] = {...} - 
    <br><br>

    glGenBuffers(1, &VBO) - 
    <br><br>
    glBindBuffer(GL_ARRAY_BUFFER, VBO) - 
    <br><br>
    glBufferData(GL_ARRAY_BUFFER, sizeof(vecs), vecs, GL_STATIC_DRAW) - 
    <br><br>

    glutMainLoop() - 
    <br><br>
    
# Main Rendering Loop
    glClear(GL_COLOR_BUFFER_BIT) - 
    <br><br>
    glEnableVertexAttribArray(0) - 
    <br><br>
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0) - 
    <br><br>

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) - 
    <br><br>

    glDrawArrays(GL_TRIANGLES, 0, 6) - 
    <br><br>

    glDisableVertexAttribArray(0) - 
    <br><br>

    glutSwapBuffers() - 
