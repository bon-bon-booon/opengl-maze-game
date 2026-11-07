#include <GL/glut.h>
#include <GL/glpng.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define xnum 61     //奇数
#define ynum 61     //奇数
#define images 32   //画像のピクセル
#define teki 25     //敵の数
#define upper images * 2    //上部の表示範囲
#define lower 352 + upper   //マップの下辺
#define footer 32   //下部の表示範囲
#define end -1  //ゲームオーバー状態
#define pause 0 //ポーズ状態
#define move 1  //スタート状態
#define clear 2 //クリア状態


struct CHARACTER{
    int w;  //x軸の移動量
    int h;  //y軸の移動量
    int xposi;  //x座標
    int yposi;  //y座標
    int dire;   //移動する方向
    int strength;   //強さ
    int lord;   //命
};

GLuint img[256];
pngInfo info[256];

GLuint charaimg[256];
pngInfo charainfo[256];

struct CHARACTER chara;     //キャラクターの情報
struct CHARACTER enemy[teki];   //敵の情報
int W;  //マップ内のx座標
int H;  //マップ内のy座標
int MOVEH;  //x座標の移動距離
int MOVEW;  //y座標の移動距離
int reh;    //Hの変化
int rew;    //Wの変化
int count;  //タイムリミット
int cleartime; //クリアタイム
int mouse_x;    //マウスのx座標
int mouse_y;    //マウスのy座標
int click;      //クリック判定
int timelag;    //時間差
int MODE;       //モード選択
int score;      //スコアを格納
int revers;     //反転
extern int msecond[];       //時間
char map[xnum][ynum + 1];   //マップ
extern char map2[xnum][ynum + 1];   //マップ

//central.c
//コールバック関数やグローバル変数の初期化
void Timer(int);    //タイマー割り込みを管理する
void Keyboard(unsigned char, int, int);     //通常のキー入力を判定する
void SpecialKey(int, int, int);     //特殊キー入力を判定する
void Reshape(int, int);     //ウインドウのリサイズを管理する
void Display(void);     //ウインドウの表示内容を更新する
void Mouse(int, int, int, int);     //マウスのクリックを判定する
void initGlobal(void);      //グローバル変数を初期化する

//layout.c
//ウインドウの背景やボタンなどの管理
void drawSquare(int, int, int, int);    //四角形を描画する
void printStr(int, int, char *);    //文字列を表示する
void mouseClick(int, int, int);     //クリック判定の更新とマウスの座標を格納する
void judgeButton(void);     //マウスで押された場所の判定
void printBack(void);       //背景の色塗りと文字の表示

//print.c
//ゲームマップやキャラクターなどの表示
void PutSprite(int, int, int, pngInfo *);   //PNG画像を表示する
void initEnemy(void);   //敵の位置を初期化する
void setChara(struct CHARACTER *, int, int, int, int, int, int);    //構造体に引数を格納する
void makechara(void);   //キャラを表示する
void makemap(void);     //ゲームマップを表示する
void printenemy(void);  //敵を表示する

//move.c
//キャラクターの移動やゲームマップの変化の管理
void moveEnemy(void);       //敵の移動方向を決める
void itemJudge(struct CHARACTER *);     //アイテムを取得したか判定する
int moverange(int);     //画面が動く範囲を決める
int mapJudge(int, int, int, char *);    //壁に当たったかどうか判定する
void enemyJudge(struct CHARACTER *);    //敵と当たったか判定する
void clearcheck(void);  //クリアチェックをする
