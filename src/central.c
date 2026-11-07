#include "base.h"

int msecond[3] = {50, 300, 1000};    //割り込み時間
char map2[xnum][ynum + 1] = {
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "BTRBBOOOOOOBBOOOOOOOOOOOOOOOOOOOOBBSOOOOOOOOOOOOOOOOOOOOOOOOB",
    "BOOBBOOOOOOBBOOOOOOOOOOOOOOOOOOOOBBOOOOOOOOOOOOOOOOOOOOOOOOOB",
    "BOOBBOOBBOOBBOOBBOOBBBOOBBBBBBBBBBBBBBBBBBBBBBBBOOBBOOBBBBOOB",
    "BOOBBOOBBOOOOOOBBOOBBBOOBBBBBBBBBBBBBBBBBBBBBBBBOOBBOOBBBBOOB",
    "BOOBBSOBBOOOOOOBBOOBBBOOOOOOOOOOOOOOOOOOOOOOOOOOOOBBOOBBBBOOB",
    "BOOBBBBBBBBBBBBBBOOBBBOOOOOOOOOOOOOOOOOOOOOOOOOOOOBBOOBBBBOOB",
    "BOOBBBBBBBBBBBBBBOOBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBOOBBBBOOB",
    "BOOBBBBBBBBBBBBBBOOBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBOOOOOOOOB",
    "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOBBBBBBBBBBBBOOOOOOOSB",
    "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOBBBBOOOOOOBBBBBBBBBBB",
    "BBBBBOOBBBBBBBBBBBBBBBBBBBBBBBBOOBBBBBBBBBBBSOOOOOBBBBBBBBBBB",
    "BBBBBOOBBBBBBBBBBBBBBBBBBBBBBBBOOBBBBBBBBBBBBBBBOOOOOOOOOOOBB",
    "BOOBBOOBBSOOOOOOOOOOOOOOOOOOOOOOOBBOOOOOOOOBBBBBOOBBBBBBOOOBB",
    "BOOBBOOBBBBBBBBBBBBBBBBBBBBBBBBOOBBOOOOOOOOBBBBBOOBBBBBBOOSBB",
    "BOOOOOOBBBBBBBBBBBBBBBBBBBBBBBBOOBBOOBBBBOOBBBBBOOBBBBBBBBBBB",
    "BOOOOOOBBOOOOOOOOOOOOOOOOOOOOBBOOOOOOBBBBOOOOOOOOOOOOOOOOOOOB",
    "BBBBBOOBBOOOOOOOOOOOOOOOOOOOOBBOOOOOOBBBBOOOOOOOOOOOOOOOOOOOB",
    "BBBBBOOBBOOBBBBBBBBBBBBBBBBOOBBOOBBBBBBBBBBBBBBBBBBBBBBBBBOOB",
    "BSOBBOOBBOOBBBBBBBBBBBBBBBBOOBBOOOOOBBBBBOOOOOOOOOOOOOOBBBOOB",
    "BOOBBOOBBOOBBOOOOOOOOOOOOBBOOBBOOOOOBBBBBOOOOOOOOOOOOOOBBBOOB",
    "BOOBBOOBBOOBBOOOOOOOOOOOOBBOOBBBBBOOBBBBBOOBBBBBBBBBBOOBBBOOB",
    "BOOBBOOBBOOBBOOBBBBBBBBOOBBOOBBBBBOOBBBBBOOBBBSOOOOOOOOBBBOOB",
    "BOOBBOOBBOOBBOOBBOOOOBBOOBBOOBBBBBOOOOOOOOOBBBBBBBBBBOOBBBOOB",
    "BOOBBOOBBOOBBOOBBOOOSBBOOBBOOBBBBBOOOOOOOOOBBBBBOOBBBOOBBBOOB",
    "BOOOOOOOOOOBBOOBBOOBBBBOOBBOOBBBBBBBBOOBBBBBBBBBOOBBBOOOOOOOB",
    "BOOOOOOOOOOBBOOBBOOBBBBOOBBOOBBBBBBBBOOBBBBBBBBBOOBBBOOOOOOOB",
    "BBBBBBBBBOOBBOOBBOOBBBBOOBBOOBOOOOOOBOOBOOOOOOBBOOBBBOOBBBOOB",
    "BBBBBBBBBOOBBOOBBOOOOOOOOBBOOBOOOOOOBOOBOOOOOOBBOOBBBOOBBBOOB",
    "BBBBBBBBBOOBBOOBBOOOOOOOOBBOOBOOBBOOBOOBOOBBOOBBOOBBBOOBBBOOB",
    "BOOOOOOOOOOBBOOBBBBBBBBBBBBOOBOOBBOOBOOBSOBBOOBBOOBBBOOBBBOOB",
    "BOOOOOOOOOOBBOOOOOOOOOOOOOOOOBOOBBBBBOOBBBBBOOBBOOBBBOOBBBOOB",
    "BOOBBBBBBBBBBOOOOOOOOOOOOOOOOBOOBBBBBOOOOOOOOOBBOOOOOOOBBBOOB",
    "BOOBBBBBBBBBBBBBBBBBBBBBBBBBBBOOBBBBBOOOOOOOOOBBOOOOOOOBBBOOB",
    "BOOOOOOOOOOBBBOOOOOOOOOOOOBBBBOOBBBBBOOBBBBBBBBBOOBBBOOBBBOOB",
    "BOOOOOOOOOOBBBOOOOOOOOOOOOBBBBOOBBBBBOOBBBBBBBBBOOBBBOOBBBOOB",
    "BBBBBBBBBOOBBBOOBBBOOBBBOOBBBBOOOOOOOOOOOOOOOOBBOOBBBOOBBBOOB",
    "BBBBBBBBBOOBBBOOBBBOSBBBOOBBBBOOOOOOOOOOOOOOOOBBOOOOOOOBBBOOB",
    "BOOOOOOOOOOBBBOOBBBBBBBBOOBBBBOOBBBBBBBBBBBBOOBBOOOOOOOBBBOOB",
    "BOOOOOOOOOOBBBOOBBBBBBBBOOBBBBOOBOOOOOOOOOOOOOBBOOBBBOOBBBOOB",
    "BOOBBBBBBBBBBBOOOOOOOOOOOOBBBBOOBOBBBBBBBBBBBOBBOOBBBOOBBBOOB",
    "BOOOOOOOOOSBBBOOOOOOOOOOOOBBBBOOBOBBBBOOOOBBBOBBOOBBBOOBBBOOB",
    "BOOBBBBBBBBBBBBBBBBOOBBBBBBBBBOOBOOOOOOBBOOBBOBBOOBBBOOBBBOOB",
    "BOOBBBBBBBBBBBBBBBBOOBBBBBBBBBOOBBBOBBBBBBBBBOBBOOBBBOOBBBOOB",
    "BOOOOOOOOOOOOOOOOOOOOBBBOOOOOOOOBOOOBOOOOOOOOOBBOOBBBOOBBBOOB",
    "BOOOOOOOOOOOOOOOOOOOOBBBOOOOOOOOBOBBBBBBBBBBOBBBOOBBBOOBBBOOB",
    "BBBBBBBOOBBBBBBBBBBBBBBBOOBBBBBBBOOOOOBBBBBBOBBBBBBBBOOBBBBBB",
    "BOOOOSBOOBBBBBBBBBBBBBBBOOBBBBBBBBBBBBBBBSOOOBOOOOOOOOOBBBBBB",
    "BOBBBBBOOBBBSOOOOOOOSBBBBBBBBOOOOOOOOOBBBBBBBBOOOOOOOOOBBBOOB",
    "BOBOOOOOOBBBOOOOOOOOOBBBBBBBBOOBBBBOBBBBBBBBBBOOBBBBBBBBBBOOB",
    "BOOOOOOOOBBBOOOOOOOOOBBBBOOOOOOBBBBOBBOOOOOOBBOOBBOOOOOOOOOOB",
    "BBBBOOBBBBBBSOOOOOOOSBBBBOOOOOOBBBBOBBOOOOOOBBOOBBOOOOOOOOOOB",
    "BBBBOOBBBBBBBBBOOBBBBBBBBOOBBBBBBBBSBBOOBBOOBBSOBBOOBBBBBBOOB",
    "BOOOOOOOOOBBBBBOOBBBBBBBBOOBBBBBBBBBBBOOBBOOBBBBBBOOBBBBBBOOB",
    "BOOOOOOOOOBBBBBOOOOOOOOBBOOBBOOOOOOOOOOOBBOOOOOOOOOOBBOOOOOOB",
    "BOOBBBBBOOBBBBBOOOOOOOOBBOOBBOOOOOOOOOOOBBOOOOOOOOOOBBOOOOOOB",
    "BOOBBBBBOOBBBBBBBBBBBOOBBOOBBOOBBBBBBBBBBBBBBBBBBBOOBBOOBBBBB",
    "BOOBBBBBOOBBBBBBBBBBBOOBBOOBBOOBBBBBBBBBBBBBBBBBBBOOBBOOBBBBB",
    "BOOOOOBBOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOBBOOOOOOOOOOBBOOOOOGB",
    "BOOOOOBBOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOBBOOOOOOOOOOBBOOOOOAB",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};

//main関数
int main(int argc, char **argv){
    srand((unsigned int)time(NULL));

    initGlobal();   //初期化
    glutInit(&argc, argv);
    glutInitWindowSize(352, 352 + upper + footer);
    glutCreateWindow("MAP GAME");
    glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    //画像
    char fname[20];
    const char *image_files[] = {
        "assets/map0.png",
        "assets/item.png",
        "assets/map1.png",
        "assets/enemy0.png",
        "assets/enemy1.png",
        "assets/start0.png",
        "assets/start1.png",
        "assets/goal0.png",
        "assets/goal1.png"
    };
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    for(int i = 0; i < 9; i++){ //背景その他
        img[i] = pngBind(image_files[i], PNG_NOMIPMAP, PNG_ALPHA, 
            &info[i], GL_CLAMP, GL_NEAREST, GL_NEAREST);
    }
    for(int i = 0; i < 8; i++){ //キャラクター
        sprintf(fname, "assets/chara%d.png", i);
        charaimg[i] = pngBind(fname, PNG_NOMIPMAP, PNG_ALPHA, 
            &charainfo[i], GL_CLAMP, GL_NEAREST, GL_NEAREST);
    }

    //コールバック関数
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SpecialKey);

    //  マウス関連のコールバック関数の登録
    glutMouseFunc(Mouse);

    //タイマー設定
    glutTimerFunc(msecond[0], Timer, 0);
    glutTimerFunc(msecond[1], Timer, 1);
    glutTimerFunc(msecond[2], Timer, 2);

    glutMainLoop();

    return(0);
}

//タイマー割り込みを管理する
void Timer(int t){
    if(t == 0){
        glutPostRedisplay();    //画面更新
    }
    if(t == 1){
        if(MODE == move) moveEnemy();   //敵の移動更新
    }
    if(t == 2){
        if(MODE == move) count--;    //タイムリミットの計算
    }
    glutTimerFunc(msecond[t], Timer, t);    //自分自身を呼び出す
}

//通常のキー入力を判定する
void Keyboard(unsigned char key, int x, int y){
    if((key == 'q') || key == 27){  //qキーまたはEscキー
        exit(0);    //終了
    }
    if(key == 8){   //BackSpaceキー
        initGlobal();   //初期化
    }
    if(key == 13){  //Enterキー
        if(MODE == move) MODE = pause;  //スタート
        else if(MODE == pause) MODE = move;     //一時停止
    }
}

//特殊キー入力を判定する
void SpecialKey(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:   //縦軸マイナスの向き
            MOVEH -= moverange(1);  //画面が動く方向と距離を調べる
            chara.h -= images / 4;  //キャラクターが移動する方向と距離
            if(MODE == move) chara.dire = 0;    //画像の切り替え判定(move状態)
            Display();    //画面更新
            break;
        case GLUT_KEY_RIGHT:    //横軸プラスの向き
            MOVEW = moverange(0);  //画面が動く方向と距離を調べる
            chara.w += images / 4;  //キャラクターが移動する方向と距離
            if(MODE == move) chara.dire = 2;    //画像の切り替え判定(move状態)
            Display();    //画面更新
            break;
        case GLUT_KEY_DOWN:     //縦軸プラスの向き
            MOVEH = moverange(1);  //画面が動く方向と距離を調べる
            chara.h += images / 4;  //キャラクターが移動する方向と距離
            if(MODE == move) chara.dire = 4;    //画像の切り替え判定(move状態)
            Display();    //画面更新
            break;
        case GLUT_KEY_LEFT:     //横軸マイナスの向き
            MOVEW -= moverange(0);  //画面が動く方向と距離を調べる
            chara.w -= images / 4;  //キャラクターが移動する方向と距離
            if(MODE == move) chara.dire = 6;    //画像の切り替え判定(move状態)
            Display();    //画面更新
            break;
        default:
            break;
    }
}

//ウインドウのリサイズを管理する
void Reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScaled(1, -1, 1);
    glTranslated(0, -h, 0);

    glutReshapeWindow(352, 352 + upper + footer);   //352×448ピクセル
}

//ウインドウの表示内容を更新する
void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    if(click == 1){
        judgeButton();
    }

    if(count <= 0 && (MODE == move || MODE == pause)){  //ゲームオーバー
        MODE = end;
    }

    int value = mapJudge(W + chara.xposi, H + chara.yposi - upper, chara.dire, "B");    //キャラクターが壁に当たるか調べる
    if(value == 1 || MODE != move){     //動いてはいけないとき  
        chara.h = 0;    //縦軸変化なし
        chara.w = 0;    //横軸変化なし
    }else if(value == 0){
        H += MOVEH;    //縦軸変化あり
        W += MOVEW;    //横軸変化あり
    }

    enemyJudge(&chara);     //敵判定
    itemJudge(&chara);      //アイテム判定

    makemap();              //マップを書く

    printenemy();  //敵を書く

    if(timelag % 2 == 0 || MODE != move) makechara();//キャラを書く

    printBack();    //背景に色を塗る

    clearcheck();   //クリアチェック

    glFlush();
    glutSwapBuffers();//ダブルバッファリング処理
}

//マウスのクリックを判定する
void Mouse(int b, int s, int x, int y){
    if ((b == GLUT_LEFT_BUTTON  ) && (s == GLUT_UP  )){
        mouseClick(0, x, y);    //クリック判定オフ
    }
    if ((b == GLUT_LEFT_BUTTON  ) && (s == GLUT_DOWN)){
        mouseClick(1, x, y);    //クリック判定オン
    }
    if ((b == GLUT_MIDDLE_BUTTON) && (s == GLUT_UP  )){
    }
    if ((b == GLUT_MIDDLE_BUTTON) && (s == GLUT_DOWN)){
    }
    if ((b == GLUT_RIGHT_BUTTON ) && (s == GLUT_UP  )){
    }
    if ((b == GLUT_RIGHT_BUTTON ) && (s == GLUT_DOWN)){
    }
}

//グローバル変数を初期化する
void initGlobal(void){
    setChara(&chara, 0, 0, images * 1, images + upper, 4, 1);   //キャラ初期化
    W = 0;      //左上
    H = 0;      //左上
    MOVEH = images / 4;     //移動距離=8
    MOVEW = images / 4;     //移動距離=8
    count = 100;    //100秒でスタート
    MODE = pause;   //一時停止
    for(int i = 0; i < xnum; i++){
        for(int j = 0; j < ynum; j++){
            map[j][i] = map2[j][i];     //マップのバックアップ
        }
    }
    initEnemy();    //敵初期化
    reh = 0;    //初期化
    rew = 0;    //初期化
    cleartime = 0;  //初期化
    click = 0;      //クリック判定オフ
    timelag = 0;    //初期化
    mouse_x = 0;    //マウスのx座標
    mouse_y = 0;    //マウスのy座標
    revers = 0;     //初期化
    score = 0;      //初期化
}
