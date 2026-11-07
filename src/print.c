#include "base.h"

//PNG画像を表示する
void PutSprite(int num, int x, int y, pngInfo *info){
    int w, h;  //テクスチャの幅と高さ

    w = info->Width;    //テクスチャの幅と高さを取得する
    h = info->Height;

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, num);
    glColor4ub(255, 255, 255, 255);

    glBegin(GL_QUADS);  //幅w、高さhの四角形

    glTexCoord2i(0, 0); 
    glVertex2i(x, y);

    glTexCoord2i(0, 1);
    glVertex2i(x, y + h);

    glTexCoord2i(1, 1);
    glVertex2i(x + w, y + h);

    glTexCoord2i(1, 0);
    glVertex2i(x + w, y);

    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

//敵の位置を初期化する
void initEnemy(void){
    int a = 0;  //マップ内のx座標
    int b = 0;  //マップ内のy座標
    int power = 0;  //強さ
    for(int i = 0; i < teki; i++){  //敵の数だけループ
        while(strncmp("O", &map[b][a], 1) != 0){    //草原になるまで
            a = rand() % xnum;  //マップ内のx座標
            b = rand() % ynum;  //マップ内のy座標
        }
        setChara(&enemy[i], 0, 0, images * a, images * b + upper, 4, power);    //構造体に格納
        a = 0;  //初期化
        b = 0;  //初期化    
        power += (100 / teki);  //強さを増やす
    }
}

//構造体に引数を格納する
void setChara(struct CHARACTER *c, int i, int j, int k, int l, int m, int n){
    c->w = i;
    c->h = j;
    c->xposi = k;
    c->yposi = l;
    c->dire = m;
    c->strength = n;
    c->lord = 1;
}

//キャラを表示する
void makechara(void){
    if(reh == H && rew == W){   //画面が移動したかどうか
        chara.xposi += chara.w;     //横軸の移動距離を足す
        chara.yposi += chara.h;     //縦軸の移動距離を足す
    }
    reh = H;    //Hの値を保持
    rew = W;    //Wの値を保持
    chara.h = 0;    //縦軸の移動距離を初期化
    chara.w = 0;    //横軸の移動距離を初期化
    PutSprite(charaimg[chara.dire + revers], chara.xposi, chara.yposi, &charainfo[chara.dire + revers]);    //キャラクターを表示
}

//ゲームマップを表示する
void makemap(void){
    if(H < 0) H = 0;    //マイナスのとき
    else if(H > (xnum - 11) * images) H = (xnum - 11) * images;     //オーバーしたとき
    if(W < 0) W = 0;    //マイナスのとき
    else if(W > (ynum - 11) * images) W = (ynum - 11) * images;     //オーバーしたとき 
    int x = -W % images;    //書き始める位置
    int y = -H % images + upper;    //書き始める位置
    for(int i = H/images; i < xnum; i++){
        if(y > lower) break;        //表示終了
        x = -W % images;    //書き始める位置
        for(int j = W/images; j < ynum; j++){
            if(x > 352) break;        //表示終了
            if(strncmp("O", &map[i][j], 1) == 0){   //歩けるマス
                PutSprite(img[0], x, y, &info[0]);  //表示
            }
            else if(strncmp("S", &map[i][j], 1) == 0){  //アイテム
                PutSprite(img[0], x, y, &info[0]);  //表示
                PutSprite(img[1], x, y, &info[1]);  //表示
            }
            else if(strncmp("B", &map[i][j], 1) == 0){  //壁
                PutSprite(img[2], x, y, &info[2]);  //表示
            }
            else if(strncmp("T", &map[i][j], 1) == 0){  //スタート地点1
                PutSprite(img[5], x, y, &info[5]);  //表示
            }
            else if(strncmp("R", &map[i][j], 1) == 0){  //スタート地点2
                PutSprite(img[6], x, y, &info[6]);  //表示
            }
            else if(strncmp("G", &map[i][j], 1) == 0){  //ゴール地点1
                PutSprite(img[7], x, y, &info[7]);  //表示
            }
            else if(strncmp("A", &map[i][j], 1) == 0){  //ゴール地点2
                PutSprite(img[8], x, y, &info[8]);  //表示
            }
            x += images;    //x座標を増やす
        }
        y += images;    //ｙ座標を増やす
    }
    MOVEH = 0;    //画面の移動距離を初期化
    MOVEW = 0;    //画面の移動距離を初期化
}

//敵を表示する
void printenemy(void){
    for(int i = 0; i < teki; i++){  //1体ずつ選択
        if(enemy[i].lord == 1){
            if(enemy[i].xposi - W <= 352 && enemy[i].xposi - W >= -24 && enemy[i].yposi - H <= lower && enemy[i].yposi - H >= upper - 24){
                if(chara.strength > enemy[i].strength) PutSprite(img[4], enemy[i].xposi - W, enemy[i].yposi - H, &info[4]);
                else PutSprite(img[3], enemy[i].xposi - W, enemy[i].yposi - H, &info[3]);
            }
        }
    }
}
