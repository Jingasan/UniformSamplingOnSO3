# 要求される CMake の最低バージョン番号
cmake_minimum_required( VERSION 2.8.9 )
if( COMMAND CMAKE_POLICY )
  cmake_policy( SET CMP0003 NEW )
endif()

# プロジェクトディレクトリ名の設定
project( UniformSamplingOnSO3 )



### UniformSamplingOnSO3 ###

# 生成される実行ファイル名とその元となるソースプログラム名
add_executable( UniformSamplingOnSO3
Code/main.cpp
Code/connectLayeredGrids.cpp
Code/generateRfromQuaternion.cpp
Code/grid_s1.cpp
Code/hopf2quat.cpp
Code/layered_grid.cpp
Code/mk_pix2xy.cpp
Code/nside2npix.cpp
Code/pix2ang_nest.cpp
Code/simple_grid.cpp
Code/Configuration.h
Code/grid_generation.h
)


