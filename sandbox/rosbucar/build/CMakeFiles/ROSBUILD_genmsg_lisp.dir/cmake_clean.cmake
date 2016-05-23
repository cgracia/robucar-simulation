FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/rosbucar/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/CarLikeInfo.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_CarLikeInfo.lisp"
  "../msg_gen/lisp/DriveCmd.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_DriveCmd.lisp"
  "../msg_gen/lisp/CarLikeCmd.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_CarLikeCmd.lisp"
  "../msg_gen/lisp/DriveInfo.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_DriveInfo.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
