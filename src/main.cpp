/*------------------------------------------------------------------------------
36本の直線(線分)を円形に並べて、円を描いてみましょう。
それぞれの直線は(x1,y1)と(x2,y2)とを結ぶものとします。
最初にx1,y1,x2,y2 という変数を使うための宣言をします。float x1,y1,x2,y2;

あとは、平行線を引いた時と同じですが、違うのは、
増えていくのがxやyではなく、th1,th2であるということです。

円周上の点(x,y)は、x = 半径×cosθ, y = 半径×sinθ で求められるので、
x1,y1,x2,y2を求めるθの代わりにth1, th2も用意します。
また、cosやsinの関数では、θを度ではなくラジアンで与えなければいけないので、
そのための変数、th1_rad, th2_radも用意します。

三角関数を使うために、行の最初に #include <math.h> を加えます。
---------------------------------------------------------------------------------*/

#define GL_SILENCE_DEPRECATION
#include "GLFW/glfw3.h"
#include <math.h>

//--初期化—------------------------------------------------------------------
void myinit(GLFWwindow** window)
{
    glfwInit();
    *window = glfwCreateWindow(600, 600, "circle", NULL, NULL); // 600*600の大きさで circle という名前のウィンドウをつくる
    glfwMakeContextCurrent(*window);
    glClearColor(0, 0, 0, 1); // 背景色の設定
}


//--再描画--------------------------------------------------------------------
void reshape(GLFWwindow* window, int w, int h)
{
    glViewport( 0, 0, (GLsizei)w, (GLsizei)h ); //ウィンドウ全体をビューポートにする
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f); //視野の指定
}

//--描画内容--------------------------------------------------------------------
void display(void)
{
    float x1,y1,x2,y2;
    float th1,th2;
    float th1_rad, th2_rad;
    float hankei = 0.7f;

    glClear(GL_COLOR_BUFFER_BIT);    //画面全体を背景色で塗りつぶす

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();                //単位行列を行列スタックに読み込む

    glColor3f(1.0f, 1.0f, 1.0f);    //頂点カラーの指定( R, G, B すべてが1.0fなら白)

    for (th1 = 0.0f;  th1 <= 360.0f;  th1 = th1 + 10.0f)
    {
        th2 = th1 + 10.0f;
        th1_rad = th1 / 180.0f * 3.1415926f;  // 「度」を「ラジアン」に直す
        th2_rad = th2 / 180.0f * 3.1415926f;

        x1 = hankei * cos(th1_rad);
        y1 = hankei * sin(th1_rad);
        x2 = hankei * cos(th2_rad);
        y2 = hankei * sin(th2_rad);

        glBegin(GL_LINES);                //glBegin(GL_LINES)とglEnd()の間に
        glVertex2f( x1, y1 );          //描画したい直線の頂点を並べる。
        glVertex2f( x2, y2 );
        glEnd();                            //ここまでで、ひとつのオブジェクトの宣言がおわる
    }
}

//--メイン関数------------------------------------------------------------------
int main(void)
{
    //初期化処理 (ウィンドウサイズや表示位置、タイトル、背景色、...を決める)
    GLFWwindow* window; // ウィンドウの変数をつくる
    myinit(&window); // ウィンドウのポインタを渡して初期化
    
    
    //コールバック関数 (キーボードやマウスの動きを捕まえる)
    glfwSetWindowSizeCallback(window, reshape);
    
    
    //イベント処理ループ
    do{
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }while( !glfwWindowShouldClose(window) );//ウィンドウが表示されるかぎりループする

   glfwTerminate();

    return 0;
}

