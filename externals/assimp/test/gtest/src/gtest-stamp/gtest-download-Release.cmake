

set(command "C:/Program Files/CMake/bin/cmake.exe;-P;D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/tmp/gtest-gitclone.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/src/gtest-stamp/gtest-download-out.log"
  ERROR_FILE "D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/src/gtest-stamp/gtest-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/src/gtest-stamp/gtest-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "gtest download command succeeded.  See also D:/my_projects/opengl_sandbox/externals/assimp/test/gtest/src/gtest-stamp/gtest-download-*.log")
  message(STATUS "${msg}")
endif()
