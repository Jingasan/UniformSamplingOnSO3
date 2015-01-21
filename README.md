# UniformSamplingOnSO3

回転空間SO(3)の均等なサンプリング

３次元の回転SO(3)を均等にサンプリングするプログラムである。

詳細は、2009年発刊論文「 Generating Uniform Incremental Grids on SO(3) Using the Hopf Fibration 」を参照。

本プログラムのベース解像度におけるサンプリング数は72点であり、解像度レベルが1段階上がるごとに、そのサンプリング点数は8倍で増えていく。すなわち、解像度レベルnでのサンプリング数は、72^8n点である。
。


