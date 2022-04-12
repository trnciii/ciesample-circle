## 準備
本章はもとの授業資料の第一回 **２次元図形を描く--線・円--** の後半に対応します。<br>
[このリポジトリ](https://github.com/trnciii/ciesample-circle)からファイルをダウンロード, 解凍したら`sample.xcodeproj` を開き、実行できるか確認してください。

## 目次
* [プログラムの解説](#プログラムの解説)
* [課題](#課題)

## プログラムの解説
円を描いている部分はdisplay関数内にあります。<br>
```cpp
void display(void)
	{
		float x1,y1,x2,y2;      //２点の座標

		float th1,th2;          //角度（度）

		float th1_rad, th2_rad; //角度（ラジアン）

		float hankei = 0.7f;    //半径

		// th1 が一周する
		for (th1 = 0.0;  th1 <= 360.0;  th1 = th1 + 10.0)
		{
			th2 = th1 + 10.0; // th1 のすすみ文
			
			// ラジアンに変換
			th1_rad = th1 / 180.0 * 3.1415926;  
			th2_rad = th2 / 180.0 * 3.1415926; 

			// x-y 座標を求める
			x1 = hankei * cos(th1_rad);
			y1 = hankei * sin(th1_rad);
			x2 = hankei * cos(th2_rad);
			y2 = hankei * sin(th2_rad);

			// 直線をひく
			glBegin(GL_LINES);          
			glVertex2f( x1, y1 );      
			glVertex2f( x2, y2 );
			glEnd();                         
		}
	}
```
このプログラムでは、短い直線をつないでいくことで円を描いています。x-y 座標上で、半径r の円は 
<img src="https://render.githubusercontent.com/render/math?math=x^{2}%2By^{2} = r^{2}">
ですが、これは極座標ではrが定数であり、θ は全領域 (なので実質
<img src="https://render.githubusercontent.com/render/math?math=\theta\in[0, 2\pi]">) を走るという条件になります。
このプログラムでは、θを少しずつ変化させながら次の関係を用いてx, y 座標を割り出し、 それらの点をつないでいっています。

直交座標と極座標の変換: 
<img src="https://render.githubusercontent.com/render/math?math=x=rcos\theta">, 
<img src="https://render.githubusercontent.com/render/math?math=y=rsin\theta">


円の一部となる短い一本の直線を引くために、片端の角度`th1`と、その10度先の角度`th2`という変数を用います。for文の中では`th1`が0 ~ 360度まで動き、円を一周します。これらの極座標値からさっきの関係式を用いて2点(x1, y1), (x2, y2)を求め、最後に`glVertex2f`で直線を引いています。

最後に、注意点が2つあります。

* 数学関数の `sin`, `cos` に渡す値の単位はラジアンである
* それぞれの直線が繋がるためには、`th1`の進みと同じだけ`th2`をずらす必要がある (ここでは10度)

後者は、`th2`は一つ隣の`th1`と同じになると言い換えることもできます。


## 課題
円を描くプログラムを変更して、 下図のような図形を作って下さい。

<img src="http://www.design.kyushu-u.ac.jp/~rtsuruno/lectures/cie2022/img/lines/daen.jpg" width="400">
<img src="http://www.design.kyushu-u.ac.jp/~rtsuruno/lectures/cie2022/img/lines/housya.jpg" width="400">
<img src="http://www.design.kyushu-u.ac.jp/~rtsuruno/lectures/cie2022/img/lines/spiral1.jpg" width="400">
<img src="http://www.design.kyushu-u.ac.jp/~rtsuruno/lectures/cie2022/img/lines/spiral2.jpg" width="400">
<img src="http://www.design.kyushu-u.ac.jp/~rtsuruno/lectures/cie2022/img/lines/taikaku_1.jpg" width="400">
<img src="http://www.design.kyushu-u.ac.jp/~rtsuruno/lectures/cie2022/img/lines/taikaku_2.jpg" width="400">
<img src="http://www.design.kyushu-u.ac.jp/~rtsuruno/lectures/cie2022/img/lines/doublecircle.gif" width="400">
<img src="http://www.design.kyushu-u.ac.jp/~rtsuruno/lectures/cie2022/img/lines/linecircle.gif" width="400">

最後に、よろしければslack のほうに完成した画像をアップしてください。
