# Computer Graphics Laboratory work 1
USATU Engineering Graphics univecity cource. <br>
Drawing a triangle, square, dots and a line in OpenGL freeglut environment.<br>
Выполнил студент группы ПРО-227 Кузнецов Кирилл.<br><br>

# Initialization
    glutInit(&argc, argv) - initialize Glut library (OpenGL utility library) and negotiate a session with window system
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA) - set double buffering with a color buffer(drawing occures in the first buffer while second buffer is displayed after which they are swapped)

    GLenum res = glewInit() - initialize Glew librarry, which provides efficient run-time mechanisms for determining which OpenGL extensions are supported on the target platform
    if (res != GLEW_OK) {...} - chech if it was initialized correctly
    glutDisplayFunc(renderSceneCB) - specify user created main rendering loop function
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f) - reset window color to the specified one
    glm::vec3 vecs[6] = {...} - create an array of 2d vertices that will be used to draw shapes

    glGenBuffers(1, &VBO) - specify global GLenum variable that will be used to point to verteces buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO) - specify that buffer will be storing an array of vertices
    glBufferData(GL_ARRAY_BUFFER, sizeof(vecs), vecs, GL_STATIC_DRAW) - fill buffer with our vertex data. Since we won't be changing it, we specify that it will be static with GL_STATIC_DRAW

    glutMainLoop() - call our main rendering loop
    
# Main Rendering Loop
    glClear(GL_COLOR_BUFFER_BIT) - clear buffer
    glEnableVertexAttribArray(0) - allow changing vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0) - set vertex attributes: 0 - attribute index set to default, 3 - coordinate components, GL_FLOAT - float data type for each component, GL_FALSE - we do not want to normalize the components, 0 - position shift step between components (our data is closely packed), the last 0 is just for goofs

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) - selects a polygon rasterization mode, GL_FRONT_AND_BACK is default. GL_LINE will specify that we do not want want to fill our polygons (the opposite of GL_FILL) 

    glDrawArrays(GL_TRIANGLES, 0, 6) - draws what we want, in this case GL_TRIANGLES, it uses more simple sequential drawing, unlike with indexed drawing same vertices cannot be reused without typing them multiple times, which is a waste of memory. 0 - means that we start at the first vertex, 6 - means that we will use 6 vertices 

    glDisableVertexAttribArray(0) - after all that we have to set access to change attributes back to diabled

    glutSwapBuffers() - we swap buffer that we were drawing on with the buffer that we are displaying on the screen
