# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp
  color.cpp
  rectangle.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  tests.cpp
  vec2.cpp
  color.cpp
  circle.cpp
  )

# Build aufgabe_2_und_3
add_executable(aufgabe_2_und_3
  aufgabe_2_und_3.cpp
  vec2.cpp
  circle.cpp
  color.cpp
  )

# Build aufgabe_6
add_executable(aufgabe_6
  aufgabe_6.cpp
  circle.cpp
  vec2.cpp
  color.cpp
  )