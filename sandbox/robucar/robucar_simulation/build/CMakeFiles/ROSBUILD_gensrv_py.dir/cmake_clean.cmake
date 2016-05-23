FILE(REMOVE_RECURSE
  "../srv_gen"
  "../src/robucar_simulation/srv"
  "../srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_py"
  "../src/robucar_simulation/srv/__init__.py"
  "../src/robucar_simulation/srv/_SpeedRequest.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
