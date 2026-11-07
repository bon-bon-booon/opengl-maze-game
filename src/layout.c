#include "base.h"

//四角形を描画する
void drawSquare(int x1, int x2, int y1, int y2){
    glBegin(GL_POLYGON);//図形を描く
    glVertex2i(x1, y1);  //座標をプロット  
    glVertex2i(x2, y1);  //座標をプロット 
    glVertex2i(x2, y2);  //座標をプロット 
    glVertex2i(x1, y2);  //座標をプロット 
    glEnd();
}

//文字列を表示する
void printStr(int x, int y, char *a){
    glRasterPos2i(x, y);    //座標指定
    for(int i = 0;i < strlen(a);i++){   //一文字ずつ
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, a[i]);    //表示
    }
}

//クリック判定の更新とマウスの座標を格納する
void mouseClick(int a, int x, int y){
    click = a;  //クリック判定の更新
    if(click == 1){
        mouse_x = x;    //x座標を格納
        mouse_y = y;    //y座標を格納
    }
}

//マウスで押された場所の判定
void judgeButton(void){
    if(mouse_y >= lower && mouse_y <= lower + footer){  //ウインドウの下部
        if(mouse_x >= 0 && mouse_x <= 117){ //左側
            MODE = move;    //スタート状態
        }
        if(mouse_x >= 118 && mouse_x <= 235){   //中央
            MODE = pause;   //一時停止状態
        }
        if(mouse_x >= 236 && mouse_x <= 532){   //右側
            initGlobal();   //初期化
        }
    }
}

//背景の色塗りと文字の表示
void printBack(void){
    char a[20];
    glColor3ub(0, 0, 0);//色を設定
    drawSquare(0, 352, 0, upper);   //上部
    drawSquare(0, 352, lower, lower + footer);  //下部
    glColor3ub(255, 255, 255);//色を設定
    printStr(32, lower + footer - 10, "START");     //スタートボタン
    printStr(150, lower + footer - 10, "PAUSE");    //ポーズボタン
    printStr(268, lower + footer - 10, "REPLAY");   //リプレイボタン
    sprintf(a, "SCORE : %04d", score);  //文字列を作成
    printStr(200, 27, a);   //スコアを表示する

    if(MODE == clear){      //クリア時
        sprintf(a, "TIME : %03d", cleartime);   //残り時間を格納
        printStr(130, 59, "CLEAR!!");       //CLEAR!!を表示
    }
    if(MODE == end){        //ゲームオーバー時
        sprintf(a, "TIME : %03d", 0);   //残り時間を格納
        printStr(130, 59, "GAMEOVER!!");       //GAMEOVER!!を表示
    }
    if(MODE == move || MODE == pause){  //プレイ中
        sprintf(a, "TIME : %03d", count);   //残り時間を格納
    }
    printStr(10, 27, a);

    if(MODE == move){   //移動可能時
        if(timelag != 0){
            if(timelag == 21){  //1秒後
                timelag = 0;    //リセット
            }
            else{
                timelag++;  //(21-1)*50ms=1sのラグ
                printStr(130, 59, "OUT!!"); //表示
            }
        }
        revers = 1 - revers;    //反転
    }
    
}
