## 準備
本章はもとの授業資料の第一回 **２次元図形を描く--線・円--** の後半に対応します。<br>
このプロジェクトをダウンロード, 解凍したら`sample.xcodeproj` を開き、実行できるか確認してください。


## 解説 (windows と共通)
円を描いている部分はdisplay関数内にあります。<br>
解説の内容はwindows と同じですのでもとの資料を読んでください。
```cpp
void display(void)
    {
        float x1,y1,x2,y2;      //２点の座標

        float th1,th2;          //角度（度）

        float th1_rad, th2_rad; //角度（ラジアン）

        float hankei = 0.7f;    //半径

        for (th1 = 0.0;  th1 <= 360.0;  th1 = th1 + 10.0)
        {           
            th2 = th1 + 10.0;
            th1_rad = th1 / 180.0 * 3.1415926;  
            th2_rad = th2 / 180.0 * 3.1415926; 

            x1 = hankei * cos(th1_rad);
            y1 = hankei * sin(th1_rad);
            x2 = hankei * cos(th2_rad);
            y2 = hankei * sin(th2_rad);

            glBegin(GL_LINES);          
            glVertex2f( x1, y1 );      
            glVertex2f( x2, y2 );
            glEnd();                         
        }
    }
```



## 課題 (windows と共通)
windows のほうの資料に従っていろいろな図形を描いてみてください。






