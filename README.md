# UniformSamplingOnSO3


３次元の回転 SO(3) を均等にサンプリングするプログラムである。

詳細は、2009 年発刊論文「 Generating Uniform Incremental Grids on SO(3) Using the Hopf Fibration 」を参照。

本プログラムのベース解像度におけるサンプリング数は 72 点であり、解像度レベルが 1 段階上がるごとに、そのサンプリング点数は 8 倍で増えていく。すなわち、解像度レベル n でのサンプリング数は、72 ^ 8n 点である。



