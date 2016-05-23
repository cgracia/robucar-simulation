FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/gps_novatel/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/NovatelInfo.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_NovatelInfo.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
