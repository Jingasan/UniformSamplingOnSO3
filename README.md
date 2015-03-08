# UniformSamplingOnSO3


３次元の回転 SO(3) を均等にサンプリングするプログラムである。

詳細は、2009 年発刊論文「 Generating Uniform Incremental Grids on SO(3) Using the Hopf Fibration 」を参照。

本プログラムのベース解像度におけるサンプリング数は 72 点であり、解像度レベルが 1 段階上がるごとに、そのサンプリング点数は 8 倍で増えていく。すなわち、解像度レベル n でのサンプリング数は、72 の 8n 乗点である。

プログラムのビルドは、付属のCMakeLists.txtを用い、CMakeを用いて行うと非常にラクである。

プログラムの実行方法は、コマンド引数にて、解像度レベルを指定するだけである。

例: 解像度レベル  0  の場合

コマンド引数  →  0

※ 指定する解像度レベルは、6  くらいまでがメモリの容量的にも限界だろう。

※ ただし、解像度レベル  6 は約1°おきくらいの密なサンプリング結果である。

プログラムを実行すると、「 UniformSamplingSO3 」というディレクトリが自動的に作成され、その中に結果となる均等にサンプリングされた回転行列パラメータを格納したテキストファイルと、その回転行列が次の解像度レベルにおいて対応する回転行列の ID 8つ を格納したテキストファイルが計 72 の 8n 乗個分出力される。
