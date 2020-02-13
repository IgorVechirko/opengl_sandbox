

set(command "C:/Program Files/CMake/bin/cmake.exe;--build;.;--config;RelWithDebInfo")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/src/gtest-stamp/gtest-build-out.log"
  ERROR_FILE "D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/src/gtest-stamp/gtest-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/src/gtest-stamp/gtest-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "gtest build command succeeded.  See also D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/src/gtest-stamp/gtest-build-*.log")
  message(STATUS "${msg}")
endif()
