add_executable(example example.cpp)

target_link_libraries(example ${FRAMEWORK_NAME} ${LIBRARIES})
add_dependencies(example glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS example DESTINATION .)

add_executable(raytracer raytracer.cpp)

target_link_libraries(raytracer ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
  )
add_dependencies(raytracer glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS raytracer DESTINATION .)

#BuildAufgabe65
#add_executable(aufgabe aufgabe65.cpp)


 #Build tests
#add_executable(tests
#  tests.cpp)
#target_link_libraries(tests
#  ${GLFW_LIBRARIES}
#  )

#Build aufgabe65
add_executable(aufgabe65 aufgabe65.cpp)
target_link_libraries(aufgabe65 ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
  )

#Build RayMoViE
add_executable(raymovie raymovie.cpp)

target_link_libraries(raymovie ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
  )
add_dependencies(raymovie glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

#Build SDFMAKER
add_executable(sdfmaker sdfmaker.cpp)

target_link_libraries(sdfmaker ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
  )
add_dependencies(sdfmaker glfw ${FRAMEWORK_NAME} ${COPY_BINARY})
