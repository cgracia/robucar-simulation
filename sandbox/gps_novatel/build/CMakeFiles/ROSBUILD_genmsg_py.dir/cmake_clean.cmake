FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/gps_novatel/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/gps_novatel/msg/__init__.py"
  "../src/gps_novatel/msg/_NovatelInfo.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
