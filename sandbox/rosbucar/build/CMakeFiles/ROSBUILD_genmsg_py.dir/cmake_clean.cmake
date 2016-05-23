FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/rosbucar/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/rosbucar/msg/__init__.py"
  "../src/rosbucar/msg/_CarLikeInfo.py"
  "../src/rosbucar/msg/_DriveCmd.py"
  "../src/rosbucar/msg/_CarLikeCmd.py"
  "../src/rosbucar/msg/_DriveInfo.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
