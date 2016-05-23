FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/rosbucar/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/rosbucar/CarLikeInfo.h"
  "../msg_gen/cpp/include/rosbucar/DriveCmd.h"
  "../msg_gen/cpp/include/rosbucar/CarLikeCmd.h"
  "../msg_gen/cpp/include/rosbucar/DriveInfo.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
